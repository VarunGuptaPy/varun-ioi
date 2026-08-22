#!/usr/bin/env python3

from __future__ import annotations

import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parent

SOLUTION_SOURCE = ROOT / "solution.cpp"
BRUTE_SOURCE = ROOT / "brute.cpp"
GENERATOR_SOURCE = ROOT / "gen.cpp"

SOLUTION_EXECUTABLE = ROOT / "solution"
BRUTE_EXECUTABLE = ROOT / "brute"
GENERATOR_EXECUTABLE = ROOT / "gen"

INPUT_FILE = ROOT / "failing_input.txt"


def run_command(
    command: list[str],
    *,
    input_data: bytes | None = None,
    timeout: float = 3.0,
) -> subprocess.CompletedProcess[bytes]:
    try:
        return subprocess.run(
            command,
            input=input_data,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            timeout=timeout,
            check=False,
        )
    except subprocess.TimeoutExpired:
        print(f"\nTime limit exceeded: {' '.join(command)}")
        sys.exit(1)


def compile_program(source: Path, executable: Path) -> None:
    command = [
        "clang++",
        str(source),
        "-std=c++20",
        "-O2",
        "-Wall",
        "-Wextra",
        "-o",
        str(executable),
    ]

    result = run_command(command, timeout=30.0)

    if result.returncode != 0:
        print(f"Compilation failed for {source.name}:")
        print(result.stderr.decode(errors="replace"))
        sys.exit(1)


def normalized(output: bytes) -> bytes:
    return b" ".join(output.split())


def main() -> None:
    compile_program(SOLUTION_SOURCE, SOLUTION_EXECUTABLE)
    compile_program(BRUTE_SOURCE, BRUTE_EXECUTABLE)
    compile_program(GENERATOR_SOURCE, GENERATOR_EXECUTABLE)

    test_number = 1

    while True:
        seed = test_number

        generated = run_command(
            [str(GENERATOR_EXECUTABLE), str(seed)]
        )

        if generated.returncode != 0:
            print("Generator crashed:")
            print(generated.stderr.decode(errors="replace"))
            return

        test_input = generated.stdout

        expected = run_command(
            [str(BRUTE_EXECUTABLE)],
            input_data=test_input,
        )

        received = run_command(
            [str(SOLUTION_EXECUTABLE)],
            input_data=test_input,
        )

        if expected.returncode != 0:
            print(f"\nBrute force crashed on seed {seed}.")
            INPUT_FILE.write_bytes(test_input)
            print(expected.stderr.decode(errors="replace"))
            return

        if received.returncode != 0:
            print(f"\nSolution crashed on seed {seed}.")
            INPUT_FILE.write_bytes(test_input)
            print(received.stderr.decode(errors="replace"))
            return

        if normalized(expected.stdout) != normalized(received.stdout):
            INPUT_FILE.write_bytes(test_input)

            print(f"\nWrong answer on test {test_number}")
            print(f"Seed: {seed}")

            print("\nInput:")
            print(test_input.decode(errors="replace"))

            print("Expected:")
            print(expected.stdout.decode(errors="replace"))

            print("Received:")
            print(received.stdout.decode(errors="replace"))

            print(f"Failing input saved to: {INPUT_FILE}")
            return

        print(f"\rPassed {test_number} tests", end="", flush=True)
        test_number += 1


if __name__ == "__main__":
    main()
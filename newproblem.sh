#!/bin/zsh

set -e

if [[ -z "$1" ]]; then
    echo "Usage: newproblem <folder-name>"
    exit 1
fi

TEMPLATE="$HOME/Desktop/CompetitiveProgramming/Template"
DESTINATION="$PWD/$1"

if [[ -e "$DESTINATION" ]]; then
    echo "Folder already exists: $DESTINATION"
    exit 1
fi

mkdir -p "$DESTINATION"

cp "$TEMPLATE/solution.cpp" "$DESTINATION/solution.cpp"
touch "$DESTINATION/input.txt"

if [[ -d "$TEMPLATE/.vscode" ]]; then
    cp -R "$TEMPLATE/.vscode" "$DESTINATION/.vscode"
fi

echo "Created: $DESTINATION"
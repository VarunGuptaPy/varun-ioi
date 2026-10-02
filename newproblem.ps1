param(
    [Parameter(Mandatory = $true)]
    [string]$FolderName
)

$ErrorActionPreference = "Stop"

$Template = "$HOME\OneDrive\Desktop\varun\varun-ioi\Template"
$Destination = Join-Path (Get-Location) $FolderName

if (Test-Path $Destination) {
    Write-Host "Folder already exists: $Destination"
    exit 1
}

New-Item -ItemType Directory -Path $Destination | Out-Null

Copy-Item "$Template\solution.cpp" "$Destination\solution.cpp"

New-Item -ItemType File -Path "$Destination\input.txt" | Out-Null

$VsCodeFolder = "$Template\.vscode"

if (Test-Path $VsCodeFolder -PathType Container) {
    Copy-Item $VsCodeFolder "$Destination\.vscode" -Recurse
}

Write-Host "Created: $Destination"
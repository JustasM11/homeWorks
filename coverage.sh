#!/bin/bash
echo "=== Running gcovr... ==="
gcovr --version
rm -rf ./coverage/
mkdir -p ./coverage/
gcovr -r ./ --html --html-details -o ./coverage/coverage.html -s --exclude=".*googletest.*" --exclude=".*ccache.*" --exclude=".*vscode.*" --exclude=".*cmake.*" --exclude=".*main.*" --exclude=".*tests.*"
echo "=== Done ==="

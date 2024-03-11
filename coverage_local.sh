#!/bin/bash
echo "=== Running gcovr... ==="
gcovr --version
rm -rf ./coverage/ ./coveralls.out
mkdir -p ./coverage/
gcovr -r ./ --coveralls coveralls.out --html --html-details -o ./coverage/coverage.html -s --exclude=".*googletest.*" --exclude=".*ccache.*" --exclude=".*vscode.*" --exclude=".*cmake.*" --exclude=".*tests.*" 2>/dev/null
echo "=== Done ==="

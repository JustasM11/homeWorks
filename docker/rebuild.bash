#!/bin/bash
set -e
bash -c "docker image rm justasm11/home_works:latest; exit 0"
docker build --tag justasm11/home_works:latest .

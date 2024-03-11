#!/bin/bash
set -e
docker run \
    --rm \
    -v $(pwd):/home/docker \
    -u $(id -u ${USER}):$(id -g ${USER}) \
    justasm11/home_works:latest \
    /bin/sh -c "./local_build.sh"

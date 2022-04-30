#!/usr/bin/env bash

set -e

cd /src
mkdir -p /build
cd /build
cmake /src
make
make test

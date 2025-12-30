#!/usr/bin/env bash

set -e

NAME=$(openssl rand -hex 16)

cargo build --release --features "read-only,no-overlay,allow-root"
cp ./target/release/deadlocked ./target/release/$NAME
sudo ./target/release/$NAME --read-only
rm ./target/release/$NAME

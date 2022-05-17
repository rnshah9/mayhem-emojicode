FROM --platform=linux/amd64 ubuntu:20.04

## Install build dependencies.
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y clang python3.8 ninja-build rsync g++ zlib1g-dev llvm-8-dev cmake

ADD . /emojicode
WORKDIR /emojicode/build
RUN cmake .. -GNinja
RUN ninja
RUN ninja magicinstall

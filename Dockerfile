FROM --platform=linux/amd64 ubuntu:20.04 as builder

## Install build dependencies.
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y clang python3.8 ninja-build rsync g++ zlib1g-dev llvm-8-dev cmake

ADD . /emojicode
WORKDIR /emojicode/build
RUN cmake .. -GNinja
RUN ninja
RUN ninja magicinstall

RUN mkdir -p /deps
RUN ldd /usr/local/bin/emojicodec | tr -s '[:blank:]' '\n' | grep '^/' | xargs -I % sh -c 'cp % /deps;'

FROM ubuntu:20.04 as package

COPY --from=builder /deps /deps
COPY --from=builder /usr/local/bin/emojicodec /usr/local/bin/emojicodec
ENV LD_LIBRARY_PATH=/deps

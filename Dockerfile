FROM ubuntu:24.04

RUN apt -y update
RUN apt -y install git cmake
RUN apt -y install clang

RUN git clone https://github.com/antlr/antlr4.git
WORKDIR /antlr4
RUN git checkout 4.11.1
RUN mkdir /antlr4/runtime/Cpp/build
WORKDIR /antlr4/runtime/Cpp/build
RUN cmake .. -DCMAKE_INSTALL_LIBDIR="/usr/local/lib"
RUN make -j$(nproc)
RUN make install

RUN apt -y install libboost-dev

WORKDIR /
COPY . /its-conversion
RUN mkdir -p /its-conversion/build-local
WORKDIR /its-conversion/build-local
RUN cmake ..
RUN make -j$(nproc)

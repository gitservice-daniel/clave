FROM ubuntu:latest

# Init
RUN DEBIAN_FRONTEND=noninteractive apt update -y && apt upgrade -y

# Installing Dependencies
RUN DEBIAN_FRONTEND=noninteractive apt install -y build-essential
RUN DEBIAN_FRONTEND=noninteractive apt install -y bison
RUN DEBIAN_FRONTEND=noninteractive apt install -y flex
RUN DEBIAN_FRONTEND=noninteractive apt install -y libgmp3-dev
RUN DEBIAN_FRONTEND=noninteractive apt install -y libmpc-dev
RUN DEBIAN_FRONTEND=noninteractive apt install -y libmpfr-dev
RUN DEBIAN_FRONTEND=noninteractive apt install -y texinfo
RUN DEBIAN_FRONTEND=noninteractive apt install -y wget

# Install Binutils and GCC Source Code
RUN DEBIAN_FRONTEND=noninteractive && mkdir -p $HOME/src && cd $HOME/src && \
    wget https://ftp.gnu.org/gnu/binutils/binutils-2.38.tar.xz && \
    tar -xf binutils-2.38.tar.xz && rm -rf binutils-2.38.tar.xz

RUN DEBIAN_FRONTEND=noninteractive && mkdir -p $HOME/src && cd $HOME/src && \
    wget https://ftp.gnu.org/gnu/gcc/gcc-12.1.0/gcc-12.1.0.tar.xz && \
    tar -xf gcc-12.1.0.tar.xz && rm -rf gcc-12.1.0.tar.xz

# Build Binutils
RUN DEBIAN_FRONTEND=noninteractive cd $HOME/src && \
    mkdir -p build-binutils && cd build-binutils && \
    ../binutils-2.38/configure --target=i686-elf --prefix="$HOME/opt/cross" --with-sysroot --disable-nls --disable-werror && \
    make && make install

# Build GCC Cross-Compiler
RUN DEBIAN_FRONTEND=noninteractive cd $HOME/src && \
    mkdir -p build-gcc && cd build-gcc && \
    ../gcc-12.1.0/configure --target=i686-elf --prefix="$HOME/opt/cross" --disable-nls --enable-languages=c,c++ --without-headers && \
    make all-gcc && make all-target-libgcc && make install-gcc && make install-target-libgcc

# Remove Build Files
RUN DEBIAN_FRONTEND=noninteractive rm -rf $HOME/src

# Install some Utilties
RUN DEBIAN_FRONTEND=noninteractive apt install -y nasm
RUN DEBIAN_FRONTEND=noninteractive apt install -y xorriso
RUN DEBIAN_FRONTEND=noninteractive apt install -y grub-pc-bin
RUN DEBIAN_FRONTEND=noninteractive apt install -y grub-common

# Add GCC to Path
ENV PATH="/root/opt/cross/bin:${PATH}"

# Make a Update and a Upgrade
RUN DEBIAN_FRONTEND=noninteractive apt update -y
RUN DEBIAN_FRONTEND=noninteractive apt upgrade -y

# Setup Volume and Workdir
VOLUME /root/env
WORKDIR /root/env
# A small glibc/apt base image designed for use in containers
FROM bitnami/minideb

# Install dependencies
RUN apt-get update && apt-get install -yq --no-install-recommends \
    python \
    python-pip && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Install tools
RUN pip install platformio

# Set the working directory
WORKDIR /usr/src/app

# Set up for building
RUN mkdir -p /assets

# Set the board
ENV BOARD huzzah

# Copy config files to the working directory
COPY platformio.ini ./

# Copy source files to the working directory
COPY src/ ./src

# Copy library files to the working directory
COPY lib/ ./lib

# Compile the firmware
RUN platformio run --environment $BOARD && \
    mv .pioenvs/$BOARD/firmware.bin /assets/

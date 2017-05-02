# esp8266 base image
# See more about resin base images here: http://docs.resin.io/runtime/resin-base-images/
FROM resin/esp8266

# Set the working directory
WORKDIR /usr/src/app

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

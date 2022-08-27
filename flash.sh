#!/bin/bash

openocd -f interface/jlink.cfg -c "transport select swd" -c "adapter_khz 6000" -f target/rp2040.cfg  \
    -c "program build/src/picotft.elf reset exit"

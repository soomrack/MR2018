#!/bin/sh

gcc -Wall -Wpedantic -Wextra  -Wcast-align -Wcast-qual -Wvla -Wshadow -Wsuggest-attribute=const -Wmissing-format-attribute -Wuninitialized -Winit-self  -Wdouble-promotion -Wno-unused-local-typedefs -O0 -isystem src/cmsis -I src -isystem src/mcu_support_package/inc -std=c99 -DSTM32F103xB -DUSE_FULL_ASSERT -DSTM32F10X_MD -DHSE_VALUE="8000000" src/main/eval.c src/main/bitmagic.c .test/tests.c -o test_runner && chmod +x test_runner && ./test_runner

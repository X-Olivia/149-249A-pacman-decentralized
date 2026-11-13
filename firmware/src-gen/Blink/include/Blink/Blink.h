#ifndef _blink_main_H
#define _blink_main_H
#ifndef _BLINK_MAIN_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_1558941021_H
#define TOP_LEVEL_PREAMBLE_1558941021_H
/*Correspondence: Range: [(15, 2), (17, 26)) -> Range: [(0, 0), (2, 26)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/Blink.lf)*/#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#endif // TOP_LEVEL_PREAMBLE_1558941021_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct blink_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    bool led_on;
    int end[0]; // placeholder; MSVC does not compile empty structs
} blink_self_t;
#endif
#endif

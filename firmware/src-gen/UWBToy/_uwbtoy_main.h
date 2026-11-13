#ifndef _UWBTOY_MAIN_H
#define _UWBTOY_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_uwb.h"
#ifndef TOP_LEVEL_PREAMBLE_540593389_H
#define TOP_LEVEL_PREAMBLE_540593389_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_540593389_H
#ifndef TOP_LEVEL_PREAMBLE_636805721_H
#define TOP_LEVEL_PREAMBLE_636805721_H
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#endif // TOP_LEVEL_PREAMBLE_636805721_H


typedef struct {
    struct self_base_t base;
#line 22 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy/_uwbtoy_main.h"
#line 23 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy/_uwbtoy_main.h"
    struct {
        _display_line0_t line0;
    } _lf_display;
    int _lf_display_width;
    struct {
        _uwb_dist_t* dist;
        trigger_t dist_trigger;
        reaction_t* dist_reactions[1];
    } _lf_uwb;
    int _lf_uwb_width;
    reaction_t _lf__reaction_0;
} _uwbtoy_main_main_self_t;
_uwbtoy_main_main_self_t* new__uwbtoy_main();
#endif // _UWBTOY_MAIN_H

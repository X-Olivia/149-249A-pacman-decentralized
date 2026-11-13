#ifndef _BLINK_MAIN_H
#define _BLINK_MAIN_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1558941021_H
#define TOP_LEVEL_PREAMBLE_1558941021_H
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#endif // TOP_LEVEL_PREAMBLE_1558941021_H
typedef struct {
    struct self_base_t base;
#line 13 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/Blink/_blink_main.h"
    #line 23 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/Blink.lf"
    bool led_on;
#line 16 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/Blink/_blink_main.h"
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _blink_main_main_self_t;
_blink_main_main_self_t* new__blink_main();
#endif // _BLINK_MAIN_H

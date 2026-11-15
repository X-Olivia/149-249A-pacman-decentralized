#ifndef _UWBTOY2_MAIN_H
#define _UWBTOY2_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_uart.h"
#include "_uwb.h"
#ifndef TOP_LEVEL_PREAMBLE_1399886428_H
#define TOP_LEVEL_PREAMBLE_1399886428_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_1399886428_H
#ifndef TOP_LEVEL_PREAMBLE_771002760_H
#define TOP_LEVEL_PREAMBLE_771002760_H
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_771002760_H
#ifndef TOP_LEVEL_PREAMBLE_2021825449_H
#define TOP_LEVEL_PREAMBLE_2021825449_H
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#define MESSAGE_SIZE 128
#endif // TOP_LEVEL_PREAMBLE_2021825449_H
typedef struct {
    struct self_base_t base;
#line 30 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy2/_uwbtoy2_main.h"
    #line 19 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/UWBToy2.lf"
    int count;
#line 33 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy2/_uwbtoy2_main.h"
    struct {
        _display_line0_t line0;
    } _lf_display;
    int _lf_display_width;
    struct {
        _uart_bt_in_t bt_in;
    } _lf_uart;
    int _lf_uart_width;
    struct {
        _uwb_dist_t* dist;
        trigger_t dist_trigger;
        reaction_t* dist_reactions[1];
    } _lf_uwb;
    int _lf_uwb_width;
    reaction_t _lf__reaction_0;
} _uwbtoy2_main_main_self_t;
_uwbtoy2_main_main_self_t* new__uwbtoy2_main();
#endif // _UWBTOY2_MAIN_H

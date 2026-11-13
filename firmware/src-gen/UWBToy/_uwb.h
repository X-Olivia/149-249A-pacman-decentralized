#ifndef _UWB_H
#define _UWB_H
#include "include/core/reactor.h"
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
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _uwb_dist_t;
typedef struct {
    struct self_base_t base;
#line 32 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy/_uwb.h"
#line 33 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy/_uwb.h"
    _uwb_dist_t _lf_dist;
    int _lf_dist_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__poll;
    reaction_t* _lf__poll_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _uwb_self_t;
_uwb_self_t* new__uwb();
#endif // _UWB_H

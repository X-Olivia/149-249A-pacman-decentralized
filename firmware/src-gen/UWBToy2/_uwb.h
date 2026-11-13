#ifndef _UWB_H
#define _UWB_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_455428179_H
#define TOP_LEVEL_PREAMBLE_455428179_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_455428179_H
#ifndef TOP_LEVEL_PREAMBLE_1168747802_H
#define TOP_LEVEL_PREAMBLE_1168747802_H
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_1168747802_H
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _uwb_dist_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_action_internal_t _base;
    self_base_t* parent;
    bool has_value;
    int source_id;

    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _uwb_uart_irq_a_t;
typedef struct {
    struct self_base_t base;
#line 50 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy2/_uwb.h"
#line 51 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy2/_uwb.h"
    _uwb_uart_irq_a_t _lf_uart_irq_a;
    _uwb_dist_t _lf_dist;
    int _lf_dist_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__poll;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__uart_irq_a;
    reaction_t* _lf__uart_irq_a_reactions[1];
} _uwb_self_t;
_uwb_self_t* new__uwb();
#endif // _UWB_H

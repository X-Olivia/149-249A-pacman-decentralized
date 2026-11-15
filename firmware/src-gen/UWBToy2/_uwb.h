#ifndef _UWB_H
#define _UWB_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_771002760_H
#define TOP_LEVEL_PREAMBLE_771002760_H
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_771002760_H
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
} _uwb_uart_data_t;
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
    struct self_base_t base;
#line 42 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy2/_uwb.h"
#line 43 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy2/_uwb.h"
    _uwb_uart_data_t* _lf_uart_data;
    // width of -2 indicates that it is not a multiport.
    int _lf_uart_data_width;
    // Default input (in case it does not get connected)
    _uwb_uart_data_t _lf_default__uart_data;
    _uwb_dist_t _lf_dist;
    int _lf_dist_width;
    reaction_t _lf__reaction_0;
    trigger_t _lf__uart_data;
    reaction_t* _lf__uart_data_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _uwb_self_t;
_uwb_self_t* new__uwb();
#endif // _UWB_H

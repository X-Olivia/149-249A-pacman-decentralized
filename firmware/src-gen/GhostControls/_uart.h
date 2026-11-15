#ifndef _UART_H
#define _UART_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_314583580_H
#define TOP_LEVEL_PREAMBLE_314583580_H
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#define MESSAGE_SIZE 128
#endif // TOP_LEVEL_PREAMBLE_314583580_H
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
} _uart_bt_in_t;
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
} _uart_uwb_out_t;
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
} _uart_bt_out_t;
typedef struct {
    struct self_base_t base;
#line 58 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_uart.h"
#line 59 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_uart.h"
    _uart_bt_in_t* _lf_bt_in;
    // width of -2 indicates that it is not a multiport.
    int _lf_bt_in_width;
    // Default input (in case it does not get connected)
    _uart_bt_in_t _lf_default__bt_in;
    _uart_uwb_out_t _lf_uwb_out;
    int _lf_uwb_out_width;
    _uart_bt_out_t _lf_bt_out;
    int _lf_bt_out_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__poll;
    reaction_t* _lf__poll_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__bt_in;
    reaction_t* _lf__bt_in_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _uart_self_t;
_uart_self_t* new__uart();
#endif // _UART_H

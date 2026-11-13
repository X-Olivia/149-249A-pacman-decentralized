#ifndef _uwb_H
#define _uwb_H
#ifndef _UWB_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_455428179_H
#define TOP_LEVEL_PREAMBLE_455428179_H
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_455428179_H
#ifndef TOP_LEVEL_PREAMBLE_1168747802_H
#define TOP_LEVEL_PREAMBLE_1168747802_H
/*Correspondence: Range: [(12, 2), (15, 19)) -> Range: [(0, 0), (3, 19)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/UWBToy2.lf)*/#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_1168747802_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct uwb_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int end[0]; // placeholder; MSVC does not compile empty structs
} uwb_self_t;
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
} uwb_dist_t;
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
} uwb_uart_irq_a_t;
#endif
#endif

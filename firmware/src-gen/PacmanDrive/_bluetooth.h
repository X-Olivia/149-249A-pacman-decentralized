#ifndef _BLUETOOTH_H
#define _BLUETOOTH_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_444520614_H
#define TOP_LEVEL_PREAMBLE_444520614_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_444520614_H
#ifndef TOP_LEVEL_PREAMBLE_1140280435_H
#define TOP_LEVEL_PREAMBLE_1140280435_H
#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_1140280435_H
#ifndef TOP_LEVEL_PREAMBLE_935741155_H
#define TOP_LEVEL_PREAMBLE_935741155_H
#include <ir_sensors.h>
#endif // TOP_LEVEL_PREAMBLE_935741155_H
#ifndef TOP_LEVEL_PREAMBLE_1360728045_H
#define TOP_LEVEL_PREAMBLE_1360728045_H
#include <stdio.h>
#include "hardware/uart.h"
#include "hardware/gpio.h"
#endif // TOP_LEVEL_PREAMBLE_1360728045_H
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    char value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _bluetooth_cmd_t;
typedef struct {
    struct self_base_t base;
#line 41 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/PacmanDrive/_bluetooth.h"
#line 42 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/PacmanDrive/_bluetooth.h"
    _bluetooth_cmd_t _lf_cmd;
    int _lf_cmd_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__poll;
    reaction_t* _lf__poll_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _bluetooth_self_t;
_bluetooth_self_t* new__bluetooth();
#endif // _BLUETOOTH_H

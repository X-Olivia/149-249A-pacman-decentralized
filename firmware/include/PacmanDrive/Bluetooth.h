#ifndef _bluetooth_H
#define _bluetooth_H
#ifndef _BLUETOOTH_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_268702926_H
#define TOP_LEVEL_PREAMBLE_268702926_H
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_268702926_H
#ifndef TOP_LEVEL_PREAMBLE_1406211721_H
#define TOP_LEVEL_PREAMBLE_1406211721_H
/*Correspondence: Range: [(19, 2), (20, 17)) -> Range: [(0, 0), (1, 17)) (verbatim=true; src=/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/lib/Motors.lf)*/#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_1406211721_H
#ifndef TOP_LEVEL_PREAMBLE_1794043670_H
#define TOP_LEVEL_PREAMBLE_1794043670_H
/*Correspondence: Range: [(33, 2), (33, 25)) -> Range: [(0, 0), (0, 23)) (verbatim=true; src=/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/lib/Line.lf)*/#include <ir_sensors.h>
#endif // TOP_LEVEL_PREAMBLE_1794043670_H
#ifndef TOP_LEVEL_PREAMBLE_1690053714_H
#define TOP_LEVEL_PREAMBLE_1690053714_H
/*Correspondence: Range: [(14, 2), (16, 26)) -> Range: [(0, 0), (2, 26)) (verbatim=true; src=/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/PacmanDrive.lf)*/#include <stdio.h>
#include "hardware/uart.h"
#include "hardware/gpio.h"
#endif // TOP_LEVEL_PREAMBLE_1690053714_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct bluetooth_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int end[0]; // placeholder; MSVC does not compile empty structs
} bluetooth_self_t;
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
} bluetooth_cmd_t;
#endif
#endif

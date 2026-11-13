#ifndef _uwbtoy_main_H
#define _uwbtoy_main_H
#ifndef _UWBTOY_MAIN_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_540593389_H
#define TOP_LEVEL_PREAMBLE_540593389_H
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_540593389_H
#ifndef TOP_LEVEL_PREAMBLE_636805721_H
#define TOP_LEVEL_PREAMBLE_636805721_H
/*Correspondence: Range: [(11, 2), (13, 26)) -> Range: [(0, 0), (2, 26)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/UWBToy.lf)*/#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#endif // TOP_LEVEL_PREAMBLE_636805721_H


#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct uwbtoy_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int end[0]; // placeholder; MSVC does not compile empty structs
} uwbtoy_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} uwb_dist_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line0_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line1_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line2_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line3_t;
#endif
#endif

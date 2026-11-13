#ifndef _linedisplay_main_H
#define _linedisplay_main_H
#ifndef _LINEDISPLAY_MAIN_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_910101408_H
#define TOP_LEVEL_PREAMBLE_910101408_H
/*Correspondence: Range: [(33, 2), (33, 25)) -> Range: [(0, 0), (0, 23)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/Line.lf)*/#include <ir_sensors.h>
#endif // TOP_LEVEL_PREAMBLE_910101408_H
#ifndef TOP_LEVEL_PREAMBLE_1238339624_H
#define TOP_LEVEL_PREAMBLE_1238339624_H
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_1238339624_H


#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct linedisplay_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    interval_t calibration_time;
    interval_t sample_period;
    int count;
    int end[0]; // placeholder; MSVC does not compile empty structs
} linedisplay_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} line_calibrate_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} line_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint16_t value[5];

} line_reflect_t;
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

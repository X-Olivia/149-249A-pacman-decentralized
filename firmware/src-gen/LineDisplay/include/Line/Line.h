#ifndef _line_H
#define _line_H
#ifndef _LINE_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_910101408_H
#define TOP_LEVEL_PREAMBLE_910101408_H
/*Correspondence: Range: [(33, 2), (33, 25)) -> Range: [(0, 0), (0, 23)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/Line.lf)*/#include <ir_sensors.h>
#endif // TOP_LEVEL_PREAMBLE_910101408_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct line_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    bool calibrating;
    bool calibrated;
    int end[0]; // placeholder; MSVC does not compile empty structs
} line_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} line_calibrate_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} line_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint16_t value[5];
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} line_reflect_t;
#endif
#endif

#ifndef _trapezoidalintegrator_H
#define _trapezoidalintegrator_H
#ifndef _TRAPEZOIDALINTEGRATOR_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_1671377200_H
#define TOP_LEVEL_PREAMBLE_1671377200_H
/*Correspondence: Range: [(21, 2), (22, 16)) -> Range: [(0, 0), (1, 16)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/IMU.lf)*/#include <pico/stdlib.h>
#include <imu.h>
#endif // TOP_LEVEL_PREAMBLE_1671377200_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct trapezoidalintegrator_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    float s;
    float prev_in;
    instant_t prev_time;
    int end[0]; // placeholder; MSVC does not compile empty structs
} trapezoidalintegrator_self_t;
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
} trapezoidalintegrator_in_t;
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
} trapezoidalintegrator_out_t;
#endif
#endif

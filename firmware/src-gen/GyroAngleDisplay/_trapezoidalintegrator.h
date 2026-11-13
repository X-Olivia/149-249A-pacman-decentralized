#ifndef _TRAPEZOIDALINTEGRATOR_H
#define _TRAPEZOIDALINTEGRATOR_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1671377200_H
#define TOP_LEVEL_PREAMBLE_1671377200_H
#include <pico/stdlib.h>
#include <imu.h>
#endif // TOP_LEVEL_PREAMBLE_1671377200_H
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
} _trapezoidalintegrator_in_t;
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
} _trapezoidalintegrator_out_t;
typedef struct {
    struct self_base_t base;
#line 40 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_trapezoidalintegrator.h"
    #line 93 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/IMU.lf"
    float s;
    #line 94 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/IMU.lf"
    float prev_in;
    #line 95 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/IMU.lf"
    instant_t prev_time;
#line 47 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_trapezoidalintegrator.h"
    _trapezoidalintegrator_in_t* _lf_in;
    // width of -2 indicates that it is not a multiport.
    int _lf_in_width;
    // Default input (in case it does not get connected)
    _trapezoidalintegrator_in_t _lf_default__in;
    _trapezoidalintegrator_out_t _lf_out;
    int _lf_out_width;
    reaction_t _lf__reaction_0;
    trigger_t _lf__in;
    reaction_t* _lf__in_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _trapezoidalintegrator_self_t;
_trapezoidalintegrator_self_t* new__trapezoidalintegrator();
#endif // _TRAPEZOIDALINTEGRATOR_H

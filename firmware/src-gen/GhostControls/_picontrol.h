#ifndef _PICONTROL_H
#define _PICONTROL_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1112073835_H
#define TOP_LEVEL_PREAMBLE_1112073835_H
#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_1112073835_H
#ifndef TOP_LEVEL_PREAMBLE_1657697023_H
#define TOP_LEVEL_PREAMBLE_1657697023_H
#include <math.h>
#define WHEEL_DIAMETER 0.032 // meters
#define COUNTS_PER_REV 360 //CPR
#define TICKS_PER_METER (WHEEL_DIAMETER * M_PI) / COUNTS_PER_REV
#endif // TOP_LEVEL_PREAMBLE_1657697023_H
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
} _picontrol_err_t;
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
} _picontrol_ctrl_t;
typedef struct {
    struct self_base_t base;
    #line 80 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    float p_gain;
    #line 80 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    float i_gain;
#line 51 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_picontrol.h"
    #line 83 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    float acum_err;
#line 54 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_picontrol.h"
    _picontrol_err_t* _lf_err;
    // width of -2 indicates that it is not a multiport.
    int _lf_err_width;
    // Default input (in case it does not get connected)
    _picontrol_err_t _lf_default__err;
    _picontrol_ctrl_t _lf_ctrl;
    int _lf_ctrl_width;
    reaction_t _lf__reaction_0;
    trigger_t _lf__err;
    reaction_t* _lf__err_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _picontrol_self_t;
_picontrol_self_t* new__picontrol();
#endif // _PICONTROL_H

#ifndef _MOTORSWITHFEEDBACK_H
#define _MOTORSWITHFEEDBACK_H
#include "include/core/reactor.h"
#include "_picontrol.h"
#include "_motors.h"
#ifndef TOP_LEVEL_PREAMBLE_62156248_H
#define TOP_LEVEL_PREAMBLE_62156248_H
#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_62156248_H
#ifndef TOP_LEVEL_PREAMBLE_1591683105_H
#define TOP_LEVEL_PREAMBLE_1591683105_H
#include <math.h>
#define WHEEL_DIAMETER 0.032 // meters
#define COUNTS_PER_REV 360 //CPR
#define TICKS_PER_METER (WHEEL_DIAMETER * M_PI) / COUNTS_PER_REV
#endif // TOP_LEVEL_PREAMBLE_1591683105_H



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
} _motorswithfeedback_left_speed_t;
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
} _motorswithfeedback_right_speed_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _motorswithfeedback_left_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _motorswithfeedback_right_t;
typedef struct {
    struct self_base_t base;
    #line 28 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    float p_gain;
    #line 28 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    float i_gain;
#line 84 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motorswithfeedback.h"
    #line 37 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    interval_t prev_time;
    #line 38 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    int32_t prev_left;
    #line 39 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    int32_t prev_right;
    #line 40 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    float target_speed_left;
    #line 41 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    float target_speed_right;
#line 95 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motorswithfeedback.h"
    _motorswithfeedback_left_speed_t* _lf_left_speed;
    // width of -2 indicates that it is not a multiport.
    int _lf_left_speed_width;
    // Default input (in case it does not get connected)
    _motorswithfeedback_left_speed_t _lf_default__left_speed;
    _motorswithfeedback_right_speed_t* _lf_right_speed;
    // width of -2 indicates that it is not a multiport.
    int _lf_right_speed_width;
    // Default input (in case it does not get connected)
    _motorswithfeedback_right_speed_t _lf_default__right_speed;
    _motorswithfeedback_left_t* _lf_left;
    // width of -2 indicates that it is not a multiport.
    int _lf_left_width;
    // Default input (in case it does not get connected)
    _motorswithfeedback_left_t _lf_default__left;
    _motorswithfeedback_right_t* _lf_right;
    // width of -2 indicates that it is not a multiport.
    int _lf_right_width;
    // Default input (in case it does not get connected)
    _motorswithfeedback_right_t _lf_default__right;
    struct {
        _picontrol_err_t err;
    } _lf_control_left;
    int _lf_control_left_width;
    struct {
        _picontrol_err_t err;
    } _lf_control_right;
    int _lf_control_right_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__left_speed;
    reaction_t* _lf__left_speed_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__right_speed;
    reaction_t* _lf__right_speed_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__left;
    reaction_t* _lf__left_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__right;
    reaction_t* _lf__right_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _motorswithfeedback_self_t;
_motorswithfeedback_self_t* new__motorswithfeedback();
#endif // _MOTORSWITHFEEDBACK_H

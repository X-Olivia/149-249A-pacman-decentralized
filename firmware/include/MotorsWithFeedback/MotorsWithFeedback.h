#ifndef _motorswithfeedback_H
#define _motorswithfeedback_H
#ifndef _MOTORSWITHFEEDBACK_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_656887876_H
#define TOP_LEVEL_PREAMBLE_656887876_H
/*Correspondence: Range: [(19, 2), (20, 17)) -> Range: [(0, 0), (1, 17)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/Motors.lf)*/#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_656887876_H
#ifndef TOP_LEVEL_PREAMBLE_438944489_H
#define TOP_LEVEL_PREAMBLE_438944489_H
/*Correspondence: Range: [(21, 2), (24, 64)) -> Range: [(0, 0), (3, 64)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf)*/#include <math.h>
#define WHEEL_DIAMETER 0.032 // meters
#define COUNTS_PER_REV 360 //CPR
#define TICKS_PER_METER (WHEEL_DIAMETER * M_PI) / COUNTS_PER_REV
#endif // TOP_LEVEL_PREAMBLE_438944489_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct motorswithfeedback_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    float p_gain;
    float i_gain;
    interval_t prev_time;
    int32_t prev_left;
    int32_t prev_right;
    float target_speed_left;
    float target_speed_right;
    int end[0]; // placeholder; MSVC does not compile empty structs
} motorswithfeedback_self_t;
#ifndef _LF_AWAIT_MARKER__left_speed
#define _LF_AWAIT_MARKER__left_speed
enum { _lf_await_requires_a_single_non_mutable_input_port__left_speed = 1 };
#endif
#ifndef _LF_AWAIT_MARKER__right_speed
#define _LF_AWAIT_MARKER__right_speed
enum { _lf_await_requires_a_single_non_mutable_input_port__right_speed = 1 };
#endif
#ifndef _LF_AWAIT_MARKER__left
#define _LF_AWAIT_MARKER__left
enum { _lf_await_requires_a_single_non_mutable_input_port__left = 1 };
#endif
#ifndef _LF_AWAIT_MARKER__right
#define _LF_AWAIT_MARKER__right
enum { _lf_await_requires_a_single_non_mutable_input_port__right = 1 };
#endif
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
} motorswithfeedback_left_speed_t;
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
} motorswithfeedback_right_speed_t;
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
} motorswithfeedback_left_t;
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
} motorswithfeedback_right_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motors_left_power_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motors_right_power_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} picontrol_err_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} picontrol_ctrl_t;
#endif
#endif

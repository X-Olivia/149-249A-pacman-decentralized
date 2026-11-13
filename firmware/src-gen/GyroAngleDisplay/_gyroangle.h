#ifndef _GYROANGLE_H
#define _GYROANGLE_H
#include "include/core/reactor.h"
#include "_trapezoidalintegrator.h"
#include "_gyro.h"
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
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _gyroangle_trigger_t;
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
} _gyroangle_x_t;
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
} _gyroangle_y_t;
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
} _gyroangle_z_t;
typedef struct {
    struct self_base_t base;
#line 74 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyroangle.h"
#line 75 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyroangle.h"
    _gyroangle_trigger_t* _lf_trigger;
    // width of -2 indicates that it is not a multiport.
    int _lf_trigger_width;
    // Default input (in case it does not get connected)
    _gyroangle_trigger_t _lf_default__trigger;
    _gyroangle_x_t _lf_x;
    int _lf_x_width;
    _gyroangle_y_t _lf_y;
    int _lf_y_width;
    _gyroangle_z_t _lf_z;
    int _lf_z_width;
    trigger_t _lf__trigger;
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _gyroangle_self_t;
_gyroangle_self_t* new__gyroangle();
#endif // _GYROANGLE_H

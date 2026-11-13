#ifndef _GYRO_H
#define _GYRO_H
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
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _gyro_trigger_t;
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
} _gyro_x_t;
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
} _gyro_y_t;
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
} _gyro_z_t;
typedef struct {
    struct self_base_t base;
#line 68 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyro.h"
#line 69 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyro.h"
    _gyro_trigger_t* _lf_trigger;
    // width of -2 indicates that it is not a multiport.
    int _lf_trigger_width;
    // Default input (in case it does not get connected)
    _gyro_trigger_t _lf_default__trigger;
    _gyro_x_t _lf_x;
    int _lf_x_width;
    _gyro_y_t _lf_y;
    int _lf_y_width;
    _gyro_z_t _lf_z;
    int _lf_z_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__trigger;
    reaction_t* _lf__trigger_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _gyro_self_t;
_gyro_self_t* new__gyro();
#endif // _GYRO_H

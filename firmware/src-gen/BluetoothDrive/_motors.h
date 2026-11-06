#ifndef _MOTORS_H
#define _MOTORS_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_69646567_H
#define TOP_LEVEL_PREAMBLE_69646567_H
#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_69646567_H
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
} _motors_left_power_t;
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
} _motors_right_power_t;
typedef struct {
    struct self_base_t base;
#line 40 "/Users/sareenarobinson/Desktop/EECS149Project/lf-3pi-template/src-gen/BluetoothDrive/_motors.h"
#line 41 "/Users/sareenarobinson/Desktop/EECS149Project/lf-3pi-template/src-gen/BluetoothDrive/_motors.h"
    _motors_left_power_t* _lf_left_power;
    // width of -2 indicates that it is not a multiport.
    int _lf_left_power_width;
    // Default input (in case it does not get connected)
    _motors_left_power_t _lf_default__left_power;
    _motors_right_power_t* _lf_right_power;
    // width of -2 indicates that it is not a multiport.
    int _lf_right_power_width;
    // Default input (in case it does not get connected)
    _motors_right_power_t _lf_default__right_power;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__left_power;
    reaction_t* _lf__left_power_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__right_power;
    reaction_t* _lf__right_power_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _motors_self_t;
_motors_self_t* new__motors();
#endif // _MOTORS_H

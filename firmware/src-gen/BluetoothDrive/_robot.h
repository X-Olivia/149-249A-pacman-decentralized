#ifndef _ROBOT_H
#define _ROBOT_H
#include "include/core/reactor.h"
#include "_motors.h"
#ifndef TOP_LEVEL_PREAMBLE_358422965_H
#define TOP_LEVEL_PREAMBLE_358422965_H
#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_358422965_H
#ifndef TOP_LEVEL_PREAMBLE_1804537094_H
#define TOP_LEVEL_PREAMBLE_1804537094_H
#include "hardware/uart.h"
#include "hardware/gpio.h"
#endif // TOP_LEVEL_PREAMBLE_1804537094_H

typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    char value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _robot_cmd_t;
typedef struct {
    struct self_base_t base;
#line 33 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/BluetoothDrive/_robot.h"
    #line 39 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/BluetoothDrive.lf"
    float speed;
#line 36 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/BluetoothDrive/_robot.h"
    _robot_cmd_t* _lf_cmd;
    // width of -2 indicates that it is not a multiport.
    int _lf_cmd_width;
    // Default input (in case it does not get connected)
    _robot_cmd_t _lf_default__cmd;
    struct {
        _motors_left_power_t left_power;
        _motors_right_power_t right_power;
    } _lf_motor;
    int _lf_motor_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__cmd;
    reaction_t* _lf__cmd_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _robot_self_t;
_robot_self_t* new__robot();
#endif // _ROBOT_H

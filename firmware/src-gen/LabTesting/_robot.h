#ifndef _ROBOT_H
#define _ROBOT_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_line.h"
#include "_motors.h"
#ifndef TOP_LEVEL_PREAMBLE_1040934535_H
#define TOP_LEVEL_PREAMBLE_1040934535_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_1040934535_H
#ifndef TOP_LEVEL_PREAMBLE_1041623626_H
#define TOP_LEVEL_PREAMBLE_1041623626_H
#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_1041623626_H
#ifndef TOP_LEVEL_PREAMBLE_1703695291_H
#define TOP_LEVEL_PREAMBLE_1703695291_H
#include <ir_sensors.h>
#endif // TOP_LEVEL_PREAMBLE_1703695291_H
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
} _robot_drive_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _robot_notify_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_action_internal_t _base;
    self_base_t* parent;
    bool has_value;
    int source_id;

    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _robot_clear_t;
typedef struct {
    struct self_base_t base;
#line 69 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/LabTesting/_robot.h"
    #line 29 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/LabTesting.lf"
    int count;
    #line 32 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/LabTesting.lf"
    bool blackleft;
    #line 33 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/LabTesting.lf"
    bool blackright;
    #line 34 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/LabTesting.lf"
    bool blackcenter;
#line 78 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/LabTesting/_robot.h"
    _robot_clear_t _lf_clear;
    _robot_drive_t* _lf_drive;
    // width of -2 indicates that it is not a multiport.
    int _lf_drive_width;
    // Default input (in case it does not get connected)
    _robot_drive_t _lf_default__drive;
    _robot_notify_t _lf_notify;
    int _lf_notify_width;
    struct {
        _line_trigger_t trigger;
        _line_calibrate_t calibrate;
        _line_reflect_t* reflect;
        trigger_t reflect_trigger;
        reaction_t* reflect_reactions[2];
    } _lf_line;
    int _lf_line_width;
    struct {
        _motors_left_power_t left_power;
        _motors_right_power_t right_power;
    } _lf_motor;
    int _lf_motor_width;
    struct {
        _display_line0_t line0;
        _display_line1_t line1;
        _display_line2_t line2;
    } _lf_disp;
    int _lf_disp_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    reaction_t _lf__reaction_3;
    reaction_t _lf__reaction_4;
    reaction_t _lf__reaction_5;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__seconds;
    trigger_t _lf__end_calibration;
    reaction_t* _lf__end_calibration_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__clear;
    reaction_t* _lf__clear_reactions[1];
    trigger_t _lf__drive;
    #ifdef FEDERATED
    
    #endif // FEDERATED
    reactor_mode_t _lf__modes[4];
} _robot_self_t;
_robot_self_t* new__robot();
#endif // _ROBOT_H

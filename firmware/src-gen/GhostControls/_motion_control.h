#ifndef _MOTION_CONTROL_H
#define _MOTION_CONTROL_H
#include "include/core/reactor.h"
#include "_encoders.h"
#include "_gyroangle.h"
#include "_motorswithfeedback.h"
#ifndef TOP_LEVEL_PREAMBLE_2118984327_H
#define TOP_LEVEL_PREAMBLE_2118984327_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_2118984327_H
#ifndef TOP_LEVEL_PREAMBLE_124540047_H
#define TOP_LEVEL_PREAMBLE_124540047_H
#include <pico/stdlib.h>
#include <imu.h>
#endif // TOP_LEVEL_PREAMBLE_124540047_H
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
#ifndef TOP_LEVEL_PREAMBLE_302059473_H
#define TOP_LEVEL_PREAMBLE_302059473_H
#include <math.h>
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#endif // TOP_LEVEL_PREAMBLE_302059473_H
#ifndef TOP_LEVEL_PREAMBLE_142302025_H
#define TOP_LEVEL_PREAMBLE_142302025_H
#include "hardware/uart.h"
#include "hardware/gpio.h"

#define NAME_MAXLEN 12
#define PIN_UART_TX 28
#define PIN_UART_RX 29
#define BAUD_RATE 9600
#endif // TOP_LEVEL_PREAMBLE_142302025_H
#ifndef TOP_LEVEL_PREAMBLE_1002410023_H
#define TOP_LEVEL_PREAMBLE_1002410023_H
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_1002410023_H
#ifndef TOP_LEVEL_PREAMBLE_2060799061_H
#define TOP_LEVEL_PREAMBLE_2060799061_H
#include "hardware/uart.h"
#include "hardware/gpio.h"
#include <float.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 20
#define TIME_BEFORE_ROTATE_ALLOWED SEC(2)
#define TIME_BEFORE_RESET SEC(20)
#define NUM_DIRS 4

// NOTE: Goes counter clockwise, unlike the simulator
typedef enum dir_t {
  FORWARDS = 0,
  LEFT = 1,
  BACKWARDS = 2,
  RIGHT = 3
} dir_t;

// circular array
typedef struct dist_arr {
  float dist[MAX_ENTRIES];
  int size;
  int tail;
} dist_arr;

typedef struct path_arr {
  dir_t path[NUM_DIRS];
  int size;
} path_arr;

typedef dist_arr dist_arr_list_t[NUM_DIRS];
#endif // TOP_LEVEL_PREAMBLE_2060799061_H








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
} _motion_control_turn_angle_t;
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
} _motion_control_target_speed_t;
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
} _motion_control_stop_t;
typedef struct {
    struct self_base_t base;
    #line 60 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    interval_t p_encoder;
    #line 60 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    interval_t p_gyro;
#line 151 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.h"
    #line 65 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    float speed;
    #line 66 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    float target_angle;
    #line 67 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    float start_angle;
    #line 68 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    float curr_angle;
#line 160 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.h"
    _motion_control_turn_angle_t* _lf_turn_angle;
    // width of -2 indicates that it is not a multiport.
    int _lf_turn_angle_width;
    // Default input (in case it does not get connected)
    _motion_control_turn_angle_t _lf_default__turn_angle;
    _motion_control_target_speed_t* _lf_target_speed;
    // width of -2 indicates that it is not a multiport.
    int _lf_target_speed_width;
    // Default input (in case it does not get connected)
    _motion_control_target_speed_t _lf_default__target_speed;
    _motion_control_stop_t* _lf_stop;
    // width of -2 indicates that it is not a multiport.
    int _lf_stop_width;
    // Default input (in case it does not get connected)
    _motion_control_stop_t _lf_default__stop;
    struct {
        _encoders_trigger_t trigger;
    } _lf_encoder;
    int _lf_encoder_width;
    struct {
        _gyroangle_trigger_t trigger;
        _gyroangle_z_t* z;
        trigger_t z_trigger;
        reaction_t* z_reactions[2];
    } _lf_gyro;
    int _lf_gyro_width;
    struct {
        _motorswithfeedback_left_speed_t left_speed;
        _motorswithfeedback_right_speed_t right_speed;
    } _lf_motors;
    int _lf_motors_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    reaction_t _lf__reaction_3;
    reaction_t _lf__reaction_4;
    reaction_t _lf__reaction_5;
    reaction_t _lf__reaction_6;
    reaction_t _lf__reaction_7;
    reaction_t _lf__reaction_8;
    reaction_t _lf__reaction_9;
    reaction_t _lf__reaction_10;
    reaction_t _lf__reaction_11;
    trigger_t _lf__t_encoder;
    reaction_t* _lf__t_encoder_reactions[1];
    trigger_t _lf__t_gyro;
    reaction_t* _lf__t_gyro_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[3];
    trigger_t _lf__reset;
    reaction_t* _lf__reset_reactions[3];
    trigger_t _lf__turn_angle;
    reaction_t* _lf__turn_angle_reactions[2];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__target_speed;
    reaction_t* _lf__target_speed_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__stop;
    reaction_t* _lf__stop_reactions[2];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    reactor_mode_t _lf__modes[3];
} _motion_control_self_t;
_motion_control_self_t* new__motion_control();
#endif // _MOTION_CONTROL_H

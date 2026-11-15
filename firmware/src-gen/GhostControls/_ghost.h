#ifndef _GHOST_H
#define _GHOST_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_uart.h"
#include "_uwb.h"
#include "_motion_control.h"
#ifndef TOP_LEVEL_PREAMBLE_690699007_H
#define TOP_LEVEL_PREAMBLE_690699007_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_690699007_H
#ifndef TOP_LEVEL_PREAMBLE_1478091345_H
#define TOP_LEVEL_PREAMBLE_1478091345_H
#include <pico/stdlib.h>
#include <imu.h>
#endif // TOP_LEVEL_PREAMBLE_1478091345_H
#ifndef TOP_LEVEL_PREAMBLE_1314779424_H
#define TOP_LEVEL_PREAMBLE_1314779424_H
#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_1314779424_H
#ifndef TOP_LEVEL_PREAMBLE_1167738766_H
#define TOP_LEVEL_PREAMBLE_1167738766_H
#include <math.h>
#define WHEEL_DIAMETER 0.032 // meters
#define COUNTS_PER_REV 360 //CPR
#define TICKS_PER_METER (WHEEL_DIAMETER * M_PI) / COUNTS_PER_REV
#endif // TOP_LEVEL_PREAMBLE_1167738766_H
#ifndef TOP_LEVEL_PREAMBLE_2079503304_H
#define TOP_LEVEL_PREAMBLE_2079503304_H
#include <math.h>
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#endif // TOP_LEVEL_PREAMBLE_2079503304_H
#ifndef TOP_LEVEL_PREAMBLE_732591497_H
#define TOP_LEVEL_PREAMBLE_732591497_H
#include "hardware/uart.h"
#include "hardware/gpio.h"

#define NAME_MAXLEN 12
#define PIN_UART_TX 28
#define PIN_UART_RX 29
#define BAUD_RATE 9600
#endif // TOP_LEVEL_PREAMBLE_732591497_H
#ifndef TOP_LEVEL_PREAMBLE_720370616_H
#define TOP_LEVEL_PREAMBLE_720370616_H
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_720370616_H
#ifndef TOP_LEVEL_PREAMBLE_2058050455_H
#define TOP_LEVEL_PREAMBLE_2058050455_H
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#define MESSAGE_SIZE 128
#endif // TOP_LEVEL_PREAMBLE_2058050455_H
#ifndef TOP_LEVEL_PREAMBLE_1096723873_H
#define TOP_LEVEL_PREAMBLE_1096723873_H
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
#endif // TOP_LEVEL_PREAMBLE_1096723873_H
typedef struct {
    struct self_base_t base;
    #line 148 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    interval_t p_turn;
#line 108 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.h"
    #line 157 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    float last_distance;
    #line 158 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    dir_t curr_dir;
    #line 159 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    dist_arr_list_t dir_to_dists;
    #line 160 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    interval_t last_decision;
    #line 161 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    interval_t last_turn;
    #line 164 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    path_arr valid_paths;
#line 121 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.h"
    struct {
        _motion_control_turn_angle_t turn_angle;
    } _lf_control;
    int _lf_control_width;
    struct {
        _uwb_dist_t* dist;
        trigger_t dist_trigger;
        reaction_t* dist_reactions[1];
    } _lf_uwb;
    int _lf_uwb_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__t_turn;
    reaction_t* _lf__t_turn_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _ghost_self_t;
_ghost_self_t* new__ghost();
#endif // _GHOST_H

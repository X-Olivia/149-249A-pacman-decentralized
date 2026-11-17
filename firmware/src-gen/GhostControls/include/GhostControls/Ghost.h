#ifndef _ghost_H
#define _ghost_H
#ifndef _GHOST_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_2084411835_H
#define TOP_LEVEL_PREAMBLE_2084411835_H
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_2084411835_H
#ifndef TOP_LEVEL_PREAMBLE_159977067_H
#define TOP_LEVEL_PREAMBLE_159977067_H
/*Correspondence: Range: [(21, 2), (22, 16)) -> Range: [(0, 0), (1, 16)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/IMU.lf)*/#include <pico/stdlib.h>
#include <imu.h>
#endif // TOP_LEVEL_PREAMBLE_159977067_H
#ifndef TOP_LEVEL_PREAMBLE_881667483_H
#define TOP_LEVEL_PREAMBLE_881667483_H
/*Correspondence: Range: [(19, 2), (20, 17)) -> Range: [(0, 0), (1, 17)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/Motors.lf)*/#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_881667483_H
#ifndef TOP_LEVEL_PREAMBLE_692182414_H
#define TOP_LEVEL_PREAMBLE_692182414_H
/*Correspondence: Range: [(21, 2), (24, 64)) -> Range: [(0, 0), (3, 64)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf)*/#include <math.h>
#define WHEEL_DIAMETER 0.032 // meters
#define COUNTS_PER_REV 360 //CPR
#define TICKS_PER_METER (WHEEL_DIAMETER * M_PI) / COUNTS_PER_REV
#endif // TOP_LEVEL_PREAMBLE_692182414_H
#ifndef TOP_LEVEL_PREAMBLE_1270661713_H
#define TOP_LEVEL_PREAMBLE_1270661713_H
/*Correspondence: Range: [(18, 2), (26, 17)) -> Range: [(0, 0), (8, 17)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/Encoders.lf)*/#include <math.h>
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#endif // TOP_LEVEL_PREAMBLE_1270661713_H
#ifndef TOP_LEVEL_PREAMBLE_1218470570_H
#define TOP_LEVEL_PREAMBLE_1218470570_H
/*Correspondence: Range: [(9, 2), (15, 22)) -> Range: [(0, 0), (6, 22)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/Bluetooth.lf)*/#include "hardware/uart.h"
#include "hardware/gpio.h"

#define NAME_MAXLEN 12
#define PIN_UART_TX 28
#define PIN_UART_RX 29
#define BAUD_RATE 9600
#endif // TOP_LEVEL_PREAMBLE_1218470570_H
#ifndef TOP_LEVEL_PREAMBLE_612268186_H
#define TOP_LEVEL_PREAMBLE_612268186_H
/*Correspondence: Range: [(9, 2), (12, 19)) -> Range: [(0, 0), (3, 19)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/UWB.lf)*/#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_612268186_H
#ifndef TOP_LEVEL_PREAMBLE_1817351236_H
#define TOP_LEVEL_PREAMBLE_1817351236_H
/*Correspondence: Range: [(9, 2), (14, 24)) -> Range: [(0, 0), (5, 24)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/UART.lf)*/#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#define MESSAGE_SIZE 128
#endif // TOP_LEVEL_PREAMBLE_1817351236_H
#ifndef TOP_LEVEL_PREAMBLE_1533237483_H
#define TOP_LEVEL_PREAMBLE_1533237483_H
/*Correspondence: Range: [(20, 2), (52, 43)) -> Range: [(0, 0), (32, 43)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf)*/#include "hardware/uart.h"
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
#endif // TOP_LEVEL_PREAMBLE_1533237483_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct ghost_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    interval_t p_turn;
    float last_distance;
    dir_t curr_dir;
    dist_arr_list_t dir_to_dists;
    interval_t last_decision;
    interval_t last_turn;
    path_arr valid_paths;
    int end[0]; // placeholder; MSVC does not compile empty structs
} ghost_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line0_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line1_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line2_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line3_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} uwb_uart_data_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} uwb_dist_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} uart_bt_in_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} uart_uwb_out_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} uart_bt_out_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motion_control_turn_angle_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motion_control_target_speed_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} motion_control_stop_t;
#endif
#endif

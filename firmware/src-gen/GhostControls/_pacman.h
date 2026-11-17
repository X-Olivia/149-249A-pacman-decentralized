#ifndef _PACMAN_H
#define _PACMAN_H
#include "include/core/reactor.h"
#include "_bluetooth.h"
#include "_display.h"
#include "_uart.h"
#include "_motion_control.h"
#ifndef TOP_LEVEL_PREAMBLE_557982257_H
#define TOP_LEVEL_PREAMBLE_557982257_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_557982257_H
#ifndef TOP_LEVEL_PREAMBLE_123629835_H
#define TOP_LEVEL_PREAMBLE_123629835_H
#include <pico/stdlib.h>
#include <imu.h>
#endif // TOP_LEVEL_PREAMBLE_123629835_H
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
#ifndef TOP_LEVEL_PREAMBLE_598977164_H
#define TOP_LEVEL_PREAMBLE_598977164_H
#include <math.h>
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#endif // TOP_LEVEL_PREAMBLE_598977164_H
#ifndef TOP_LEVEL_PREAMBLE_671981276_H
#define TOP_LEVEL_PREAMBLE_671981276_H
#include "hardware/uart.h"
#include "hardware/gpio.h"

#define NAME_MAXLEN 12
#define PIN_UART_TX 28
#define PIN_UART_RX 29
#define BAUD_RATE 9600
#endif // TOP_LEVEL_PREAMBLE_671981276_H
#ifndef TOP_LEVEL_PREAMBLE_1125509551_H
#define TOP_LEVEL_PREAMBLE_1125509551_H
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_1125509551_H
#ifndef TOP_LEVEL_PREAMBLE_430983166_H
#define TOP_LEVEL_PREAMBLE_430983166_H
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#define MESSAGE_SIZE 128
#endif // TOP_LEVEL_PREAMBLE_430983166_H
#ifndef TOP_LEVEL_PREAMBLE_911561694_H
#define TOP_LEVEL_PREAMBLE_911561694_H
#include "hardware/uart.h"
#include "hardware/gpio.h"
#include <float.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "pico/stdlib.h"

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
#endif // TOP_LEVEL_PREAMBLE_911561694_H











typedef struct {
    struct self_base_t base;
    #line 298 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    interval_t sample_period;
#line 122 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_pacman.h"
#line 123 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_pacman.h"
    struct {
        _display_line0_t line0;
    } _lf_disp;
    int _lf_disp_width;
    struct {
        _motion_control_stop_t stop;
        _motion_control_turn_angle_t turn_angle;
    } _lf_control;
    int _lf_control_width;
    struct {
        _bluetooth_cmd_t* cmd;
        trigger_t cmd_trigger;
        reaction_t* cmd_reactions[1];
    } _lf_bt;
    int _lf_bt_width;
    reaction_t _lf__reaction_0;
} _pacman_self_t;
_pacman_self_t* new__pacman();
#endif // _PACMAN_H

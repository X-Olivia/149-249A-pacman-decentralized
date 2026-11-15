#ifndef _GHOSTCONTROLS_MAIN_H
#define _GHOSTCONTROLS_MAIN_H
#include "include/core/reactor.h"
#include "_bluetooth.h"
#include "_ghost.h"
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
    struct self_base_t base;
#line 107 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghostcontrols_main.h"
#line 108 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghostcontrols_main.h"
} _ghostcontrols_main_main_self_t;
_ghostcontrols_main_main_self_t* new__ghostcontrols_main();
#endif // _GHOSTCONTROLS_MAIN_H

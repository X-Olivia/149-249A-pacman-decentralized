#ifndef _GHOSTCONTROLS_MAIN_H
#define _GHOSTCONTROLS_MAIN_H
#include "include/core/reactor.h"
#include "_bluetooth.h"
#include "_ghost.h"
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
#line 104 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghostcontrols_main.h"
#line 105 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghostcontrols_main.h"
} _ghostcontrols_main_main_self_t;
_ghostcontrols_main_main_self_t* new__ghostcontrols_main();
#endif // _GHOSTCONTROLS_MAIN_H

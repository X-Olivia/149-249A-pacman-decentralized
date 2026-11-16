#ifndef _PACMANDRIVE_MAIN_H
#define _PACMANDRIVE_MAIN_H
#include "include/core/reactor.h"
#include "_bluetooth.h"
#include "_display.h"
#include "_robot.h"
#ifndef TOP_LEVEL_PREAMBLE_444520614_H
#define TOP_LEVEL_PREAMBLE_444520614_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_444520614_H
#ifndef TOP_LEVEL_PREAMBLE_1140280435_H
#define TOP_LEVEL_PREAMBLE_1140280435_H
#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_1140280435_H
#ifndef TOP_LEVEL_PREAMBLE_935741155_H
#define TOP_LEVEL_PREAMBLE_935741155_H
#include <ir_sensors.h>
#endif // TOP_LEVEL_PREAMBLE_935741155_H
#ifndef TOP_LEVEL_PREAMBLE_1360728045_H
#define TOP_LEVEL_PREAMBLE_1360728045_H
#include <stdio.h>
#include "hardware/uart.h"
#include "hardware/gpio.h"
#endif // TOP_LEVEL_PREAMBLE_1360728045_H
typedef struct {
    struct self_base_t base;
#line 30 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/PacmanDrive/_pacmandrive_main.h"
#line 31 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/PacmanDrive/_pacmandrive_main.h"
} _pacmandrive_main_main_self_t;
_pacmandrive_main_main_self_t* new__pacmandrive_main();
#endif // _PACMANDRIVE_MAIN_H

#ifndef _LABTESTING_MAIN_H
#define _LABTESTING_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_robot.h"
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
    struct self_base_t base;
#line 23 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/LabTesting/_labtesting_main.h"
    #line 144 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/LabTesting.lf"
    bool drive;
#line 26 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/LabTesting/_labtesting_main.h"
    struct {
        _robot_drive_t drive;
    } _lf_robot;
    int _lf_robot_width;
    reaction_t _lf__reaction_0;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
} _labtesting_main_main_self_t;
_labtesting_main_main_self_t* new__labtesting_main();
#endif // _LABTESTING_MAIN_H

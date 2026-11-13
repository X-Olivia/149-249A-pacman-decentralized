#ifndef _GYROANGLEDISPLAY_MAIN_H
#define _GYROANGLEDISPLAY_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_gyroangle.h"
#ifndef TOP_LEVEL_PREAMBLE_1980362761_H
#define TOP_LEVEL_PREAMBLE_1980362761_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_1980362761_H
#ifndef TOP_LEVEL_PREAMBLE_1671377200_H
#define TOP_LEVEL_PREAMBLE_1671377200_H
#include <pico/stdlib.h>
#include <imu.h>
#endif // TOP_LEVEL_PREAMBLE_1671377200_H





typedef struct {
    struct self_base_t base;
#line 24 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyroangledisplay_main.h"
#line 25 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyroangledisplay_main.h"
    struct {
        _gyroangle_trigger_t trigger;
        _gyroangle_x_t* x;
        trigger_t x_trigger;
        reaction_t* x_reactions[1];
        _gyroangle_y_t* y;
        trigger_t y_trigger;
        reaction_t* y_reactions[1];
        _gyroangle_z_t* z;
        trigger_t z_trigger;
        reaction_t* z_reactions[1];
    } _lf_gyro;
    int _lf_gyro_width;
    struct {
        _display_line0_t line0;
        _display_line1_t line1;
        _display_line2_t line2;
        _display_line3_t line3;
    } _lf_display;
    int _lf_display_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    reaction_t _lf__reaction_3;
    reaction_t _lf__reaction_4;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _gyroangledisplay_main_main_self_t;
_gyroangledisplay_main_main_self_t* new__gyroangledisplay_main();
#endif // _GYROANGLEDISPLAY_MAIN_H

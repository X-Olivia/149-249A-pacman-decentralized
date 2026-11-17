#ifndef _TEST1_MAIN_H
#define _TEST1_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_line.h"
#ifndef TOP_LEVEL_PREAMBLE_910101408_H
#define TOP_LEVEL_PREAMBLE_910101408_H
#include <ir_sensors.h>
#endif // TOP_LEVEL_PREAMBLE_910101408_H
#ifndef TOP_LEVEL_PREAMBLE_105393903_H
#define TOP_LEVEL_PREAMBLE_105393903_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_105393903_H


typedef struct {
    struct self_base_t base;
    #line 22 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/Test1.lf"
    interval_t calibration_time;
    #line 22 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/Test1.lf"
    interval_t sample_period;
#line 24 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/Test1/_test1_main.h"
    #line 29 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/Test1.lf"
    int count;
#line 27 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/Test1/_test1_main.h"
    struct {
        _display_line0_t line0;
        _display_line1_t line1;
        _display_line2_t line2;
        _display_line3_t line3;
    } _lf_disp;
    int _lf_disp_width;
    struct {
        _line_calibrate_t calibrate;
        _line_trigger_t trigger;
        _line_reflect_t* reflect;
        trigger_t reflect_trigger;
        reaction_t* reflect_reactions[1];
    } _lf_line;
    int _lf_line_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    reaction_t _lf__reaction_3;
    reaction_t _lf__reaction_4;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__seconds;
    reaction_t* _lf__seconds_reactions[1];
    trigger_t _lf__end_calibration;
    reaction_t* _lf__end_calibration_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _test1_main_main_self_t;
_test1_main_main_self_t* new__test1_main();
#endif // _TEST1_MAIN_H

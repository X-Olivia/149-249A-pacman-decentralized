#ifndef _LINEDISPLAY_MAIN_H
#define _LINEDISPLAY_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_line.h"
#ifndef TOP_LEVEL_PREAMBLE_910101408_H
#define TOP_LEVEL_PREAMBLE_910101408_H
#include <ir_sensors.h>
#endif // TOP_LEVEL_PREAMBLE_910101408_H
#ifndef TOP_LEVEL_PREAMBLE_1238339624_H
#define TOP_LEVEL_PREAMBLE_1238339624_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_1238339624_H


typedef struct {
    struct self_base_t base;
    #line 21 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/LineDisplay.lf"
    interval_t calibration_time;
    #line 21 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/LineDisplay.lf"
    interval_t sample_period;
#line 24 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/LineDisplay/_linedisplay_main.h"
    #line 28 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/LineDisplay.lf"
    int count;
#line 27 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/LineDisplay/_linedisplay_main.h"
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
} _linedisplay_main_main_self_t;
_linedisplay_main_main_self_t* new__linedisplay_main();
#endif // _LINEDISPLAY_MAIN_H

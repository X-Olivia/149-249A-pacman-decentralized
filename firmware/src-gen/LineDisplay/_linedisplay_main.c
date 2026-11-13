#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/LineDisplay/LineDisplay.h"
#include "_linedisplay_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _linedisplay_mainreaction_function_0(void* instance_args) {
    _linedisplay_main_main_self_t* self = (_linedisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 31 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/LineDisplay.lf"
    lf_set(disp.line0, "CALIBRATING");
    lf_set(disp.line1, "Roll robot over");
    lf_set(disp.line2, "light and dark.");
#line 25 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/LineDisplay/_linedisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _linedisplay_mainreaction_function_1(void* instance_args) {
    _linedisplay_main_main_self_t* self = (_linedisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line3_t* line3;
    
    } disp;
    disp.line3 = &(self->_lf_disp.line3);
    #line 37 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/LineDisplay.lf"
    static char buf[17];
    snprintf(buf, 17, "time:%8d s", self->count++);
    lf_set(disp.line3, buf);
#line 40 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/LineDisplay/_linedisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _linedisplay_mainreaction_function_2(void* instance_args) {
    _linedisplay_main_main_self_t* self = (_linedisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_calibrate_t* calibrate;
    
    } line;
    line.calibrate = &(self->_lf_line.calibrate);
    #line 43 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/LineDisplay.lf"
    lf_set(line.calibrate, false);
#line 53 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/LineDisplay/_linedisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _linedisplay_mainreaction_function_3(void* instance_args) {
    _linedisplay_main_main_self_t* self = (_linedisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_trigger_t* trigger;
    
    } line;
    line.trigger = &(self->_lf_line.trigger);
    #line 47 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/LineDisplay.lf"
    lf_set(line.trigger, true);
#line 66 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/LineDisplay/_linedisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _linedisplay_mainreaction_function_4(void* instance_args) {
    _linedisplay_main_main_self_t* self = (_linedisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_reflect_t* reflect;
    
    } line;
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    line.reflect = self->_lf_line.reflect;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 51 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/LineDisplay.lf"
    static char buf0[17];
    static char buf1[17];
    static char buf2[17];
    snprintf(buf0, 17, "0:%4d 1:%4d", line.reflect->value[0], line.reflect->value[1]);
    snprintf(buf1, 17, "2:%4d 3:%4d", line.reflect->value[2], line.reflect->value[3]);
    snprintf(buf2, 17, "4:%4d", line.reflect->value[4]);
    lf_set(disp.line0, buf0);
    lf_set(disp.line1, buf1);
    lf_set(disp.line2, buf2);
#line 96 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/LineDisplay/_linedisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
_linedisplay_main_main_self_t* new__linedisplay_main() {
    _linedisplay_main_main_self_t* self = (_linedisplay_main_main_self_t*)lf_new_reactor(sizeof(_linedisplay_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_line_width = -2;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_line.reflect_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_line.reflect_reactions[0] = &self->_lf__reaction_4;
    self->_lf_line.reflect_trigger.reactions = self->_lf_line.reflect_reactions;
    self->_lf_line.reflect_trigger.last_tag = NEVER_TAG;
    self->_lf_line.reflect_trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf_line.reflect_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _linedisplay_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _linedisplay_mainreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _linedisplay_mainreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__reaction_3.number = 3;
    self->_lf__reaction_3.function = _linedisplay_mainreaction_function_3;
    self->_lf__reaction_3.self = self;
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    self->_lf__reaction_3.STP_handler = NULL;
    self->_lf__reaction_3.name = "?";
    self->_lf__reaction_3.mode = NULL;
    self->_lf__reaction_4.number = 4;
    self->_lf__reaction_4.function = _linedisplay_mainreaction_function_4;
    self->_lf__reaction_4.self = self;
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    self->_lf__reaction_4.STP_handler = NULL;
    self->_lf__reaction_4.name = "?";
    self->_lf__reaction_4.mode = NULL;
    self->_lf__t.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_reactions[0] = &self->_lf__reaction_3;
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    self->_lf__t.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__seconds.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__seconds_reactions[0] = &self->_lf__reaction_1;
    self->_lf__seconds.reactions = &self->_lf__seconds_reactions[0];
    self->_lf__seconds.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__seconds.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__seconds.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__end_calibration.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__end_calibration_reactions[0] = &self->_lf__reaction_2;
    self->_lf__end_calibration.reactions = &self->_lf__end_calibration_reactions[0];
    self->_lf__end_calibration.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__end_calibration.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__end_calibration.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    return self;
}

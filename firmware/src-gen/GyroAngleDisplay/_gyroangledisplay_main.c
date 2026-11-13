#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/GyroAngleDisplay/GyroAngleDisplay.h"
#include "_gyroangledisplay_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _gyroangledisplay_mainreaction_function_0(void* instance_args) {
    _gyroangledisplay_main_main_self_t* self = (_gyroangledisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_trigger_t* trigger;
    
    } gyro;
    gyro.trigger = &(self->_lf_gyro.trigger);
    #line 27 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GyroAngleDisplay.lf"
    lf_set(gyro.trigger, true);
#line 19 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyroangledisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _gyroangledisplay_mainreaction_function_1(void* instance_args) {
    _gyroangledisplay_main_main_self_t* self = (_gyroangledisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct display {
        _display_line0_t* line0;
    
    } display;
    display.line0 = &(self->_lf_display.line0);
    #line 31 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GyroAngleDisplay.lf"
    lf_set(display.line0, "GYRO ANGLE:");
#line 32 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyroangledisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _gyroangledisplay_mainreaction_function_2(void* instance_args) {
    _gyroangledisplay_main_main_self_t* self = (_gyroangledisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_x_t* x;
    
    } gyro;
    struct display {
        _display_line1_t* line1;
    
    } display;
    gyro.x = self->_lf_gyro.x;
    display.line1 = &(self->_lf_display.line1);
    #line 35 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GyroAngleDisplay.lf"
    static char buf[17];
    snprintf(buf, 17, "x: %.1f", gyro.x->value);
    lf_set(display.line1, buf);
#line 52 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyroangledisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _gyroangledisplay_mainreaction_function_3(void* instance_args) {
    _gyroangledisplay_main_main_self_t* self = (_gyroangledisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_y_t* y;
    
    } gyro;
    struct display {
        _display_line2_t* line2;
    
    } display;
    gyro.y = self->_lf_gyro.y;
    display.line2 = &(self->_lf_display.line2);
    #line 41 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GyroAngleDisplay.lf"
    static char buf[17];
    snprintf(buf, 17, "y: %.1f", gyro.y->value);
    lf_set(display.line2, buf);
#line 72 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyroangledisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _gyroangledisplay_mainreaction_function_4(void* instance_args) {
    _gyroangledisplay_main_main_self_t* self = (_gyroangledisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_z_t* z;
    
    } gyro;
    struct display {
        _display_line3_t* line3;
    
    } display;
    gyro.z = self->_lf_gyro.z;
    display.line3 = &(self->_lf_display.line3);
    #line 47 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GyroAngleDisplay.lf"
    static char buf[17];
    snprintf(buf, 17, "z: %.1f", gyro.z->value);
    lf_set(display.line3, buf);
#line 92 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyroangledisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
_gyroangledisplay_main_main_self_t* new__gyroangledisplay_main() {
    _gyroangledisplay_main_main_self_t* self = (_gyroangledisplay_main_main_self_t*)lf_new_reactor(sizeof(_gyroangledisplay_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_gyro_width = -2;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_gyro.x_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_gyro.x_reactions[0] = &self->_lf__reaction_2;
    self->_lf_gyro.x_trigger.reactions = self->_lf_gyro.x_reactions;
    self->_lf_gyro.x_trigger.last_tag = NEVER_TAG;
    self->_lf_gyro.x_trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf_gyro.x_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_gyro.y_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_gyro.y_reactions[0] = &self->_lf__reaction_3;
    self->_lf_gyro.y_trigger.reactions = self->_lf_gyro.y_reactions;
    self->_lf_gyro.y_trigger.last_tag = NEVER_TAG;
    self->_lf_gyro.y_trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf_gyro.y_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_gyro.z_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_gyro.z_reactions[0] = &self->_lf__reaction_4;
    self->_lf_gyro.z_trigger.reactions = self->_lf_gyro.z_reactions;
    self->_lf_gyro.z_trigger.last_tag = NEVER_TAG;
    self->_lf_gyro.z_trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf_gyro.z_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_display_width = -2;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _gyroangledisplay_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _gyroangledisplay_mainreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _gyroangledisplay_mainreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__reaction_3.number = 3;
    self->_lf__reaction_3.function = _gyroangledisplay_mainreaction_function_3;
    self->_lf__reaction_3.self = self;
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    self->_lf__reaction_3.STP_handler = NULL;
    self->_lf__reaction_3.name = "?";
    self->_lf__reaction_3.mode = NULL;
    self->_lf__reaction_4.number = 4;
    self->_lf__reaction_4.function = _gyroangledisplay_mainreaction_function_4;
    self->_lf__reaction_4.self = self;
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    self->_lf__reaction_4.STP_handler = NULL;
    self->_lf__reaction_4.name = "?";
    self->_lf__reaction_4.mode = NULL;
    self->_lf__t.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    self->_lf__t.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_1;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    return self;
}

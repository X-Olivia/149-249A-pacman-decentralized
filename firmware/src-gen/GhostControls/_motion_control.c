#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/GhostControls/Motion_control.h"
#include "_motion_control.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _motion_controlreaction_function_0(void* instance_args) {
    _motion_control_self_t* self = (_motion_control_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct encoder {
        _encoders_trigger_t* trigger;
    
    } encoder;
    encoder.trigger = &(self->_lf_encoder.trigger);
    #line 74 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    lf_set(encoder.trigger, true);
#line 19 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motion_controlreaction_function_1(void* instance_args) {
    _motion_control_self_t* self = (_motion_control_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_trigger_t* trigger;
    
    } gyro;
    gyro.trigger = &(self->_lf_gyro.trigger);
    #line 77 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    lf_set(gyro.trigger, true);
#line 32 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motion_controlreaction_function_2(void* instance_args) {
    _motion_control_self_t* self = (_motion_control_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    enum { _lf_await_requires_a_single_non_mutable_input_port__target_speed = 1 };
    _motion_control_target_speed_t* target_speed = self->_lf_target_speed;
    int target_speed_width = self->_lf_target_speed_width; SUPPRESS_UNUSED_WARNING(target_speed_width);
    #line 84 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    self->speed = target_speed->value;
#line 43 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motion_controlreaction_function_3(void* instance_args) {
    _motion_control_self_t* self = (_motion_control_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_z_t* z;
    
    } gyro;
    gyro.z = self->_lf_gyro.z;
    #line 87 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    self->curr_angle = gyro.z->value;
#line 56 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motion_controlreaction_function_4(void* instance_args) {
    _motion_control_self_t* self = (_motion_control_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motors {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } motors;
    motors.left_speed = &(self->_lf_motors.left_speed);
    motors.right_speed = &(self->_lf_motors.right_speed);
    #line 93 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    lf_set(motors.left_speed, self->speed);
    lf_set(motors.right_speed, self->speed);
#line 72 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motion_controlreaction_function_5(void* instance_args) {
    _motion_control_self_t* self = (_motion_control_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    enum { _lf_await_requires_a_single_non_mutable_input_port__turn_angle = 1 };
    _motion_control_turn_angle_t* turn_angle = self->_lf_turn_angle;
    int turn_angle_width = self->_lf_turn_angle_width; SUPPRESS_UNUSED_WARNING(turn_angle_width);
    reactor_mode_t* ROTATE = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_ROTATE_change_type = reset_transition;
    #line 98 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    lf_set_mode(ROTATE);
    self->start_angle = self->curr_angle;
    self->target_angle = turn_angle->value;
#line 87 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motion_controlreaction_function_6(void* instance_args) {
    _motion_control_self_t* self = (_motion_control_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    enum { _lf_await_requires_a_single_non_mutable_input_port__stop = 1 };
    _motion_control_stop_t* stop = self->_lf_stop;
    int stop_width = self->_lf_stop_width; SUPPRESS_UNUSED_WARNING(stop_width);
    reactor_mode_t* STOP = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_STOP_change_type = reset_transition;
    #line 104 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    lf_set_mode(STOP);
#line 100 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motion_controlreaction_function_7(void* instance_args) {
    _motion_control_self_t* self = (_motion_control_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motors {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } motors;
    motors.left_speed = &(self->_lf_motors.left_speed);
    motors.right_speed = &(self->_lf_motors.right_speed);
    reactor_mode_t* FORWARD = &self->_lf__modes[0];
    lf_mode_change_type_t _lf_FORWARD_change_type = reset_transition;
    #line 110 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    if (self->target_angle > 0){
      lf_set(motors.left_speed, -self->speed);
      lf_set(motors.right_speed, self->speed);
    } else if (self->target_angle == 0) {
      lf_set_mode(FORWARD);
    } else {
      lf_set(motors.left_speed, self->speed);
      lf_set(motors.right_speed, -self->speed);
    }
#line 125 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motion_controlreaction_function_8(void* instance_args) {
    _motion_control_self_t* self = (_motion_control_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_z_t* z;
    
    } gyro;
    gyro.z = self->_lf_gyro.z;
    reactor_mode_t* FORWARD = &self->_lf__modes[0];
    lf_mode_change_type_t _lf_FORWARD_change_type = reset_transition;
    #line 121 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    if (abs(gyro.z->value - self->start_angle) >= abs(self->target_angle)){
      lf_set_mode(FORWARD);
    }
#line 142 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motion_controlreaction_function_9(void* instance_args) {
    _motion_control_self_t* self = (_motion_control_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    enum { _lf_await_requires_a_single_non_mutable_input_port__stop = 1 };
    _motion_control_stop_t* stop = self->_lf_stop;
    int stop_width = self->_lf_stop_width; SUPPRESS_UNUSED_WARNING(stop_width);
    reactor_mode_t* STOP = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_STOP_change_type = reset_transition;
    #line 126 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    lf_set_mode(STOP);
#line 155 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motion_controlreaction_function_10(void* instance_args) {
    _motion_control_self_t* self = (_motion_control_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motors {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } motors;
    motors.left_speed = &(self->_lf_motors.left_speed);
    motors.right_speed = &(self->_lf_motors.right_speed);
    #line 132 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    lf_set(motors.left_speed, 0);
    lf_set(motors.right_speed, 0);
#line 171 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motion_controlreaction_function_11(void* instance_args) {
    _motion_control_self_t* self = (_motion_control_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    enum { _lf_await_requires_a_single_non_mutable_input_port__turn_angle = 1 };
    _motion_control_turn_angle_t* turn_angle = self->_lf_turn_angle;
    int turn_angle_width = self->_lf_turn_angle_width; SUPPRESS_UNUSED_WARNING(turn_angle_width);
    reactor_mode_t* ROTATE = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_ROTATE_change_type = reset_transition;
    #line 136 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    lf_set_mode(ROTATE);
    self->start_angle = self->curr_angle;
    self->target_angle = turn_angle->value;
#line 186 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motion_control.c"
}
#include "include/api/reaction_macros_undef.h"
_motion_control_self_t* new__motion_control() {
    _motion_control_self_t* self = (_motion_control_self_t*)lf_new_reactor(sizeof(_motion_control_self_t));
    // Set input by default to an always absent default input.
    self->_lf_turn_angle = &self->_lf_default__turn_angle;
    // Set the default source reactor pointer
    self->_lf_default__turn_angle._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_target_speed = &self->_lf_default__target_speed;
    // Set the default source reactor pointer
    self->_lf_default__target_speed._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_stop = &self->_lf_default__stop;
    // Set the default source reactor pointer
    self->_lf_default__stop._base.source_reactor = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_encoder_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_gyro_width = -2;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_gyro.z_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_gyro.z_reactions[0] = &self->_lf__reaction_3;
    self->_lf_gyro.z_reactions[1] = &self->_lf__reaction_8;
    self->_lf_gyro.z_trigger.reactions = self->_lf_gyro.z_reactions;
    self->_lf_gyro.z_trigger.last_tag = NEVER_TAG;
    self->_lf_gyro.z_trigger.number_of_reactions = 2;
    #ifdef FEDERATED
    self->_lf_gyro.z_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_motors_width = -2;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _motion_controlreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _motion_controlreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _motion_controlreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__reaction_3.number = 3;
    self->_lf__reaction_3.function = _motion_controlreaction_function_3;
    self->_lf__reaction_3.self = self;
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    self->_lf__reaction_3.STP_handler = NULL;
    self->_lf__reaction_3.name = "?";
    self->_lf__reaction_3.mode = NULL;
    self->_lf__reaction_4.number = 4;
    self->_lf__reaction_4.function = _motion_controlreaction_function_4;
    self->_lf__reaction_4.self = self;
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    self->_lf__reaction_4.STP_handler = NULL;
    self->_lf__reaction_4.name = "?";
    self->_lf__reaction_4.mode = &self->_lf__modes[0];
    self->_lf__reaction_5.number = 5;
    self->_lf__reaction_5.function = _motion_controlreaction_function_5;
    self->_lf__reaction_5.self = self;
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    self->_lf__reaction_5.STP_handler = NULL;
    self->_lf__reaction_5.name = "?";
    self->_lf__reaction_5.mode = &self->_lf__modes[0];
    self->_lf__reaction_6.number = 6;
    self->_lf__reaction_6.function = _motion_controlreaction_function_6;
    self->_lf__reaction_6.self = self;
    self->_lf__reaction_6.deadline_violation_handler = NULL;
    self->_lf__reaction_6.STP_handler = NULL;
    self->_lf__reaction_6.name = "?";
    self->_lf__reaction_6.mode = &self->_lf__modes[0];
    self->_lf__reaction_7.number = 7;
    self->_lf__reaction_7.function = _motion_controlreaction_function_7;
    self->_lf__reaction_7.self = self;
    self->_lf__reaction_7.deadline_violation_handler = NULL;
    self->_lf__reaction_7.STP_handler = NULL;
    self->_lf__reaction_7.name = "?";
    self->_lf__reaction_7.mode = &self->_lf__modes[1];
    self->_lf__reaction_8.number = 8;
    self->_lf__reaction_8.function = _motion_controlreaction_function_8;
    self->_lf__reaction_8.self = self;
    self->_lf__reaction_8.deadline_violation_handler = NULL;
    self->_lf__reaction_8.STP_handler = NULL;
    self->_lf__reaction_8.name = "?";
    self->_lf__reaction_8.mode = &self->_lf__modes[1];
    self->_lf__reaction_9.number = 9;
    self->_lf__reaction_9.function = _motion_controlreaction_function_9;
    self->_lf__reaction_9.self = self;
    self->_lf__reaction_9.deadline_violation_handler = NULL;
    self->_lf__reaction_9.STP_handler = NULL;
    self->_lf__reaction_9.name = "?";
    self->_lf__reaction_9.mode = &self->_lf__modes[1];
    self->_lf__reaction_10.number = 10;
    self->_lf__reaction_10.function = _motion_controlreaction_function_10;
    self->_lf__reaction_10.self = self;
    self->_lf__reaction_10.deadline_violation_handler = NULL;
    self->_lf__reaction_10.STP_handler = NULL;
    self->_lf__reaction_10.name = "?";
    self->_lf__reaction_10.mode = &self->_lf__modes[2];
    self->_lf__reaction_11.number = 11;
    self->_lf__reaction_11.function = _motion_controlreaction_function_11;
    self->_lf__reaction_11.self = self;
    self->_lf__reaction_11.deadline_violation_handler = NULL;
    self->_lf__reaction_11.STP_handler = NULL;
    self->_lf__reaction_11.name = "?";
    self->_lf__reaction_11.mode = &self->_lf__modes[2];
    self->_lf__t_encoder.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t_encoder.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_encoder_reactions[0] = &self->_lf__reaction_0;
    self->_lf__t_encoder.reactions = &self->_lf__t_encoder_reactions[0];
    self->_lf__t_encoder.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t_encoder.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t_encoder.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t_encoder.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_gyro.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t_gyro.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_gyro_reactions[0] = &self->_lf__reaction_1;
    self->_lf__t_gyro.reactions = &self->_lf__t_gyro_reactions[0];
    self->_lf__t_gyro.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t_gyro.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t_gyro.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t_gyro.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_4;
    self->_lf__startup_reactions[1] = &self->_lf__reaction_7;
    self->_lf__startup_reactions[2] = &self->_lf__reaction_10;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 3;
    self->_lf__startup.is_timer = false;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__reset.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__reset_reactions[0] = &self->_lf__reaction_4;
    self->_lf__reset_reactions[1] = &self->_lf__reaction_7;
    self->_lf__reset_reactions[2] = &self->_lf__reaction_10;
    self->_lf__reset.last_tag = NEVER_TAG;
    self->_lf__reset.reactions = &self->_lf__reset_reactions[0];
    self->_lf__reset.number_of_reactions = 3;
    self->_lf__reset.is_timer = false;
    self->_lf__turn_angle.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__turn_angle.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__turn_angle_reactions[0] = &self->_lf__reaction_5;
    self->_lf__turn_angle_reactions[1] = &self->_lf__reaction_11;
    self->_lf__turn_angle.reactions = &self->_lf__turn_angle_reactions[0];
    self->_lf__turn_angle.number_of_reactions = 2;
    #ifdef FEDERATED
    self->_lf__turn_angle.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__turn_angle.tmplt.type.element_size = sizeof(float);
    self->_lf__target_speed.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__target_speed.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__target_speed_reactions[0] = &self->_lf__reaction_2;
    self->_lf__target_speed.reactions = &self->_lf__target_speed_reactions[0];
    self->_lf__target_speed.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__target_speed.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__target_speed.tmplt.type.element_size = sizeof(float);
    self->_lf__stop.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__stop.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__stop_reactions[0] = &self->_lf__reaction_6;
    self->_lf__stop_reactions[1] = &self->_lf__reaction_9;
    self->_lf__stop.reactions = &self->_lf__stop_reactions[0];
    self->_lf__stop.number_of_reactions = 2;
    #ifdef FEDERATED
    self->_lf__stop.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__stop.tmplt.type.element_size = sizeof(bool);
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[0].name = "FORWARD";
    self->_lf__modes[0].deactivation_time = 0;
    self->_lf__modes[0].flags = 0;
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[1].name = "ROTATE";
    self->_lf__modes[1].deactivation_time = 0;
    self->_lf__modes[1].flags = 0;
    self->_lf__modes[2].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[2].name = "STOP";
    self->_lf__modes[2].deactivation_time = 0;
    self->_lf__modes[2].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}

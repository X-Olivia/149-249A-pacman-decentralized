#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/MotorsWithFeedback/MotorsWithFeedback.h"
#include "_motorswithfeedback.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _motorswithfeedbackreaction_function_0(void* instance_args) {
    _motorswithfeedback_self_t* self = (_motorswithfeedback_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    enum { _lf_await_requires_a_single_non_mutable_input_port__left_speed = 1 };
    _motorswithfeedback_left_speed_t* left_speed = self->_lf_left_speed;
    int left_speed_width = self->_lf_left_speed_width; SUPPRESS_UNUSED_WARNING(left_speed_width);
    #line 50 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    self->target_speed_left = left_speed->value;
#line 17 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motorswithfeedback.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motorswithfeedbackreaction_function_1(void* instance_args) {
    _motorswithfeedback_self_t* self = (_motorswithfeedback_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    enum { _lf_await_requires_a_single_non_mutable_input_port__right_speed = 1 };
    _motorswithfeedback_right_speed_t* right_speed = self->_lf_right_speed;
    int right_speed_width = self->_lf_right_speed_width; SUPPRESS_UNUSED_WARNING(right_speed_width);
    #line 54 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    self->target_speed_right = right_speed->value;
#line 28 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motorswithfeedback.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _motorswithfeedbackreaction_function_2(void* instance_args) {
    _motorswithfeedback_self_t* self = (_motorswithfeedback_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct control_left {
        _picontrol_err_t* err;
    
    } control_left;
    struct control_right {
        _picontrol_err_t* err;
    
    } control_right;
    enum { _lf_await_requires_a_single_non_mutable_input_port__left = 1 };
    _motorswithfeedback_left_t* left = self->_lf_left;
    int left_width = self->_lf_left_width; SUPPRESS_UNUSED_WARNING(left_width);
    enum { _lf_await_requires_a_single_non_mutable_input_port__right = 1 };
    _motorswithfeedback_right_t* right = self->_lf_right;
    int right_width = self->_lf_right_width; SUPPRESS_UNUSED_WARNING(right_width);
    control_left.err = &(self->_lf_control_left.err);
    control_right.err = &(self->_lf_control_right.err);
    #line 59 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    // Ignore the first input because we can't estimate speed.
    instant_t now = lf_time_logical();
    if (self->prev_time > 0) {
      interval_t interval = now - self->prev_time;
    
      // Ignore intervals that are too small. Assume a maximum sample rate of 1kHz.
      if (interval >= MSEC(1)) {
        float est_speed_left = ((left->value - self->prev_left) * TICKS_PER_METER) / (interval * 1e-9f);
        float est_speed_right = ((right->value - self->prev_right) * TICKS_PER_METER) / (interval * 1e-9f);
    
        self->prev_left = left->value;
        self->prev_right = right->value;
    
        lf_set(control_left.err, self->target_speed_left - est_speed_left);
        lf_set(control_right.err, self->target_speed_right - est_speed_right);
      }
    }
    self->prev_time = now;
#line 69 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_motorswithfeedback.c"
}
#include "include/api/reaction_macros_undef.h"
_motorswithfeedback_self_t* new__motorswithfeedback() {
    _motorswithfeedback_self_t* self = (_motorswithfeedback_self_t*)lf_new_reactor(sizeof(_motorswithfeedback_self_t));
    // Set input by default to an always absent default input.
    self->_lf_left_speed = &self->_lf_default__left_speed;
    // Set the default source reactor pointer
    self->_lf_default__left_speed._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_right_speed = &self->_lf_default__right_speed;
    // Set the default source reactor pointer
    self->_lf_default__right_speed._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_left = &self->_lf_default__left;
    // Set the default source reactor pointer
    self->_lf_default__left._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_right = &self->_lf_default__right;
    // Set the default source reactor pointer
    self->_lf_default__right._base.source_reactor = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_control_left_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_control_right_width = -2;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _motorswithfeedbackreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _motorswithfeedbackreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _motorswithfeedbackreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__left_speed.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__left_speed.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__left_speed_reactions[0] = &self->_lf__reaction_0;
    self->_lf__left_speed.reactions = &self->_lf__left_speed_reactions[0];
    self->_lf__left_speed.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__left_speed.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__left_speed.tmplt.type.element_size = sizeof(float);
    self->_lf__right_speed.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__right_speed.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__right_speed_reactions[0] = &self->_lf__reaction_1;
    self->_lf__right_speed.reactions = &self->_lf__right_speed_reactions[0];
    self->_lf__right_speed.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__right_speed.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__right_speed.tmplt.type.element_size = sizeof(float);
    self->_lf__left.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__left.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__left_reactions[0] = &self->_lf__reaction_2;
    self->_lf__left.reactions = &self->_lf__left_reactions[0];
    self->_lf__left.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__left.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__left.tmplt.type.element_size = sizeof(int32_t);
    self->_lf__right.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__right.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__right_reactions[0] = &self->_lf__reaction_2;
    self->_lf__right.reactions = &self->_lf__right_reactions[0];
    self->_lf__right.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__right.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__right.tmplt.type.element_size = sizeof(int32_t);
    return self;
}

#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/MotorsWithFeedback/PIControl.h"
#include "_picontrol.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _picontrolreaction_function_0(void* instance_args) {
    _picontrol_self_t* self = (_picontrol_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    enum { _lf_await_requires_a_single_non_mutable_input_port__err = 1 };
    _picontrol_err_t* err = self->_lf_err;
    int err_width = self->_lf_err_width; SUPPRESS_UNUSED_WARNING(err_width);
    _picontrol_ctrl_t* ctrl = &self->_lf_ctrl;
    #line 86 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/MotorsWithFeedback.lf"
    self->acum_err += err->value;
    lf_set(ctrl, err->value * self->p_gain +
                (self->acum_err) * self->i_gain);
#line 20 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_picontrol.c"
}
#include "include/api/reaction_macros_undef.h"
_picontrol_self_t* new__picontrol() {
    _picontrol_self_t* self = (_picontrol_self_t*)lf_new_reactor(sizeof(_picontrol_self_t));
    // Set input by default to an always absent default input.
    self->_lf_err = &self->_lf_default__err;
    // Set the default source reactor pointer
    self->_lf_default__err._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _picontrolreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__err.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__err.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__err_reactions[0] = &self->_lf__reaction_0;
    self->_lf__err.reactions = &self->_lf__err_reactions[0];
    self->_lf__err.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__err.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__err.tmplt.type.element_size = sizeof(float);
    return self;
}

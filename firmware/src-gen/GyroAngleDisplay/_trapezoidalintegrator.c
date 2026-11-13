#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/IMU/TrapezoidalIntegrator.h"
#include "_trapezoidalintegrator.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _trapezoidalintegratorreaction_function_0(void* instance_args) {
    _trapezoidalintegrator_self_t* self = (_trapezoidalintegrator_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _trapezoidalintegrator_in_t* in = self->_lf_in;
    int in_width = self->_lf_in_width; SUPPRESS_UNUSED_WARNING(in_width);
    _trapezoidalintegrator_out_t* out = &self->_lf_out;
    #line 98 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/IMU.lf"
    instant_t now = lf_time_logical();
    if (self->prev_time > SEC(0)) {
      float interval = ((now - self->prev_time) * 1e-9);
      self->s += (in->value + self->prev_in) * interval / 2;
    }
    lf_set(out, self->s);
    self->prev_in = in->value;
    self->prev_time = now;
#line 24 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_trapezoidalintegrator.c"
}
#include "include/api/reaction_macros_undef.h"
_trapezoidalintegrator_self_t* new__trapezoidalintegrator() {
    _trapezoidalintegrator_self_t* self = (_trapezoidalintegrator_self_t*)lf_new_reactor(sizeof(_trapezoidalintegrator_self_t));
    // Set input by default to an always absent default input.
    self->_lf_in = &self->_lf_default__in;
    // Set the default source reactor pointer
    self->_lf_default__in._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _trapezoidalintegratorreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__in.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__in.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__in_reactions[0] = &self->_lf__reaction_0;
    self->_lf__in.reactions = &self->_lf__in_reactions[0];
    self->_lf__in.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__in.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__in.tmplt.type.element_size = sizeof(float);
    return self;
}

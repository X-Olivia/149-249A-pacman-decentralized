#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/Encoders/Encoders.h"
#include "_encoders.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _encodersreaction_function_0(void* instance_args) {
    _encoders_self_t* self = (_encoders_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 36 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/Encoders.lf"
    PIO pio = pio0;
    pio_add_program(pio, &quadrature_encoder_program);
    quadrature_encoder_program_init(pio, RIGHT_SM, RIGHT_ENCODER_AB, 0);
    quadrature_encoder_program_init(pio, LEFT_SM, LEFT_ENCODER_AB, 0);
#line 18 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_encoders.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _encodersreaction_function_1(void* instance_args) {
    _encoders_self_t* self = (_encoders_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    enum { _lf_await_requires_a_single_non_mutable_input_port__trigger = 1 };
    _encoders_trigger_t* trigger = self->_lf_trigger;
    int trigger_width = self->_lf_trigger_width; SUPPRESS_UNUSED_WARNING(trigger_width);
    _encoders_left_t* left = &self->_lf_left;
    _encoders_right_t* right = &self->_lf_right;
    #line 43 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/Encoders.lf"
    // Also, the sign is reversed, where reverse increases, so we negate.
    int32_t rcount = -quadrature_encoder_get_count(pio0, RIGHT_SM);
    int32_t lcount = -quadrature_encoder_get_count(pio0, LEFT_SM);
    lf_set(right, rcount);
    lf_set(left, lcount);
#line 35 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_encoders.c"
}
#include "include/api/reaction_macros_undef.h"
_encoders_self_t* new__encoders() {
    _encoders_self_t* self = (_encoders_self_t*)lf_new_reactor(sizeof(_encoders_self_t));
    // Set input by default to an always absent default input.
    self->_lf_trigger = &self->_lf_default__trigger;
    // Set the default source reactor pointer
    self->_lf_default__trigger._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _encodersreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _encodersreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    self->_lf__trigger.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__trigger_reactions[0] = &self->_lf__reaction_1;
    self->_lf__trigger.reactions = &self->_lf__trigger_reactions[0];
    self->_lf__trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__trigger.tmplt.type.element_size = sizeof(bool);
    return self;
}

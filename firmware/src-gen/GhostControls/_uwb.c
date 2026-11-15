#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/UWB/UWB.h"
#include "_uwb.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _uwbreaction_function_0(void* instance_args) {
    _uwb_self_t* self = (_uwb_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    enum { _lf_await_requires_a_single_non_mutable_input_port__uart_data = 1 };
    _uwb_uart_data_t* uart_data = self->_lf_uart_data;
    int uart_data_width = self->_lf_uart_data_width; SUPPRESS_UNUSED_WARNING(uart_data_width);
    _uwb_dist_t* dist = &self->_lf_dist;
    #line 24 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/UWB.lf"
    char* data = uart_data->value;
    char* endptr;
    float num = strtof(data, &endptr);
    if (endptr != data) {
      lf_set(dist, num);
    }
#line 23 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_uwb.c"
}
#include "include/api/reaction_macros_undef.h"
_uwb_self_t* new__uwb() {
    _uwb_self_t* self = (_uwb_self_t*)lf_new_reactor(sizeof(_uwb_self_t));
    // Set input by default to an always absent default input.
    self->_lf_uart_data = &self->_lf_default__uart_data;
    // Set the default source reactor pointer
    self->_lf_default__uart_data._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _uwbreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__uart_data.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__uart_data.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__uart_data_reactions[0] = &self->_lf__reaction_0;
    self->_lf__uart_data.reactions = &self->_lf__uart_data_reactions[0];
    self->_lf__uart_data.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__uart_data.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__uart_data.tmplt.type.element_size = sizeof(string);
    return self;
}

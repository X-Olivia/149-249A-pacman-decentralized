#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/Bluetooth/Bluetooth.h"
#include "_bluetooth.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _bluetoothreaction_function_0(void* instance_args) {
    _bluetooth_self_t* self = (_bluetooth_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _bluetooth_uart_data_t* uart_data = self->_lf_uart_data;
    int uart_data_width = self->_lf_uart_data_width; SUPPRESS_UNUSED_WARNING(uart_data_width);
    _bluetooth_cmd_t* cmd = &self->_lf_cmd;
    #line 23 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/Bluetooth.lf"
    if (uart_data->value){
      lf_set(cmd, uart_data->value[0]);
    }
#line 19 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_bluetooth.c"
}
#include "include/api/reaction_macros_undef.h"
_bluetooth_self_t* new__bluetooth() {
    _bluetooth_self_t* self = (_bluetooth_self_t*)lf_new_reactor(sizeof(_bluetooth_self_t));
    // Set input by default to an always absent default input.
    self->_lf_uart_data = &self->_lf_default__uart_data;
    // Set the default source reactor pointer
    self->_lf_default__uart_data._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _bluetoothreaction_function_0;
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

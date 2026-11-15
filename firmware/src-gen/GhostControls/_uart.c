#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/UART/UART.h"
#include "_uart.h"
// *********** From the preamble, verbatim:
#line 23 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/UART.lf"
char buffer[MESSAGE_SIZE + 1] = {0};
int buf_ptr = 0;
#line 11 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_uart.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _uartreaction_function_0(void* instance_args) {
    _uart_self_t* self = (_uart_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 32 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/UART.lf"
    uart_init(uart0, 9600);
    gpio_set_function(28, GPIO_FUNC_UART);  // GP28 = TX -> ESP32 RX (20)
    gpio_set_function(29, GPIO_FUNC_UART);  // GP29 = RX <- ESP32 TX (21)
#line 24 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_uart.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _uartreaction_function_1(void* instance_args) {
    _uart_self_t* self = (_uart_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _uart_uwb_out_t* uwb_out = &self->_lf_uwb_out;
    _uart_bt_out_t* bt_out = &self->_lf_bt_out;
    #line 39 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/UART.lf"
    while (uart_is_readable(uart0)) {
        buffer[buf_ptr] = uart_getc(uart0);
        if (buffer[buf_ptr] == '\n' || buf_ptr >= MESSAGE_SIZE) {
            buffer[buf_ptr] = '\0';
            buf_ptr = 0;
    
            // parse the string "use:data" -> "use", "data"
            char* use = strtok(buffer, ":");
            char* data = strtok(NULL, "");
            if (use != NULL && data != NULL) {
                if (strcmp(use, "UWB") == 0) {
                    lf_set(uwb_out, data);
                } else if (strcmp(use, "BT") == 0) {
                    lf_set(bt_out, data);
                }
            }
            return;
        } else {
            buf_ptr++;
        }
    }
#line 54 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_uart.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _uartreaction_function_2(void* instance_args) {
    _uart_self_t* self = (_uart_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    enum { _lf_await_requires_a_single_non_mutable_input_port__bt_in = 1 };
    _uart_bt_in_t* bt_in = self->_lf_bt_in;
    int bt_in_width = self->_lf_bt_in_width; SUPPRESS_UNUSED_WARNING(bt_in_width);
    #line 64 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/UART.lf"
    // send message to bluetooth
    char message[MESSAGE_SIZE + 1] = {0};
    snprintf(message, MESSAGE_SIZE + 1, "BT:%s\n", bt_in->value);
    uart_puts(uart0, message);
#line 68 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_uart.c"
}
#include "include/api/reaction_macros_undef.h"
_uart_self_t* new__uart() {
    _uart_self_t* self = (_uart_self_t*)lf_new_reactor(sizeof(_uart_self_t));
    // Set input by default to an always absent default input.
    self->_lf_bt_in = &self->_lf_default__bt_in;
    // Set the default source reactor pointer
    self->_lf_default__bt_in._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _uartreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _uartreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _uartreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__poll.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__poll.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__poll_reactions[0] = &self->_lf__reaction_1;
    self->_lf__poll.reactions = &self->_lf__poll_reactions[0];
    self->_lf__poll.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__poll.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__poll.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__poll.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    self->_lf__bt_in.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__bt_in.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__bt_in_reactions[0] = &self->_lf__reaction_2;
    self->_lf__bt_in.reactions = &self->_lf__bt_in_reactions[0];
    self->_lf__bt_in.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__bt_in.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__bt_in.tmplt.type.element_size = sizeof(string);
    return self;
}

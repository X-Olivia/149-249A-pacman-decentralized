#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/UART/UART.h"
#include "_uart.h"
// *********** From the preamble, verbatim:
#line 22 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/UART.lf"
bool on = false;
void* uart_irq;
char buffer[MESSAGE_SIZE + 1] = {0};
int buf_ptr = 0;
void uart_irq_handler(){
if (uart_is_readable(uart0)){
    buffer[buf_ptr] = uart_getc(uart0);
    if (buffer[buf_ptr] == '\n' || buf_ptr >= MESSAGE_SIZE){
    buffer[buf_ptr] = '\0';
    buf_ptr = 0;
    lf_schedule(uart_irq, 0);
    }
    else {
    buf_ptr++;
    }
}
}
#line 26 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy2/_uart.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _uartreaction_function_0(void* instance_args) {
    _uart_self_t* self = (_uart_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _uart_uart_irq_a_t* uart_irq_a = &self->_lf_uart_irq_a;
    #line 46 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/UART.lf"
    uart_init(uart0, 9600);
    gpio_set_function(28, GPIO_FUNC_UART);  // GP28 = TX -> ESP32 RX (20)
    gpio_set_function(29, GPIO_FUNC_UART);  // GP29 = RX <- ESP32 TX (21)
    irq_set_exclusive_handler(UART0_IRQ, uart_irq_handler);
    irq_set_enabled(UART0_IRQ, true);
    uart_set_irqs_enabled (uart0, true, false);
    uart_irq = uart_irq_a;
#line 43 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy2/_uart.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _uartreaction_function_1(void* instance_args) {
    _uart_self_t* self = (_uart_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    lf_critical_section_enter(self->base.environment);
    // Expose the action struct as a local variable whose name matches the action name.
    _uart_uart_irq_a_t* uart_irq_a = &self->_lf_uart_irq_a;
    // Set the fields of the action struct to match the current trigger.
    uart_irq_a->is_present = (bool)self->_lf__uart_irq_a.status;
    uart_irq_a->has_value = ((self->_lf__uart_irq_a.tmplt.token) != NULL && (self->_lf__uart_irq_a.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)uart_irq_a, (self->_lf__uart_irq_a.tmplt.token));
    lf_critical_section_exit(self->base.environment);
    _uart_uwb_out_t* uwb_out = &self->_lf_uwb_out;
    _uart_bt_out_t* bt_out = &self->_lf_bt_out;
    #line 56 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/UART.lf"
    char* endptr = NULL;
    // parse the string "use:data" -> "use", "data"
    char* use = strtok(buffer, ":");
    char* data = strtok(NULL, "");
    if (strcmp(use, "UWB") == 0){
        lf_set(uwb_out, data);
    } else if (strcmp(use, "BT") == 0){
        lf_set(bt_out, data);
    }
#line 69 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy2/_uart.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _uartreaction_function_2(void* instance_args) {
    _uart_self_t* self = (_uart_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    enum { _lf_await_requires_a_single_non_mutable_input_port__bt_in = 1 };
    _uart_bt_in_t* bt_in = self->_lf_bt_in;
    int bt_in_width = self->_lf_bt_in_width; SUPPRESS_UNUSED_WARNING(bt_in_width);
    #line 69 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/UART.lf"
    // send message to bluetooth
    char message[MESSAGE_SIZE + 1] = {0};
    snprintf(message, MESSAGE_SIZE + 1, "BT:%s\n", bt_in->value);
    uart_puts(uart0, message);
#line 83 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy2/_uart.c"
}
#include "include/api/reaction_macros_undef.h"
_uart_self_t* new__uart() {
    _uart_self_t* self = (_uart_self_t*)lf_new_reactor(sizeof(_uart_self_t));
    self->_lf_uart_irq_a._base.trigger = &self->_lf__uart_irq_a;
    self->_lf_uart_irq_a.parent = (self_base_t*)self;
    self->_lf_uart_irq_a.source_id = -1;
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
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    self->_lf__uart_irq_a.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__uart_irq_a.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__uart_irq_a_reactions[0] = &self->_lf__reaction_1;
    self->_lf__uart_irq_a.reactions = &self->_lf__uart_irq_a_reactions[0];
    self->_lf__uart_irq_a.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__uart_irq_a.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__uart_irq_a.is_physical = true;
    
    self->_lf__uart_irq_a.tmplt.type.element_size = 0;
    self->_lf_uart_irq_a.type.element_size = 0;
    self->_lf__uart_irq_a.tmplt.length = 1;
    self->_lf_uart_irq_a.length = 1;
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

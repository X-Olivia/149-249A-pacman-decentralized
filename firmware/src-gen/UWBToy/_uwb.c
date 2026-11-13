#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/UWBToy/UWB.h"
#include "_uwb.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _uwbreaction_function_0(void* instance_args) {
    _uwb_self_t* self = (_uwb_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 24 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/UWBToy.lf"
    uart_init(uart0, 9600);
    gpio_set_function(28, GPIO_FUNC_UART);  // GP28 = TX -> ESP32 RX (20)
    gpio_set_function(29, GPIO_FUNC_UART);  // GP29 = RX <- ESP32 TX (21)
#line 17 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy/_uwb.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _uwbreaction_function_1(void* instance_args) {
    _uwb_self_t* self = (_uwb_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _uwb_dist_t* dist = &self->_lf_dist;
    #line 30 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/UWBToy.lf"
    static char buf[8];
    int charRead = 0;
    if (uart_is_readable(uart0)){
      do {
        while (!uart_is_readable(uart0));
        buf[charRead] = uart_getc(uart0);
        printf("%c", buf[charRead]);
        charRead++;
      } while (buf[charRead - 1] != '\n' && charRead < 7);
      buf[charRead - 1] = '\0'; 
      lf_set(dist, buf);
      printf("\n");
    }
#line 38 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy/_uwb.c"
}
#include "include/api/reaction_macros_undef.h"
_uwb_self_t* new__uwb() {
    _uwb_self_t* self = (_uwb_self_t*)lf_new_reactor(sizeof(_uwb_self_t));
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _uwbreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _uwbreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
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
    return self;
}

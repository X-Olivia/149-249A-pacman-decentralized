#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/Blink/Blink.h"
#include "_blink_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _blink_mainreaction_function_0(void* instance_args) {
    _blink_main_main_self_t* self = (_blink_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 26 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/Blink.lf"
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
#line 16 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/Blink/_blink_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _blink_mainreaction_function_1(void* instance_args) {
    _blink_main_main_self_t* self = (_blink_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 31 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/Blink.lf"
    self->led_on = !self->led_on;
    printf("LED State: %b\n", self->led_on);
    gpio_put(PICO_DEFAULT_LED_PIN, !self->led_on);
#line 27 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/Blink/_blink_main.c"
}
#include "include/api/reaction_macros_undef.h"
_blink_main_main_self_t* new__blink_main() {
    _blink_main_main_self_t* self = (_blink_main_main_self_t*)lf_new_reactor(sizeof(_blink_main_main_self_t));
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _blink_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _blink_mainreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__t.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    self->_lf__t.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
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

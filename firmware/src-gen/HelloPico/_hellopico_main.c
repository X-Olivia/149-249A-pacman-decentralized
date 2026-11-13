#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/HelloPico/HelloPico.h"
#include "_hellopico_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _hellopico_mainreaction_function_0(void* instance_args) {
    _hellopico_main_main_self_t* self = (_hellopico_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 62 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/HelloPico.lf"
    printf("Hello World! %d\n", self->count++);
#line 15 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/HelloPico/_hellopico_main.c"
}
#include "include/api/reaction_macros_undef.h"
_hellopico_main_main_self_t* new__hellopico_main() {
    _hellopico_main_main_self_t* self = (_hellopico_main_main_self_t*)lf_new_reactor(sizeof(_hellopico_main_main_self_t));
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _hellopico_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__t1.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t1.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t1_reactions[0] = &self->_lf__reaction_0;
    self->_lf__t1.reactions = &self->_lf__t1_reactions[0];
    self->_lf__t1.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t1.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t1.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t1.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    return self;
}

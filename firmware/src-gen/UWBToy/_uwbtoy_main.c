#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/UWBToy/UWBToy.h"
#include "_uwbtoy_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _uwbtoy_mainreaction_function_0(void* instance_args) {
    _uwbtoy_main_main_self_t* self = (_uwbtoy_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct uwb {
        _uwb_dist_t* dist;
    
    } uwb;
    struct display {
        _display_line0_t* line0;
    
    } display;
    uwb.dist = self->_lf_uwb.dist;
    display.line0 = &(self->_lf_display.line0);
    #line 50 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/UWBToy.lf"
    static char buf[17];
    snprintf(buf, 17, "Dist: %s cm", uwb.dist->value);
    lf_set(display.line0, buf);
#line 26 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/UWBToy/_uwbtoy_main.c"
}
#include "include/api/reaction_macros_undef.h"
_uwbtoy_main_main_self_t* new__uwbtoy_main() {
    _uwbtoy_main_main_self_t* self = (_uwbtoy_main_main_self_t*)lf_new_reactor(sizeof(_uwbtoy_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_display_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_uwb_width = -2;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_uwb.dist_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_uwb.dist_reactions[0] = &self->_lf__reaction_0;
    self->_lf_uwb.dist_trigger.reactions = self->_lf_uwb.dist_reactions;
    self->_lf_uwb.dist_trigger.last_tag = NEVER_TAG;
    self->_lf_uwb.dist_trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf_uwb.dist_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _uwbtoy_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    return self;
}

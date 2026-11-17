#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/LabTesting/LabTesting.h"
#include "_labtesting_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _labtesting_mainreaction_function_0(void* instance_args) {
    _labtesting_main_main_self_t* self = (_labtesting_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct robot {
        _robot_drive_t* drive;
    
    } robot;
    robot.drive = &(self->_lf_robot.drive);
    #line 150 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/LabTesting.lf"
    lf_set(robot.drive, self->drive);
    // Toggle the drive state variable for next time.
    self->drive = !self->drive;
#line 21 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/LabTesting/_labtesting_main.c"
}
#include "include/api/reaction_macros_undef.h"
_labtesting_main_main_self_t* new__labtesting_main() {
    _labtesting_main_main_self_t* self = (_labtesting_main_main_self_t*)lf_new_reactor(sizeof(_labtesting_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_robot_width = -2;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _labtesting_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__t.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    self->_lf__t.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    return self;
}

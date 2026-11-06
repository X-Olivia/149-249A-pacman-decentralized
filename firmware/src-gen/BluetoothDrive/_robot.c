#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/BluetoothDrive/Robot.h"
#include "_robot.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _robotreaction_function_0(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motor {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motor;
    motor.left_power = &(self->_lf_motor.left_power);
    motor.right_power = &(self->_lf_motor.right_power);
    #line 42 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/BluetoothDrive.lf"
    lf_set(motor.left_power, 0.0f);
    lf_set(motor.right_power, 0.0f);
#line 22 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/BluetoothDrive/_robot.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _robotreaction_function_1(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motor {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motor;
    _robot_cmd_t* cmd = self->_lf_cmd;
    int cmd_width = self->_lf_cmd_width; SUPPRESS_UNUSED_WARNING(cmd_width);
    motor.left_power = &(self->_lf_motor.left_power);
    motor.right_power = &(self->_lf_motor.right_power);
    #line 48 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/BluetoothDrive.lf"
    switch (cmd->value) {
      case 'w':
        lf_set(motor.left_power,  self->speed);
        lf_set(motor.right_power, self->speed);
        break;
      case 's':
        lf_set(motor.left_power,  -self->speed);
        lf_set(motor.right_power, -self->speed);
        break;
      case 'a':
        lf_set(motor.left_power,  -self->speed);
        lf_set(motor.right_power,  self->speed);
        break;
      case 'd':
        lf_set(motor.left_power,   self->speed);
        lf_set(motor.right_power, -self->speed);
        break;
      case ' ':
        lf_set(motor.left_power,  0.0f);
        lf_set(motor.right_power, 0.0f);
        break;
    }
#line 60 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/BluetoothDrive/_robot.c"
}
#include "include/api/reaction_macros_undef.h"
_robot_self_t* new__robot() {
    _robot_self_t* self = (_robot_self_t*)lf_new_reactor(sizeof(_robot_self_t));
    // Set input by default to an always absent default input.
    self->_lf_cmd = &self->_lf_default__cmd;
    // Set the default source reactor pointer
    self->_lf_default__cmd._base.source_reactor = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_motor_width = -2;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _robotreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _robotreaction_function_1;
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
    self->_lf__cmd.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__cmd.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__cmd_reactions[0] = &self->_lf__reaction_1;
    self->_lf__cmd.reactions = &self->_lf__cmd_reactions[0];
    self->_lf__cmd.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__cmd.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__cmd.tmplt.type.element_size = sizeof(char);
    return self;
}

#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/LabTesting/Robot.h"
#include "_robot.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _robotreaction_function_0(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_trigger_t* trigger;
    
    } line;
    line.trigger = &(self->_lf_line.trigger);
    #line 37 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/LabTesting.lf"
    lf_set(line.trigger, true);
#line 19 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/LabTesting/_robot.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _robotreaction_function_1(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motor {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motor;
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    _robot_notify_t* notify = &self->_lf_notify;
    motor.left_power = &(self->_lf_motor.left_power);
    motor.right_power = &(self->_lf_motor.right_power);
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 44 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/LabTesting.lf"
      lf_set(notify, "INIT");
    
      lf_set(motor.left_power, 0);
      lf_set(motor.right_power, 0);
    
    //   lf_set(disp.line0, "CALIBRATING");
    //   lf_set(disp.line1, "Roll robot over");
    //   lf_set(disp.line2, "light and dark.");
#line 51 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/LabTesting/_robot.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _robotreaction_function_2(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_calibrate_t* calibrate;
    
    } line;
    struct motor {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motor;
    reactor_mode_t* DRIVING = &self->_lf__modes[3];
    lf_mode_change_type_t _lf_DRIVING_change_type = reset_transition;
    line.calibrate = &(self->_lf_line.calibrate);
    motor.left_power = &(self->_lf_motor.left_power);
    motor.right_power = &(self->_lf_motor.right_power);
    #line 61 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/LabTesting.lf"
    lf_set(line.calibrate, false);
    lf_set(motor.left_power, 0.15f);
    lf_set(motor.right_power, 0.15f);
    lf_set_mode(DRIVING);
#line 76 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/LabTesting/_robot.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _robotreaction_function_3(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    struct motor {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motor;
    lf_critical_section_enter(self->base.environment);
    // Expose the action struct as a local variable whose name matches the action name.
    _robot_clear_t* clear = &self->_lf_clear;
    // Set the fields of the action struct to match the current trigger.
    clear->is_present = (bool)self->_lf__clear.status;
    clear->has_value = ((self->_lf__clear.tmplt.token) != NULL && (self->_lf__clear.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)clear, (self->_lf__clear.tmplt.token));
    lf_critical_section_exit(self->base.environment);
    reactor_mode_t* RECENTER = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_RECENTER_change_type = reset_transition;
    disp.line0 = &(self->_lf_disp.line0);
    motor.left_power = &(self->_lf_motor.left_power);
    motor.right_power = &(self->_lf_motor.right_power);
    #line 71 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/LabTesting.lf"
    //   if (self->blackleft) {
    //       lf_set(motor.left_power, 0.2f);
    //       lf_set(motor.right_power, -0.2f);
    //       lf_schedule(clear, SEC(0.1));
    //       lf_set_mode(TURNING);
    //   }
    //   else if (self->blackright) {
    //       lf_set(motor.left_power, -0.2f);
    //       lf_set(motor.right_power, 0.2f);
    //       lf_schedule(clear, SEC(0.1));
    //       lf_set_mode(TURNING);
    //   }
    //   else if (self->blackcenter) {
    //       lf_set(motor.left_power, 0);
    //       lf_set(motor.right_power, 0);
    //   }
    static char buf0[17];
    snprintf(buf0, 17, "Intersection!%c");
    lf_set(disp.line0, buf0);
#line 124 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/LabTesting/_robot.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _robotreaction_function_4(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_reflect_t* reflect;
    
    } line;
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    struct motor {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motor;
    line.reflect = self->_lf_line.reflect;
    reactor_mode_t* DRIVING = &self->_lf__modes[3];
    lf_mode_change_type_t _lf_DRIVING_change_type = reset_transition;
    disp.line0 = &(self->_lf_disp.line0);
    motor.left_power = &(self->_lf_motor.left_power);
    motor.right_power = &(self->_lf_motor.right_power);
    #line 96 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/LabTesting.lf"
    static char buf0[17];
    self->blackleft = (line.reflect->value[0] > 800) || (line.reflect->value[1] > 800);
    self->blackright = (line.reflect->value[3] > 800) || (line.reflect->value[4] > 800);
    self->blackcenter = (line.reflect->value[2] > 800);
    if (self->blackcenter) {
      lf_set(motor.left_power, 0.15f);
      lf_set(motor.right_power, 0.15f);
      lf_set_mode(DRIVING);
    }
    if (self->blackleft) {
          lf_set(motor.left_power, 0.075f);
          lf_set(motor.right_power, 0.15f);
          snprintf(buf0, 17, "Turning Left!%c");
    }
    else if (self->blackright) {
          lf_set(motor.left_power, 0.15);
          lf_set(motor.right_power, 0.075f);
          snprintf(buf0, 17, "Turning Right!%c");
    }
    lf_set(disp.line0, buf0);
#line 170 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/LabTesting/_robot.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _robotreaction_function_5(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_reflect_t* reflect;
    
    } line;
    struct motor {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motor;
    line.reflect = self->_lf_line.reflect;
    reactor_mode_t* RECENTER = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_RECENTER_change_type = reset_transition;
    reactor_mode_t* INTERSECTION = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_INTERSECTION_change_type = reset_transition;
    _robot_clear_t* clear = &self->_lf_clear;
    motor.left_power = &(self->_lf_motor.left_power);
    motor.right_power = &(self->_lf_motor.right_power);
    #line 122 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/LabTesting.lf"
    self->blackleft = (line.reflect->value[0] > 800) || (line.reflect->value[1] > 800);
    self->blackright = (line.reflect->value[3] > 800) || (line.reflect->value[4] > 800);
    self->blackcenter = (line.reflect->value[2] > 800);
    if ((self->blackleft || self->blackright) && (self->blackcenter)) {
        lf_set(motor.left_power, 0);
        lf_set(motor.right_power, 0);
        lf_schedule(clear, SEC(0.1));
        lf_set_mode(INTERSECTION);
    }
    else if (!(self->blackcenter)) {
      //   lf_set(motor.left_power, 0);
      //   lf_set(motor.right_power, 0);
        //lf_schedule(clear, SEC(0.1));
        lf_set_mode(RECENTER);
    }
#line 209 "/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src-gen/LabTesting/_robot.c"
}
#include "include/api/reaction_macros_undef.h"
_robot_self_t* new__robot() {
    _robot_self_t* self = (_robot_self_t*)lf_new_reactor(sizeof(_robot_self_t));
    self->_lf_clear._base.trigger = &self->_lf__clear;
    self->_lf_clear.parent = (self_base_t*)self;
    self->_lf_clear.source_id = -1;
    // Set input by default to an always absent default input.
    self->_lf_drive = &self->_lf_default__drive;
    // Set the default source reactor pointer
    self->_lf_default__drive._base.source_reactor = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_line_width = -2;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_line.reflect_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_line.reflect_reactions[0] = &self->_lf__reaction_4;
    self->_lf_line.reflect_reactions[1] = &self->_lf__reaction_5;
    self->_lf_line.reflect_trigger.reactions = self->_lf_line.reflect_reactions;
    self->_lf_line.reflect_trigger.last_tag = NEVER_TAG;
    self->_lf_line.reflect_trigger.number_of_reactions = 2;
    #ifdef FEDERATED
    self->_lf_line.reflect_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_motor_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
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
    self->_lf__reaction_1.mode = &self->_lf__modes[0];
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _robotreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = &self->_lf__modes[0];
    self->_lf__reaction_3.number = 3;
    self->_lf__reaction_3.function = _robotreaction_function_3;
    self->_lf__reaction_3.self = self;
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    self->_lf__reaction_3.STP_handler = NULL;
    self->_lf__reaction_3.name = "?";
    self->_lf__reaction_3.mode = &self->_lf__modes[1];
    self->_lf__reaction_4.number = 4;
    self->_lf__reaction_4.function = _robotreaction_function_4;
    self->_lf__reaction_4.self = self;
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    self->_lf__reaction_4.STP_handler = NULL;
    self->_lf__reaction_4.name = "?";
    self->_lf__reaction_4.mode = &self->_lf__modes[2];
    self->_lf__reaction_5.number = 5;
    self->_lf__reaction_5.function = _robotreaction_function_5;
    self->_lf__reaction_5.self = self;
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    self->_lf__reaction_5.STP_handler = NULL;
    self->_lf__reaction_5.name = "?";
    self->_lf__reaction_5.mode = &self->_lf__modes[3];
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
    self->_lf__seconds.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__seconds.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__end_calibration.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__end_calibration_reactions[0] = &self->_lf__reaction_2;
    self->_lf__end_calibration.reactions = &self->_lf__end_calibration_reactions[0];
    self->_lf__end_calibration.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__end_calibration.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__end_calibration.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_1;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    self->_lf__clear.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__clear.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__clear_reactions[0] = &self->_lf__reaction_3;
    self->_lf__clear.reactions = &self->_lf__clear_reactions[0];
    self->_lf__clear.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__clear.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__clear.is_physical = false;
    
    self->_lf__clear.tmplt.type.element_size = 0;
    self->_lf_clear.type.element_size = 0;
    self->_lf__clear.tmplt.length = 1;
    self->_lf_clear.length = 1;
    self->_lf__drive.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__drive.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__drive.tmplt.type.element_size = sizeof(bool);
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[0].name = "calibrating";
    self->_lf__modes[0].deactivation_time = 0;
    self->_lf__modes[0].flags = 0;
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[1].name = "INTERSECTION";
    self->_lf__modes[1].deactivation_time = 0;
    self->_lf__modes[1].flags = 0;
    self->_lf__modes[2].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[2].name = "RECENTER";
    self->_lf__modes[2].deactivation_time = 0;
    self->_lf__modes[2].flags = 0;
    self->_lf__modes[3].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[3].name = "DRIVING";
    self->_lf__modes[3].deactivation_time = 0;
    self->_lf__modes[3].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}

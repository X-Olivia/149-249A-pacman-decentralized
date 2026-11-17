#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/GhostControls/Pacman.h"
#include "_pacman.h"
// ***** Start of method declarations.
void _pacman_method_turn(void* instance_args, char command, _motion_control_turn_angle_t* control, int rel_dir, _display_line0_t* disp);
#define turn(...) _pacman_method_turn(self, ##__VA_ARGS__)
#line 306 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
#include "include/api/reaction_macros.h"
// Implementation of method turn()
void _pacman_method_turn(void* instance_args, char command, _motion_control_turn_angle_t* control, int rel_dir, _display_line0_t* disp) {
    _pacman_self_t* self = (_pacman_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 307 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    lf_set(control, rel_dir);
    static char buf[17];
    snprintf(buf, 17, "Cmd: %c", command);
    printf("%s\n", buf);
    lf_set(disp, buf);
}
#include "include/api/reaction_macros_undef.h"
#line 23 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_pacman.c"
#undef turn
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
#define turn(...) _pacman_method_turn(self, ##__VA_ARGS__)
void _pacmanreaction_function_0(void* instance_args) {
    _pacman_self_t* self = (_pacman_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct bt {
        _bluetooth_cmd_t* cmd;
    
    } bt;
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    struct control {
        _motion_control_stop_t* stop;
    _motion_control_turn_angle_t* turn_angle;
    
    } control;
    bt.cmd = self->_lf_bt.cmd;
    disp.line0 = &(self->_lf_disp.line0);
    control.stop = &(self->_lf_control.stop);
    control.turn_angle = &(self->_lf_control.turn_angle);
    #line 315 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    float s = 0.1f;  // 30% power; keep low for the first test
    switch (bt.cmd->value) {
      case 'w': turn(bt.cmd->value, control.turn_angle, 0, disp.line0); break;
      case 's': turn(bt.cmd->value, control.turn_angle, 180, disp.line0); break;
      case 'a': turn(bt.cmd->value, control.turn_angle, 90, disp.line0); break;
      case 'd': turn(bt.cmd->value, control.turn_angle, -90, disp.line0); break;
      case 'S': lf_set(control.stop, true); break;
    
    }
#line 57 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_pacman.c"
}
#undef turn
#include "include/api/reaction_macros_undef.h"
_pacman_self_t* new__pacman() {
    _pacman_self_t* self = (_pacman_self_t*)lf_new_reactor(sizeof(_pacman_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_control_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_bt_width = -2;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_bt.cmd_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_bt.cmd_reactions[0] = &self->_lf__reaction_0;
    self->_lf_bt.cmd_trigger.reactions = self->_lf_bt.cmd_reactions;
    self->_lf_bt.cmd_trigger.last_tag = NEVER_TAG;
    self->_lf_bt.cmd_trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf_bt.cmd_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _pacmanreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    return self;
}

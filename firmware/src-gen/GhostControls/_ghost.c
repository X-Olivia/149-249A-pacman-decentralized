#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/GhostControls/Ghost.h"
#include "_ghost.h"
// ***** Start of method declarations.
void _ghost_method_d2d_dir_reset(void* instance_args, dir_t dir);
float _ghost_method_d2d_dir_get_last(void* instance_args, dir_t dir);
float _ghost_method_d2d_dir_get_dist_roc(void* instance_args, dir_t dir);
void _ghost_method_d2d_dir_add_dist(void* instance_args, dir_t dir, float dist);
void _ghost_method_d2d_reset_all_dists(void* instance_args);
bool _ghost_method_in_exits(void* instance_args, path_arr exits, dir_t dir);
dir_t _ghost_method_choose_exit(void* instance_args, path_arr exits);
void _ghost_method_turn(void* instance_args, _motion_control_turn_angle_t* control, dir_t rel_dir);
void _ghost_method_print_roc(void* instance_args, _uart_bt_in_t* uart);
#define d2d_dir_reset(...) _ghost_method_d2d_dir_reset(self, ##__VA_ARGS__)
#define d2d_dir_get_last(...) _ghost_method_d2d_dir_get_last(self, ##__VA_ARGS__)
#define d2d_dir_get_dist_roc(...) _ghost_method_d2d_dir_get_dist_roc(self, ##__VA_ARGS__)
#define d2d_dir_add_dist(...) _ghost_method_d2d_dir_add_dist(self, ##__VA_ARGS__)
#define d2d_reset_all_dists() _ghost_method_d2d_reset_all_dists(self)
#define in_exits(...) _ghost_method_in_exits(self, ##__VA_ARGS__)
#define choose_exit(...) _ghost_method_choose_exit(self, ##__VA_ARGS__)
#define turn(...) _ghost_method_turn(self, ##__VA_ARGS__)
#define print_roc(...) _ghost_method_print_roc(self, ##__VA_ARGS__)
#line 162 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
#include "include/api/reaction_macros.h"
// Implementation of method d2d_dir_reset()
void _ghost_method_d2d_dir_reset(void* instance_args, dir_t dir) {
    _ghost_self_t* self = (_ghost_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 163 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    dist_arr* arr = &self->dir_to_dists[dir];
    for (int x = 0; x < arr->size; x++){
      arr->dist[x] = 0;
    }  
    arr->size = 0;
    arr->tail = 0;
}
#include "include/api/reaction_macros_undef.h"
#line 40 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.c"
#line 170 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
#include "include/api/reaction_macros.h"
// Implementation of method d2d_dir_get_last()
float _ghost_method_d2d_dir_get_last(void* instance_args, dir_t dir) {
    _ghost_self_t* self = (_ghost_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 171 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    dist_arr* arr = &self->dir_to_dists[dir];
    return arr->dist[(arr->tail - 1 + MAX_ENTRIES) % MAX_ENTRIES];
}
#include "include/api/reaction_macros_undef.h"
#line 51 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.c"
#line 174 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
#include "include/api/reaction_macros.h"
// Implementation of method d2d_dir_get_dist_roc()
float _ghost_method_d2d_dir_get_dist_roc(void* instance_args, dir_t dir) {
    _ghost_self_t* self = (_ghost_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 175 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    float sum = 0;
    dist_arr* arr = &self->dir_to_dists[dir];
    for(int x = 0; x < arr->size; x++){
      sum += arr->dist[x];
    }
    return arr->size == 0 ? 0 : sum / arr->size;
}
#include "include/api/reaction_macros_undef.h"
#line 66 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.c"
#line 182 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
#include "include/api/reaction_macros.h"
// Implementation of method d2d_dir_add_dist()
void _ghost_method_d2d_dir_add_dist(void* instance_args, dir_t dir, float dist) {
    _ghost_self_t* self = (_ghost_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 183 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    dist_arr* arr = &self->dir_to_dists[dir];
    arr->dist[arr->tail] = dist;
    arr->tail = (arr->tail + 1) % MAX_ENTRIES;
    arr->size = arr->size == MAX_ENTRIES ? MAX_ENTRIES : arr->size + 1;
}
#include "include/api/reaction_macros_undef.h"
#line 79 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.c"
#line 188 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
#include "include/api/reaction_macros.h"
// Implementation of method d2d_reset_all_dists()
void _ghost_method_d2d_reset_all_dists(void* instance_args) {
    _ghost_self_t* self = (_ghost_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 189 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    for (int x = 0; x < NUM_DIRS; x++){
      d2d_dir_reset(x);
    }
}
#include "include/api/reaction_macros_undef.h"
#line 91 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.c"
#line 195 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
#include "include/api/reaction_macros.h"
// Implementation of method in_exits()
bool _ghost_method_in_exits(void* instance_args, path_arr exits, dir_t dir) {
    _ghost_self_t* self = (_ghost_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 196 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    for (int x = 0; x < exits.size; x++){
      if (exits.path[x] == dir){
        return true;
      }
    }
    return false;
}
#include "include/api/reaction_macros_undef.h"
#line 106 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.c"
#line 203 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
#include "include/api/reaction_macros.h"
// Implementation of method choose_exit()
dir_t _ghost_method_choose_exit(void* instance_args, path_arr exits) {
    _ghost_self_t* self = (_ghost_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 204 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    // if last distance is invalid, keep going or pick a random exit -> will have to edit this
    if (self->last_distance < 0){
      return in_exits(exits, FORWARDS) ? FORWARDS : exits.path[rand() % exits.size];
    }
    // pick the best roc
    int size = self->dir_to_dists[self->curr_dir].size;
    if (in_exits(exits, FORWARDS) && size > 0 && d2d_dir_get_last(self->curr_dir) < 0){
      return FORWARDS;
    }
    float min_roc = FLT_MAX;
    dir_t min_dir = exits.path[0];
    // unlike in the simulation, I simply choose the first min_dir, since its pretty unlikely for distances to be the exact same (unless we give a closeness range?)
    for (int x = 0; x < exits.size; x++){
      dir_t rel = exits.path[x];
      float curr_roc = d2d_dir_get_dist_roc((self->curr_dir + rel) % NUM_DIRS);
      if (curr_roc < min_roc){
        min_roc = curr_roc;
        min_dir = rel;
      }
    }
    return min_dir;
}
#include "include/api/reaction_macros_undef.h"
#line 136 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.c"
#line 227 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
#include "include/api/reaction_macros.h"
// Implementation of method turn()
void _ghost_method_turn(void* instance_args, _motion_control_turn_angle_t* control, dir_t rel_dir) {
    _ghost_self_t* self = (_ghost_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 228 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    if (rel_dir != FORWARDS){
      self->curr_dir = (self->curr_dir + rel_dir) % NUM_DIRS;
      d2d_dir_reset(self->curr_dir);
      self->last_turn = lf_time_logical_elapsed();
      lf_set(control, 360 / NUM_DIRS * rel_dir);
    }
}
#include "include/api/reaction_macros_undef.h"
#line 151 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.c"
#line 236 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
#include "include/api/reaction_macros.h"
// Implementation of method print_roc()
void _ghost_method_print_roc(void* instance_args, _uart_bt_in_t* uart) {
    _ghost_self_t* self = (_ghost_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 237 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    static char buf[129];
    static const char* dirs[NUM_DIRS] = {"F", "L", "B", "R"};
    int n = 0;
    for (int x = 0; x < NUM_DIRS; x++){
      n += snprintf(buf + n, sizeof(buf) - n, "%s%s:%.2f", x ? "," : "", dirs[x], d2d_dir_get_dist_roc(x));
      if (n >= (int)sizeof(buf)) break;
    }
    lf_set(uart, buf);
}
#include "include/api/reaction_macros_undef.h"
#line 168 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.c"
#undef d2d_dir_reset
#undef d2d_dir_get_last
#undef d2d_dir_get_dist_roc
#undef d2d_dir_add_dist
#undef d2d_reset_all_dists
#undef in_exits
#undef choose_exit
#undef turn
#undef print_roc
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
#define d2d_dir_reset(...) _ghost_method_d2d_dir_reset(self, ##__VA_ARGS__)
#define d2d_dir_get_last(...) _ghost_method_d2d_dir_get_last(self, ##__VA_ARGS__)
#define d2d_dir_get_dist_roc(...) _ghost_method_d2d_dir_get_dist_roc(self, ##__VA_ARGS__)
#define d2d_dir_add_dist(...) _ghost_method_d2d_dir_add_dist(self, ##__VA_ARGS__)
#define d2d_reset_all_dists() _ghost_method_d2d_reset_all_dists(self)
#define in_exits(...) _ghost_method_in_exits(self, ##__VA_ARGS__)
#define choose_exit(...) _ghost_method_choose_exit(self, ##__VA_ARGS__)
#define turn(...) _ghost_method_turn(self, ##__VA_ARGS__)
#define print_roc(...) _ghost_method_print_roc(self, ##__VA_ARGS__)
void _ghostreaction_function_0(void* instance_args) {
    _ghost_self_t* self = (_ghost_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 249 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    self->valid_paths.path[0] = FORWARDS;
    self->valid_paths.path[1] = LEFT;
    self->valid_paths.path[2] = BACKWARDS;
    self->valid_paths.path[3] = RIGHT;
    self->valid_paths.size = NUM_DIRS;
    self->curr_dir = FORWARDS;
    srand((unsigned int)time(NULL));
    memset(self->dir_to_dists, 0, sizeof(self->dir_to_dists));
#line 201 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.c"
}
#undef d2d_dir_reset
#undef d2d_dir_get_last
#undef d2d_dir_get_dist_roc
#undef d2d_dir_add_dist
#undef d2d_reset_all_dists
#undef in_exits
#undef choose_exit
#undef turn
#undef print_roc
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
#define d2d_dir_reset(...) _ghost_method_d2d_dir_reset(self, ##__VA_ARGS__)
#define d2d_dir_get_last(...) _ghost_method_d2d_dir_get_last(self, ##__VA_ARGS__)
#define d2d_dir_get_dist_roc(...) _ghost_method_d2d_dir_get_dist_roc(self, ##__VA_ARGS__)
#define d2d_dir_add_dist(...) _ghost_method_d2d_dir_add_dist(self, ##__VA_ARGS__)
#define d2d_reset_all_dists() _ghost_method_d2d_reset_all_dists(self)
#define in_exits(...) _ghost_method_in_exits(self, ##__VA_ARGS__)
#define choose_exit(...) _ghost_method_choose_exit(self, ##__VA_ARGS__)
#define turn(...) _ghost_method_turn(self, ##__VA_ARGS__)
#define print_roc(...) _ghost_method_print_roc(self, ##__VA_ARGS__)
void _ghostreaction_function_1(void* instance_args) {
    _ghost_self_t* self = (_ghost_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct control {
        _motion_control_turn_angle_t* turn_angle;
    
    } control;
    struct uart {
        _uart_bt_in_t* bt_in;
    
    } uart;
    control.turn_angle = &(self->_lf_control.turn_angle);
    uart.bt_in = &(self->_lf_uart.bt_in);
    #line 259 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    print_roc(uart.bt_in);
    if (lf_time_logical_elapsed() > self->last_decision + TIME_BEFORE_ROTATE_ALLOWED){
      self->last_decision = lf_time_logical_elapsed();
      if (self->valid_paths.size == 1){
        // deadend. There is only one path
        dir_t rel_dir = self->valid_paths.path[0];
        turn(control.turn_angle, rel_dir);
        return;
      } else {
        dir_t rel_dir;
        // every once in a while try a new path time spent on current dir is too long
        if (lf_time_logical_elapsed() > self->last_turn + TIME_BEFORE_RESET){
          d2d_reset_all_dists();
          do {
            rel_dir = self->valid_paths.path[rand() % self->valid_paths.size];
          } while (rel_dir == FORWARDS);
        } else {
          rel_dir = choose_exit(self->valid_paths);
        }
        turn(control.turn_angle, rel_dir);
        return;
      }
    }
#line 259 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.c"
}
#undef d2d_dir_reset
#undef d2d_dir_get_last
#undef d2d_dir_get_dist_roc
#undef d2d_dir_add_dist
#undef d2d_reset_all_dists
#undef in_exits
#undef choose_exit
#undef turn
#undef print_roc
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
#define d2d_dir_reset(...) _ghost_method_d2d_dir_reset(self, ##__VA_ARGS__)
#define d2d_dir_get_last(...) _ghost_method_d2d_dir_get_last(self, ##__VA_ARGS__)
#define d2d_dir_get_dist_roc(...) _ghost_method_d2d_dir_get_dist_roc(self, ##__VA_ARGS__)
#define d2d_dir_add_dist(...) _ghost_method_d2d_dir_add_dist(self, ##__VA_ARGS__)
#define d2d_reset_all_dists() _ghost_method_d2d_reset_all_dists(self)
#define in_exits(...) _ghost_method_in_exits(self, ##__VA_ARGS__)
#define choose_exit(...) _ghost_method_choose_exit(self, ##__VA_ARGS__)
#define turn(...) _ghost_method_turn(self, ##__VA_ARGS__)
#define print_roc(...) _ghost_method_print_roc(self, ##__VA_ARGS__)
void _ghostreaction_function_2(void* instance_args) {
    _ghost_self_t* self = (_ghost_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct uwb {
        _uwb_dist_t* dist;
    
    } uwb;
    uwb.dist = self->_lf_uwb.dist;
    #line 284 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    if(self->last_distance >= 0){
      d2d_dir_add_dist(self->curr_dir, uwb.dist->value - self->last_distance);
    }
    self->last_distance = uwb.dist->value;
#line 293 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.c"
}
#undef d2d_dir_reset
#undef d2d_dir_get_last
#undef d2d_dir_get_dist_roc
#undef d2d_dir_add_dist
#undef d2d_reset_all_dists
#undef in_exits
#undef choose_exit
#undef turn
#undef print_roc
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
#define d2d_dir_reset(...) _ghost_method_d2d_dir_reset(self, ##__VA_ARGS__)
#define d2d_dir_get_last(...) _ghost_method_d2d_dir_get_last(self, ##__VA_ARGS__)
#define d2d_dir_get_dist_roc(...) _ghost_method_d2d_dir_get_dist_roc(self, ##__VA_ARGS__)
#define d2d_dir_add_dist(...) _ghost_method_d2d_dir_add_dist(self, ##__VA_ARGS__)
#define d2d_reset_all_dists() _ghost_method_d2d_reset_all_dists(self)
#define in_exits(...) _ghost_method_in_exits(self, ##__VA_ARGS__)
#define choose_exit(...) _ghost_method_choose_exit(self, ##__VA_ARGS__)
#define turn(...) _ghost_method_turn(self, ##__VA_ARGS__)
#define print_roc(...) _ghost_method_print_roc(self, ##__VA_ARGS__)
void _ghostreaction_function_3(void* instance_args) {
    _ghost_self_t* self = (_ghost_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct uwb {
        _uwb_dist_t* dist;
    
    } uwb;
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    struct uart {
        _uart_bt_in_t* bt_in;
    
    } uart;
    uwb.dist = self->_lf_uwb.dist;
    disp.line0 = &(self->_lf_disp.line0);
    uart.bt_in = &(self->_lf_uart.bt_in);
    #line 290 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/GhostControls.lf"
    static char buf[17];
    snprintf(buf, 17, "Dist: %.2f cm", uwb.dist->value);
    lf_set(disp.line0, buf);
#line 336 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_ghost.c"
}
#undef d2d_dir_reset
#undef d2d_dir_get_last
#undef d2d_dir_get_dist_roc
#undef d2d_dir_add_dist
#undef d2d_reset_all_dists
#undef in_exits
#undef choose_exit
#undef turn
#undef print_roc
#include "include/api/reaction_macros_undef.h"
_ghost_self_t* new__ghost() {
    _ghost_self_t* self = (_ghost_self_t*)lf_new_reactor(sizeof(_ghost_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_control_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_uart_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_uwb_width = -2;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_uwb.dist_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_uwb.dist_reactions[0] = &self->_lf__reaction_2;
    self->_lf_uwb.dist_reactions[1] = &self->_lf__reaction_3;
    self->_lf_uwb.dist_trigger.reactions = self->_lf_uwb.dist_reactions;
    self->_lf_uwb.dist_trigger.last_tag = NEVER_TAG;
    self->_lf_uwb.dist_trigger.number_of_reactions = 2;
    #ifdef FEDERATED
    self->_lf_uwb.dist_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _ghostreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _ghostreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _ghostreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__reaction_3.number = 3;
    self->_lf__reaction_3.function = _ghostreaction_function_3;
    self->_lf__reaction_3.self = self;
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    self->_lf__reaction_3.STP_handler = NULL;
    self->_lf__reaction_3.name = "?";
    self->_lf__reaction_3.mode = NULL;
    self->_lf__t_turn.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t_turn.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_turn_reactions[0] = &self->_lf__reaction_1;
    self->_lf__t_turn.reactions = &self->_lf__t_turn_reactions[0];
    self->_lf__t_turn.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t_turn.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t_turn.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t_turn.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
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

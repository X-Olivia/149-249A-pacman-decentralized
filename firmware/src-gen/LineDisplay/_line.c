#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/Line/Line.h"
#include "_line.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _linereaction_function_0(void* instance_args) {
    _line_self_t* self = (_line_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _line_calibrate_t* calibrate = self->_lf_calibrate;
    int calibrate_width = self->_lf_calibrate_width; SUPPRESS_UNUSED_WARNING(calibrate_width);
    #line 46 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/Line.lf"
    self->calibrating = calibrate->value;
#line 16 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/LineDisplay/_line.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _linereaction_function_1(void* instance_args) {
    _line_self_t* self = (_line_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _line_trigger_t* trigger = self->_lf_trigger;
    int trigger_width = self->_lf_trigger_width; SUPPRESS_UNUSED_WARNING(trigger_width);
    _line_reflect_t* reflect = &self->_lf_reflect;
    #line 50 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/Line.lf"
    if (self->calibrating) {
      line_sensors_calibrate();
      self->calibrated = true;
    } else {
      if (!self->calibrated) {
        // Calibration has not been performed, so read raw data.
        line_sensors_read();
        for (int i=0; i<5; i++) {
          reflect->value[i] = line_sensors[i];
        }
      } else {
        line_sensors_read_calibrated();
        for (int i=0; i<5; i++) {
          reflect->value[i] = line_sensors_calibrated[i];
        }
      }
      lf_set_present(reflect);
    }
#line 44 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/LineDisplay/_line.c"
}
#include "include/api/reaction_macros_undef.h"
_line_self_t* new__line() {
    _line_self_t* self = (_line_self_t*)lf_new_reactor(sizeof(_line_self_t));
    // Set input by default to an always absent default input.
    self->_lf_calibrate = &self->_lf_default__calibrate;
    // Set the default source reactor pointer
    self->_lf_default__calibrate._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_trigger = &self->_lf_default__trigger;
    // Set the default source reactor pointer
    self->_lf_default__trigger._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _linereaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _linereaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__calibrate.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__calibrate.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__calibrate_reactions[0] = &self->_lf__reaction_0;
    self->_lf__calibrate.reactions = &self->_lf__calibrate_reactions[0];
    self->_lf__calibrate.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__calibrate.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__calibrate.tmplt.type.element_size = sizeof(bool);
    self->_lf__trigger.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__trigger_reactions[0] = &self->_lf__reaction_1;
    self->_lf__trigger.reactions = &self->_lf__trigger_reactions[0];
    self->_lf__trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__trigger.tmplt.type.element_size = sizeof(bool);
    return self;
}

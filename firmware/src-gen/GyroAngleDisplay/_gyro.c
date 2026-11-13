#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/IMU/Gyro.h"
#include "_gyro.h"
// *********** From the preamble, verbatim:
#line 29 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/IMU.lf"
// Static global IMU instance struct.
static imu_inst_t imu_instance;
// Boolean to ensure the IMU instance is initialized only once.
static bool _pololu_robot_imu_initialized = false;
#line 13 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyro.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _gyroreaction_function_0(void* instance_args) {
    _gyro_self_t* self = (_gyro_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 42 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/IMU.lf"
    if (!_pololu_robot_imu_initialized) {
      _pololu_robot_imu_initialized = true;
      imu_init(&imu_instance);
    }
#line 27 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyro.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _gyroreaction_function_1(void* instance_args) {
    _gyro_self_t* self = (_gyro_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _gyro_trigger_t* trigger = self->_lf_trigger;
    int trigger_width = self->_lf_trigger_width; SUPPRESS_UNUSED_WARNING(trigger_width);
    _gyro_x_t* x = &self->_lf_x;
    _gyro_y_t* y = &self->_lf_y;
    _gyro_z_t* z = &self->_lf_z;
    #line 77 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/IMU.lf"
    axes_data_t gyro_data;
    imu_read_gyro(&imu_instance, &gyro_data);
    lf_set(x, gyro_data.x);
    lf_set(y, gyro_data.y);
    lf_set(z, gyro_data.z);
#line 44 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GyroAngleDisplay/_gyro.c"
}
#include "include/api/reaction_macros_undef.h"
_gyro_self_t* new__gyro() {
    _gyro_self_t* self = (_gyro_self_t*)lf_new_reactor(sizeof(_gyro_self_t));
    // Set input by default to an always absent default input.
    self->_lf_trigger = &self->_lf_default__trigger;
    // Set the default source reactor pointer
    self->_lf_default__trigger._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _gyroreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _gyroreaction_function_1;
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

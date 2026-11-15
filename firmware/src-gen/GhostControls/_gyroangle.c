#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/IMU/GyroAngle.h"
#include "_gyroangle.h"
// ***** Start of method declarations.
// ***** End of method declarations.
_gyroangle_self_t* new__gyroangle() {
    _gyroangle_self_t* self = (_gyroangle_self_t*)lf_new_reactor(sizeof(_gyroangle_self_t));
    // Set input by default to an always absent default input.
    self->_lf_trigger = &self->_lf_default__trigger;
    // Set the default source reactor pointer
    self->_lf_default__trigger._base.source_reactor = (self_base_t*)self;
    self->_lf__trigger.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__trigger.tmplt.type.element_size = sizeof(bool);
    return self;
}

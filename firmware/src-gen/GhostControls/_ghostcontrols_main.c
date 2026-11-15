#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/GhostControls/GhostControls.h"
#include "_ghostcontrols_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
_ghostcontrols_main_main_self_t* new__ghostcontrols_main() {
    _ghostcontrols_main_main_self_t* self = (_ghostcontrols_main_main_self_t*)lf_new_reactor(sizeof(_ghostcontrols_main_main_self_t));

    return self;
}

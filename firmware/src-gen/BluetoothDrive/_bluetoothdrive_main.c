#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/BluetoothDrive/BluetoothDrive.h"
#include "_bluetoothdrive_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
_bluetoothdrive_main_main_self_t* new__bluetoothdrive_main() {
    _bluetoothdrive_main_main_self_t* self = (_bluetoothdrive_main_main_self_t*)lf_new_reactor(sizeof(_bluetoothdrive_main_main_self_t));

    return self;
}

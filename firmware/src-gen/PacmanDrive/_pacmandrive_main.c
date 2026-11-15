#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/PacmanDrive/PacmanDrive.h"
#include "_pacmandrive_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
_pacmandrive_main_main_self_t* new__pacmandrive_main() {
    _pacmandrive_main_main_self_t* self = (_pacmandrive_main_main_self_t*)lf_new_reactor(sizeof(_pacmandrive_main_main_self_t));

    return self;
}

#ifndef _hellopico_main_H
#define _hellopico_main_H
#ifndef _HELLOPICO_MAIN_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_2075093711_H
#define TOP_LEVEL_PREAMBLE_2075093711_H
/*Correspondence: Range: [(52, 2), (53, 24)) -> Range: [(0, 0), (1, 24)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/HelloPico.lf)*/#include <stdio.h>
#include "pico/stdlib.h"
#endif // TOP_LEVEL_PREAMBLE_2075093711_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct hellopico_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int count;
    int end[0]; // placeholder; MSVC does not compile empty structs
} hellopico_self_t;
#endif
#endif

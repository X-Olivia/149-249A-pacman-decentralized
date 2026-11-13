#ifndef _HELLOPICO_MAIN_H
#define _HELLOPICO_MAIN_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_2075093711_H
#define TOP_LEVEL_PREAMBLE_2075093711_H
#include <stdio.h>
#include "pico/stdlib.h"
#endif // TOP_LEVEL_PREAMBLE_2075093711_H
typedef struct {
    struct self_base_t base;
#line 12 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/HelloPico/_hellopico_main.h"
    #line 59 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/HelloPico.lf"
    int count;
#line 15 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/HelloPico/_hellopico_main.h"
    reaction_t _lf__reaction_0;
    trigger_t _lf__t1;
    reaction_t* _lf__t1_reactions[1];
} _hellopico_main_main_self_t;
_hellopico_main_main_self_t* new__hellopico_main();
#endif // _HELLOPICO_MAIN_H

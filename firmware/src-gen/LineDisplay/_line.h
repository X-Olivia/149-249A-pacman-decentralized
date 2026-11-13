#ifndef _LINE_H
#define _LINE_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_910101408_H
#define TOP_LEVEL_PREAMBLE_910101408_H
#include <ir_sensors.h>
#endif // TOP_LEVEL_PREAMBLE_910101408_H
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _line_calibrate_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _line_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint16_t value[5];
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _line_reflect_t;
typedef struct {
    struct self_base_t base;
#line 53 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/LineDisplay/_line.h"
    #line 42 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/Line.lf"
    bool calibrating;
    #line 43 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/lf-packages/pololu-3pi-c/src/lib/Line.lf"
    bool calibrated;
#line 58 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/LineDisplay/_line.h"
    _line_calibrate_t* _lf_calibrate;
    // width of -2 indicates that it is not a multiport.
    int _lf_calibrate_width;
    // Default input (in case it does not get connected)
    _line_calibrate_t _lf_default__calibrate;
    _line_trigger_t* _lf_trigger;
    // width of -2 indicates that it is not a multiport.
    int _lf_trigger_width;
    // Default input (in case it does not get connected)
    _line_trigger_t _lf_default__trigger;
    _line_reflect_t _lf_reflect;
    int _lf_reflect_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__calibrate;
    reaction_t* _lf__calibrate_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__trigger;
    reaction_t* _lf__trigger_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _line_self_t;
_line_self_t* new__line();
#endif // _LINE_H

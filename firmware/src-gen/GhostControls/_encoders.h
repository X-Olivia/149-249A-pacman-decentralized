#ifndef _ENCODERS_H
#define _ENCODERS_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_302059473_H
#define TOP_LEVEL_PREAMBLE_302059473_H
#include <math.h>
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#endif // TOP_LEVEL_PREAMBLE_302059473_H
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
} _encoders_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _encoders_right_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _encoders_left_t;
typedef struct {
    struct self_base_t base;
#line 61 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_encoders.h"
#line 62 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_encoders.h"
    _encoders_trigger_t* _lf_trigger;
    // width of -2 indicates that it is not a multiport.
    int _lf_trigger_width;
    // Default input (in case it does not get connected)
    _encoders_trigger_t _lf_default__trigger;
    _encoders_right_t _lf_right;
    int _lf_right_width;
    _encoders_left_t _lf_left;
    int _lf_left_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__trigger;
    reaction_t* _lf__trigger_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _encoders_self_t;
_encoders_self_t* new__encoders();
#endif // _ENCODERS_H

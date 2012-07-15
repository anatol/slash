#ifndef SL_AST_H
#define SL_AST_H

#include "value.h"

typedef enum sl_node_type {
    SL_NODE_SEQ,
    SL_NODE_RAW,
    SL_NODE_ECHO,
    SL_NODE_ECHO_RAW,
    SL_NODE_VAR,
    SL_NODE_IVAR,
    SL_NODE_CVAR,
    SL_NODE_IMMEDIATE,
    SL_NODE_SELF,
    SL_NODE_CLASS,
    SL_NODE_DEF,
    SL_NODE_IF,
    SL_NODE_UNLESS,
    SL_NODE_FOR,
    SL_NODE_WHILE,
    SL_NODE_UNTIL,
    SL_NODE_SEND
}
sl_node_type_t;

struct sl_eval_ctx;
struct sl_node_base;

typedef struct sl_node_base {
    sl_node_type_t type;
    SLVAL(*eval)(struct sl_node_base*, struct sl_eval_ctx*);
}
sl_node_base_t;

typedef SLVAL(*sl_node_eval_fn_t)(struct sl_node_base* node, struct sl_eval_ctx*);

typedef struct sl_node_seq {
    sl_node_base_t base;
    sl_node_base_t** exprs;
    size_t expr_count;
}
sl_node_seq_t;

typedef struct sl_node_raw {
    sl_node_base_t base;
    SLVAL string;
}
sl_node_raw_t;

typedef struct sl_node_echo {
    sl_node_base_t base;
    sl_node_base_t* expr;
}
sl_node_echo_t;

typedef struct sl_node_var {
    sl_node_base_t base;
    sl_string_t* name;
}
sl_node_var_t;

typedef struct sl_node_immediate {
    sl_node_base_t base;
    SLVAL value;
}
sl_node_immediate_t;

typedef struct sl_node_class {
    sl_node_base_t base;
    sl_string_t* name;
    SLVAL extends;
    sl_node_base_t* body;
}
sl_node_class_t;

typedef struct sl_node_def {
    sl_node_base_t base;
    sl_node_base_t* on;
    sl_string_t* name;
    sl_string_t** args;
    size_t arg_count;
    sl_node_base_t* body;
}
sl_node_def_t;

typedef struct sl_node_if {
    sl_node_base_t base;
    sl_node_base_t* condition;
    sl_node_base_t* body;
    sl_node_base_t* else_body;
}
sl_node_if_t;

typedef struct sl_node_for {
    sl_node_base_t base;
    sl_node_base_t* lval;
    sl_node_base_t* expr;
    sl_node_base_t* body;
    sl_node_base_t* else_body;
}
sl_node_for_t;

typedef struct sl_node_while {
    sl_node_base_t base;
    sl_node_base_t* condition;
    sl_node_base_t* body;
}
sl_node_while_t;

typedef struct sl_node_send {
    sl_node_base_t base;
    sl_node_base_t* recv;
    sl_string_t* id;
    sl_node_base_t** args;
    size_t arg_count;
}
sl_node_send_t;

#endif
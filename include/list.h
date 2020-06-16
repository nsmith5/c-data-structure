#pragma once

#include <stdbool.h>

typedef struct {
    int len, cap, *buf;
} list;

// Constructor
list new_list();

// Simple array interface (get, set)
int get(list l, int index);
void set(list l, int index, int value);

// Stack-like interface
list push(list, int value);
int pop(list*);
bool empty(list);

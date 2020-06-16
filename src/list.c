#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

list _grow(list l) {
    // Double the capacity
    l.cap = l.cap << 1;
    int *newbuf = (int *)malloc(l.cap * sizeof(int));
    memcpy(newbuf, l.buf, l.len);
    free(l.buf);
    l.buf = newbuf;
    return l;
}

list _shrink(list l) {
    // 64 is the minimum size
    if (l.cap == 64) {
        return l;
    }

    // Divide the capacity by two.
    l.cap = l.cap >> 1;
    int *newbuf = (int *)malloc(l.cap * sizeof(int));
    memcpy(newbuf, l.buf, l.cap); 
    free(l.buf);
    l.buf = newbuf;
    return l;
}

list new_list() {
    list l = {
        .cap = 64,
        .len = 0,
        .buf = (int *)malloc(64 * sizeof(int))
    };
    return l;
}

int get(list l, int index) {
    return l.buf[index];
}

void set(list l, int index, int value) {
    l.buf[index] = value;
    return;
}

list push(list l, int x) {
    if (l.cap == l.len) {
        // Buffer is full, need to grow
        l = _grow(l);
    }
    l.buf[l.len] = x;
    l.len++;
    return l;
}

int pop(list* l) {
    int output = l->buf[l->len-1];
    l->len--; 
    if (l->cap == l->len << 1) {
        *l = _shrink(*l); 
    }
    return output;
}

bool empty(list l) {
    return l.len == 0;
}

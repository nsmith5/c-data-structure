#include <assert.h>

#include "list.h"

void test_list() {
    list l = new_list();
    l = push(l, 1);
    l = push(l, 2);
    l = push(l, 3);
    assert(!empty(l));
    assert(l.len == 3);
    assert(get(l, 0) == 1);
    set(l, 0, 10);
    assert(get(l, 0) == 10);

    assert(get(l, 0) == 1);
}


int main() {
    test_list();
}

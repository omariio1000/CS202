#include "clist.h"

int list::copySpecial(list & destination) {
    return copySpecial(destination.rear, rear);
}

int list::copySpecial(node *& dest, node * source) {
    if (!source) return 0;
    if (source -> data % 2 != 0) {
        return  1;
    }
    return 1;
    
}

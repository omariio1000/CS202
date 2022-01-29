#include "list.h"

int list::num_times(int match) {
   return num_times(head, match);
}

int list::num_times(node * head, int match) {
    if (!head) return 0;
    if (head -> data == match) return 1 + num_times(head -> next, match);
    return num_times(head -> next, match);
}

int list::displayAlmostAll() {
    if (!head) return 0;
    return displayAlmostAll(head);
}

int list::displayAlmostAll(node * current) {
    if (current == head) return head -> data + displayAlmostAll(current -> next);
    else if (current == tail) return tail -> data;
    cout << current -> data << endl;
    return displayAlmostAll(current -> next);
}

int list::removeAlmostAll() {
    return removeAlmostAll(head);
}

int list::removeAlmostAll(node *& current) {
    if (current -> next == tail) return 0;
    node * temp = current -> next;
    current -> next = nullptr;
    delete current;
    current = temp;
    return 1 + removeAlmostAll(current);
}

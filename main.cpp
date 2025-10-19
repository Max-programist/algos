#include "list.h"


int main() {
    struct list* head = add_front(NULL, 3);
    head = add_front(head, 2);
    head = add_front(head, 1);

    print_list(head);
    free_list(head);
    return 0;
}
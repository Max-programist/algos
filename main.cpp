#include "list.h"


int main() {
    struct list* head = add_front(NULL, 4);
    head = add_front(head, 6);
    head = add_front(head, 1);
    head = add_front(head, 2);
    head = add_front(head, 3);
    head = add_front(head, 5);

    Human only_man(46, "Optimus prime");
    only_man.hello();
    if(only_man.get_age() > 60) {
        std::cout << "retirement ON \n";
    }
    Human choose_gender(23, "enigma", 0); 
    choose_gender.hello();
    if(choose_gender.get_age() > 60) {
        std::cout << "retirement ON \n";
    }
    

    MyList spisok();

    struct list* temp = head->next;
    struct list* temp2 = temp->next;
    sort_list(head);
    std::cout << size_list(head) << "  \n";
   // swap_nodes(temp, temp2);
    print_list(head);
    free_list(head);
    return 0;
}
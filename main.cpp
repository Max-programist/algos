#include "list.h"


int main() {
    MyList example;   
    example.add_front(1);
    example.add_front(5);
    example.add_front(3);
    example.add_front(8);
    example.add_front(0);
    example.add_front(18);
    example.sort();
    example.show();
    example.free_list();
    return 0;
}
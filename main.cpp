#include "list.h"


int main() {
    MyList example;   
    example.add(2);
    example.add(5);
    example.add(3);
    example.add(1);
    example.show();
    example.remove(5);
    example.show();
    return 0;
}
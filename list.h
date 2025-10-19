#include <iostream>

struct list {    
    int elem;
    struct list* next;
};

struct list* create_elem(int elem);
struct list* del_elem(struct list* node, int elem);
struct list* add_back(struct list* node, int elem);
struct list* add_front(struct list* node, int elem);
void free_list(struct list* node); 
void print_list(struct list* node);
bool find_elem(struct list* node, int elem);

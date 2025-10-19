#include "list.h"

void print_list(struct list* node) {
    for(; node != NULL;) {
        std::cout << node->elem << std::endl;
        node = node->next;
    }
}

bool find_elem(struct list* node, int elem) {
    bool flag = false;
    for(; node != NULL; ) {
        if(elem == node->elem) {
            flag = true;
        } 
        node = node->next;
    }

    return flag;
}
// 0 ->  1  2 3
struct list* add_elem_head(struct list* node, int elem) {
    struct list* temp = (struct list*)malloc(sizeof(struct list));
    temp->next = node;
    temp->elem = elem;
    return temp;
}

//prinimaet: ykazatel na golovy spiska, elemer mashini kotoryu mi ydalyaem
//vozvrashaet ykazatel na golovy spiska
//                                             115
struct list*  del_elem(struct list* node, int elem) {
    struct list* result = node; 
    struct list* prev = NULL;
    for(; node != NULL;) {
        if(node->elem == elem) {
            if(node->next == NULL) {
                std::cout << "log111" << std::endl;
                prev->next = NULL;
                free(node);
                break; 
            } else if(prev == NULL) {
                    std::cout << "log222" << std::endl;

                result = node->next;
                free(node);
                break;
            }  else{
                std::cout << "log234567" << std::endl;
                prev->next = node->next;
                free(node);
                break;
            }

        }    
        prev = node;
        node = node->next;
    }
    
    return result;
}
    
struct list* create_elem(int elem) {
    struct list* result = (struct list*)malloc(sizeof(struct list));
    result->elem = elem;
    result->next = NULL;
    return result;
}

void free_list(struct list* node) {
    for(; node != NULL; ) {
        struct list* temp = node;
        node = node->next;
        free(temp);
        temp = NULL;
    }
}

struct list* add_back(struct list* node, int elem) {
    struct list* result = node;
    if(node == NULL)  {
        node = create_elem(elem);
        result = node;
    } else {
        for(; node != NULL;) {
            if(node->next == NULL) {
                node->next = create_elem(elem);
                break;
            }
            node = node->next;
        }
    }

    return result;
}

struct list* add_front(struct list* node, int elem) {
    struct list* result = node;
    if(node == NULL)  {
        node = create_elem(elem);
        result = node;
    } else { //   2 3
        struct list* temp = node;
        node = create_elem(elem);
        result = node;
        node->next = temp;
    }
    return result;
}

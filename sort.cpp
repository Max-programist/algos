#include <iostream>
#include <vector>

struct list {
    int car;
    struct list* next;
};

bool find(const std::vector<int> &arr, int num);
void sort(std::vector<int> &arr);
void reverso(std::vector<int> &arr);
void insert_left(int *arr, int num, int elem);
void print_list(struct list* node);
bool find_car(struct list* node, int nom);
struct list*  del_elem(struct list* node, int nom);
struct list* create_elem(int nom);
void free_list(struct list* node); 
struct list* add_back(struct list* node, int nom);

int main() {
    struct list* head = add_back(NULL, 1);
    add_back(head, 2);
    add_back(head, 3);


    print_list(head);
    free_list(head);
    return 0;
}

void sort(std::vector<int> &arr) {
    int temp = 0;
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                // count += 1;
                // std:: cout << count << std::endl;
            }
        }
        
    }

}
// 2 15 27 126 486 

bool find(const std::vector<int> &arr, int num) {
    
    int l = 0;
    int r = arr.size() - 1;
    int mid = (r + l) / 2;
    //                          lm    r
    //  8 12 13 68 91 96 99 118 163 1008
    for( ; l != mid; ) {
        if(num == arr[mid] || num == arr[l] || num == arr[r]) {
            return true;
        } else if(num > arr[mid]) {
            l = mid;
        } else {
            r = mid;
        } 
        mid = (l + r) / 2;

    }
    
    return false;
}
// i    m        j 
// 486 15 27 126 2 ??  

void reverso(std::vector<int> &arr) {
    int temp = 0;
    for(int i = 0; i < arr.size() / 2; i++) {
        temp = arr[i]; 
        arr[i] = arr[arr.size() - i - 1];
        arr[arr.size() - i - 1] = temp;
    }

}

void insert_left(int *arr, int num, int elem) {

    for(int i = num - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }

    arr[0] = elem;


}


void print_list(struct list* node) {

    for(; node != NULL;) {
        std::cout << node->car << std::endl;
        node = node->next;
    }
}


bool find_car(struct list* node, int nom) {
    bool flag = false;
    for(; node != NULL; ) {
        if(nom == node->car) {
            flag = true;
        } 
        node = node->next;
    }

    return flag;
}
// 0 ->  1  2 3
struct list* add_elem_head(struct list* node, int nom) {
    struct list* temp = (struct list*)malloc(sizeof(struct list));
    temp->next = node;
    temp->car = nom;
    return temp;
}

//prinimaet: ykazatel na golovy spiska, nomer mashini kotoryu mi ydalyaem
//vozvrashaet ykazatel na golovy spiska
//                                             115
struct list*  del_elem(struct list* node, int nom) {
    struct list* result = node; 
    struct list* prev = NULL;
    for(; node != NULL;) {
        if(node->car == nom) {
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
    


struct list* create_elem(int nom) {
    struct list* result = (struct list*)malloc(sizeof(struct list));
    result->car = nom;
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

struct list* add_back(struct list* node, int nom) {
    struct list* result = node;
    if(node == NULL)  {
        node = create_elem(nom);
        result = node;
    } else {
        for(; node != NULL;) {
            if(node->next == NULL) {
                node->next = create_elem(nom);
                break;
            }
            node = node->next;
        }
    }

    return result;
}
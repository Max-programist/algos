#include <iostream>

struct list {    
    int elem;
    struct list* next;
};

class MyList {
    private:
        struct list* head;
        struct list* create_elem(int elem) {
            struct list* result = (struct list*)malloc(sizeof(struct list));
            result->elem = elem;
            result->next = NULL;
            return result;  
              
        }
    public:
    //2->5->3->1->NULL 
        void remove(int elem) {
            struct list* temp = head;
            struct list* prev = NULL;
            for(;temp != NULL;) {
                
                if((*temp).elem == elem) {
                    if(prev != NULL) {
                        prev->next = temp->next;
                    } else {
                        head = temp->next;
                    }
                    free(temp);
                    temp = NULL;
                    break;   
                }
                prev = temp; 
                if(temp != NULL) {
                    temp = temp->next;
                }
            }
        }

        void add(int elem) {
            struct list* node = create_elem(elem);
            if(head == NULL) {
                head = node;
            } else {
                struct list* temp = head; 
                for(;temp->next != NULL;) {
                    temp = temp->next;
                }
                temp->next = node;
            }
        }
        void show() {// 100 21 377 NUll
            struct list* temp = head;
            for(; temp != NULL; ) {
                std::cout << temp->elem << "->" ;
                temp = temp->next;
            } 
            std::cout << "NULL"<< std::endl; 
        }
        MyList() {
            head = NULL;
            std::cout << "Dosvidos \n";

        };
        ~MyList() {
            std::cout << "Gabella \n";
            for(; head != NULL; ) {
                struct list* temp = head;
                head = head->next;
                free(temp);

            } 
        };

};


class Human {
    private:
        int m_age;
        std::string m_name;
        bool m_gender;
    public:
        Human(int age, std::string name) {
            m_age = age;
            m_name = name;
            m_gender = 1;
        };
        Human(int age, std::string name, bool gender) {
            m_age = age;
            m_name = name;
            m_gender = 1;
        };
        void hello() {
            std::cout << "i`m human,i have " << m_age << " ages. My name is " << m_name << "My gender is:" << m_gender << "\n";
        }
        void set_age(int age) {
            if(age < 0 || age > 150) {
                std::cout << "err: invalide age \n";
                std::terminate();
            }
            m_age = age;

        }
        void set_name(std::string name) {
            if(name.size() == 0) {
                std::cout << "err: invalide name \n";
                std::terminate();
            }
            m_name = name;
        }
        void set_gender(bool gender) {
            m_gender = gender;
        }
        
        int get_age() {
            return m_age;
        }

        std::string get_name() {
            return m_name;
        }

        bool get_gender() {
            return m_gender;
        }

};

struct list* del_elem(struct list* node, int elem);
struct list* add_back(struct list* node, int elem);
struct list* add_front(struct list* node, int elem);
void free_list(struct list* node); 
bool find_elem(struct list* node, int elem);
bool swap_nodes(struct list* node1, struct list* node2);
void sort_list(struct list* head);
int size_list(struct list* head);


#include <iostream>
#include <vector>


bool find(const std::vector<int> &arr, int num);
void sort(std::vector<int> &arr);
void reverso(std::vector<int> &arr);
void insert_left(int *arr, int num, int elem);

int main() {
    std::cout << "Hello World" << std::endl;
                               
    //std::vector<int> arr = {486, 15, 27, 126, 2};

    // sort(arr);
    // std:: cout << find(arr, 235678986789) << std::endl;
    //reverso(arr);
    int arr[7] = {0, 65, 11, 35, 74, 95};
    
    insert_left(arr, 6, 110);


    for(int i = 0; i < 7; i++) {
        std::cout << arr[i] << " ";
    }
    std:: cout << std::endl;

    return 0;
}
//ob = 0       
//                                  i = 0;     j = 1
//                                     85        49
//min = 0
// arr[j] = 49
// 85, 49, 20, 35, 432, 99, 81, 47
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

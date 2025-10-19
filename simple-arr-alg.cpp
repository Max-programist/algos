#include "simple-arr-alg.h"

void sort(std::vector<int> &arr) {
    int temp = 0;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }   
    }
}


bool find(const std::vector<int> &arr, int num) {
    int l = 0;
    int r = arr.size() - 1;
    int mid = (r + l) / 2;
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


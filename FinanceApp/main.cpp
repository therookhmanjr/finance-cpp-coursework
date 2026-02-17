#include <iostream>
using namespace std;

struct Operation {
    int id;
    char type;
    double amount;
    char category[50];
    char date[20];
};

void addOperation(Operation*& arr, int& size, const Operation& op) {
    Operation* newArr = new Operation[size + 1];
    
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    
    newArr[size] = op;
    
    delete[] arr;
    arr = newArr;
    size++;
}

void removeOperation(Operation*& arr, int& size, int index) {
    if (index < 0 || index >= size) {
        return;
    }
    
    Operation* newArr = new Operation[size - 1];
    
    for (int i = 0, j = 0; i < size; i++) {
        if (i == index) continue;
        newArr[j++] = arr[i];
    }
    
    delete[] arr;
    arr = newArr;
    size--;
}

int main(int argc, const char * argv[]) {
    Operation* operations = nullptr;
    int size = 0;
    
    Operation op1 = {1, 'I', 1500, "Salary", "2026-02-15"};
    Operation op2 = {2, 'E', 25, "Food", "2026-02-15"};
    Operation op3 = {3, 'E', 12, "Transport", "2026-02-16"};
    
    addOperation(operations, size, op1);
    addOperation(operations, size, op2);
    addOperation(operations, size, op3);
    
    cout << "Size after add: " << size << endl;
    
    removeOperation(operations, size, 1);
    
    cout << "Size after remove: " << size << endl;
    
    delete[] operations;
    return 0;
}

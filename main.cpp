#include <iostream>
#include<vector>
#include<map>
#include<string>
#include"printVector.h"
#include"QuickSort.h"
using namespace std;

int main(){
    int n = 10;
    vector<int> test{3, 1, 4, 7, 2, 3, 6, 9};
    quickSort<int>(test, 0, test.size() - 1);
    printVector(test);
    return 0;
}
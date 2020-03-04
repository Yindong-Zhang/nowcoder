//
// Created by so_go on 2020/3/4.
//

#ifndef UNTITLED_PRINTVECTOR_H
#define UNTITLED_PRINTVECTOR_H
#include<iostream>
#include<vector>
using namespace std;

template <class T>
void printVector(vector<T> &vec){
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i] << ' ';
    }
    cout << endl;
}
#endif //UNTITLED_PRINTVECTOR_H

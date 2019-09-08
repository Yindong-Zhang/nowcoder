//
// Created by yindong on 19-9-8.
//

#ifndef UNTITLED_TEST_H
#define UNTITLED_TEST_H
#include<vector>
#include<iostream>
using namespace std;

int test(){
    vector<int> a{1, 2, 3, 4};
    int c = 0, d = 1;
//    int &cp = a[1];
//    int &cp = a[2];
    cout << c << ' ' << d << endl;
    for(int i = 0; i < a.size(); i++){
        int &ai = a[i];
        cout << &ai << endl;
        cout << ai << endl;
    }
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << endl;
    }
    return 0;
}
#endif //UNTITLED_TEST_H

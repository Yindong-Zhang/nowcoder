//
// Created by so_go on 2020/4/23.
//

#ifndef UNTITLED_NUMBERCONVERSE_H
#define UNTITLED_NUMBERCONVERSE_H
#include<bits/stdc++.h>
using namespace std;
int converse(int n){
    int res = 1;
    while(n > 0){
        res *= n % 10;
        n /= 10;
    }
    return res;
}
int converseCount(int n){
    int count = 0;
    while(n > 9){
        cout << n << endl;
        n = converse(n);
        count++;
    }
    return count;
}
int numberConverse(){
    int n;
    cin >> n;
    cout << converseCount(n);
    return 0;
}
#endif //UNTITLED_NUMBERCONVERSE_H

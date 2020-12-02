//
// Created by so_go on 2020/8/13.
//

#ifndef UNTITLED_TRANSFORMWORDS_H
#define UNTITLED_TRANSFORMWORDS_H
#include<bits/stdc++.h>
using namespace std;

bool solve(string &A, string &B){
    map<char, int> mA, mB;
    for(char ch: A){
        if(mA.find(ch) == mA.end()){
            mA[ch] = 1;
        }
        else{
            mA[ch]++;
        }
    }
    for(char ch: B){
        if(mB.find(ch) == mB.end()){
            mB[ch] = 1;
        }
        else{
            mB[ch]++;
        }
    }
    for(auto ptr = mA.begin(); ptr != mA.end(); ptr++){
        char ch = ptr->first;
        if(mB.find(ch) == mB.end()){
            return false;
        }
        if(mB[ch] != ptr->second){
            return false;
        }
    }
    return true;
}

int transformWord(){
    string A, B;
    cin >> A;
    cin >> B;
    if(solve(A, B)){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
#endif //UNTITLED_TRANSFORMWORDS_H

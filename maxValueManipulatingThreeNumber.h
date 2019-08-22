//
// Created by yindong on 19-8-22.
//

#ifndef UNTITLED_MAXVALUEMANIPULATINGTHREENUMBER_H
#define UNTITLED_MAXVALUEMANIPULATINGTHREENUMBER_H
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solve(int v[3]){
    sort(v, v + 3);
    if(v[2] == 1){
        return 3;
    }
    else if(v[0] == 1){
        return (v[0] + v[1]) * v[2];
    }
    else{
        return v[0] * v[1] * v[2];
    }
}

int maxValue(){
    int v[3], value;
    for(int i = 0; i < 3; i++){
        cin >> value;
        v[i] = value;
    }
    cout << solve(v) << endl;
}
#endif //UNTITLED_MAXVALUEMANIPULATINGTHREENUMBER_H

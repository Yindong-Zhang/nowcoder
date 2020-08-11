//
// Created by so_go on 2020/8/2.
//

#ifndef UNTITLED_PINDUODUO01_0802_H
#define UNTITLED_PINDUODUO01_0802_H
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &D, int K){
    int k = K;
    int rt_cnt = 0;
    for(int d: D){
        k = k - d;
        if(k == 0){
            cout << "paradox" << endl;
            return;
        }
        else if(k < 0){
            rt_cnt++;
            k = -k;
        }
    }
    cout << k << ' ' << rt_cnt << endl;
}

int pdd_1(){
    int N, K;
    cin >> K >> N;
    vector<int> D(N, 0);
    for(int i = 0; i < N; ++i){
        cin >> D[i];
    }
    solve(D, K);
    return 0;
}
#endif //UNTITLED_PINDUODUO01_0802_H

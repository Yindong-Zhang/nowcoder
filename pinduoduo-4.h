//
// Created by so_go on 2020/9/1.
//

#ifndef UNTITLED_PINDUODUO_4_H
#define UNTITLED_PINDUODUO_4_H
#include<bits/stdc++.h>
using namespace std;

int solve(int N, vector<int> Y){
    int cnt = 0;
    for(int i = 1; i <= N; ++i){
        bool flag= false;
        for(int j = 0; j < Y.size(); ++j){
            if(i % Y[j] == 0){
                flag = true;
                continue;
            }
        }
        if(flag){
            cnt++;
        }
    }
    return cnt;
}
int pinduoduo_4(){
    int N, M;
    cin >> N >> M;
    vector<int> Y(M, 0);
    for(int i = 0; i < M; ++i){
        cin >> Y[i];
    }
    cout << solve(N, Y);
    return 0;
}
#endif //UNTITLED_PINDUODUO_4_H

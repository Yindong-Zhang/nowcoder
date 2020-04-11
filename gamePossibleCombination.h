//
// Created by so_go on 2020/4/11.
//
// 网易互娱第二题
#ifndef UNTITLED_GAMEPOSSIBLECOMBINATION_H
#define UNTITLED_GAMEPOSSIBLECOMBINATION_H
#include<bits/stdc++.h>
//#include"printVector.h"
using namespace std;
int solve(vector<int> P, int N, int M){
    vector<vector<int>> dp(N, vector<int>(M + 1, 0));
    for(int m = 0; m <= M; ++m){
        if(m % P[0] == 0){
            dp[0][m] = 1;
        }
    }
    for(int i = 0; i < N; ++i){
        dp[i][0] = 1;
    }
//    printVector(dp[0]);
    for(int i = 1; i < N; ++i){
        for(int m = 1; m <= M; ++m){
            for(int k = 0; k <= m / P[i]; ++k){
                dp[i][m] += dp[i - 1][ m - k * P[i]];
            }
        }
//        printVector(dp[i]);
    }
    return dp[N - 1][M];
}
int gameBuy(){
    int N, M;
    cin >> N >> M;
    vector<int> P(N, 0);
    for(int i = 0; i < N; ++i){
        cin >> P[i];
    }
    cout << solve(P, N, M) << endl;
}
#endif //UNTITLED_GAMEPOSSIBLECOMBINATION_H

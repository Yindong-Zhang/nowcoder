//
// Created by so_go on 2020/8/6.
//

#ifndef UNTITLED_JINDONG_1_H
#define UNTITLED_JINDONG_1_H
#include<bits/stdc++.h>
#include<stdio.h>
#include"printVector.h"
using namespace std;
int longestCommonSubSequence(vector<char> &X, vector<char> &Y){
    int N = X.size();
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j ){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(X[i] == Y[j]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    return dp[N][N];
}
int jindong1(){
    int N;
    cin >> N;
    vector<char> X(N), Y(N);
    for(int i = 0; i < N; ++i){
        cin >> X[i];
    }
    for(int i = 0; i < N; ++i){
        cin >> Y[i];
    }
    printVector(X);
    printVector(Y);
    int ls = longestCommonSubSequence(X, Y);
    float res = float(ls) / N;
    printf("%.2f ", res);
    if(res <= 0.5){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
#endif //UNTITLED_JINDONG_1_H

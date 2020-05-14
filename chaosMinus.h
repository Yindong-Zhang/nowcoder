//
// Created by so_go on 2020/4/16.
//

#ifndef UNTITLED_CHAOSMINUS_H
#define UNTITLED_CHAOSMINUS_H
#include<bits/stdc++.h>
using namespace std;

double solve(int a0, int n){
    vector<vector<double>> dp(n, vector<double>(a0 + 1, 0));
    for(int i = 0; i <= a0; ++i){
        dp[0][i] = 1. / (a0 + 1);
    }
    for(int i = 1; i < n; ++i){
        for(int j = 0; j <= a0; ++j){
            for(int k = a0; k >= j; k--){
                dp[i][j] += dp[i - 1][k] * 1. / (k + 1);
            }
        }
    }
    return dp[n - 1][0];
}

int chaosMinus(){
    int n, a0;
    cin >> n >> a0;
    double res = solve(a0, n);
    printf("%.5f", res);
    return 0;
}
#endif //UNTITLED_CHAOSMINUS_H

//
// Created by so_go on 2020/3/12.
//

#ifndef UNTITLED_MODARRAY_H
#define UNTITLED_MODARRAY_H
#define M 1000000007
#include<vector>
#include<iostream>
using namespace std;

int solve(int n, int k, int l, int r){
    vector<int> g(k, 0);
    int a = l / k, b= r / k;
    int lm = l % k, rm = r % k;
    for (int i = 0; i < k; ++i) {
        if(i >= lm and i > rm){
            g[i] = b - a;
        }
        else if( i >= lm and i <= rm){
            g[i] = b - a + 1;
        } else if( i < l and i <= r){
            g[i] = b - a;
        }
        else if(i < l and i > r){
            g[i] = b - a - 1;
        }
    }
    vector<vector<int>> dp(n, vector<int>(k, 0));
    for(int ki = 0; ki < k; ++ki){
        dp[0][ki] = g[ki];
    }
    for(int ni = 1; ni < n; ++ni){
        for(int ki = 0; ki < k; ++ki){
            for(int j = 0; j < k; ++j){
                for(int w = 0; w < g[(ki - j) % k]; ++w){
                    dp[ni][ki] = (dp[ni][ki] + dp[ni - 1][j] ) % M;
                }
            }
        }
    }
    return dp[n-1][0];
}

int main(){
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    cout << solve(n, k, l, r) << endl;
    return 0;
}
#endif //UNTITLED_MODARRAY_H

//
// Created by yindong on 19-8-29.
//
// 01 背包
// dp 填表法
#ifndef UNTITLED_WINDPOWERSTATION_H
#define UNTITLED_WINDPOWERSTATION_H
#include<vector>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int dp(vector<int> weights, vector<int> caps, int capacity){
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int l = 1; l <= capacity; l++){
            if( l < caps[i]){
                dp[i][l] = dp[i - 1][l];
            }
            else{
                dp[i][l] = max(dp[i - 1][l], dp[i - 1][l - caps[i]] + weights[i]);
            }
        }
    }
    return dp[n][capacity];

}
int windPowerStation(){
    string s;
    vector<int> w, v;
    int wi, vi;
    getline(cin, s);
    stringstream ss(s);
    while(ss >> vi){
        v.push_back(vi);
    }
    getline(cin, s);
    stringstream ss2(s);
    while(ss2 >> wi){
        w.push_back(wi);
    }
    int cap;
    cin >> cap;
    cout << dp(w, v, cap) << endl;
    return 0;
}
#endif //UNTITLED_WINDPOWERSTATION_H

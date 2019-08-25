//
// Created by so_go on 2019/8/13.
//

#ifndef UNTITLED_LONGESTCOMMONSUBSEQUENCE_H
#define UNTITLED_LONGESTCOMMONSUBSEQUENCE_H
#include<string>
#include<vector>
#include<iostream>
using namespace std;

int longestCommonSubsequence(string a, string b){
    int size_a = a.size() + 1, size_b = b.size() + 1;
    vector<vector<int>> dp(size_a, vector<int>(size_b, 0));
    for(int i = 1; i < size_a; i++){
        for(int j = 1; j < size_b; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
            }
        }
    }
//    for(int i = 0; i < size_a; i++){
//        for(int j = 0; j < size_b; j++){
//            cout << dp[i][j] << ' ';
//        }
//        cout << endl;
//    }
    return dp[size_a - 1][size_b - 1];
}


#endif //UNTITLED_LONGESTCOMMONSUBSEQUENCE_H

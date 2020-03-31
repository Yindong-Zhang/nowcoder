//
// Created by so_go on 2020/3/22.
//

#ifndef UNTITLED_STRINGSIMILARITY_H
#define UNTITLED_STRINGSIMILARITY_H
#include<bits/stdc++.h>
using namespace std;

float solve(string &a, string &b){
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for(int i = 0; i <= a.size(); ++i){
        dp[i][0] = i;
    }
    for(int j = 0; j <= b.size(); ++j){
        dp[0][j] = j;
    }
    for(int i = 1; i <= a.size(); ++i){
        for(int j = 1; j <= b.size(); ++j){
            int tmp = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = min(dp[i - 1][j - 1], tmp);
            }
            else{
                dp[i][j] = min(dp[i - 1][j - 1] + 1, tmp);
            }
        }
    }
    return 1. / (dp[a.size()][b.size()] + 1);
}
int stringSimilarity(){
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << solve(a, b) << endl;
    return 0;
}
#endif //UNTITLED_STRINGSIMILARITY_H

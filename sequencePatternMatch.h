//
// Created by LCY on 2019/10/23.
//

#ifndef UNTITLED_SEQUENCEPATTERNMATCH_H
#define UNTITLED_SEQUENCEPATTERNMATCH_H

#include<string>
#include<iostream>
#include<vector>
using namespace std;

void solve(string s, string p){
    int nrows = s.size() + 1, ncols = p.size() + 1;
    vector<vector<int>> dp(nrows, vector<int>(ncols, 0));

    for(int j = 0; j < s.size(); j++){
        if(s[j] == p[0]){
            dp[j][0] = 1;
        }
        else{
            dp[j][0] = dp[j - 1][0] > 0 ? dp[j - 1][0] + 1 : 0;
        }

    }
    for(int i = 1; i < ncols; i++){
        for(int j = 1; j < nrows; j++){
            if(s[j] == p[i]){
                dp[j][i] = dp[j -1][i - 1] > 0 ? dp[j - 1][i - 1] + 1 : 0;
            }
            else{
                dp[j][i] = dp[j - 1][i] > 0 ? dp[j - 1][i] + 1 : 0;
            }
        }
    }
    int minLen = 1000;
    int start = -1, end = -1;
    for(int j = 0; j < s.size(); j++){
        if(dp[j][p.size()] > 0 and dp[j][p.size()] < minLen){
            minLen = dp[j][p.size() - 1];
            start = j - minLen + 1;
            end = j;
        }
    }
    cout << start <<  ' ' << end << endl;
}

int sequencePatternMatch(){
    string s, p;
    while(cin >> s >> p){
        solve(s, p);
    }
}

#endif //UNTITLED_SEQUENCEPATTERNMATCH_H

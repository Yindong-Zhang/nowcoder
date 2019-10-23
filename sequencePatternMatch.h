//
// Created by LCY on 2019/10/23.
//
/*
 * 题目描述
给定文本text和待匹配字符串pattern，二者皆只包含小写字母，并且不为空。
在text中找出匹配pattern的最短字符串，匹配指按序包含pattern，但不要求pattern连续。
如text为abaacxbcbbbbacc，pattern为cbc，text中满足条件的是abaacxbcbbbbacc下划线部分。
输入描述:
多行，每行一个text和一个pattern，用空格分隔。
保证1<=|text|,|pattern|<=1000，Σ|text|,Σ|pattern|<=10000。
输出描述:
输出最短匹配序列起止位置（位置下标从0开始），用空格分隔。若有多个答案，输出起止位置最小的答案；若无满足条件的答案，则起止均为-1。
示例1
输入
复制
abaacxbcbbbbacc cbc
abc x
aaabcac ac
输出
复制
4 7
-1 -1
0 4
// 答案有问题。。。
 */
#ifndef UNTITLED_SEQUENCEPATTERNMATCH_H
#define UNTITLED_SEQUENCEPATTERNMATCH_H

#include<string>
#include<iostream>
#include<vector>
using namespace std;

void solve(string s, string p){
    int nrows = s.size() + 1, ncols = p.size() + 1;
    vector<vector<int>> dp(nrows, vector<int>(ncols, 0));

    for(int j = 1; j < nrows; j++){
        if(s[j - 1] == p[0]){
            dp[j][1] = 1;
        }
        else{
            dp[j][1] = dp[j - 1][1] > 0 ? dp[j - 1][1] + 1 : 0;
        }

    }
    for(int i = 2; i < ncols; i++){
        for(int j = 1; j < nrows; j++){
            if(s[j - 1] == p[i - 1]){
                dp[j][i] = dp[j -1][i - 1] > 0 ? dp[j - 1][i - 1] + 1 : 0;
            }
            else{
                dp[j][i] = dp[j - 1][i] > 0 ? dp[j - 1][i] + 1 : 0;
            }
        }
    }
    int minLen = 1000;
    int start = -1, end = -1;
    for(int j = 1; j < nrows; j++){
        if(dp[j][p.size()] > 0 and dp[j][p.size()] < minLen){
            minLen = dp[j][p.size()];
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
    return 0;
}

#endif //UNTITLED_SEQUENCEPATTERNMATCH_H

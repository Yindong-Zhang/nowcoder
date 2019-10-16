//
// Created by LCY on 2019/10/16.
//
/*
 * 题目描述
给定两个字符串，已知可以使用三种方式进行变换
1. 插入一个字符
2. 删除一个字符
3. 更改一个字符
请设计一个算法，找到两个字符串之间的经历几次最小变换，可以字符串1转换成字符串2
输入描述:
输入两个字符串，字符串的长度<=1000
输出描述:
最小变换次数
示例1
输入
复制
hello
helle
输出
复制
1
 */
#ifndef UNTITLED_MINEDITLENGTH_H
#define UNTITLED_MINEDITLENGTH_H
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int solve(string a, string b){
    int la = a.size(), lb = b.size();
    vector<vector<int>> dp(la + 1, vector<int>(lb + 1, 0));
    for(int i = 0; i <= la; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j <= lb; j++){
        dp[0][j] = j;
    }
    int tmp;
    for(int i = 1; i <= la; i++){
        for(int j = 1; j <= lb; j++){
            tmp = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = min(tmp, dp[i - 1][j - 1]);
            }
            else{
                dp[i][j] = min(tmp, dp[ i - 1][j - 1] + 1);
            }
        }
    }
    return dp[la][lb];
}
int minEditLength(){
    string a, b;
    cin>> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}
#endif //UNTITLED_MINEDITLENGTH_H

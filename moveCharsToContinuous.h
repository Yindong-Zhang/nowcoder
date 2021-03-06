//
// Created by yindong on 19-9-9.
//
/*
 *
 * 链接：https://www.nowcoder.com/questionTerminal/8da0ea4b4853464795f5c32634a1b06f
来源：牛客网

编码题】字符串S由小写字母构成，长度为n。定义一种操作，每次都可以挑选字符串中任意的两个相邻字母进行交换。询问在至多交换m次之后，字符串中最多有多少个连续的位置上的字母相同？


输入描述:

第一行为一个字符串S与一个非负整数m。(1 <= |S| <= 1000, 1 <= m <= 1000000)



输出描述:

一个非负整数，表示操作之后，连续最长的相同字母数量。

示例1
输入

abcbaa 2

输出

2

说明

使2个字母a连续出现，至少需要3次操作。即把第1个位置上的a移动到第4个位置。
所以在至多操作2次的情况下，最多只能使2个b或2个a连续出现。
 */
#ifndef UNTITLED_MOVECHARSTOCONTINUOUS_H
#define UNTITLED_MOVECHARSTOCONTINUOUS_H
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int solve(string s, int m){
    vector<vector<int>> inds(26, vector<int>());
    for(int i = 0; i < s.size(); i++){
        inds[s[i] - 'a'].push_back(i);
    }
    vector<vector<vector<int>>> dp(26);
    for(int i = 0; i < 26; i++){
        int n =  inds[i].size();
        if(n > 0){
            vector<vector<int>> dpi(n, vector<int>(n , 0));

            for(int k = 1; k < n; k++){
                for(int left = 0; left < n - k; left++){
                    int right = left + k;
                    dpi[left][right] = dpi[left + 1][right - 1] + inds[i][right] - inds[i][left] - right + left;
                }
            }

            dp[i] = dpi;
        }
    }
    int res = 0;
    for(int i = 0; i < 26; i++){
        int n = dp[i].size();
        for(int row = 0; row < n; row++){
            for(int col = row + 1; col < n; col++){
               if(dp[i][row][col] <= m){
                   if(col - row + 1 > res){
                       res = col - row + 1;
                   }
               }
            }

        }
    }
    return res;
}

int moveChartoContinues(){
    string s;
    int m;
    cin >> s >> m;
    cout << solve(s, m) << endl;
    return 0;
}
#endif //UNTITLED_MOVECHARSTOCONTINUOUS_H

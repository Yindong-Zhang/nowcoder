//
// Created by yindong on 19-9-8.
//
/*
 *
 * [编程题]手串

时间限制：1秒

空间限制：65536K

作为一个手串艺人，有金主向你订购了一条包含n个杂色串珠的手串——每个串珠要么无色，要么涂了若干种颜色。为了使手串的色彩看起来不那么单调，金主要求，手串上的任意一种颜色（不包含无色），在任意连续的m个串珠里至多出现一次（注意这里手串是一个环形）。手串上的颜色一共有c种。现在按顺时针序告诉你n个串珠的手串上，每个串珠用所包含的颜色分别有哪些。请你判断该手串上有多少种颜色不符合要求。即询问有多少种颜色在任意连续m个串珠中出现了至少两次。

输入描述:

第一行输入n，m，c三个数，用空格隔开。(1 <= n <= 10000, 1 <= m <= 1000, 1 <= c <= 50) 接下来n行每行的第一个数num_i(0 <= num_i <= c)表示第i颗珠子有多少种颜色。接下来依次读入num_i个数字，每个数字x表示第i颗柱子上包含第x种颜色(1 <= x <= c)


输出描述:

一个非负整数，表示该手链上有多少种颜色不符需求。


输入例子1:

5 2 3
3 1 2 3
0
2 2 3
1 2
1 3


输出例子1:

2


 */
#ifndef UNTITLED_BRACELETS_H
#define UNTITLED_BRACELETS_H
// 采用倒排的思想
#include<vector>
#include<iostream>
#include<map>
using namespace std;

int solve(vector<vector<int>> bracelets, int n, int c, int m){
    map<int, vector<int>> d;
    int count = 0;
    for(int color = 1; color <= c; color++){
        d.emplace(color, vector<int>());
    }
    int color;
    for(int i = 0; i < bracelets.size(); i++){
        for(int j = 0; j < bracelets[i].size(); j++){
            color= bracelets[i][j];
            d[color].push_back(i);
        }
    }
    for(auto ptr = d.begin(); ptr != d.end(); ptr++){
        color = ptr->first;
        ptr->second.push_back(ptr->second.front() + n); // 项链环
        for(int j = 1; j < ptr->second.size(); j++){
            if(ptr->second[j] - ptr->second[j - 1] < m){
                count++;
                break;
            }
        }
    }
    return count;
}

int bracelets(){
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> bracelets(n, vector<int>());
    int ni, bij;
    for(int i = 0; i < n; i++){
        cin >> ni;
        for(int j = 0; j < ni; j++){
            cin >> bij;
            bracelets[i].push_back(bij);
        }
    }
    cout << solve(bracelets, n, c, m) << endl;
    return 0;
}

#endif //UNTITLED_BRACELETS_H

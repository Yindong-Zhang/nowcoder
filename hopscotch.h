//
// Created by yindong on 19-9-6.
//

/*
 * 题目描述
假设你正在玩跳格子（所有格子排成一个纵列）游戏。需要 跳完n 个格子你才能抵达终点。
每次你可以跳 1 或 2 个格子。你有多少种不同的方法可以到达终点呢？
注意：给定 n 是一个正整数。
输入描述:

格子数n

输出描述:

跳完n个格子到达终点的方法

示例1
输入
复制

2

输出
复制

2


 */
#ifndef UNTITLED_HOPSCOTCH_H
#define UNTITLED_HOPSCOTCH_H
#include<vector>
#include<iostream>
using namespace std;

// 本质是一个 fibonacci数列
int solve(int n){
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < dp.size(); i++){
        dp[i] = dp[i - 1] + dp[ i - 2];
    }
    return dp[n];
}
int hopscotch(){
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif //UNTITLED_HOPSCOTCH_H

//
// Created by so_go on 2019/8/15.
//
/*
 *
牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食, 牛牛的背包容量为w。
牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
牛牛想知道在总体积不超过背包容量的情况下,他一共有多少种零食放法(总体积为0也算一种放法)。
输入描述:

输入包括两行
第一行为两个正整数n和w(1 <= n <= 30, 1 <= w <= 2 * 10^9),表示零食的数量和背包的容量。
第二行n个正整数v[i](0 <= v[i] <= 10^9),表示每袋零食的体积。

输出描述:

输出一个正整数, 表示牛牛一共有多少种零食放法。

示例1
输入
复制

3 10
1 2 4

输出
复制

8

说明

三种零食总体积小于10,于是每种零食有放入和不放入两种情况，一共有2*2*2 = 8种情况。


 */
#ifndef UNTITLED_BAG01_H
#define UNTITLED_BAG01_H
#include<vector>
#include<iostream>
// 递归dp 内存超出，dfs 还是 dp
// dfs 超时， 记忆化搜索？
// TODO:
using namespace std;
int recursive_dp(int i, int cap, const vector<int> &weights){
    if(i == 0 or cap == 0){
        return 1;
    }
    int num;
    if(cap > weights[i - 1]){
        num = recursive_dp(i - 1, cap - weights[i - 1], weights) + recursive_dp(i - 1, cap, weights);
    }
    else{
        num = recursive_dp(i - 1, cap, weights);
    }
//    cout << i << ' ' << cap << ' ' << num << endl;
    return num;
}

int dp(vector<int> weights, vector<int> caps, int capacity){
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int l = 1; l <= capacity; l++){
            if( l < caps[i]){
                dp[i][l] = dp[i - 1][l];
            }
            else{
                dp[i][l] = max(dp[i - 1][l], dp[i - 1][l - l[i]] + weights[i])
            }
        }
    }
    return dp[n][capacity];

}
int solve(vector<int> weights, int cap){
    int num_items = weights.size();
    return recursive_dp(num_items, cap, weights);
}

int numSolutionBag01(){
    int n, cap, tmp;
    vector<int> items;
    cin >> n >> cap;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        items.push_back(tmp);
    }
    cout << solve(items, cap) << endl;
    return 0;
}
#endif //UNTITLED_BAG01_H

//
// Created by yindong on 19-9-2.
//
/*
 * 题目描述
你需要爬上一个N层的楼梯，在爬楼梯过程中， 每阶楼梯需花费非负代价，第i阶楼梯花费代价表示为cost[i]， 一旦你付出了代价，你可以在该阶基础上往上爬一阶或两阶。
你可以从第 0 阶或者 第 1 阶开始，请找到到达顶层的最小的代价是多少。
N和cost[i]皆为整数，且N∈[2,1000]，cost[i]∈ [0, 999]。

输入描述:

输入为一串半角逗号分割的整数，对应cost数组，例如

10,15,20

输出描述:

输出一个整数，表示花费的最小代价

示例1
输入
复制

1,100,1,1,1,100,1,1,100,1

输出
复制

6


 */
#ifndef UNTITLED_CLIMBSTEPS_H
#define UNTITLED_CLIMBSTEPS_H
#include<vector>
#include<iostream>
using namespace std;
int solve(vector<int> costs){
    int n = costs.size();
    vector<int> dp(n + 1, 0);
    for(int i = 2; i < dp.size(); i++){
        dp[i] = min(dp[i - 1] + costs[ i - 1], dp[i - 2] + costs[ i - 2 ]);
    }
    return dp[n];
}

int climbSteps(){
    vector<int> costs;
    int cst;
    char sep;
    do{
        cin >> cst;
        costs.push_back(cst);
        cin.get(sep);
    }
    while(sep != '\n');
    cout << solve(costs) << endl;
    return 0;
}

#endif //UNTITLED_CLIMBSTEPS_H

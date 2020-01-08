//
// Created by yindong on 19-8-29.
//
/*
 * 题目描述
一个非空整数数组，选择其中的两个位置，使得两个位置之间的数和最大。
如果最大的和为正数，则输出这个数；如果最大的和为负数或0，则输出0
输入描述:

3,-5,7,-2,8

输出描述:

13

示例1
输入
复制

-6,-9,-10

输出
复制

0


 */
#ifndef UNTITLED_MAXSUBSTRINGSUM_H
#define UNTITLED_MAXSUBSTRINGSUM_H

#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> nums){
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int mx = max(dp[0], 0);
    for(int i = 1; i < dp.size(); i++){
        if(dp[i - 1] <= 0){
            dp[i] = nums[i];

        }
        else{
            dp[i] = dp[i - 1] + nums[i];
        }
        if(dp[i] > mx){
            mx = dp[i];
        }
    }
    return mx;
}
int maxSubstringSum(){
    int n;
    vector<int> nums;
    char sep;
    do{
        cin >> n;
        nums.push_back(n);
        sep = cin.get();
    }
    while(sep != '\n');
    cout << solve(nums) << endl;
    return 0;
}
#endif //UNTITLED_MAXSUBSTRINGSUM_H

//
// Created by yindong on 19-9-2.
//
/*
 * 题目描述

给定一个正整数数组，它的第 i 个元素是比特币第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一次），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入比特币前卖出。
输入描述:

正整数数组，为以空格分隔的n个正整数

输出描述:

最大利润

示例1
输入
复制

7 1 5 3 6 4

输出
复制

5


 */
#ifndef UNTITLED_STOCKSEXCHANGE_H
#define UNTITLED_STOCKSEXCHANGE_H
#include<vector>
#include <iostream>
#include <string>
#include<sstream>
#include<climits>
using namespace std;

int solve(vector<int> prices){
    int min = INT_MAX;
    int maxGain = 0;
    for(int i = 0; i < prices.size(); i++){
        if(prices[i] < min){
            min = prices[i];
        }
        else{
            maxGain = max(maxGain, prices[i] - min);
        }
    }
    return maxGain;
}
int stockExchange(){
    string line;

    getline(cin, line);
    stringstream ss(line);
    int price;
    vector<int> prices;
//    char sep;
//    do{
//        cin>> price;
//        cin.get(sep);
//        cout << price << sep;
//    }
//    while(sep != '\n');
    while(ss >> price){
        prices.push_back(price);
    }
    cout << solve(prices) << endl;
    return 0;
}
#endif //UNTITLED_STOCKSEXCHANGE_H

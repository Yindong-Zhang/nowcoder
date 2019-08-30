//
// Created by yindong on 19-8-30.
//
/*
 * 题目描述
有一个无限长的数字序列1，2，2，3，3，3，4，4，4，4，5，5，5，5，5。。。（数字序列从1开始递增，且数字k在该序列中正好出现k次），求第n项是多少
输入描述:

输入为一个整数n

输出描述:

输出一个整数，即第n项的值
 */
#ifndef UNTITLED_THENTHNUMBER_H
#define UNTITLED_THENTHNUMBER_H
#include<cmath>
#include<iostream>
using namespace std;

int solve(int n){
    float sqrt_2n = sqrt(2 * n);
    int k0 = floor(sqrt_2n), k1= ceil(sqrt_2n);
    if(2 * n <= k0 * k0 + k0){
        return k0;
    }
    else{
        return k1;
    }
}

int theKthNumber(){
    int n;
    cin >> n;
    cout << solve(n) << endl;
}
#endif //UNTITLED_THENTHNUMBER_H

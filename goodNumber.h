//
// Created by yindong on 19-9-4.
//
/*
 * 题目描述

我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。

如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。

现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？
输入描述:

输入正整数N

输出描述:

输出1到N中好数个数

示例1
输入
复制

10

输出
复制

4

说明

在[1, 10]中有四个好数： 2, 5, 6, 9。
注意 1 和 10 不是好数, 因为他们在旋转之后不变。


 */
#ifndef UNTITLED_GOODNUMBER_H
#define UNTITLED_GOODNUMBER_H
#include<cmath>
#include<iostream>
using namespace std;
// TODO: 思路有问题
int solve(unsigned int n){
    if(n < 10){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(i == 2 or i == 5 or i == 6 or i == 9){
                sum++;
            }
        }
        return sum;
    }
    int base = 1;
    int m = n / 10;
    int size = 1;
    while(m){
        size += 1;
        base *= 10;
        m = m / 10;
    }
//    cout << base << ' ' << size << endl;
    uint n0 = n / base;
    long long sum = 0;
    for(int i = 0; i < n0; i++){
        if(i == 0 or i == 1 or i == 8){
            sum += pow(7, size - 1);
            sum -= pow(3, size - 1);
        }
        else if( i == 2 or i == 5 or i == 6 or i == 9){
            sum += pow(7, size - 1);
        }
    }
    if(n0 == 1 or n0 == 2 or n0 == 5 or n0 == 6 or n0== 8 or n0 == 9 or n0 == 0){
        if( size > 1){
            sum += solve(n - n0 * pow(10, size - 1));

        }
    }
    return sum;
}

int goodNumber(){
    uint n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif //UNTITLED_GOODNUMBER_H

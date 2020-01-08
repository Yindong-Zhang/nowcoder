//
// Created by LCY on 2019/10/16.
//
/*
 * 题目描述
给定一个正整数n，计算n与斐波那契数的最小差值(绝对值)

说明：
斐波那契数定义：
                          从0，1开始后面的数值为前面两者之和, 即第三个数为第一和第二个数之和
                          形如：0，1，1，2，3，5，8，13，21。。。。  其中3为1与2的和，5为2与3的和，8为3与5的和等等
要计算的数值案例：
                          输入15，与斐波那契数相减，与13相减的绝对值是2，与21相减的绝对值是6，与众多斐波那契数相减的最小差值为2
                          因此输入15，输出2





输入描述:
输入任意正整数
输出描述:
数组正整数
示例1
输入
复制
15
输出
复制
2
说明
15与“0，1，1，2，3，5，8，13，21。。。。”当中的13差值的绝对值最小，与21的差值为6，与8的差值为7
 */
#ifndef UNTITLED_MINDISTANCEFIBNOCCI_H
#define UNTITLED_MINDISTANCEFIBNOCCI_H
#include<iostream>
using namespace std;
int solve(int n){
    int a = 0, b= 1;
    int tmp;
    while(b < n){
        tmp = b;
        b = a + b;
        a = tmp;
//        cout << a << ' ' << b << endl;
    }
    return min(b - n, n - a);

}
int minDistFibnocci(){
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif //UNTITLED_MINDISTANCEFIBNOCCI_H

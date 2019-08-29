//
// Created by yindong on 19-8-29.
//
/*
 * 题目描述
解析加减法运算
如：
输入字符串："1+2+3" 输出："6"
输入字符串："1+2-3" 输出："0"
输入字符串："-1+2+3" 输出："4"
输入字符串："1" 输出："1"
输入字符串："-1" 输出："-1"

已知条件：输入的运算都是整数运算，且只有加减运算
要求：输出为String类型，不能使用内建的eval()函数

输入描述:

输入字符串："1+2+3"

输出描述:

输出："6"

示例1
输入
复制

1+2+3

输出
复制

6


 */

#ifndef UNTITLED_PLUSMINUSCACULATOR_H
#define UNTITLED_PLUSMINUSCACULATOR_H

#include<string>
#include<iostream>
#include <cctype>
using namespace std;

int plusMinusCaculator(){
    char sign, op;
    int n, res = 0;
    op = '+';
    do{
        sign = cin.peek();
        if(sign == '+' or sign == '-'){
            cin.get();
        }
        cin >> n;
        if(sign == '-'){
            n = -n;
        }
        if(op == '+'){
            res += n;
        }
        else if(op == '-'){
            res -= n;
        }
        else{
            return -1; // unknown operator
        }
        op = cin.get();
    }
    while(op != '\n');
    cout << res << endl;
    return 0;
}
#endif //UNTITLED_PLUSMINUSCACULATOR_H

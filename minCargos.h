//
// Created by yindong on 19-8-28.
//
/*
 * 题目描述
有重量分别为3，5，7公斤的三种货物，和一个载重量为X公斤的箱子（不考虑体积等其它因素，只计算重量）
需要向箱子内装满X公斤的货物，要求使用的货物个数尽可能少（三种货物数量无限）

输入描述:

输入箱子载重量X(1 <= X <= 10000)，一个整数。

输出描述:

如果无法装满，输出 -1。
如果可以装满，输出使用货物的总个数。
 */

#ifndef UNTITLED_MINCARGOS_H
#define UNTITLED_MINCARGOS_H
#include<iostream>
using namespace std;
int minCargoes(){
    int X;
    cin >> X;
    if ( X == 1 or X == 2 or X == 4){
        cout << "-1" << endl;
        return 0;
    }
    int res;
    int n7 = X / 7;
    int m7 = X % 7;
    switch(m7){
        case 0: res = n7; break;
        case 1: res = n7 + 1; break;
        case 2: res = n7 + 2; break;
        case 3: res = n7 + 1; break;
        case 4: res = n7 + 2; break;
        case 5: res = n7 + 1; break;
        case 6: res = n7 + 2; break;
    }
    cout << res << endl;
    return 0;

}
#endif //UNTITLED_MINCARGOS_H

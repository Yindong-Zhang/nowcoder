//
// Created by yindong on 19-8-30.
//
/*
 * 题目描述
求a/b的小数表现形式。如果a可以整除b则不需要小数点。如果是有限小数，则可以直接输出。如果是无限循环小数，则需要把小数循环的部分用"()"括起来。

输入描述:

两个整数a和b，其中

0 <= a <= 1000 000

1 <= b <= 10 000

输出描述:

一个字符串，该分数的小数表现形式

示例1
输入
复制

10 1

输出
复制

10

说明

10/1 = 10


 */
#ifndef UNTITLED_DECIMALREPRESENTATION_H
#define UNTITLED_DECIMALREPRESENTATION_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(int a, int b){
    int i, d;
    int z, r;
    bool isRecur = false;
    int iRepeat;
    vector<int> vd;
    vector<int> vr;
    z = a/b;
    r = a % b;
    cout << z;
    if(r != 0){
        cout << '.';
        while(r != 0){
            auto rptr = find(vr.begin(), vr.end(), r);
            // 此处要小心
            if( rptr != vr.end()){ // 检查当前被除数是否重复
                iRepeat = rptr - vr.begin();
                break;
            }
            vr.push_back(r);
            z = 10 * r / b;
            r = 10 * r % b;
            vd.push_back(z);

        }

        for(int i = 0; i < vd.size(); i++){
            if(i == iRepeat){
                cout << '(';
            }
            cout << vd[i];
        }
        if(r!= 0){
            cout << ')';
        }
    }
}

int decimalRepresentation(){
    int a, b;
    cin >> a >> b;
    solve(a, b);
    return 0;
}
#endif //UNTITLED_DECIMALREPRESENTATION_H

//
// Created by so_go on 2019/12/24.
//
/*
 * 题目描述
给定两个数字（0-9）字符串（长度不限）求它们的乘积。
输入描述:

第一行为第一个数字字符串

第二行为第二个数字字符串

输出描述:

乘积字符串

示例1
输入
复制

123
20

输出
复制

2460


 */
#ifndef UNTITLED_BIGNUMBERMULTIPLY_H
#define UNTITLED_BIGNUMBERMULTIPLY_H
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int solve(vector<int> a, vector<int> b){
    vector<int> res(a.size() + b.size(), 0);
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            int tmp = a[i] * b[j], Itmp = i + j, jw = 0;
            while(tmp > 0 or jw > 0){
                int sum = res[Itmp] + tmp % 10 + jw;
                if(sum > 9){
                    jw = sum / 10;
                }
                else{
                    jw = 0;
                }
                res[Itmp]= sum % 10;
                tmp = tmp / 10;
                Itmp++;
            }
        }
    }
    int k = res.size() - 1;
    while(res[k] == 0){
        k--;
    }
    for(int ki = k; ki >= 0; ki--){
        cout << res[ki];
    }
    return 0;
}

int bigNumberMultiply(){
    vector<int> a, b;
    string line;
    getline(cin, line);
    for(int i = line.size() - 1; i >= 0; i--){
//        cout << line[i] << endl;
        int tmp = line[i] - '0';
        if( tmp < 10 and tmp >= 0){
            a.push_back(line[i] - '0');
        }
        else{
            exit(-1);
        }
    }

    getline(cin, line);
    for(int i = line.size() - 1; i >= 0; i--){
        int tmp = line[i] - '0';
        if( tmp < 10 and tmp >= 0){
            b.push_back(tmp);
        }
        else{
            exit(-1);
        }
    }
    solve(a, b);
    return 0;
}
#endif //UNTITLED_BIGNUMBERMULTIPLY_H

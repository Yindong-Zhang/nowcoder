//
// Created by yindong on 19-8-27.
//
/*
 * 题目描述
小明有26种游戏海报，用小写字母"a"到"z"表示。小明会把游戏海报装订成册（可能有重复的海报），册子可以用一个字符串来表示，每个字符就表示对应的海报，例如abcdea。小明现在想做一些“特别版”，然后卖掉。特别版就是会从所有海报（26种）中随机选一张，加入到册子的任意一个位置。
那现在小明手里已经有一种海报册子，再插入一张新的海报后，他一共可以组成多少不同的海报册子呢？
输入描述:

海报册子的字符串表示，1 <= 字符串长度<= 20

输出描述:

一个整数，表示可以组成的不同的海报册子种类数

示例1
输入
复制

a

输出
复制

51

说明

我们可以组成 'ab','ac',...,'az','ba','ca',...,'za' 还有 'aa', 一共 51 种不同的海报册子。


 */

#ifndef UNTITLED_ADDONECHAR_H
#define UNTITLED_ADDONECHAR_H
#include<string>
#include<iostream>
#include<set>
using namespace std;
int solve(string a){
    set<string> st;
    int n = a.size();
    string b(n + 1, 'a');
    for(int i = 0; i <= n; i++){
        for(int k = 0; k < 26; k++){
            for(int j = 0; j < i; j++){
                b[j] = a[j];
            }
            b[i] = 'a' + k;
            for(int j = i +  1; j <= n; j++){
                b[j] = a[j - 1];
            }
            if(st.find(b) == st.end()){
                st.insert(b);
            }
        }
    }
    return st.size();
}
int addOneChar(){
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
#endif //UNTITLED_ADDONECHAR_H

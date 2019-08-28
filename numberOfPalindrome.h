//
// Created by yindong on 19-8-28.
//
/*
 * 题目描述
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
("回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。)
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
可用C++,Java,C#实现相关代码逻辑
输入描述:

输入一个字符串S 例如“aabcb”(1 <= |S| <= 50), |S|表示字符串S的长度。

输出描述:

符合条件的字符串有"a","a","aa","b","c","b","bcb"

所以答案:7
 */
#ifndef UNTITLED_NUMBEROFPALINDROME_H
#define UNTITLED_NUMBEROFPALINDROME_H
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int manacher(string s){
    string ns = "#";
    for(int i = 0; i < s.size(); i++){
        ns.push_back(s[i]);
        ns.push_back('#');
    }
    vector<int> l(ns.size(), 0);
    l[0] = 1;
    int mid = 0, nx = 1, li, di;
    int res = 0;
    for(int i = 1; i < ns.size(); i++){
        if( i < nx){
            li = min(nx - i, l[ 2 * mid - i]);
        }
        else{
            li = 1;
        }
        while(i + li < ns.size() and i - li >= 0 and ns[i + li] == ns[i - li]){
            li++;
        }
        l[i] = li;
        res +=  li / 2;
    }
    return res;
}

int numberOfPalindrome(){
    string s;
    cin >> s;
    cout << manacher(s) << endl;
}
#endif //UNTITLED_NUMBEROFPALINDROME_H

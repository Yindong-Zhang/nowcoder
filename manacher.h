//
// Created by LCY on 2019/10/22.
//
/*
 * 题目描述
给定一个字符串（数字或大小写字母）, 找出最长的对称的子串（如有多个，输出任意一个）。
例如：
输入：“abbaad”
输出：“abba”
输入描述:
字符串
输出描述:
字符串
 */
#ifndef UNTITLED_MANACHER_H
#define UNTITLED_MANACHER_H
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
string pad_string(string s){
    string sp = "#";
    for(char ch : s){
        sp.push_back(ch);
        sp.push_back('#');
    }
    return sp;
}
string manacher(string rs){
    string s = pad_string(rs);
    vector<int> x(s.size(), 0);
    x[0] = 1;
    int m = 0, r = 1;
    int maxLen = 1;
    string maxStr = "#";
    for(int i = 1; i < s.size(); i++){
        if( i >= r){
            x[i] = 1;
        }
        else{
            x[i] = min(x[2 * m - i], r - i);
        }
        while(i + x[i] < s.size() and i - x[i] >= 0 and s[i + x[i]] == s[i - x[i]]){
            x[i]++;
        }
        if(maxLen <= x[i] - 1){
            maxLen = x[i] - 1;
            maxStr = rs.substr( (i - x[i] + 1) / 2, maxLen);
//            cout << maxLen << ' ' << maxStr << endl;
        }
    }
    return maxStr;
}



int longestPalindromSubstring(){
    string s;
    cin >> s;
    cout << manacher(s);
    return 0;
}
#endif //UNTITLED_MANACHER_H

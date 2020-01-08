//
// Created by LCY on 2019/10/16.
//
/*
 * 题目描述
给定一个字符串，请找出其中长度最长且不含有重复字符的子串，计算该子串长度。
输入描述:
输入类型为字符串，例如”abcde“
输出描述:
输出类型为整型， 例如 5
示例1
输入
复制
pwwkew
输出
复制
3
说明
无重复字符的最长子串是"abc"，其长度为 3
 */
#ifndef UNTITLED_LONGESTUNREPEATEDSUBSTRING_H
#define UNTITLED_LONGESTUNREPEATEDSUBSTRING_H
#include<string>
#include<iostream>
#include<map>
using  namespace std;
int solve(string s){
    int ind_start = 0;
    map<char, int> inds_dict;
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(inds_dict.find(ch) != inds_dict.end() and inds_dict[ch] >= ind_start){
            ind_start = inds_dict[ch] + 1;
        }
        inds_dict[ch] = i;
        res = max(res, i - ind_start + 1);
        cout << ind_start << ' ' << i << ' ' << res << endl;
    }
    return res;

}

int longestUnrepeatedSubstring(){
    string s;
    cin >> s;
    cout  << solve(s) << endl;
    return 0;
}
#endif //UNTITLED_LONGESTUNREPEATEDSUBSTRING_H

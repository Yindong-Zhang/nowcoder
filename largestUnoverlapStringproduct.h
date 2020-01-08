//
// Created by yindong on 19-8-29.
//
/*
 * 题目描述
已知一个字符串数组words，要求寻找其中两个没有重复字符的字符串，使得这两个字符串的长度乘积最大，输出这个最大的乘积。如：
words=["abcd","wxyh","defgh"], 其中不包含重复字符的两个字符串是"abcd"和"wxyh"，则输出16
words=["a","aa","aaa","aaaa"], 找不到满足要求的两个字符串，则输出0
输入描述:

Input:

["a","ab","abc","cd","bcd","abcd"]

输出描述:

Output:

4

示例1
输入
复制

["a","ab","abc","cd","bcd","abcd"]

输出
复制

4


 */
// 超出内存限制。。。
// 可以不使用预处理
#ifndef UNTITLED_LARGESTUNOVERLAPSTRINGPRODUCT_H
#define UNTITLED_LARGESTUNOVERLAPSTRINGPRODUCT_H
#include<bitset>
#include<iostream>
#include <vector>
using namespace std;
int solve(vector<string> vs){
    vector<bitset<26>> ss(vs.size());
    bitset<26> neg;
    string s;
    bitset<26> bs;
    for(int i = 0; i < vs.size(); i++){
        s = vs[i];
        bs.reset();
        for(char ch: s){
            bs[ch - 'a'] = 1;
        }
        ss[i] = bs;
    }

    int mp = 0, p;
    for(int i = 0; i < ss.size(); i++){
        for(int j = 0; j < ss.size(); j++){
            if((ss[i] & ss[j]) == neg){
                p = ss[i].count() * ss[j].count();
                if(p > mp){
                    mp = p;
                }
            }
        }

    }
    return mp;

}
int largestUnoverlapStringProduct(){
    string s;
    char ch, sep;
    vector<string> vs;
    cin.get();
    do{
        cin.get(); // "
        s.clear();
        while(true){
            cin.get(ch);
            if(ch != '"'){
                s.push_back(ch);
            }
            else{
                break;
            }
        }
        vs.push_back(s);
        cin.get(sep); // ,
    }
    while(sep != ']');
//    for(string s: vs){
//        cout << s << endl;
//    }
    cout << solve(vs) << endl;
    return 0;
}
#endif //UNTITLED_LARGESTUNOVERLAPSTRINGPRODUCT_H

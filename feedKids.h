//
// Created by yindong on 19-9-6.
//
/*
 * 题目描述
假设你是一位很有爱的幼儿园老师，想要给幼儿园的小朋友们一些小糖果。但是，每个孩子最多只能给一块糖果。对每个孩子 i ，都有一个胃口值 gi ，这是能让孩子们满足胃口的糖果的最小尺寸；并且每块糖果 j ，都有一个尺寸 sj 。如果 sj >= gi ，我们可以将这个糖果 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
注意：
你可以假设胃口值为正。
一个小朋友最多只能拥有一块糖果。

输入描述:

第一行输入每个孩子的胃口值

第二行输入每个糖果的尺寸

孩子数和糖果数不超过1000

输出描述:

能满足孩子数量的最大值

示例1
输入
复制

1 2 3
1 1

输出
复制

1


 */
// 经典贪心
#ifndef UNTITLED_FEEDKIDS_H
#define UNTITLED_FEEDKIDS_H
#include<vector>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
int solve(vector<int> kids, vector<int> sugars){
    sort(sugars.begin(), sugars.end());
    vector<bool> available(sugars.size(), true);
    int ind, count = 0;
    for(int kid: kids){
        auto ptr = lower_bound(sugars.begin(), sugars.end(), kid);
        ind = ptr - sugars.begin();
        while(ind < sugars.size() and not available[ind]){
            ind++;
        }
        if(ind < sugars.size()){
            count++;
            available[ind] = false;
        }
    }
    return count;
}
int feedKids(){
    string l1, l2;
    getline(cin, l1);
    getline(cin, l2);
    stringstream sl1(l1), sl2(l2);
    int kid, sugar;
    vector<int> kids, sugars;
    while(sl1 >> kid){
        kids.push_back(kid);
    }
    while(sl2 >> sugar){
        sugars.push_back(sugar);
    }
    cout << solve(kids, sugars) << endl;
    return 0;
}
#endif //UNTITLED_FEEDKIDS_H

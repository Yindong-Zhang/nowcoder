//
// Created by yindong on 19-9-3.
//
/*
 * 题目描述

小招喵喜欢吃喵粮。这里有 N 堆喵粮，第 i 堆中有 p[i] 粒喵粮。喵主人离开了，将在 H 小时后回来。

小招喵可以决定她吃喵粮的速度 K （单位：粒/小时）。每个小时，她将会选择一堆喵粮，从中吃掉 K 粒。如果这堆喵粮少于 K 粒，她将吃掉这堆的所有喵粮，然后这一小时内不会再吃更多的喵粮。

小招喵喜欢慢慢吃，但仍然想在喵主人回来前吃掉所有的喵粮。

返回她可以在 H 小时内吃掉所有喵粮的最小速度 K（K 为整数）。
输入描述:

第一行输入为喵粮数组，以空格分隔的N个整数

第二行输入为H小时数

输出描述:

最小速度K

示例1
输入
复制

3 6 7 11
8

输出
复制

4


 */
#ifndef UNTITLED_CATFOOD_H
#define UNTITLED_CATFOOD_H
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

bool judge(vector<int> &p, int K, int H){
    int sum = 0;
    for(auto pi: p){
        sum += ceil(pi / float(K) );
    }
    if(sum <= H){
        return true;
    }
    else{
        return false;
    }
}
int binary_search(vector<int> p, int H){
    int N = p.size();
    int psum = 0, pmax = 0;
    for(int pi : p){
        psum += pi;
        if(pi > pmax){
            pmax = pi;
        }
    }
    int left = psum / H, right = pmax, mid;
    while(left + 1 < right){
        cout << left << ' ' << right << endl;
        mid = (left + right) / 2;
        if(judge(p, mid, H)){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    cout << left << ' ' << right << endl;
    return right;
}

int lowestSpeed(){
    int pi;
    vector<int> p;
    int H;
    char sep;
    do{
        cin >> pi;
        p.push_back(pi);
        cin.get(sep);
    }
    while(sep != '\n');
    cin >> H;
    cout << binary_search(p, H) << endl;
    return 0;
}

#endif //UNTITLED_CATFOOD_H

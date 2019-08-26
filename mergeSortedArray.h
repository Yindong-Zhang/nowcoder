//
// Created by so_go on 2019/8/26.
//
/*
 * 题目描述
请实现一个函数，功能为合并两个升序数组为一个升序数组
点击页面左下角“例2”，了解如何实现输入输出
输入描述:

输入有多个测试用例，每个测试用例有1-2行，每行都是以英文逗号分隔从小到大排列的数字

输出描述:

输出一行以英文逗号分隔从小到大排列的数组

示例1
输入
复制

1,5,7,9
2,3,4,6,8,10

输出
复制

1,2,3,4,5,6,7,8,9,10

00++++++++++++++++++++++++++++++++++++++++++++++++++++----------------










































 */
#ifndef UNTITLED_MERGESORTEDARRAY_H
#define UNTITLED_MERGESORTEDARRAY_H
#include<vector>
#include<iostream>
using namespace std;
vector<int> solve(vector<int> a, vector<int> b){
    int i = 0, j = 0;
    vector<int> res(a.size() + b.size(), 0);
    while(i < a.size() or j < b.size()){
        if(i < a.size() and j < b.size()){
            if(a[i] <= b[j]){
                res[i + j] = a[i];
                i++;
            }
            else{
                res[i + j] = b[j];
                j++;
            }
        }
        else if(i < a.size() and j == b.size()){
            res[i + j] = a[i];
            i++;
        }
        else {
            res[i + j] = b[j];
            j++;
        }
    }
    return res;
}

int mergeSortedArray(){
    vector<int> a, b;
    int num;
    char ch;
    if(cin.peek() != '\n'){
        do{
            cin >> num;
            cin.get(ch);
            // cout << num << ' ' << ch << endl;
            a.push_back(num);
        }
        while(ch != '\n');
    }
    if(cin.peek() != '\n'){
        do{
            cin >> num;
            cin.get(ch);
            // cout << num << ' ' << ch << endl;
            b.push_back(num);
        }
        while(ch != '\n');
    }
    vector<int> res = solve(a, b);
    for(int i = 0; i < res.size(); i++){
        cout << res[i];
        if( i != res.size() - 1){
            cout << ',';
        }
    }
    return 0;
}
#endif //UNTITLED_MERGESORTEDARRAY_H

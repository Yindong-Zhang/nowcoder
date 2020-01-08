//
// Created by LCY on 2019/10/23.
//
/*
 * 题目描述
小多想在美化一下自己的庄园。他的庄园毗邻一条小河，他希望在河边种一排树，共 M 棵。小多采购了 N 个品种的树，每个品种的数量是 Ai (树的总数量恰好为 M)。但是他希望任意两棵相邻的树不是同一品种的。小多请你帮忙设计一种满足要求的种树方案。
输入描述:
第一行包含一个正整数 N，表示树的品种数量。
第二行包含 N 个正整数，第 i (1 <= i <= N) 个数表示第 i 个品种的树的数量。
数据范围：
1 <= N <= 1000
1 <= M <= 2000
输出描述:
输出一行，包含 M 个正整数，分别表示第 i 棵树的品种编号 (品种编号从1到 N)。若存在多种可行方案，则输出字典序最小的方案。若不存在满足条件的方案，则输出"-"。
示例1
输入
复制
3
4 2 1
输出
复制
1 2 1 2 1 3 1
 */
#ifndef UNTITLED_NOADJACENTPERMUTATION_H
#define UNTITLED_NOADJACENTPERMUTATION_H
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int first_max(vector<int> array, int ind_exlude){
    int max_ind = -1, max_value = 0;
    for(int i = 0; i < array.size(); i++){
        if(i != ind_exlude){
            if(array[i] > max_value){
                max_ind = i;
                max_value = array[i];
            }
        }
    }
    return max_ind;
}

// 解答不对。。。
void solve(vector<int> a, int M){
    if(first_max(a, a.size()) > ceil(M / 2)){
        cout << "-";
    }
    else{
        vector<int> res;
        int last_ind = a.size();
        int left = M;
        for(int i = 0; i < M; i++){
            int max_ind = first_max(a, last_ind);
            int ind = 0;
            if(a[max_ind] < ceil( (left - 1) / 2 ) ){
                for(; 0 == a[ind]  or ind == last_ind and ind < a.size(); ind++);
            }
            else{
//
                ind = max_ind;
            }
            a[ind]--;
            res.push_back(ind + 1);
            left--;
            last_ind = ind;
        }
        for(int i = 0; i < M; i++){
            cout << res[i] << ' ';
        }
    }

}
int noAdjacentPermuatation(){
    int N;
    cin >> N;
    vector<int> a(N);
    int M = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        M = M + a[i];
    }
    cout << M << endl;
    solve(a, M);
    return 0;
}
#endif //UNTITLED_NOADJACENTPERMUTATION_H

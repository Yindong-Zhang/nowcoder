//
// Created by so_go on 2019/8/16.
//
/*
 * 题目描述
小易觉得高数课太无聊了，决定睡觉。不过他对课上的一些内容挺感兴趣，所以希望你在老师讲到有趣的部分的时候叫醒他一下。你知道了小易对一堂课每分钟知识点的感兴趣程度，并以分数量化，以及他在这堂课上每分钟是否会睡着，你可以叫醒他一次，这会使得他在接下来的k分钟内保持清醒。你需要选择一种方案最大化小易这堂课听到的知识点分值。
输入描述:

第一行 n, k (1 <= n, k <= 105) ，表示这堂课持续多少分钟，以及叫醒小易一次使他能够保持清醒的时间。
第二行 n 个数，a1, a2, ... , an(1 <= ai <= 104) 表示小易对每分钟知识点的感兴趣评分。
第三行 n 个数，t1, t2, ... , tn 表示每分钟小易是否清醒, 1表示清醒。

输出描述:

小易这堂课听到的知识点的最大兴趣值。

示例1
输入
复制

6 3
1 3 5 2 5 4
1 1 0 1 0 0

输出
复制

16


 */
#ifndef UNTITLED_WAKEUP_H
#define UNTITLED_WAKEUP_H
#include<vector>
#include<iostream>
// %10 样例 超时。。。
using namespace std;
int solve(vector<int> scores, int k){
    int max = 0;
    int sum_k = 0;
    for(int i = 0; i < scores.size(); i++){
        if(scores[i] != 0){
            sum_k = 0;
            for(int j = i; j < scores.size() and j < i + k; j++){
                sum_k += scores[j];
            }
            if(sum_k > max){
                max = sum_k;
            }
        }
    }
    return max;
}
int wakeup(){
    int n, k;
    vector<int> scores;
    int score, is_awake;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> score;
        scores.push_back(score);
    }
    int awake_sum = 0;
    for(int i = 0; i < n; i++){
        cin >> is_awake;
        if(is_awake){
            awake_sum += scores[i];
            scores[i] = 0;
        }
    }
    int wakeup_sum = solve(scores, k);
    cout << awake_sum + wakeup_sum << endl;
    return 0;
}
#endif //UNTITLED_WAKEUP_H

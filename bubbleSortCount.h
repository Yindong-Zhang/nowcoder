//
// Created by yindong on 19-9-2.
//
/*
 * 题目描述
农场有n只鸡鸭排为一个队伍，鸡用“C”表示，鸭用“D”表示。当鸡鸭挨着时会产生矛盾。需要对所排的队伍进行调整，使鸡鸭各在一边。每次调整只能让相邻的鸡和鸭交换位置，现在需要尽快完成队伍调整，你需要计算出最少需要调整多少次可以让上述情况最少。例如：CCDCC->CCCDC->CCCCD这样就能使之前的两处鸡鸭相邻变为一处鸡鸭相邻，需要调整队形两次。

输入描述:

输入一个长度为N，且只包含C和D的非空字符串。

输出描述:

使得最后仅有一对鸡鸭相邻，最少的交换次数

示例1
输入
复制

CCDCC

输出
复制

2


 */
#ifndef UNTITLED_BUBBLESORTCOUNT_H
#define UNTITLED_BUBBLESORTCOUNT_H
#include<string>
#include<iostream>
using namespace std;
int solve(string q){
    int sum = 0;
    int count = 0;
    int n = q.size();
    for(int i = 0; i < q.size(); i++){
        if(q[i] == 'D'){
            sum += (i + 1);
            count++;
        }
    }
    return (2 * n - count + 1) * count / 2 - sum;
}
int bubbleSortCount(){
    string q;
    cin >> q;
    cout << solve(q) << endl;
    return 0;
}
#endif //UNTITLED_BUBBLESORTCOUNT_H

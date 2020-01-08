//
// Created by so_go on 2020/1/8.
//
/*
 *
题目描述

我们部门要排队唱歌，大家乱哄哄的挤在一起，现在需要按从低到高的顺序拍成一列，但每次只能交换相邻的两位，请问最少要交换多少次


输入描述:

第一行是N（N<50000）,表示有N个人
然后每一行是人的身高Hi（Hi<2000000,不要怀疑，我们以微米计数），持续N行，表示现在排列的队伍

输出描述:

输出一个数，代表交换次数。

示例1
输入
复制

6
3
1
2
5
6
4

输出
复制

4


 */

// 实际就是求逆序对数？
#ifndef UNTITLED_BUBBLESORT_H
#define UNTITLED_BUBBLESORT_H
#include<iostream>
#include<vector>
using namespace std;
/*
int solve(vector<long> H){
    int count = 0;
    for(int i = 0; i < H.size(); i++){
        bool isSorted = true;
        for(int j = 0; j < H.size() - i - 1; j++){
            if( H[j] > H[j + 1]){
                swap(H[j], H[j + 1]);
                count++;
                isSorted= false;
            }


        }
        if(isSorted){
            break;
        }
    }
    return count;
}
*/

int solve(vector<long> H ){
    int count = 0;
    for(int i = 0; i < H.size(); i++){
        for(int j = i + 1; j < H.size(); j++){
            if( H[i] > H[j]){
                count++;
            }
        }
    }
    return count;
}

int bubbleSort(){
    int N;
    long hi;
    cin >> N;
    vector<long> H;
    for(int i = 0; i < N; i++){
        cin >> hi;
        H.push_back(hi);
    }
    cout << solve(H) << endl;
    return 0;
}
#endif //UNTITLED_BUBBLESORT_H

//
// Created by so_go on 2020/3/18.
//
/*
 * 现在现在有一台机器，这台机器可以接收两种形式任务：（1）任务列表，任务列表里面有N个任务，对于第i个任务，机器在Ti时间开始执行，并在1个单位时间内做完。（2）临时任务，机器可以在任意时间接收一个临时任务，但任务列表里面的任务优先级要高于临时任务，也就是说当机器空闲的时候才会执行临时任务。
现在机器已经接收一个任务列表。接下来会有M个临时任务，我们想知道每个临时任务何时被执行。为了简化问题我们可以认为这M个临时任务是独立无关即任务是可以同时执行的，互不影响的。



输入
输入数据有多组，每组数据第一行包括两个整数N和M（1<=N, M<=10^5）。
接下来一行有N个不同数字T1,T2,T3.....TN（1<=T1
接下来又M行，每行一个数字Qi（1<=Qi<=10^9），表示第i个临时任务的的接收时间。

样例输入
5 6
1 2 3 5 6
3
2
1
4
5
6

输出
对于每个临时任务，输出它被执行的时间。


 */
#ifndef UNTITLED_TASKLIST_H
#define UNTITLED_TASKLIST_H
#include<bits/stdc++.h>
using namespace std;
// 一个可以接收的算法，并没有那么复杂
int solve(vector<int> &nums, int q){
    auto ptr= lower_bound(nums.begin(), nums.end(), q);
    if(*ptr == q){
        while(ptr + 1 != nums.end() and *(ptr + 1) - *ptr == 1){
            ptr++;
        }
        return *ptr + 1;
    }
    else{
        return q;
    }
}
int tasklist(){
    vector<int> nums;
    int n, m;
    cin >> n >> m;
    int num, query;
    for(int i = 0; i < n; ++i){
        cin >> num;
        nums.push_back(num);
    }
    for(int j = 0; j < m; ++j){
        cin >> query;
        cout << solve(nums, query) << endl;
    }
}
#endif //UNTITLED_TASKLIST_H

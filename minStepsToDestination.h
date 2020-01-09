//
// Created by so_go on 2020/1/9.
//
/*
 * 题目描述
考虑你从家出发步行去往一处目的地，该目的地恰好离你整数单位步长（大于等于1）。你只能朝向该目的地或者背向该目的地行走，而你行走的必须为单位步长的整数倍，且要求你第N次行走必须走N步。
请就给出目的地离你距离，判断你是否可以在有限步内到达该目的地。如果可以到达的话，请计算到达目的地的最短总步数(不能到达则输出-1)。
输入描述:

1个整数：目的地离你距离T

输出描述:

1个整数：最短总步数（进行了多少次行走）

示例1
输入
复制

2

输出
复制

3

说明

距离目的地2， 需要3步：朝向走1，背向走2，朝向走3


 */
#ifndef UNTITLED_MINSTEPSTODESTINATION_H
#define UNTITLED_MINSTEPSTODESTINATION_H
#include<vector>
#include<set>
#include<iostream>
using namespace std;
int solve(int T){
    if(T == 0){
        return 0;
    }
    set<int> last_pos{0, }, cur_pos;
    int k = 1;
    while(true){
        for(int pos : last_pos){
            if(pos + k != T){
                if(cur_pos.find(pos + k) == cur_pos.end())
                    cur_pos.insert(pos + k);
            }
            else{
                return k;
            }
            if(pos - k != T){
                if(cur_pos.find(pos - k) == cur_pos.end())
                    cur_pos.insert(pos - k);
            }
            else{
                return k;
            }
        }
        k++;
        last_pos = cur_pos;
        cur_pos.clear();

    }
}

int minStepsToDestination(){
    int T;
    cin >> T;
    cout << solve(T) << endl;
    return 0;
}
#endif //UNTITLED_MINSTEPSTODESTINATION_H

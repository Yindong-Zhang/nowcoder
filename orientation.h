//
// Created by so_go on 2019/8/14.
//
/*
 * 题目描述
牛牛去犇犇老师家补课，出门的时候面向北方，但是现在他迷路了。虽然他手里有一张地图，但是他需要知道自己面向哪个方向，请你帮帮他。
输入描述:

每个输入包含一个测试用例。
每个测试用例的第一行包含一个正整数，表示转方向的次数N(N<=1000)。
接下来的一行包含一个长度为N的字符串，由L和R组成，L表示向左转，R表示向右转。

输出描述:

输出牛牛最后面向的方向，N表示北，S表示南，E表示东，W表示西。

示例1
输入
复制

3
LRR

输出
复制

E


 */
#ifndef UNTITLED_ORIENTATION_H
#define UNTITLED_ORIENTATION_H

#include<string>
using namespace std;


char orientation(string turn){
    int pos = 0;
    string directions = "NESW";
    for(int i = 0; i < turn.size(); i++){
        if(turn[i] == 'L'){
            pos--;
        }
        else{
            pos++;
        }
    }
    int pos_mod = pos % 4;
    if(pos_mod < 0){
        pos_mod += 4;
    }
    return directions[pos_mod];
}

#endif //UNTITLED_ORIENTATION_H

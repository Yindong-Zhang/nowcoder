//
// Created by yindong on 19-10-20.
//
/*
 * 题目描述

小云正在参与开发一个即时聊天工具，他负责其中的会话列表部分。

会话列表为显示为一个从上到下的多行控件，其中每一行表示一个会话，每一个会话都可以以一个唯一正整数id表示。

当用户在一个会话中发送或接收信息时，如果该会话已经在会话列表中，则会从原来的位置移到列表的最上方；如果没有在会话列表中，则在会话列表最上方插入该会话。
小云在现在要做的工作是测试，他会先把会话列表清空等待接收信息。当接收完大量来自不同会话的信息后，就输出当前的会话列表，以检查其中是否有bug。
输入描述:

输入的第一行为一个正整数T（T<=10），表示测试数据组数。
接下来有T组数据。每组数据的第一行为一个正整数N（1<=N<=200），表示接收到信息的次数。第二行为N个正整数，按时间从先到后的顺序表示接收到信息的会话id。会话id不大于1000000000。

输出描述:

对于每一组数据，输出一行，按会话列表从上到下的顺序，输出会话id。
相邻的会话id以一个空格分隔，行末没有空格。

示例1
输入
复制

3
5
1 2 3 4 5
6
1 100 1000 1000 100 1
7
1 6 3 3 1 8 1

输出
复制

5 4 3 2 1
1 100 1000
1 8 3 6


 */
// 数据结构：查找，删除，尾部插入
// 使用vector
#ifndef UNTITLED_CHATLIST_H
#define UNTITLED_CHATLIST_H
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void solve(vector<int> messageList){
    vector<int> chatList;
    for(int m: messageList){
        auto ptr = find(chatList.begin(), chatList.end(), m);
        if( ptr != chatList.end()){
            chatList.erase(ptr);
        }
        chatList.push_back(m);
    }
    for(auto ptr = chatList.rbegin(); ptr != chatList.rend(); ptr++){
        cout << *ptr << ' ';
    }
    cout << endl;
}

int chatList(){
    int nSamples;
    cin >> nSamples;
    int n, m;
    vector<int> mList;
    for(int i = 0; i < nSamples; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> m;
            mList.push_back(m);
        }
        solve(mList);
        mList.clear();
    }
    return 0;
}
#endif //UNTITLED_CHATLIST_H

//
// Created by so_go on 2019/8/15.
//
/*
 * 小Q和牛博士合唱一首歌曲,这首歌曲由n个音调组成,每个音调由一个正整数表示。
对于每个音调要么由小Q演唱要么由牛博士演唱,对于一系列音调演唱的难度等于所有相邻音调变化幅度之和, 例如一个音调序列是8, 8, 13, 12, 那么它的难度等于|8 - 8| + |13 - 8| + |12 - 13| = 6(其中||表示绝对值)。
现在要对把这n个音调分配给小Q或牛博士,让他们演唱的难度之和最小,请你算算最小的难度和是多少。
如样例所示: 小Q选择演唱{5, 6}难度为1, 牛博士选择演唱{1, 2, 1}难度为2,难度之和为3,这一个是最小难度和的方案了。

输入描述:

输入包括两行,第一行一个正整数n(1 ≤ n ≤ 2000) 第二行n个整数v[i](1 ≤ v[i] ≤ 10^6), 表示每个音调。


输出描述:

输出一个整数,表示小Q和牛博士演唱最小的难度和是多少。


输入例子1:

5
1 5 6 2 1


输出例子1:

3


 */
#ifndef UNTITLED_CHORUSDIFFICULTY_H
#define UNTITLED_CHORUSDIFFICULTY_H
#include<vector>
#include<cmath>
#include<iostream>
#include<climits>
using namespace std;
// 不完整，对于贪心中每步有多种最优解的情况
// 仍然有问题。。。。
//TODO:
int dfs(int hs, int g0, int la, int lb, int i, vector<int> &a){
    cout << hs << ' ' << g0 << ' ' << la << ' ' << lb << ' ' << i << endl;
    if(i == a.size()){
        return hs;
    }
    int choice[3] = {hs + abs(a[i] - la), hs + abs(a[i] - lb), g0};
    int cmin = INT_MAX;
    vector<int> indMin;
    for(int i = 0; i < 3; i++){
        if(choice[i] < cmin){
            cmin = choice[i];
            indMin.clear();
            indMin.push_back(i);
        }
        else if(choice[i] == cmin){
            indMin.push_back(i);
        }
    }

    g0 += abs(a[i] - a[i-1]);
    int res = INT_MAX;
    for(int ind: indMin){
        cout << ind << ' ';
        if( ind == 0){
            res = min(res, dfs(choice[0], g0, a[i], lb, i + 1, a));
        }
        else if(ind == 1){
            res = min(res, dfs(choice[1], g0, la, a[i], i + 1, a));
        }
        else if(ind == 2){
            res = min(res, dfs(choice[2], g0, a[i - 1], a[i], i + 1, a));
        }
    }
    return res;


}
int solve(vector<int> a){
    if(a.size() <= 2){
        return 0;
    }
    return dfs(0, abs(a[1] - a[0]), a[0], a[1], 2, a);
}

int chorusDifficulty(){
    int n, tmp;
    vector<int> vec;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        vec.push_back(tmp);
    }
    cout << solve(vec) << endl;
    return 0;
}
#endif //UNTITLED_CHORUSDIFFICULTY_H

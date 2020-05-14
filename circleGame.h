//
// Created by so_go on 2020/4/16.
//

#ifndef UNTITLED_CIRCLEGAME_H
#define UNTITLED_CIRCLEGAME_H
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int solve(queue<int > Q, int m){
    ll res = 0;
    int lastWin;
    int cWin;
    int a = Q.front();
    Q.pop();
    int b= Q.front();
    Q.pop();
    if(a > b){
        lastWin = a;
        Q.push(b);
    }
    else{
        lastWin = b;
        Q.push(a);
    }
    cWin = 1;
    res = 1;
    while(cWin < m){
        int cur= Q.front();
        Q.pop();
        res++;
        if(lastWin > cur){
            cWin++;
            Q.push(cur);
        }
        else{
            cWin = 1;
            Q.push(lastWin);
            lastWin = cur;
        }
    }
    return res;
}

int circleGame(){
    int n, m;
    cin >> n >> m;
    queue<int > Q;
    int Ni;
    for(int i = 0; i < n; ++i){
        cin >> Ni;
        Q.push(Ni);
    }
    cout << solve(Q, m);
}
#endif //UNTITLED_CIRCLEGAME_H

//
// Created by so_go on 2020/3/19.
//

#ifndef UNTITLED_MAXSCORE_H
#define UNTITLED_MAXSCORE_H
#include<bits/stdc++.h>
using namespace std;

int maxScore(){
    int n, k, m;
    int p, q;
    vector<int> t;
    int ti;
    cin >> n >> k >> m;
    cin >> p >> q;
    int tsum = 0;
    for(int i = 0; i < k; ++i){
        cin >> ti;
        t.push_back(ti);
        tsum += ti;
    }
    vector<int> res(n, k);
    return m / *min_element(t.begin(), t.end()) * p;
}
#endif //UNTITLED_MAXSCORE_H

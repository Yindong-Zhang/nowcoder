//
// Created by so_go on 2020/3/27.
//
// 招行网络中心第二题，未通过
#ifndef UNTITLED_HANDLEBAR_H
#define UNTITLED_HANDLEBAR_H
#include<bits/stdc++.h>
//#include"printVector.h"
using namespace std;

int solve(vector<vector<int>> &E, vector<int> inCount, int N){
//    printVector(inCount);
    vector<bool> isVisit(N, false);
    int count = N;
    int cur = -1;
    for(int i = 0; i < N; ++i){
        if(inCount[i] == 0){
            cur = i;
            count--;
            break;
        }
    }

    int res = 1;
    while(count > 1){
        cout << cur << endl;
//        printVector(inCount);
        isVisit[cur] = true;
        for(auto node : E[cur]){
            inCount[node]--;
        }
        bool hasNext = false;
        for(auto node : E[cur]){
            if(inCount[node] == 0){
                cur = node;
                count--;
                hasNext = true;
                break;
            }
        }
        if(not hasNext){
            for(int i = 0; i < N; ++i){
                if(not isVisit[i] and inCount[i] == 0){
                    cur = i;
                    count--;
                    res++;
//                    cout << i << ' ' << res  << ' ' << count << endl;
                    break;
                }
            }
        }
    }
    return res;

}
struct Pair{
    int a, b;
};
int handleBar(){
    int T,n;
    cin >> T;
    int a, b;
    vector<int> A, B;
    for(int t = 0; t < T; ++t){
        cin >> n;
        vector<vector<int>> E(n);
        vector<int> inCount(n, 0);
        for(int i = 0; i < n; ++i){
            cin >> a;
            A.push_back(a);
        }
        for(int i = 0; i < n; ++i){
            cin >> b;
            B.push_back(b);
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i != j and A[i] <= A[j] and B[i] <= B[j]){
                    E[i].push_back(j);
                    inCount[j]++;
                }

            }
        }
        cout << solve(E, inCount, n) << endl;
        A.clear();
        B.clear();

    }
    return 0;
}
#endif //UNTITLED_HANDLEBAR_H

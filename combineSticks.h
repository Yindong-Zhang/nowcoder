//
// Created by so_go on 2020/5/6.
//

#ifndef UNTITLED_COMBINESTICKS_H
#define UNTITLED_COMBINESTICKS_H
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> &stklen, vector<int> &count, vector<int> &used,  int i, int resLen, vector<vector<int>> &useCount){
    if(resLen == 0){
        useCount.push_back(used);
        return;
    }
    if( i == count.size()){
        return;
    }
    for(int u = 0; u <= count[i]; u++){
        if(resLen - u * stklen[i] >= 0){
            used[i] = u;
            dfs(stklen, count, used, i + 1, resLen - u * stklen[i],useCount);
            used[i] = 0;
        }
        else{
            break;
        }
    }
}

bool findNext(vector<int> &stkLen, vector<int> &count, int SideReady, int len, vector<vector<int>> &pComb){
    if(SideReady == 3){
        return true;
    }
    for(auto &comb: pComb){
        vector<int> leftCount(count.size(), 0);

        for(int i = 0; i < count.size(); ++i){
            leftCount[i] = count[i] - comb[i];
        }
        bool canContinue = true;
        for(int leftCnt : leftCount){
            if(leftCnt < 0){
                canContinue = false;
            }
        }
        if(canContinue){
            if(findNext(stkLen, leftCount, SideReady + 1, len, pComb)){
                return true;
            }
        }
    }
    return false;

}

bool findComb(map<int,int> sticks){
    vector<int> stkLen, count;
    int sumLen = 0, len;
    for(auto ptr = sticks.begin(); ptr != sticks.end(); ptr++){
        stkLen.push_back(ptr->first);
        count.push_back(ptr->second);
        sumLen += ptr->first * ptr->second;
    }

    if( sumLen % 4 == 0){
        len = sumLen / 4;
    }
    else{
        return false;
    }

    for(auto stkl : stkLen){
        if(stkl > len){
            return false;
        }
    }
    vector<vector<int>> pUsed;
    vector<int> used(count.size(), 0);
    dfs(stkLen, count, used, 0, len, pUsed);

    return findNext(stkLen, count, 0, len, pUsed);

}

int canBeSolved(){
    int T;
    cin >> T;
    map<int, int> sticks;
    for(int t = 0; t < T; ++t){
        int n, li;
        cin >> n;
        for(int ni = 0; ni < n; ++ni){
            cin >> li;
            if(sticks.find(li) == sticks.end()){
                sticks[li] = 1;
            }
            else{
                sticks[li]++;
            }
        }
        if(findComb(sticks)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        sticks.clear();
    }
    return 0;
}
#endif //UNTITLED_COMBINESTICKS_H

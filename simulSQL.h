//
// Created by so_go on 2020/4/11.
//
// 网易互娱第三题
#ifndef UNTITLED_SIMULSQL_H
#define UNTITLED_SIMULSQL_H
#include<bits/stdc++.h>
using namespace std;

int popularity(){
    int N;
    cin >> N;
    map<int, set<int>> rd;
    int id, uid, iid;
    map<int, set<int>> res;
    for(int i = 0; i < N; ++i){
        cin >> id >> uid >> iid;
        rd[iid].insert(uid);
    }
    for(auto ptr = rd.begin(); ptr != rd.end(); ptr++){
        auto st = ptr->second;
        if(st.size() > 1){
            for(auto u1_ptr = st.begin(); u1_ptr != st.end(); u1_ptr++){
                for(auto u2_ptr = st.begin(); u2_ptr != st.end(); u2_ptr++){
                    if(u1_ptr == u2_ptr){
                        continue;
                    }
                    int u1_id = *u1_ptr, u2_id = *u2_ptr;
                    res[u1_id].insert(u2_id);
                }
            }
        }
    }
    for(auto u_ptr = res.begin(); u_ptr != res.end(); u_ptr++){
        int u_id = u_ptr->first, count = u_ptr->second.size();
        if(count > 0){
            cout << u_id << ' ' << count << endl;
        }
    }
    return 0;
}
#endif //UNTITLED_SIMULSQL_H

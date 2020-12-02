//
// Created by so_go on 2020/8/23.
//

#ifndef UNTITLED_TECENT0823_2_H
#define UNTITLED_TECENT0823_2_H
#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> edges, int n){
    int m = edges.size();
    vector<set<int>> adj_ls(n);
    for(int i = 0; i < m; ++i){
        int u = edges[i][0], v = edges[i][1];
        adj_ls[u - 1].insert(v - 1);
        adj_ls[v - 1].insert(u - 1);
    }
    map<set<int>, int> cnt;
    for(auto adj: adj_ls){
        if(cnt.find(adj) == cnt.end()){
            cnt[adj] = 1;
        }
        else{
            cnt[adj]++;
        }
    }
    int res = 0;
    for(auto ptr = cnt.begin(); ptr != cnt.end(); ptr++){
        int n = ptr->second;
        if(n > 1){

//            auto st = ptr->first;
//            for(auto ptr = st.begin(); ptr != st.end(); ptr++){
//                cout << *ptr << ' ';
//            }
//            cout << endl;
            res += n * (n - 1) / 2;
        }
    }
    return res;
}
int tecent0823_2(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    int u, v;
    for(int mi = 0; mi < m; ++mi){
        cin >> u >> v;
        edges.push_back({u, v});
    }
    cout << solve(edges, n) << endl;
    return 0;
}
#endif //UNTITLED_TECENT0823_2_H

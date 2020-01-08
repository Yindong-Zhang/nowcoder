//
// Created by yindong on 19-9-15.
//

#ifndef UNTITLED_TREEMAXROUTELENGTH_H
#define UNTITLED_TREEMAXROUTELENGTH_H
#include<vector>
#include<iostream>
typedef long long llong;
using namespace std;
typedef pair<int, llong> edge;

//TODO: 0%

llong dfs(int u, vector<vector<edge>> &adj, vector<llong> &res){
    llong ans = 0;
    for(int i = 0; i < adj[u].size(); i++){
        llong tmp = dfs(adj[u][i].first, adj, res);
        if( tmp + adj[u][i].second > ans){
            ans =  tmp + adj[u][i].second;
        }
    }
    res[u] = ans;
    return ans;
}


vector<llong> solve(vector<vector<edge>> adj){
    vector<llong> res(adj.size(), 0);
    dfs(0, adj, res);
    return res;
}


int maxTreeRouteLength(){
    int n;
    cin >> n;
    vector<vector<edge>> adj(n, vector<edge>());
    int u, v;
    llong c;

    for(int i = 0; i < n - 1; i++){
        cin >> u >> v >> c;
        adj[u - 1].push_back({v - 1, c});
    }
    auto res = solve(adj);
    for(int i = 0; i < res.size(); i++){
        cout << res[i];
        if(i != res.size() - 1){
            cout << ' ';
        }
    }
    return 0;
}

#endif //UNTITLED_TREEMAXROUTELENGTH_H

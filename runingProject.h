//
// Created by so_go on 2020/3/19.
//

#ifndef UNTITLED_RUNINGPROJECT_H
#define UNTITLED_RUNINGPROJECT_H
#include<bits/stdc++.h>
#include"printVector.h"

#define MAX 0x3f3f3f3f
using namespace std;
typedef long long ll;
struct Edge{
    ll u, v;
    ll cost;
};
// 单源最短路算法， bellman-ford, dijstra

// bellman-ford 算法，有向图
bool bellman_ford(vector<Edge> &E, vector<ll> &dist){
    // dist array should be initial distance array, in which souce point distance = 0, and the rest = inf
    ll node_num= dist.size();
    for(ll n = 0; n < node_num; ++n){
        for(auto &edge : E){ // 对所有边进行原地松弛
            if(dist[edge.v] > dist[edge.u] + edge.cost){
                dist[edge.v] = dist[edge.u] + edge.cost;
            }
            if(dist[edge.u] > dist[edge.v] + edge.cost){
                dist[edge.u] = dist[edge.v] + edge.cost;
            }
        }
    }
    for(auto &edge: E){
        if(dist[edge.v] > dist[edge.u] + edge.cost){
            return false;
        }
    }
    return true;
}
ll solve(vector<Edge> &E, ll n, ll s, ll k){
    vector<ll> d(n, MAX);
    d[s] = 0;

    bellman_ford(E, d);
    printVector(d);
    ll res = 0;
    for(ll i = 0; i < n; i++){
        if(d[i] == k){
            res++;
        }
    }
    for(Edge &e: E){
        if(d[e.u] < k and k < d[e.u] + e.cost){
            if(2 * k < d[e.u] + d[e.v] + e.cost){
                res++;
            }
            if(2 * k == d[e.u] + d[e.v] + e.cost){
                res++;
                continue;
            }
        }
        if(d[e.v] < k and k < d[e.v] + e.cost){
            if( 2 * k < d[e.u] + d[e.v] + e.cost){
                res++;
            }
        }
    }
    return res;
}
ll runningProject(){
    ll n, m, s, k;
    vector<Edge> E;
    cin >> n >> m >> s;
    ll u, v, w;
    for(ll i = 0; i < m; ++i){
        cin >> u >> v >> w;
        E.push_back(Edge{u - 1, v - 1, w});
    }
    cin >> k;
    cout << solve(E, n, s, k) << endl;
    return 0;
}
#endif //UNTITLED_RUNINGPROJECT_H

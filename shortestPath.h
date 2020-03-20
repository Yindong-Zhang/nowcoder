//
// Created by so_go on 2020/3/12.
//

#ifndef UNTITLED_SHORTESTPATH_H
#define UNTITLED_SHORTESTPATH_H
#include<bits/stdc++.h>
#define MAX 0x3f3f3f3f // inf + inf = inf, inf + k = inf
using namespace std;

struct Edge{
    int u, v;
    int cost;
};
// 单源最短路算法， bellman-ford, dijstra

// bellman-ford 算法，有向图
bool bellman_ford(vector<Edge> E, vector<int> &dist){
    // dist array should be initial distance array, in which souce point distance = 0, and the rest = inf
    int node_num= dist.size();
    for(int n = 0; n < node_num; ++n){
        for(auto &edge : E){ // 对所有边进行原地松弛
            if(dist[edge.v] > dist[edge.u] + edge.cost){
                dist[edge.v] = dist[edge.u] + edge.cost;
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


void dijstra(vector<vector<Edge>> &E, vector<int> &dist, int n, int s){
    // dist array should be initial distance array, in which souce point distance = 0, and the rest = inf
    /*
     * s: start point ind;
     * E: node mapped edge list
     * n: number of nodes
     */
    vector<bool> is_ready(n, false);
    for(int i = 0; i < n; ++i){
        int min_dist= INT_MAX, min_ind = -1;
        for(int i = 0; i < n; ++i){
            if(not is_ready[i] and dist[i] < min_dist){
                min_dist = dist[i];
                min_ind = i;
            }
        }
        is_ready[min_ind] = true;
        // 接下来进行松弛
        for(Edge &e: E[min_ind]){
            if(dist[e.v] > dist[e.u] + e.cost){
                dist[e.v] = dist[e.u] + e.cost;
            }
        }
    }
}

struct D{
    int ind, dist;
    bool operator <(const D& a, const D& b) const {
        return a.dist < b.dist;
    }
};
void priorityQueueDijstra(vector<vector<Edge>> &E, vector<int> &dist, int n, int s){
    // dist array should be initial distance array, in which souce point distance = 0, and the rest = inf
    /*
     * s: start point ind;
     * E: node mapped edge list
     * n: number of nodes
     */
    priority_queue<D> q;
    vector<bool> visited(n, false);
    q.push({s, 0});
    while(not q.empty()){
        auto record = q.top();
        q.pop();
        if(visited[record.ind]){
            continue;
        }
        dist[record.ind] = record.dist;
        visited[record.ind] = true;
        for(Edge &e: E[record.ind]){ // 松弛操作
            if(dist[e.v] > dist[e.u] + e.cost){
                dist[e.v] = dist[e.u] + e.cost;
                q.push({e.v, dist[e.v]});
            }
        }
    }
}

// 多源最短路，floyd算法

void floyd(vector<int> &E, vector<vector<int>> dist){
    // dist should be a matrix in shape(num_node ,num_node)
    int num_node = dist.shape[0];
    for(int i = 0; i < num_node; ++i){
        for(int j = 0; j < num_node; ++j){
            dist[i][j] = MAX;
        }
    }

    for(Edge &e : E){
        dist[e.u][e.v] = e.cost;
    }
    for(int k = 0; k < num_node; ++k){
        for(int i = 0; i < num_node; ++i){
            for(int j = 0; j < num_node; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // 原地松弛
            }
        }
    }
}
#endif //UNTITLED_SHORTESTPATH_H



//
// Created by so_go on 2020/3/12.
//

#ifndef UNTITLED_SHORTESTPATH_H
#define UNTITLED_SHORTESTPATH_H
#include<bits/stdc++.h>
#include<assert.h>
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

void dijstra(vector<Edge> E, vector<int> &dist){

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



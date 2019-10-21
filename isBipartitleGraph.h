//
// Created by LCY on 2019/10/21.
//
/*
 * 题目描述
给定一个由n个点，m条边组成的无向图（注意，此图可能不连通），对任意1 ≤ i ≤ m存在一条边连接u[i], v[i]。回答此图是不是二分图。二分图定义为存在一种给图中每一个点染上黑白两色其中之一的着色方式，使得对每一对有边直接相连的点颜色不同。

输入描述:
第一行输入为N和M，代表无向图的点数和边数。

接下来M行，表示M条边，每一行两个整数u[i], v[i]，满足1 ≤ u[i], v[i] ≤ n，保证图中无重边，自环。

其中保证1 ≤ N, M ≤ 100000
输出描述:
一行字符串，为Yes，或者No。

Yes表示输入图是二分图。

No表示输入图不是二分图。
示例1
输入
复制
5 7
1 2
2 3
3 4
4 1
4 5
5 2
 // 样例少一行
输出
复制
Yes
 */
#ifndef UNTITLED_ISBIPARTITLEGRAPH_H
#define UNTITLED_ISBIPARTITLEGRAPH_H
#include<vector>
#include<iostream>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj_list,vector<bool> &visited, vector<int> &colors){
//    cout << node << endl;
    for(int next_node: adj_list[node]){
        if(not visited[next_node]){
            colors[next_node] = -colors[node];
            visited[next_node] = true;
            if(not dfs(next_node, adj_list, visited, colors)){
                return false;
            };
        }
        else{
            if(colors[next_node] == colors[node]){
                return false;
            }
        }
//        cout << ' ' << node << ' ' << colors[node] << ' ' << next_node << ' ' << colors[next_node] << endl;
    }
    return true;
}
bool solve(vector<vector<int>> adj_list, int N){
    vector<int> colors(N, 0);
    vector<bool> visit(N, false);
    for(int i = 0; i < N; i++){
        if(not visit[i]){
            visit[i] = true;
            colors[i] = 1;
            if(not dfs(i, adj_list, visit, colors)){
                return false;
            }

        }
    }
    return true;
}

int isBipartitleGraph(){
    int N, M;
    cin>> N >> M;
    vector<vector<int>> adj_list(N);
    int u, v;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        adj_list[u - 1].push_back(v - 1);
        adj_list[v - 1].push_back(u - 1);
    }
//    for(int i = 0; i < N; i++){
//        for(int j = 0; j < adj_list[i].size();j++){
//            cout << adj_list[i][j] << ' ';
//        }
//        cout << endl;
//    }

    if(solve(adj_list, N))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
#endif //UNTITLED_ISBIPARTITLEGRAPH_H

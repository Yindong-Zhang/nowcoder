//
// Created by so_go on 2020/8/15.
//

#ifndef UNTITLED_MERGELOCATIONS_H
#define UNTITLED_MERGELOCATIONS_H
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class UnionFindSet{
public:
    vector<int> parent;
    UnionFindSet(int n){
        for(int i = 0; i < n; i++){
            parent.push_back(i);
        }
    }

    /*
     * 一个写法
    int find(int i){
        int root= i;
        while(parent[root] != root){
            root= parent[root];
        }
        // 路劲压缩
        int cur= i, tmp;
        while(cur != root){
            tmp = parent[cur];
            parent[cur]= root;
            cur= tmp;
        }
        return root;
    }
    */

    // 递归写法：
    int find(int i){
        // 对于当前节点，查找根节点，并返回
        if(parent[i] != i){
            parent[i] = find(parent[i]); // 路径压缩在find不断上溯的过程中完成
        }
        return parent[i];
    }

    // 或者
    /*
    int find(int i){
        if(parent[i] == i){
            return i;
        }
        pre[x] = find(pre[x]);
        return pre[x];
    }
     */

    int join(int i, int j){
        int rti= find(i);
        int rtj = find(j);
        if(rti != rtj){
            parent[rti] = rtj;
        }
    }
};

vector<vector<int>> solve(vector<vector<int>> &edges, int n){
    UnionFindSet ufs(n);
    for(auto edge: edges){
        int u = edge[0], v = edge[1];
        ufs.join(u - 1, v - 1);
    }
    map<int, int> s2i;
    vector<vector<int>> res;
    for(int i = 0; i < n; ++i){
        if(s2i.find(ufs.find(i)) == s2i.end()){
            s2i[ufs.parent[i]] = res.size();
            res.push_back({i + 1, });
        }
        else{
            int ind = s2i[ufs.find(i)];
            res[ind].push_back(i + 1);
        }
    }
    return res;
}
int mergeLocs(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    int u, v;
    for(int mi = 0; mi < m; ++mi){
        cin >> u >> v;
        edges.push_back({u, v});
    }
    vector<vector<int>> res = solve(edges, n);
    cout << res.size() << endl;
    for(auto vec: res){
        for(int i : vec){
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
#endif //UNTITLED_MERGELOCATIONS_H

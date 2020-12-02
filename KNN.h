//
// Created by so_go on 2020/12/2.
//

#ifndef UNTITLED_KNN_H
#define UNTITLED_KNN_H
#include<bits/stdc++.h>
using namespace std;
struct Record{
    double dist;
    int index;
    bool operator >(Record &b){
        if(dist > b.dist){
            return true;
        }
        return false;
    }
};
double distance(vector<double> &a, vector<double> &b){
    double res = 0;
    res += (a[0] - b[0]) * (a[0] - b[0]);
    res += (a[1] - b[1]) * (a[1] - b[1]);
    return res;
};

vector<int> knn(vector<vector<double>> points, vector<double> req, int k){
    priority_queue<Record, greater<Record>> max_heap;
    for(int i = 0; i < points.size(); ++i){
        double dist = distance(points[i], req);
        if(max_heap.size() < k){
            max_heap.emplace(dist, i);
        }
        else{
            if(dist < max_heap.top().dist){
                max_heap.pop();
                max_heap.push(Record{dist, i});
            }
        }
    }
    vector<int> res;
    while(not max_heap.empty()){
        int index = max_heap.top().index;
        max_heap.pop();
        res.push_back(index);
    }
    return res;
}
#endif //UNTITLED_KNN_H

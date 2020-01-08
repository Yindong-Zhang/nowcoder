//
// Created by yindong on 19-9-8.
//

#ifndef UNTITLED_ROBOTSINLINE_H
#define UNTITLED_ROBOTSINLINE_H

#include <vector>
#include<iostream>
using namespace std;

int solve(vector<int> robots){
    vector<int> count(robots.size(), 0);
    for(int i = 0; i < robots.size(); i++){
        int si = -1;
        int j = i - 1;
        while( j >= 0){
            if(robots[j] >= robots[i]){
                si = j;
                break;
            }
            j--;
        }
        if(si != -1){
            count[si]++;
        }
    }
    int maxInd = -1, maxCount = 0;
    for(int i = 0; i < count.size(); i++){
        if(count[i] > maxCount){
            maxInd = i;
            maxCount = count[i];
        }
    }
    if(maxInd != -1){
        return robots[maxInd];
    }
    else{
        return -1;
    }
}

int robotsInLine(){
    int n, robot;
    vector<int> robots;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> robot;
        robots.push_back(robot);
    }
    cout << solve(robots) << endl;
    return 0;
}
#endif //UNTITLED_ROBOTSINLINE_H

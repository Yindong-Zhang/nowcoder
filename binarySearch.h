//
// Created by so_go on 2020/12/2.
//

#ifndef UNTITLED_BINARYSEARCH_H
#define UNTITLED_BINARYSEARCH_H

#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> nums, int req){
    int l = 0, r = nums.size();
    while(l <= r){
        int m = (l + r) / 2;
        if(nums[m] == req){
            return m;
        }
        else if(req < nums[m]){
            r = m - 1;
        }
        else if(req > nums[m]){
            l = m + 1;
        }
    }
    return -1;
}
#endif //UNTITLED_BINARYSEARCH_H

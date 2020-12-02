//
// Created by so_go on 2020/11/27.
//

#ifndef UNTITLED_TEST1127_H
#define UNTITLED_TEST1127_H
#include<bits/stdc++.h>
using namespace std;
bool ssolve(vector<int> nums){
    int mCnt = 0;
    for(int i = 1; i < nums.size(); ++i){
        if(nums[i] <= nums[i - 1]){
            continue;
        }
        else{
            mCnt++;
            if(i > 1 and i < nums.size() - 1 and nums[i - 1] < nums[ i + 1] and nums[i - 2] < nums[i]){
//                cout << i << ' ' << endl;
                return false;
            }
        }
        if(mCnt > 1){
//            cout << '2' ;
            return false;
        }
    }
    return true;
}
int solve(){
    vector<int> nums{7, 5, 5, 4, 8};
    cout << ssolve(nums) << endl;
    return 0;
}
#endif //UNTITLED_TEST1127_H

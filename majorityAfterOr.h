//
// Created by so_go on 2020/3/12.
//

#ifndef UNTITLED_MAJORITYAFTEROR_H
#define UNTITLED_MAJORITYAFTEROR_H
#include<bits/stdc++.h>
using namespace std;

int majority(vector<int>& nums){
    vector<int> count(1000, 0);
    for(int &n : nums){
        count[n] += 1;
    }
    int res = INT_MIN;
    for(int i = 0; i < 1000; i++){
        res= max(res, count[i]);
    }
    return res;
}
int main(){
    int n, x;
    vector<int> nums;
    cin >> n >> x;
    int x_ = ~x;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        nums.push_back(num & x_);
    }
    cout <<  majority(nums) << endl;
    return 0;
}
#endif //UNTITLED_MAJORITYAFTEROR_H

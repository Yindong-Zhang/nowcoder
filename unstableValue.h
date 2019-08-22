//
// Created by yindong on 19-8-22.
//
/*
 * 题目描述
小易有一些立方体，每个立方体的边长为1，他用这些立方体搭了一些塔。
现在小易定义：这些塔的不稳定值为它们之中最高的塔与最低的塔的高度差。
小易想让这些塔尽量稳定，所以他进行了如下操作：每次从某座塔上取下一块立方体，并把它放到另一座塔上。
注意，小易不会把立方体放到它原本的那座塔上，因为他认为这样毫无意义。
现在小易想要知道，他进行了不超过k次操作之后，不稳定值最小是多少。
输入描述:

第一行两个数n,k (1 <= n <= 100, 0 <= k <= 1000)表示塔的数量以及最多操作的次数。
第二行n个数，ai(1 <= ai <= 104)表示第i座塔的初始高度。

输出描述:

第一行两个数s, m，表示最小的不稳定值和操作次数(m <= k)
接下来m行，每行两个数x,y表示从第x座塔上取下一块立方体放到第y座塔上。

示例1
输入
复制

3 2
5 8 5

输出
复制

0 2
2 1
2 3


 */
#ifndef UNTITLED_UNSTABLEVALUE_H
#define UNTITLED_UNSTABLEVALUE_H
#include<vector>
#include<iostream>
using namespace std;
typedef pair<int, int> action;

void solve(vector<int> nums, int k){
    int ind_min = -1, ind_max = -1, count = 0;
    vector<action> acts;
    for(int j = 0;j < k; j++){
        ind_min = ind_max = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < nums[ind_min]){
                ind_min = i;
            }
            if(nums[i] > nums[ind_max]){
                ind_max = i;
            }
        }
        if(nums[ind_max] - nums[ind_min] <= 1){
            break;
        }
        else{
            nums[ind_max]--;
            nums[ind_min]++;
            acts.push_back(action(ind_max, ind_min));
            count++;
        }
    }

    ind_min = 0;
    ind_max = 0;
    for(int i = 0; i < nums.size(); i++){
        if( nums[i] < nums[ind_min]){
            ind_min = i;
        }
        if( nums[i] > nums[ind_max]){
            ind_max = i;
        }
    }
    cout << nums[ind_max] - nums[ind_min] << ' ' << count << endl;
    for(int i = 0; i < acts.size(); i++){
        cout << acts[i].first + 1  << ' ' << acts[i].second + 1;
        if( i != acts.size() - 1){
            cout << endl;
        }
    }
}
int unstableValue(){
    int n, k;
    int height;
    vector<int> heights;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> height;
        heights.push_back(height);
    }
    solve(heights, k);
    return 0;
}
#endif //UNTITLED_UNSTABLEVALUE_H

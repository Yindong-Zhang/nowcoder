//
// Created by yindong on 19-8-11.
//

#ifndef UNTITLED_CIRCLEMOVESUM_H
#define UNTITLED_CIRCLEMOVESUM_H
#include<vector>
#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;

/* 未完成
 * 珍珠项链问题
 * 暴力搜索, 似乎完成了
 */

int distSum(int ind, vector<int> point, const int N){
    vector<int> reorder(point.size());
    int dist = 0;
    for(int i = 0; i < point.size(); i++){
        dist = point[i] - point[ind];
        if(dist <= N / 2 and dist > -N / 2){
            reorder[i] = dist;
        }
        else if (dist > N / 2){
            reorder[i] =  -N + dist;
        }
        else{
            reorder[i] = N + dist;
        }
    }
    for(int i = 0; i < point.size(); i++){
        cout << reorder[i] << ' ';
    }
    cout << endl;
    sort(reorder.begin(), reorder.end());
    for(int i = 0; i < point.size(); i++){
        cout << reorder[i] << ' ';
    }
    cout << endl;
    int zero_ind = 0;
    for(; zero_ind < reorder.size(); zero_ind++){
        if(reorder[zero_ind] == 0){
            break;
        }
    }
    int sum = 0;
    int left = 1, right = 1;
    for(int left_ind = zero_ind - 1; left_ind >= 0; left_ind--){
        sum = sum - reorder[left_ind] - left;
        cout << left_ind << ' ' << reorder[left_ind]  << ' ' << sum << endl;
        left++;
    }
    for(int right_ind = zero_ind + 1;  right_ind!= reorder.size(); right_ind++){
        sum = sum + reorder[right_ind] - right;
        cout << right_ind << ' ' << reorder[right_ind] << ' ' << sum << endl;
        right++;
    }
    cout << "sum" << ' ' << sum << endl;
    return sum;
}

int circleMoveSum(){
    int N, L;
    cin >> N >> L;
    vector<int> point(L);

    for(int i = 0; i < L; i++){
        cin >> point[i];
    }
    sort(point.begin(), point.end());
    cout << "size: " << point.size() << endl;
    int min = INT_MAX, tmp;
    for(int i = 0; i < L; i++){
        cout << i << endl;
        tmp = distSum(i, point, N);
        if (tmp < min){
            min = tmp;
        }
        cout << min << endl;
    }
    return min;
}
#endif //UNTITLED_CIRCLEMOVESUM_H

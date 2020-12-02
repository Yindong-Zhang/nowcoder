//
// Created by so_go on 2020/8/12.
//

#ifndef UNTITLED_CROSSCUT_H
#define UNTITLED_CROSSCUT_H
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
void choice(vector<vector<int>> &nums, vector<ll> &rowSum, vector<ll > &colSum, int N,  int &n, int &m){
    ll mx = LLONG_MIN;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            ll tmp = rowSum[i] + colSum[j] - nums[i][j];
            if(tmp > mx){
                mx = tmp;
                n = i + 1;
                m = j + 1;
            }
        }
    }
//    cout << n << ' ' << m << endl;
    return;
}
void solve(vector<vector<int>> &nums){
    int N = nums.size();
    vector<ll > rowSum(N, 0), colSum(N, 0);
    for(int i = 0; i < N; ++i){
        ll tRowSum = 0, tColSum = 0;
        for(int j = 0; j < N; ++j){
            tRowSum += nums[i][j];
            tColSum += nums[j][i];
        }
        rowSum[i] = tRowSum;
        colSum[i] = tColSum;
    }
    for(int Ni = 0; Ni < N; ++Ni){
        int n = 0, m = 0;
        choice(nums, rowSum, colSum, N - Ni, n, m);
        for(int i = 0; i < N - Ni; ++i){
            rowSum[i] = rowSum[i] - nums[i][m - 1];
            colSum[i] = colSum[i] - nums[n - 1][i];
        }
        cout << n << ' ' << m << endl;
        for(int i = n; i < N - Ni; ++i){
            rowSum[i - 1] = rowSum[i];
            for(int j = 0; j < N - Ni; ++j){
                nums[i - 1][j] = nums[i][j];
            }
        }
        for(int j = m; j < N - Ni; ++j){
            colSum[j - 1] = colSum[j];
            for(int i = 0; i < N - Ni; ++i){
                nums[i][j - 1] = nums[i][j];
            }
        }
    }
    return;
}
int crossCut(){
    int N;
    cin >> N;
    vector<vector<int>> nums(N, vector<int>(N, 0));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> nums[i][j];
        }
    }
    solve(nums);
    return 0;
}
#endif //UNTITLED_CROSSCUT_H

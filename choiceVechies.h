//
// Created by so_go on 2020/8/15.
//

#ifndef UNTITLED_CHOICEVECHIES_H
#define UNTITLED_CHOICEVECHIES_H
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct S{
    int x, y;
};
int solve(vector<S> nums, int a, int b){
    int n = nums.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>( a + 1, vector<int>(b + 1, 0)));
    for(int ni = 1; ni <= n; ++ni){
        for(int ai = 0; ai <= a; ++ai){
            for(int bi = 0; bi <= b; ++bi){
                int tmp = dp[ni - 1][ai][bi];
                if(ai > 0){
                    tmp = max(tmp, dp[ni - 1][ai - 1][bi] + nums[ni - 1].x);
                }
                if(bi > 0){
                    tmp = max(tmp, dp[ni - 1][ai][bi - 1] + nums[ni - 1].y);
                }
                dp[ni][ai][bi] = tmp;
            }
        }
    }
    return dp[n][a][b];
}

int solve_1(vector<S> nums, int a, int b){
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(b + 1, 0));
    for(int bi = 0; bi <= b and bi + a <= n; ++bi){
        int ni = bi + a;
        dp[ni][bi] = max(dp[ni - 1][bi - 1] + nums[ni - 1].y, dp[ni - 1][bi]);
    }
    for(int bi = 0; bi <= b; ++ bi){
        for(int ni = bi + a + 1; ni <= n; ++ni){
            dp[ni][bi] = max(dp[ni - 1][bi - 1] + nums[ni - 1].y, dp[ni - 1][b] + nums[ni - 1].x);
        }
    }
    return dp[n][b];
}
int choiceV(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<S> nums;
    int x, y;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        nums.push_back({x, y});
    }
    cout << solve_1(nums, a, b) << endl;
    return 0;
}
#endif //UNTITLED_CHOICEVECHIES_H

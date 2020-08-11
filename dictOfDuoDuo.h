//
// Created by so_go on 2020/8/11.
//
/*
 * 多多鸡打算造一本自己的电子字典，里面的所有单词都只由a和b组成。
每个单词的组成里a的数量不能超过N个且b的数量不能超过M个。
多多鸡的幸运数字是K，它打算把所有满足条件的单词里的字典序第K小的单词找出来，作为字典的封面。

输入描述:

共一行，三个整数N, M, K。(0 < N, M < 50, 0 < K < 1,000,000,000,000,000)


输出描述:

共一行，为字典序第K小的单词。


输入例子1:

2 1 4


输出例子1:

ab


例子说明1:

满足条件的单词里，按照字典序从小到大排列的结果是
a
aa
aab
ab
aba
b
ba
baa


 */
#ifndef UNTITLED_DICTOFDUODUO_H
#define UNTITLED_DICTOFDUODUO_H
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
// 64% 碰到了大数问题
string solve(int N, int M, ll K){
    vector<vector<ll>> dp(N + 1, vector<ll>( M + 1, 0));
    for(int i = 1; i <= N; ++i){
        dp[i][0] = i;
    }
    for(int j = 1; j <= M; ++j){
        dp[0][j] = j;
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + 2;
        }
    }
    cout << dp[N][M] << endl;
    string res;
    while(K > 0){
        if(N - 1 >= 0 and K <= dp[N - 1][M] + 1){
            K--;
            res.push_back('a');
            N--;
        }
        else{
            if(N - 1 >= 0){
                K = K - dp[N - 1][M] - 2;
            }
            else{
                K--;
            }
            res.push_back('b');
            M--;
        }
//        cout << res << ' ' << N << ' ' << M << ' ' << K << endl;
    }
    return res;
}

int dictOfDuoDuo(){
    int N, M;
    ll K;
    cin >> N >> M >> K;
//    cout << N << M << K << endl;
    cout << solve(N, M, K) << endl;
    return 0;
}
#endif //UNTITLED_DICTOFDUODUO_H

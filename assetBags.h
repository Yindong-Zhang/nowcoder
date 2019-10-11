//
// Created by LCY on 2019/10/11.
//
/*
 * 题目描述
在金融资产交易中，经常涉及到资产包的挑选打包。在资产包打包过程中，每种类型的资产有固定的数量与价值，需选择某几种资产打包，使得资产包总价值最大。打包时每种资产只能整体打包，不能分割。假设现有可容纳M条资产的资产包，另外有N种资产。资产Na数量为Ta条，总价值为Va元；资产Nb数量为Tb条，总价值为Vb元；资产Nc数量为Tc条，总价值为Vc元......；资产Nn数量为Tn，总价值为Vn。编写算法，挑选哪些类型资产放入资产包可使得资产包总价值最大？
输入描述:

资产总量,资产种类,每类资产条数,每类资产价值(逗号分隔)；其中每类资产条数与每类资产价值为空格分隔。
总格式如下：
资产总量,资产种类,资产A条数 资产B条数 资产C条数,资产A价值 资产B价值 资产C价值！
举例，资产总量为12，资产种类3种，3种资产条数分别为4，5，7，三种资产价值分别是500元，600元，800元，输入如下：
12,3,4 5 7,500 600 800
资产总量和资产种类都不超过1000，资产条数不超过1000，资产价值不超过10000，所有数值均为正整数。

输出描述:

资产包中资产最大总价值

示例1
输入
复制

12,3,4 5 7,500 600 800

输出
复制

1400


 */
#ifndef UNTITLED_ASSETBAGS_H
#define UNTITLED_ASSETBAGS_H

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int solve(int capacity, vector<int> counts, vector<int> values){
    int n = counts.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= capacity; j++){
            if( j - counts[i - 1] >= 0){
                dp[i][j] = max(dp[i - 1][j - counts[i - 1]] + values[i - 1], dp[i - 1][j]);

            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][capacity];
}

int assetBag(){
    int n, capacity;
    cin >> capacity;
    cin.get();
    cin >> n;
    cin.get();
    vector<int> counts(n, 0);
    vector<int> values(n, 0);
    for(int i = 0; i < n; i++){
        cin >> counts[i];
    }
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }
    for(int i = 0; i < n; i++){
        cout << counts[i] << ' ';
    }
    cout << endl;
    cout << solve(capacity, counts, values);
    return 0;
}
#endif //UNTITLED_ASSETBAGS_H

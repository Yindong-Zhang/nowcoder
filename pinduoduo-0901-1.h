//
// Created by so_go on 2020/9/1.
//

#ifndef UNTITLED_PINDUODUO_0901_1_H
#define UNTITLED_PINDUODUO_0901_1_H
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int n){
    vector<vector<int>> res(n, vector<int>(n, 0));
    for(int j = 0; j < n; ++j){
        for(int i = 0; i < n; ++i){
            if(j > i){
                if(i + j < n - 1){
                    if(j < n / 2){
                        res[i][j] = 2;
                    }
                    else if (j >= (n + 1) / 2 ){
                        res[i][j]= 1;
                    }
                }
                else if(i + j > n - 1){
                        if(i < n / 2) {
                            res[i][j] = 8;
                        }
                        else if(i >= (n + 1) /  2){
                            res[i][j] = 7;
                        }
                }
            }
            else if(j < i){
                if( i + j < n - 1){
                    if(i < n / 2){
                        res[i][j] = 3;
                    }
                    else if( i >= (n + 1)/ 2){
                        res[i][j] = 4;
                    }
                }
                else if (i + j > n - 1){
                    if( j < n / 2){
                        res[i][j] = 5;
                    }
                    else if(j >= (n + 1) / 2){
                        res[i][j] = 6;
                    }
                }
            }
        }

    }
    return res;
}
int pinduoduo_0901_1(){
    int n;
    cin >> n;
    auto res = solve(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
#endif //UNTITLED_PINDUODUO_0901_1_H

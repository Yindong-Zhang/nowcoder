//
// Created by yindong on 19-8-25.
//

#ifndef UNTITLED_GAME1024_H
#define UNTITLED_GAME1024_H
#include<iostream>
#include<vector>
using namespace std;

void solve(int d, vector<vector<int>> &a){
    if(d == 2){
        for(int col = 0; col < 4; col++){
            int i = 3, i1, j = 3;
            while(i >= 0){

                if(a[i][col] == 0){
                    i--;
                }
                else if(i > 0){
                    i1 = i - 1;
                    while(i1 >= 0 and a[i1][col] == 0){
                        i1--;
                    }
                    if(i1 >= 0 and a[i1][col] == a[i][col]){
                        a[j][col] = a[i][col] + a[i1][col];
                        j--;
                        i = i1 - 1 ;
                    }
                    else{
                        a[j][col] = a[i][col];
                        j--;
                        i--;
                    }

                }

            }
            while(j >= 0){
                a[j][col] = 0;
                j--;
            }
        }
    }
    else if(d == 1){
        for(int col = 0; col < 4; col++){
            int i = 0, j = 0, i1 = 0;
            while(i < 4){
                if(a[i][col] == 0){
                    i++;
                }
                else{
                    i1 = i + 1;
                    while(i1 < 4 and a[i1][col] == 0){
                        i1++;
                    }
                    if(i1 < 4 and a[i1][col] == a[i][col]){
                        a[j][col] = a[i][col] + a[i1][col];
                        j++;
                        i = i1 + 1;
                    }
                    else{
                        a[j][col] = a[i][col];
                        j++;
                        i++;
                    }

                }
            }
            while(j < 4){
                a[j][col] = 0;
                j++;
            }
        }
    }
    else if(d == 3){
        for(int row = 0; row < 4; row++){
            int i = 0, j = 0, i1;
            while(i < 4){
                if(a[row][i] == 0){
                    i++;
                }
                else{
                    i1 = i + 1;
                    while(i1 < 4 and a[row][i1] == 0){
                        i1++;
                    }
                    if(i1 < 4 and a[row][i1] == a[row][i]){
                        a[row][j] = a[row][i] + a[row][i1];
                        j++;
                        i = i1 + 1;
                    }
                    else{
                        a[row][j] = a[row][i];
                        j++;
                        i++;
                    }

                }
            }
            while(j < 4){
                a[row][j] = 0;
                j++;
            }
        }
    }
    else if(d == 4){
        for(int row = 0; row < 4; row++){
            int i = 3, j = 3, i1;
            while(i >= 0){
                if(a[row][i] == 0){
                    i--;
                }
                else {
                    i1 = i - 1;
                    while (i1 >= 0 and a[row][i1] == 0) {
                        i1--;
                    }
                    if (i1 >= 0 and a[row][i1] == a[row][i]) {
                        a[row][j] = a[row][i] + a[row][i1];
                        j--;
                        i = i1 - 1 ;
                    } else {
                        a[row][j] = a[row][i];
                        j--;
                        i--;
                    }
                }
            }
            while(j >= 0){
                a[row][j] = 0;
                j--;
            }
        }
    }
}
int game1024(){
    int n;
    cin >> n;
    vector<vector<int>> a(4, vector<int>(4, 0));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j< 4; j++){
            cin >> a[i][j];
        }
    }
    solve(n, a);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}
#endif //UNTITLED_GAME1024_H

//
// Created by yindong on 19-9-4.
//
/*
 *
 *
 * 10
1 0.90
0 0.70
1 0.60
1 0.55
0 0.52
1 0.40
0 0.38
0 0.35
1 0.31
0 0.10
 */
#ifndef UNTITLED_AUC_H
#define UNTITLED_AUC_H
#define EPS 1E-9
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

float auc(vector<float> pos, vector<float> neg){
    float punish = 0;
    for(int i = 0; i < pos.size(); i++){
        for(int j = 0; j < neg.size(); j++){
            if(pos[i] < neg[j]){
               punish += 1;
            }
            else if(fabs(pos[i] - neg[j]) < EPS){
                punish += 0.5;
            }
        }

    }
    return 1 - punish / (pos.size() * neg.size());
}

int auc(){
    int n;
    cin >> n;
    vector<float> pos;
    vector<float> neg;
    int label;
    float pred;
    for(int i = 0; i < n; i++){
        cin >> label >> pred;
        if(label){
            pos.push_back(pred);
        }
        else{
            neg.push_back(pred);
        }
    }
    cout << auc(pos, neg) << endl;
}
#endif //UNTITLED_AUC_H

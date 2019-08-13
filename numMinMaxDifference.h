//
// Created by so_go on 2019/8/13.
//

#ifndef UNTITLED_NUMMINMAXDIFFERENCE_H
#define UNTITLED_NUMMINMAXDIFFERENCE_H
#include<vector>
#include<algorithm>
#include<climits>

// incomplete
using namespace std;
int numMinDifference(vector<int> a){
    sort(a.begin(), a.end());
    int min= INT_MAX, min_count = 1, diff = 0;
    for(int i = 0; i < a.size() - 1; i++){
        diff = a[i + 1] - a[i];
        if(diff < min){
            min = diff;
            if (min == 0){
                break;
            }
            min_count= 1;
        }
        else if(diff == min){
            min_count++;
        }
    }
    if(min == 0){
        min_count = 0;
        int count = 1;
        for(int i = 1; i < a.size(); i++){
            if(a[i] == a[i - 1]){
                count+= 1;
            }
            else{
                min_count += count * (count - 1) / 2;
                count = 1;
            }
        }
        min_count += count * (count - 1) / 2;
    }
    return min_count;
}

int numMaxDifference(vector<int> a){
    int min = INT_MAX, min_count = 1, max = INT_MIN, max_count = 1;
    for(int i = 0; i < a.size(); i++){
        if(a[i] < min){
            min = a[i];
            min_count= 1;
        }
        else if(a[i] == min){
            min_count++;
        }
        if(a[i] > max){
            max = a[i];
            max_count = 1;
        }
        else if(a[i] == max){
            max_count++;
        }
    }
    return min_count * max_count;
}
#endif //UNTITLED_NUMMINMAXDIFFERENCE_H

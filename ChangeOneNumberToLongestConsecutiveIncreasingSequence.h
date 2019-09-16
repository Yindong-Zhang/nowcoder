//
// Created by yindong on 19-9-16.
//

#ifndef UNTITLED_CHANGEONENUMBERTOLONGESTCONSECUTIVEINCREASINGSEQUENCE_H
#define UNTITLED_CHANGEONENUMBERTOLONGESTCONSECUTIVEINCREASINGSEQUENCE_H


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int> vec){
    int n = vec.size();
    vector<int> pre(n,1);
    vector<int> last(n,1);
    for(int i=1;i<n;i++){    //pre记录的是以i结尾的递增子序列长度
        pre[i]=vec[i]>vec[i-1]?pre[i-1]+1:1;
    }
    for(int i=n-2;i>=0;i--){  //last记录的是以i开始的递增子序列长度
        last[i]=vec[i+1]>vec[i]?last[i+1]+1:1;
    }
    int res=1;
    for(int i=1;i<n-1;i++){
        if(vec[i+1]-vec[i-1]>=2)
            res=max(res,pre[i-1]+last[i+1]+1);
        else{
            int tmp = max(pre[i], last[i]) + 1;
            res = max(tmp, res);
        }
    }
    return res;

}
int changeMaxConsecutiveSeq(){
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for(int i= 0; i < n; i++){
        cin >> vec[i];
    }
    cout << solve(vec) << endl;
    return 0;
}

#endif //UNTITLED_CHANGEONENUMBERTOLONGESTCONSECUTIVEINCREASINGSEQUENCE_H

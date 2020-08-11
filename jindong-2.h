//
// Created by so_go on 2020/8/6.
//

#ifndef UNTITLED_JINDONG_2_H
#define UNTITLED_JINDONG_2_H
#include<bits/stdc++.h>
//#include"printVector.h"
using namespace std;

bool isPalindrome(vector<int> &nums, int ind){
    int i = 0, j = nums.size() - 1;
    if(ind == nums.size() - 1){
        j = nums.size() - 2;
        while( j == 0){
             j--;
        }
    }
    for(; i < j; i++, j--){
        if(i == ind){
            i++;
        }
        if(j == ind){
            j--;
        }
        if( nums[i] != nums[j]){
            return false;
        }
    }
    return true;
}
bool isPrime(int n){
    for(int i = 2; i <= sqrt(n); ++i){
        if( n % i == 0){
            return false;
        }
    }
    return true;
}
vector<int> num2vec(int n){
    vector<int> res;
    while(n > 0){
        res.push_back(n % 10);
        n = n / 10;
    }
    return res;
}
int solve(int N, int M){
    int count = 0;
    for(int n = N; n <= M; ++n){
        vector<int> nums = num2vec(n);
//        printVector(nums);
        for(int ind = 0; ind < nums.size(); ++ind){
//            cout << ind << ' ' << isPalindrome(nums, ind) << endl;
            if(isPalindrome(nums, ind)){
                int dn = 0;
                int base = 1;
                for(int i = 0; i < nums.size(); ++i){
                    if( i != ind){
                        dn += nums[i] * base;
                        base *= 10;
                    }
                }
                if(isPrime(dn)){
                    count++;
                    break;
                }
            }
        }

    }
    return count;

}
int jindong2(){
    int N, M;
    cin >> N >> M;
    cout << solve(N, M) << endl;
    return 0;
}
#endif //UNTITLED_JINDONG_2_H

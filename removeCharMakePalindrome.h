//
// Created by so_go on 2019/8/13.
//

#ifndef UNTITLED_REMOVECHARMAKEPALINDROME_H
#define UNTITLED_REMOVECHARMAKEPALINDROME_H
#include"longestCommonSubsequence.h"

int deleteCharLengthPalindrome(string a){
    string rev_a;
    for(int i = a.size() - 1; i >= 0; i--){
        rev_a.push_back(a[i]);
    }
    int length = longestCommonSubsequence(a, rev_a);
    return a.size() - length;
}
#endif //UNTITLED_REMOVECHARMAKEPALINDROME_H

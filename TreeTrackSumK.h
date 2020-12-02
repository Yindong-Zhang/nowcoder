//
// Created by so_go on 2020/12/2.
//

#ifndef UNTITLED_TREETRACKSUMK_H
#define UNTITLED_TREETRACKSUMK_H
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left, *right;
};
map<int, int> helper(TreeNode *root, int &res, int req){
    map<int, int> cnt_dkt;
    if(root == NULL){
        return cnt_dkt;
    }
    map<int, int> lcnt_dkt = helper(root->left, res, req);
    map<int, int> rcnt_dkt = helper(root->right, res, req);
    cnt_dkt[root->val] = 1;
    for(auto ptr = lcnt_dkt.begin(); ptr != lcnt_dkt.end(); ptr++){
        int sum = ptr->first + root->val;
        if(cnt_dkt.find(sum) == cnt_dkt.end()){
            cnt_dkt[sum] = ptr->second;
        }
        else{
            cnt_dkt[sum] += ptr->second;
        }
    }
    for(auto ptr = rcnt_dkt.begin(); ptr != rcnt_dkt.end(); ptr++){
        int sum = ptr->first + root->val;
        if(cnt_dkt.find(sum) == cnt_dkt.end()){
            cnt_dkt[sum] = ptr->second;
        }
        else{
            cnt_dkt[sum] += ptr->second;
        }
    }
    if(cnt_dkt.find(req) != cnt_dkt.end()){
        res += cnt_dkt[req];
    }
    return cnt_dkt;
}
int solve(TreeNode *root, int req){
    int res = 0;
    helper(root, res, req);
    return res;
}
#endif //UNTITLED_TREETRACKSUMK_H

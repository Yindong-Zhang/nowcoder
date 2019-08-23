//
// Created by yindong on 19-8-23.
//
/*
 * 题目描述
给满出二叉树，编写算法将其转化为求和树

什么是求和树：二叉树的求和树， 是一颗同样结构的二叉树，其树中的每个节点将包含原始树中的左子树和右子树的和。

二叉树：
                  10
               /      \
             -2        6
           /   \      /  \
          8    -4    7    5

求和树：
                 20(4-2+12+6)
               /      \
           4(8-4)      12(7+5)
            /   \      /  \
          0      0    0    0

二叉树给出前序和中序输入，求和树要求中序输出；
所有处理数据不会大于int；

输入描述:

2行整数，第1行表示二叉树的前序遍历，第2行表示二叉树的中序遍历，以空格分割

输出描述:

1行整数，表示求和树的中序遍历，以空格分割

示例1
输入
复制

10 -2 8 -4 6 7 5
8 -2 -4 10 7 6 5

输出
复制

0 4 0 20 0 12 0


 */
#ifndef UNTITLED_SUMFULLBINARYTREE_H
#define UNTITLED_SUMFULLBINARYTREE_H
#include<vector>
#include<iostream>
#include<numeric>
// 内存超出，可以只使用一个中序数组???
using namespace std;

void recur(vector<int> &inOrder, int left, int right){
    int mid, sum;
    if(right - left == 1){
        inOrder[left] = 0;
        return;
    }
    else{
        mid = (right + left)/ 2;
        sum = accumulate(inOrder.begin() + left, inOrder.begin() + right, -inOrder[mid]);
        inOrder[mid] = sum;
        recur(inOrder, left, mid);
        recur(inOrder, mid + 1, right);
    }
}

void solve(vector<int> &inOrder){
    recur(inOrder, 0, inOrder.size());
}
int sumFullBinaryTree(){
    vector<int> preOrder;
    vector<int> inOrder;
    int value;
    while(cin.peek() != '\n'){
        cin >> value;
        preOrder.push_back(value);
    }
    cin.get();
    while(cin.peek() != '\n'){
        cin >> value;
        inOrder.push_back(value);
    }
    cin.get();
    for(int i = 0; i < preOrder.size(); i++){
        cout << preOrder[i] << ' ';
    }
    cout << endl;
    for(int j = 0; j < inOrder.size(); j++){
        cout << inOrder[j] << ' ';
    }
    cout << endl;
    solve(inOrder);
    for(int i = 0; i < inOrder.size(); i++){
        cout << inOrder[i] << ' ';
    }
    cout << endl;
}
#endif //UNTITLED_SUMFULLBINARYTREE_H

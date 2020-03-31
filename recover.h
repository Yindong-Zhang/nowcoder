//
// Created by so_go on 2020/3/26.
//
/*
 *
有一个含有n个数字的序列，每个数字的大小是不超过200的正整数，同时这个序列满足以下条件：
1. a_1<=a_2
2. a_n<=a_(n-1) （此时n>2）
3. a_i<=max(a_{i-1},a_{i+1})

但是很不幸的是，在序列保存的过程中，有些数字丢失了，请你根据上述条件，计算可能有多少种不同的序列可以满足以上条件。

输入描述:

输入第一行是一个n，表示这个序列的长度。(3<=n<=10^4)

输入第二行有n个非负整数，中间用空格隔开，如果数字为0，说明这个数字丢失了，其他数字则都在1-200之间。


输出描述:

输出仅包含一个整数，即方案数对998244353取模的结果。


输入例子1:

3
2 0 1


输出例子1:

1


 */



// 你必须定义一个 `main()` 函数入口。
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*
void heap_tz(vector<int> &nums, int i, int n){
    while( i < n ){

        if(nums[i] < nums[2 * i] and nums[i] > nums[2 * i + 1]){
            swap(nums[i], nums[2 *i]);
            i = 2 * i;
        }
        if( nums[i] > nums[2 * i] and nums[i] < nums[ 2 * i + 1]){
            swap(nums[i], nums[2 * i + 1]);
        }
        i = 2 * i + 1;
    }
}
void heap_sort(vector<int>& nums)
{
    int n = nums.size() - 1;
    for(int i = n / 2; i >= 0; ++i){
        heap_tz(nums, i, n + 1);
    }
    for(int i = 0; i < n; ++i){
        swap(nums[0], nums[n - i]);
        heap_tz(nums, 0, n - i - 1);
    }
}

int main(){
    vector<int> t{5, 1, 3, 6, 7};
    cout << "hello world" << endl;
    for(auto num : t){
        cout << num << ' ';
    }
    heap_sort(t);
    for(auto num : t){
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}
*/
// 你必须定义一个 `main()` 函数入口。
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void heap_tz(vector<int> &nums, int i, int n){
    while( i < n ){

        if(nums[i] < nums[2 * i] and nums[i] > nums[2 * i + 1]){
            swap(nums[i], nums[2 *i]);
            i = 2 * i;
        }
        if( nums[i] > nums[2 * i] and nums[i] < nums[ 2 * i + 1]){
            swap(nums[i], nums[2 * i + 1]);
        }
        i = 2 * i + 1;
    }
}
void heap_sort(vector<int>& nums)
{
    int n = nums.size() - 1;
    for(int i = n / 2; i >= 0; ++i){
        heap_tz(nums, i, n + 1);
    }
    for(int i = 0; i < n; ++i){
        swap(nums[0], nums[n - i]);
        heap_tz(nums, 0, n - i - 1);
    }
}

int main(){
    vector<int> t{5, 1, 3, 6, 7};
    cout << "hello world" << endl;
    for(auto num : t){
        cout << num << ' ';
    }
    heap_sort(t);
    for(auto num : t){
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}
#ifndef UNTITLED_RECOVER_H
#define UNTITLED_RECOVER_H
#include<bits/stdc++.h>
#define M 998244353
using namespace std;
typedef long long ll;

int solve(vector<int> &nums){
    int n = nums.size();
    vector<vector<int>> f(n, vector<int>(200, 0)), g(n, vector<int>(200, 0));
    if(nums[0] == 0){
        for(int i = 0; i < 200; ++i){
            f[0][i] = 1;
            g[0][i] = 1;
        }
    }
    else{
        f[0][nums[0] - 1] = 1;
        g[0][nums[0] - 1] = 1;
    }

    if(n > 1 and nums[1] == 0){
        int preSum = 0;
        for(int i = 0; i < 200; ++i){
            preSum += f[0][i];
            f[1][i] = preSum;
            g[1][i] = g[0][i];
        }
    }
    else{
        int preSum = 0;
        for(int i = 0; i < nums[1]; ++i){
            preSum += f[0][i];
        }
        f[1][nums[1] - 1] = preSum;
        g[1][nums[1] - 1] = g[0][nums[1] - 1];
    }
    for(int k = 2; k < n; ++k){
        if(nums[k] != 0){
            int a = 0, b = 0;
            for(int i = 0; i <= nums[k] - 1; ++i){
                a = (a + f[k - 1][i]) % M;
            }
            for(int i = nums[k]; i < 200; ++i){
                b = (b + g[k - 1][i]) % M;
            }
            f[k][nums[k] - 1] = (a + b) % M;
            g[k][nums[k] - 1] = (f[k - 1][nums[k] - 1] + b) % M;
        }
        else{
            int a = 0, b = 0;
            for(int i = 0; i < 200; ++i){
                b = (b + g[k-1][i]) % M;
            }
            for(int i = 0; i < 200; ++i){
                a = (a + f[k - 1][i]) % M;
                b = (b - g[k - 1][i]) % M;
                f[k][i] = (a + b) % M;
                g[k][i] = (f[k - 1][i] + b) % M;
            }
        }
    }
    int res = 0;
    if(nums[n - 1] == 0){
        for(int i = 0; i < 200; ++i){
            res = (res + g[n - 1][i]) % M;
        }
    }
    else{
        res = g[n - 1][nums[n - 1] - 1];
    }
    return res;
}

int recoverCombination(){
    int n;
    cin >> n;
    vector<int> nums;
    int num;
    for(int i = 0; i < n; ++i){
        cin >> num;
        nums.push_back(num);
    }
    cout << solve(nums) << endl;
    return 0;
}
#endif //UNTITLED_RECOVER_H

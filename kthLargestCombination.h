//
// Created by so_go on 2020/3/3.
//
/*
 *

打败魔人布欧以后，孙悟空收了n个徒弟，每个徒弟战斗力各不相同。他教导所有的徒弟和体术，合体后战斗力为原战斗力相乘。任何两个徒弟都可以合体，所以一共有n*(n-1)/2种合体徒弟。有一天，他想考验一下孙悟天战斗力如何，希望在所有n*(n-1)/2种合体徒弟中选择战斗力第k高的，与孙悟天对战。可是孙悟空徒弟太多了，他已然懵逼，于是找到了你，请你帮他找到对的人。

输入描述:

第一行两个int。徒弟数量：n <= 1*10^6；战斗力排名:k <= n*(n-1)/2
第二行空格分隔n个int，表示每个徒弟的战斗力。


输出描述:

战斗力排名k的合体徒弟战斗力。


输入例子1:

5 2
1 3 4 5 9


输出例子1:

36


 */
#ifndef UNTITLED_KTHLARGESTCOMBINATION_H
#define UNTITLED_KTHLARGESTCOMBINATION_H
/*
 * 目前的解法有二：
 * 一：
 * 排序后的乘积矩阵满足行有序和列有序的性质，这道题就可以转化为在有序矩阵内找第k大的数。leetcode有相同的题目。
 * 二：
 * 值搜索问题，利用逆向思维，二分搜索查找符合要求的最大值：有k种组合大于等于这个数，
 * int l, r, mid, [l, r)
 * 当有k种组合大于等于mid, ->[mid, r)
 * 当没有k种组合大于等于mid, -> [l, mid)
 */
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
// 通过 20%。。。，想法没问题，应该可以改进。
/* 复制下别人改进的代码，在查找的同时不仅计算k，还计算>= query的最小值，
 * 甚至还记录最小值有几个，从而判断有多个最小值的情况。。。
 * #include <bits/stdc++.h>
using namespace std;
long long check(vector<long long>& att, long long& mid, long long k, long long n)
{
    long long below = 0;
    long long num = 0;
    long long same_p = 0;
    long long min_val = att[n - 1] * att[n - 1] * 2;
    for (long long i = 0; i < n; i++)
    {
        long long pos = upper_bound(att.begin() + i + 1, att.end(), mid / att[i]) - att.begin();
        num += att.size() - pos;
        if (pos == att.size())
            continue;
        long long minu = att[pos] * att[i] - mid;
        if (minu < min_val)
        {
            min_val = minu;
            below = att[pos] * att[i];
            same_p = 0;
        }
        if(minu == min_val)
            same_p++;
    }
    if(k == num || (num > k && num-same_p < k))
    {
        mid = below;
        num = k;
    }
    return num;
}

int main() {
    long long n,k;
    vector<long long> att;
    scanf("%lld %lld", &n, &k);
    long long tmp;
    for (long long i = 0; i < n; i++)
    {
        scanf("%lld", &tmp);
        att.push_back(tmp);
    }
    sort(att.begin(), att.end());
    long long lo = att[0] * att[1];
    long long hi = att[n - 1] * att[n - 2];
    long long ans;
    while (lo <= hi)
    {
        long long mid = (lo + hi) >> 1;
        long long num = check(att, mid, k, n);
        if (num == k)
        {
            ans = mid;
            break;
        }
        if (num > k)
        {
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    printf("%lld\n", ans);
    return 0;
}
 */
int fcount(vector<int> &nums, int query){
    // nums 升序排列
    int i = 0, j = nums.size() - 1;
    int res = 0;
    for(int i = 0; i < nums.size(); ++i){
        if(j >= 0 and j > i and nums[i] * nums[j] >= query){
            j--;
        }
        res += (nums.size() - max(j, i)- 1);
    }
    return res;
}

int solve(vector<int> nums, int k){
    sort(nums.begin(), nums.end(), less<int>());
    int n = nums.size() - 1;
    int l = nums[0] * nums[1], r = nums[n] * nums[n - 1] + 1;
    while(r - l > 1){
        cout << l << ' ' << r << endl;
        int mid = (r + l) / 2;
        cout << fcount(nums, mid) << ' ' << mid << endl;
        if(fcount(nums, mid) >= k){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return l;
}

int kthLargestCombination(){
    int n, k;
    vector<int> nums;
    cin >> n >> k;
    int num;
    for(int i = 0; i < n; ++i){
        cin >> num;
        nums.push_back(num);
    }
    cout << solve(nums, k) << endl;
    return 0;
}
#endif //UNTITLED_KTHLARGESTCOMBINATION_H

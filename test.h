//
// Created by yindong on 19-9-8.
//

#ifndef UNTITLED_TEST_H
#define UNTITLED_TEST_H
#include<vector>
#include<iostream>
using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<string>
#include<istream>
#define int64 long long
using namespace std;
bool ismatch(string reg, string s)
{
    vector<vector<int> > dp;
    for (int i = 0; i<=reg.size(); i++) {
        vector<int> tem;
        for (int j = 0; j <= s.size(); j++)
        {
            if (i == 0) tem.push_back(1);
            else tem.push_back(0);
        }
        dp.push_back(tem);
    }

    for(int i=0;i<reg.size();i++)
        for (int j = 0; j < s.size(); j++)
        {
            if (reg[i] == s[j]) dp[i + 1][j + 1] = dp[i][j];
            if (reg[i] =='^'&&j == 0)   dp[i + 1][1] = 1;
            if (reg[i] == '$'&&j == s.size() - 1) dp[i + 1][s.size()] = dp[i][s.size()-1];
            if (reg[i] == '.')  dp[i + 1][j + 1] = dp[i][j];
            if (reg[i] == '*') dp[i + 1][j + 1] = (dp[i][j+1] || dp[i+1][j]);

        }
    return dp[reg.size()][s.size()];

}
int test()
{
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin, s2);
    for(int j = 0; j < s2.size();j++)
        for (int i = 1; i <= s2.size() - (j); i++)
        {
//            cout << s2.substr(j, i) << endl;
//            cout << ismatch(s1, s2.substr(j, i))<<endl;
            if(ismatch(s1, s2.substr(j, i))){
                cout << '1' << endl;
                return 0;
            }
        }
    cout << '0' << endl;
    return 0;
}
#endif //UNTITLED_TEST_H

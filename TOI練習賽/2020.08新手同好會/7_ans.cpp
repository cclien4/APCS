#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;
int num;
vector<int> tree;
vector<int> v[205];
int query(int s)
{
    int ans = 0;
    for(int i = 1; i <= s; i++)
    {
        ans += tree[i];
    }
    return ans;
}
int main()
{
    double start, end;
    scanf("%d", &num);
    tree.resize(num + 1, 1);
    for(int i = 1; i <= num; i++)
    {
        int n;
        scanf("%d", &n);
        v[n].push_back(i);
    }
    long long ans = 0;
    for(int i = 1; i <= 200; i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            int r = query(num) - query(v[i][j]) - (v[i].size() - j - 1);
            int l = query(v[i][j] - 1);
            ans += min(l, r);
            tree[v[i][j]] = 0;
        }
    }
    cout << ans << endl;
}


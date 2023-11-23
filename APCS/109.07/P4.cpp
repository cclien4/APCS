// Copyright (C) Algo Seacow. 2020. All Rights Reserved.
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7;

int n, m;
vector<vector<int>> G;
vector<string> strs;
vector<char> c;
// dp(u, i) : �H u ���ڪ��l��, �B�ڪ��r���� i ���̤p�~���Z��
vector<array<int, 26>> dp;

void solve(int u, int par) {
    fill(dp[u].begin(), dp[u].end(), INF);
    for (int i = 0; i < 26; i++) {
        if (c[u] != '@' && c[u] != 'A' + i) continue;
        dp[u][i] = 0;
    }
    for (int vi = 0; vi < (int)G[u].size(); vi++) {
        int v = G[u][vi];
        if (v == par) continue;
        solve(v, u);
        for (int i = 0; i < 26; i++) {
            if (c[u] != '@' && c[u] != 'A' + i) continue;
            int mi = INF;
            for (int j = 0; j < 26; j++) {
                mi = min(mi, dp[v][j] + (i != j));
            }
            dp[u][i] += mi;
        }
    }
}

int main() {
    cin >> n >> m;
    G.resize(n);
    strs.resize(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        cin >> strs[i];
    }
    int ans = 0;
    c.resize(n);
    for (int d = 0; d < m; d++) {
        for (int i = 0; i < n; i++) {
            c[i] = strs[i][d];
        }
        dp = vector<array<int, 26>>(n);
        solve(0, 0);
        ans += *min_element(dp[0].begin(), dp[0].end());
    }
    cout << ans << endl;
}

/*
2 3
1 1 ABB
1 2 A@@
*/

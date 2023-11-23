// Author: Yi-Feng Chen

#include <bits/stdc++.h>

using namespace std;
const __int128_t INF = ((__int128_t)(0x7FFFFFFFFFFFFFFLL)<<50)|0x7FFFFFFFFFFFFFFLL;
const __int128_t NINF = -INF;
const int MAX = 1005;

int num; // total num of node
__int128_t path[MAX][MAX], weight_x[MAX], weight_y[MAX];
bool visit_x[MAX], visit_y[MAX];
int parent[MAX];
int N, K;
__int128_t L, U;
__int128_t origin[2][1005];
bool valid[1005][1005];
bool matched[1005];

bool find(int i) {
    visit_x[i] = true;
    for (int j = 0; j < num; ++j) {
        if (visit_y[j]) continue;
        if (!valid[i][j]) continue;
        if (weight_x[i] + weight_y[j] == path[i][j]) {
            visit_y[j] = true;
            if (parent[j] == -1 || find(parent[j])) {
                parent[j] = i;
                matched[j] = true;
                return true;
            }
        }
    }
    return false;
}

__int128_t weighted_hangarian() {
    /* remember to initial weight_x (max weight of node's edge)*/
    /* initialize */
    for (int i = 0; i < num; ++i) {
        weight_y[i] = 0;
        parent[i] = -1;
        matched[i] = false;
    }

    for (int i = 0; i < num; ++i) {
        while (1) {
            memset(visit_x, false, sizeof(visit_x));
            memset(visit_y, false, sizeof(visit_y));
            if (find(i)) {
                break;
            }

            __int128_t lack = INF;
            for (int j = 0; j < num; ++j) {
                if (visit_x[j]) {
                    for (int k = 0; k < num; ++k) {
                        if (!visit_y[k] && valid[j][k]) {
                            lack = min(lack, weight_x[j] + weight_y[k] - path[j][k]);
                        }
                    }
                }
            }

            if (lack == INF) break;

            for (int j = 0; j < num; ++j) {
                if (visit_x[j]) weight_x[j] -= lack;
                if (visit_y[j]) weight_y[j] += lack;
            }
    
        }
    }

    for (int i = 0; i < num; ++i) {
        if (!matched[i]) return -1;
    }

    __int128_t ans=0;
    for (int i = 0; i < num; ++i) {
        ans += weight_x[i];
        ans += weight_y[i];
    }
    return -ans;
}

int main () {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        long long tmp_L, tmp_U;
        scanf("%d%lld%lld%d", &N, &tmp_L, &tmp_U, &K);
        U = tmp_U;
        L = tmp_L;
        memset(valid, true, sizeof(valid));
        for (int i = 0; i < K; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            valid[a-1][b-1] = false;
        }
        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < N; ++i) {
                long long tmp;
                scanf("%lld", &tmp);
                origin[j][i] = tmp;
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!valid[i][j]) continue;
                __int128_t target = origin[0][i]+origin[1][j];
                if (target <= L) {
                    path[i][j] = 0;
                }
                else if (target <= U) {
                    path[i][j] = -(target-L);
                }
                else {
                    path[i][j] = -(U-L);
                }
            }
        }

        bool can_do = true;
        for (int i = 0; i < N; ++i) {
            __int128_t tmp = NINF;
            for (int j = 0 ; j < N; ++j) {
                if (!valid[i][j]) continue;
                tmp = max(tmp, path[i][j]);
            }
            weight_x[i] = tmp;
            if (tmp == NINF) can_do = false;
        }

        num = N;
        if (!can_do) {
            printf("no\n");
            continue;
        }
        __int128_t ans = weighted_hangarian();
        if (ans == -1) {
            printf("no\n");
        }
        else {
            if(ans >= 1000000000000000LL)
            printf("%lld%015lld\n", (long long)(ans/1000000000000000LL),
                   (long long)(ans%1000000000000000LL));
            else printf("%lld\n",(long long)ans);
        }
    }
    return 0;
}

// Solver: Yi-Feng Chen
// Modifier: Min-Zheng Shieh
// Expected running time: 1.2 seconds

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 1004
#define INF 0x7fffffffffffffffll

using namespace std;

int num; // total num of node
int left_node_num, right_node_num;
int line_num;
long long path[MAX][MAX];
bool visit_x[MAX], visit_y[MAX];
int parent[MAX];
long long weight_x[MAX], weight_y[MAX], slack[MAX];

bool find(int i) {
    visit_x[i] = true;
    for (int j = 0; j < num; ++j) {
        if (visit_y[j]) continue;
        long long t = weight_x[i] + weight_y[j] - path[i][j];
        if (slack[j] > t) slack[j] = t; // update slackness of right node
        if (t == 0LL) {
            visit_y[j] = true;
            if (parent[j] == -1 || find(parent[j])) {
                parent[j] = i;
                return true;
            }
        }
    }
    return false;
}

long long weighted_hangarian() {
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) slack[j] = INF; // initialize slackness
        while (1) {
            memset(visit_x, 0, sizeof(visit_x));
            memset(visit_y, 0, sizeof(visit_y));
            if (find(i)) break;

            long long lack = INF;
            for (int j = 0; j < num; ++j)
                if (!visit_y[j])
                    lack = min(lack, slack[j]);
            if (lack == INF) break;
            // renew label
            for (int j = 0; j < num; ++j) {
                if (visit_x[j]) weight_x[j] -= lack;
                if (visit_y[j]) weight_y[j] += lack;
            }
    
        }
    }

    long long ans = 0;
    for (int i = 0; i < num; ++i) {
        ans += weight_x[i];
        ans += weight_y[i];
    }
    return ans;
}

void init() {
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            path[i][j] = 0;
        }
        weight_x[i] = weight_y[i] = 0;
        parent[i] = -1;
    }
}

long long gcd(long long x, long long y)
{
	if(x==0LL || y==0LL) return x+y;
	return gcd(y,x%y);
}

int main () {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d%d", &left_node_num, &right_node_num);
        num = max(left_node_num, right_node_num);
        scanf("%d", &line_num);
        init();
        for (int i = 0; i < line_num; ++i) {
            int st, ed;
				long long p, q; // q/p
            scanf("%d%d%lld%lld", &st, &ed, &q, &p);
            path[st-1][ed-1] = q*10ll*9*8*7*6*5*4*3*2/p;
            if(path[st-1][ed-1] > weight_x[st-1])
                weight_x[st-1] = path[st-1][ed-1];
        }
        long long ans = weighted_hangarian();
        long long div = gcd(ans,10ll*9*8*7*6*5*4*3*2);
        cout << ans/div << " " << (10ll*9*8*7*6*5*4*3*2/div) << endl;
    }
}

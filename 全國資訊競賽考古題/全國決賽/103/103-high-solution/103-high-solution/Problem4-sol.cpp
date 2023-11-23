// Solver: Yi-Feng Chen
// Expected running time: 6 seconds

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#define MAX 1000010

using namespace std;

int n, max_cost, total_cost;

struct LINE {
    int a, b, weight;
    bool taken;
} line[MAX];

struct NODE {
    vector<int> road;
    int cost, take_cost, neighbor_num;
    bool is_leaf;
} node[MAX];

class cmp {
    public:
        bool operator()(const int& a, const int& b) const {
            return node[a].take_cost > node[b].take_cost;
        }
};

priority_queue<int, vector<int>, cmp> leaf;

void print() {
    for (int i = 0; i < n; ++i) {
        cout << node[i].cost << " " << node[i].take_cost << " " << node[i].is_leaf << endl;
    }
}

void judge() {
    if (n == 1) {
        cout << "0" << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (node[i].is_leaf) {
            node[i].take_cost += line[node[i].road[0]].weight;
            leaf.push(i);
        }
    }

    while (total_cost > max_cost) {
        int take = leaf.top();
        leaf.pop();
        for (int i = 0; i < node[take].road.size(); ++i) {
            int target = node[take].road[i];
            if (line[target].taken) continue;
            line[target].taken = true;
            total_cost -= line[target].weight;
            if (line[target].a == take) target = line[target].b;
            else target = line[target].a;

            --node[target].neighbor_num;
            node[target].cost = max(node[target].cost, node[take].take_cost);

            if (node[target].neighbor_num == 1) {
                node[target].is_leaf = true;
                for (int j = 0; j < node[target].road.size(); ++j) {
                    int tmp = node[target].road[j];
                    if (line[tmp].taken) continue;
                    node[target].take_cost = node[target].cost + line[tmp].weight;
                    break;
                }
                leaf.push(target);
            }
        }
    }

    int ans = 0;
    while (leaf.size()) {
        int take = leaf.top();
        ans = max(ans, node[take].cost);
        leaf.pop();
    }
    cout << ans << endl;
}

void init() {
    for (int i = 0; i < n; ++i) {
        node[i].road.clear();
        node[i].neighbor_num = node[i].cost = node[i].take_cost = 0;
        node[i].is_leaf = true;
    }
    while (leaf.size()) leaf.pop();
    total_cost = 0;
}

int main () {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d%d", &n, &max_cost);
        init();
        for (int i = 0; i < n-1; ++i) {
            int a, b;
            scanf("%d%d%d", &a, &b, &line[i].weight);
            total_cost += line[i].weight;
            line[i].taken = false;
            line[i].a = a, line[i].b = b;
            node[a].road.push_back(i); 
            node[b].road.push_back(i);
            ++node[a].neighbor_num;
            ++node[b].neighbor_num;
            if (node[a].neighbor_num > 1) node[a].is_leaf = false;
            if (node[b].neighbor_num > 1) node[b].is_leaf = false;
        }
        judge();
    }
    return 0;
}

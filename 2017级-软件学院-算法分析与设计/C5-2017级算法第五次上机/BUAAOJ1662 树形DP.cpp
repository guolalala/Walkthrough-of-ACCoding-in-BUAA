#include<iostream>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<vector>
#include<climits>
#define maxn 7000
using namespace std;
/********************************
dp[i][0]表示不邀请i
dp[i][1]表示邀请i
********************************/
vector<int>g[maxn];
int father[maxn], dp[maxn][2];

void dfs(int root) {
    for (int i = 0; i < g[root].size(); ++i) {
        dfs(g[root][i]);
    }
    for (int i = 0; i < g[root].size(); ++i) {
        dp[root][0] += max(dp[g[root][i]][0], dp[g[root][i]][1]);
        dp[root][1] += dp[g[root][i]][0];
    }
}

inline void eraseDP() {
    memset(father, 0, sizeof(father));
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < maxn; ++i) {
        g[i].clear();
    }
}
int n;
int l, k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> n) {
        eraseDP();
        for (int i = 1; i <= n; ++i)
            cin >> dp[i][1];
        cin >> l >> k;
        while (l && k) {
            father[l] = k;
            g[k].push_back(l);
            cin >> l >> k;
        }
        int root = 1;
        while (father[root])root = father[root];
        dfs(root);
        cout << max(dp[root][0], dp[root][1]) << endl;

    }

}

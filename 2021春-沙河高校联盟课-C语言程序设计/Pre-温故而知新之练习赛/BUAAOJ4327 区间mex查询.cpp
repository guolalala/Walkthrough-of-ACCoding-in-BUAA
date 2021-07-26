#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long ll;
int rd() {
    int k = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
void wr(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}
const int N = 400005, M = 5000005;
int n, m, a[N], lst[N], idx;
int tot, root[N], ls[M], rs[M], val[M];

void change(int old, int& k, int l, int r, int p, int x) {
    k = ++tot;
    ls[k] = ls[old], rs[k] = rs[old];
    if (l == r) return (void)(val[k] = x);
    int mid = (l + r) >> 1;
    if (p <= mid) change(ls[old], ls[k], l, mid, p, x);
    else change(rs[old], rs[k], mid + 1, r, p, x);
    val[k] = min(val[ls[k]], val[rs[k]]);
}
int query(int k, int l, int r, int x) {
    if (!k || l == r) return lst[l];
    int mid = (l + r) >> 1;
    if (val[ls[k]] >= x) return query(rs[k], mid + 1, r, x);
    return query(ls[k], l, mid, x);
}

int main() {

    n = rd(), m = 1;
    lst[++idx] = 0;
    for (int i = 1; i <= n; i++)
        a[i] = rd(), lst[++idx] = a[i], lst[++idx] = a[i] + 1;
    sort(lst + 1, lst + idx + 1);
    idx = unique(lst + 1, lst + idx + 1) - lst - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(lst + 1, lst + idx + 1, a[i]) - lst;
        change(root[i - 1], root[i], 1, idx, a[i], i);
    }
    while (m--) {
        int l, r;
        l = 1, r = n;
        wr(query(root[r], 1, idx, l)), putchar('\n');
    }

    return 0;
}
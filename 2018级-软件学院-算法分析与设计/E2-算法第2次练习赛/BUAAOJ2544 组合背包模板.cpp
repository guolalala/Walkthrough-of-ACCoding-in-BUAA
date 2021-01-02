#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define full 233
#define single 1
#define maxn 510
#define maxv 200000
using namespace std;
inline void write(int x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline int read() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
template <typename T>
struct MonotoneQueue {
    deque<T>q, m;
    inline void push(const T& x) {
        q.push_back(x);
        while (!m.empty() && m.back() < x)m.pop_back();
        m.push_back(x);
    }
    inline void pop() {
        T x = q.front();
        q.pop_front();
        if (x == m.front())m.pop_front();
    }
    inline size_t size() {
        return q.size();
    }
    T top() {
        return m.front();
    }
};
int t;
int V, N;
int value, cost, cnt;
int f[maxv + 10], g[maxv + 10], q[maxv + 10];//多重背包单调队列优化
int rear, front;//手写队列
inline void buildDP_01Pack(int cost, int value) {
    for (int v = V; v >= cost; --v) {
        f[v] = max(f[v], f[v - cost] + value);
    }
}
inline void buildDP_FullPack(int cost, int value) {
    for (int v = cost; v <= V; ++v) {
        f[v] = max(f[v], f[v - cost] + value);
    }
}
inline void buildDP_MultiPack_Binary(int cost, int value, int count) {
    int num = min(count, V / cost);
    for(int k = 1; num > 0; k <<= 1) {
        if(k > num) k = num;
        num -= k;
        for(int j = V; j >= cost * k && j; --j)
        f[j] = max(f[j], f[j - cost * k] + value * k);
    }
}
inline void buildDP_MultiPack_MonoQueue_A(int cost, int value, int count) {
    memcpy(g, f, (V + 1) * sizeof(int));
    for(int j = 0; j < cost; ++j) {
        rear = front = 1;
        q[1] = 0;
        for(int k = 0; k * cost + j <= V; ++k) {
            while (front != rear && k - q[front] > count) ++front;
            f[k * cost + j] = max(g[k * cost + j], g[q[front] * cost + j] + (k - q[front]) * value);
            while (front <= rear && g[q[rear] * cost + j] + (k - q[rear]) * value <= g[k * cost + j]) --rear;
            q[++rear] = k;
        }
    }
}
inline void buildDP_MultiPack_MonoQueue_B(int cost, int value, int count) {
    count = min(count, V / cost);
    for (int r = 0; r < cost; ++r) {
        MonotoneQueue<int>q;
        int m = (V - r) / cost;
        for (int k = 0; k <= m; ++k) {
            if (q.size() == count + 1)q.pop();
            q.push(f[k * cost + r] - k * value);
            f[k * cost + r] = q.top() + k * value;
        }
    }
}
inline void buildDP_MultiPack(int cost, int value, int count, int ver) {
    switch (ver) {
        case 1:
            buildDP_MultiPack_Binary(cost, value, count);
            break;
        case 2:
            buildDP_MultiPack_MonoQueue_A(cost, value, count);
            break;
        case 3:
            buildDP_MultiPack_MonoQueue_B(cost, value, count);
            break;
        default:
            break;
    }
}
inline void buildDP_CombinedPack(int cost, int value, int count) {
    if (count == single)buildDP_01Pack(cost, value);
    else if (count == full)buildDP_FullPack(cost, value);
    else buildDP_MultiPack(cost, value, count, 2);
}
int main() {
    while(scanf("%d%d", &N, &V) != EOF) {
        memset(f, 0, (V + 1) * sizeof(int));
        while (N--) {
            cost = read(), value = read(), cnt = read();
            buildDP_CombinedPack(cost, value, cnt);
        }
        write(f[V]), putchar('\n');
    }
}

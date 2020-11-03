#include <cstdio>
#include <algorithm>
#define maxn 1010
using namespace std;
int n, k;
struct KeyWord {
    int name;
    int w[11];
    const bool operator < (const KeyWord& o) const {
        for(int i = 1; i <= k; ++i) {
            if(w[i] < o.w[i]) return true;
            else if (w[i]>o.w[i])return false;
        }
        return name < o.name;
    }
} A[maxn];
int main() {
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; ++i) {
        A[i].name = i;
        for(int j = 1; j <= k; ++j)
            scanf("%d", &A[i].w[j]);
    }
    sort(A+1, A+n+1);
    for(int i = 1; i < n; ++i)
        printf("%d ",A[i].name);
    printf("%d",A[n].name);
}

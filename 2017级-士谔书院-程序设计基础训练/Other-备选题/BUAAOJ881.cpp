#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int a2b[260];
int b2a[260];

const int maxn = 1010;
int input[maxn];

void init() {
    for (int i = 0; i < 256; ++i) {
        b2a[i] = (i ^ (i << 1)) & 255;
    }
    for (int i = 0; i < 256; ++i) {
        a2b[b2a[i]] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    init();
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &input[i]);
        }
        for (int i = 0; i < n; ++i) {
            printf("%d ", a2b[input[i]]);
        }
        printf("\n");
    }
    return 0;
}

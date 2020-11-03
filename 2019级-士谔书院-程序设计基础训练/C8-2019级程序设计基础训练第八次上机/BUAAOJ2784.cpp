#include <cstdio>
#include <algorithm>
int a[4];
int t;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d",a,a+1,a+2);
        std::sort(a,a+3);
        puts(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]?"Yes":"No");
    }
}

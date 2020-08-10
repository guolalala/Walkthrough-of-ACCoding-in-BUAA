#include<cstdio>
#include<cmath>
inline void func(double n) {
    double result = (double)n - (n * n * n) / 18 + (n*n*n*n*n)/600-(n*n*n*n*n*n*n)/35280;
    printf("%.3lf\n", result);
}
int main() {
    double n;
    while (scanf("%lf", &n) != EOF)
        func(n);
    return 0;
}

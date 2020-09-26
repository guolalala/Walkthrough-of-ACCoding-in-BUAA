#include<cstdio>
typedef long long ll;
const int maxn = 100010;
const ll MOD = 1000000007;
ll fac[maxn], ifac[maxn];//阶乘的模和阶乘逆元
inline ll C(int n, int m) {//计算组合数C_n^m
    if (m > n)return 0;
    if (m == 0)return 1;
    ll ret = (fac[n] * ifac[m]) % MOD;
    ret = (ret * ifac[n - m]) % MOD;
    return ret;
}
inline ll ApowBmodP(ll a, ll b, ll p) {
    ll ret = 1;
    while (b) {
        if (b & 1)ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret % p;
}
inline void build_fac_ifac_inv() {
    fac[0] = 1;
    for (int i = 1; i < maxn; ++i)
        fac[i] = (fac[i - 1] * i) % MOD;
    ifac[maxn - 1] = ApowBmodP(fac[maxn - 1], MOD - 2, MOD);//n!的逆元
    for (int i = maxn - 2; i >= 0; --i)
        ifac[i] = (ifac[i + 1] * (i + 1)) % MOD;

}
int a, b, k;
ll ans;
int main() {
    build_fac_ifac_inv();
    while (scanf("%d%d%d", &a, &b, &k) != EOF) {
        //卡特兰数变种,ans = C_{k-1}^{(k-b)/2}-C_{k-1}^{(k-b)/2-1}=\frac{2b}{k+b}C_{k-1}^{(k-b)/2}
        if (k < b) puts("0");
        //else if (k == b) puts("1"); 加上这句话只有0.5,然而这很显然是正确的
        else if ((k - b) & 1) puts("0");
        else {
            ans = (((((((2ll * b) % MOD) * fac[k + b - 1]) % MOD) * ifac[k + b]) % MOD) * C(k - 1, (k - b) >> 1)) % MOD;
            //ans = C(k - 1, (k - b) >> 1) - C(k - 1, ((k - b) >> 1) - 1);
            //while (ans <= 0)ans += MOD; ans %= MOD;
            printf("%lld\n", ans);
        }
    }
}

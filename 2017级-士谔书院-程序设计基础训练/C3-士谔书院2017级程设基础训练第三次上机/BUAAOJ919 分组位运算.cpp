#include<cstdio>
#include<cctype>
#define RADIX 10

inline unsigned long long read() {
    unsigned long long k = 0;// int f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        //printf("get here!\n");
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k;//*f
}
inline void write(unsigned long long x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x >= RADIX)write(x / RADIX);
    putchar(x % RADIX + 48);
}
inline long long pow(int c) {
    return (long long)1 << c;
}
long long mask[6] = { 0b0101010101010101010101010101010101010101010101010101010101010101,
                      0b0011001100110011001100110011001100110011001100110011001100110011,
                      0b0000111100001111000011110000111100001111000011110000111100001111,
                      0b0000000011111111000000001111111100000000111111110000000011111111,
                      0b0000000000000000111111111111111100000000000000001111111111111111,
                      0b0000000000000000000000000000000011111111111111111111111111111111 };
inline long long round(long long n, int c) {
    return (n & mask[c]) + (n >> pow(c)& mask[c]);//这里还设计到运算的优先级，先右移再按位与(虽然这一点并不是最重要的)
}
long long countOnes2(unsigned long long n) {
    n = round(n, 0);//每02位为一组，各组前01位于后01位相加，每组内相加得到的结果就是这02位中1的数目
    n = round(n, 1);//每04位为一组，各组前02位于后02位相加，每组内相加得到的结果就是这04位中1的数目
    n = round(n, 2);//每08位为一组，各组前04位于后04位相加，每组内相加得到的结果就是这08位中1的数目
    n = round(n, 3);//每16位为一组，各组前08位于后08位相加，每组内相加得到的结果就是这16位中1的数目
    n = round(n, 4);//每32位为一组，各组前16位于后16位相加，每组内相加得到的结果就是这32位中1的数目
    n = round(n, 5);//每64位为一组，各组前32位于后32位相加，每组内相加得到的结果就是这64位中1的数目
    return n;
}
long long n, m;
long long result;
int main() {
    n = read();
    while (n--) {
        m = read();
        result = countOnes2(m);
        if (result == 1) { putchar('2'); putchar('2'); putchar('2'); }
        else write(result);
        putchar('\n');
    }
}

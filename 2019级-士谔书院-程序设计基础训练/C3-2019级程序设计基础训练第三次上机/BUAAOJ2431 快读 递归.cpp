#include<stdio.h>
void write(int x) {
    if (x > 2)write(x / 3);
    putchar(x % 3 + 48);
}
int n;
int main() {
    while(scanf("%d",&n)!=EOF)
        write(n),putchar('\n');
}

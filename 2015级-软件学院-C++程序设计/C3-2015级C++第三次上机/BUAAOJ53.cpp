#include<cstdio>
int read() {
    int k = 0;// int f = 1;
    char c = getchar();
    while (c<'0'||c>'9') {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        //printf("get here!\n");
        k = ((k<<1)+(k<<3))%4+(c - 48)%4;
        c = getchar();
    }
    return k;
}
int n;
int main(){n=read();if(n==1||n==5||n==2)printf("1\n");else printf("0\n");}

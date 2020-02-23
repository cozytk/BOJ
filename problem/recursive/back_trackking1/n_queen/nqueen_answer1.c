#include<stdio.h>
int n, cnt, tmp;
void back(int p, int chk1, int chk2, int chk3)
{
    int chk, l;
    if(p>n)
    {
        ++cnt;
        return;
    }
    chk=~(chk1|chk2|chk3)&tmp;
    while(chk)
    {
        l=chk&~(chk-2);
        back(p+1, chk1+l, (chk2+l)<<1, (chk3+l)>>1);
        chk&=~l;
    }
    return;
}
int main()
{
    int i, x;
    scanf("%d", &n);i=1<<(n>>1);
    tmp = (1<<n+1)-2;
    for(x=1; x<i; x<<=1) back(2, x<<1, x<<2, x);
    cnt<<=1;
    if(n&1) back(2, x<<1, x<<2, x);
    printf("%d", cnt);
}
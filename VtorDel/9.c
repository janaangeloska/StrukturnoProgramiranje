/*Да се имплементира рекурзивна функција која за низа од цели броеви $[a{0}, a{1}, ..., a_{n-1}]$ ќе ја пресмета вредноста на непрекинатата дропка дефинирана како:

v=a0+1a1+...1an−2+1an−1

Да се напише програма во која се чита цел број N, по што се читаат елементите на низа од N цели броеви (не повеќе од 100). Потоа се повикува рекурзивната функција и се печати резултатот во нов ред.*/

#include<stdio.h>
float f(int a[],int n, int x)
{
    if(x==n-1)
    {
        if(n==1)
        {
            return a[x];
        }
        return a[x];
    }
    return 1/f(a,n,x+1)+a[x];
}
int main()
{
    int i,n;
    scanf("%d",&n);
    int a[100];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%f",f(a,n,0));
    return 0;
}

/*Од тастатура се читаат непознат број позитивни цели броеви се додека не се внесе нешто различно од број.
За секој број треба да се пресмета збирот на цифрата со максимална вредност од претходно внесениот број 
и сумата на цифрите на тековниот број (за првиот внесен број се пресметува само сумата на неговите цифри). 
За секој внесен број резултатот треба да се испечати во следниот формат:
[број]: [сумата на цифрите на бројот + максималната цифра од претходниот број]
342: 9   //3+4+2
345: 16 //3+4+5+4
123: 11 //1+2+3+5
456: 18 //4+5+6+3*/

#include<stdio.h>
int main(){
    int a,zbir=0,maxCifra=0,i=0;
    while(scanf("%d",&a)){
        int temp=a;
        zbir=0;
        if(i!=0) {
            zbir += maxCifra;
        }
        maxCifra=0;
        while(temp>0) {
            zbir = zbir + temp % 10;
            if (temp % 10 > maxCifra) {
                maxCifra = temp % 10;
            }
            temp /= 10;
        }
        printf("%d: %d\n",a,zbir);
        i++;
    }
    return 0;
}

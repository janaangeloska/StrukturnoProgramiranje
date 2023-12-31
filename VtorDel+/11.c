/*Од тастатура се внесува цел број M, а потоа M низи од цели броеви. За секоја низа прво се внесува бројот на елементи во низата N (N<=100), а потоа и елементите на низата. 

Секоја од внесените низи треба да се трансформира според следново правило:

    Ако првиот елемент од низата е позитивен број, тоа значи сите елементи од низата (вклучувајќи го и првиот) да се поместат за онолку места во десно, колку што е вредноста на елементот, празнините што ќе настанат во низата да се пополнат со елементи со вредност нула.

    Ако првиот елемент од низата е негативен број, тоа значи сите елементи од низата (вклучувајќи го и првиот) да се поместат за онолку места во лево, колку што е вредноста на елементот, празнините што ќе настанат во низата да се пополнат со елементи со вредност нула.

При поместување на елементите, бројот на елементите во низата останува непроменет.

На крајот да се испечатат трансформираните низи како и тоа колку од влезните низи останале празни, односно по трансформацијата имаат само елементи со вредност нула.

Трансформацијата на низите да се реализира во посебна функција. Решенијата без користење функција ќе бидат оценети со најмногу 40% од поените.

Објаснување на вториот и третиот пример:
Во вториот пример се вчитува само една низа со 5 елементи (1,2,3,4,5). Првиот елемент е 1 (позитивен број), па елементите се поместуваат за една позиција на десно (_,1,2,3,4). Потоа празнините се пополнуваат со 0 и низата ги има елементите 0,1,2,3,4.

Во третиот пример се вчитува исто само една низа со 5 елементи (-2,-3,-4,-5,-6). Првиот елемент е -2 (негативен број), па елементите се поместуваат за две позиции на лево (-4,-5,-6,_,__). Потоа празнините се пополнуваат со 0 и низата ги има елементите -4,-5,-6,0,0.*/

#include <stdio.h>
#include <stdlib.h>
void pomestuvanje(int *array, int N, int br) {
    int i;
    if (br > 0) {
        //ako prviot el e pogolem od br na clenovi vo nizata vrednosta na site el od nizata kje bide 0
        if (br > abs(N)) {
            for (i = 0; i < N; i++) {
                array[i] = 0;
            }
        } else {
            // Pomestuvanje el vo desno
            for (i = N - 1; i >= br; i--) {
                array[i] = array[i - br];
            }
            // Popolnuvanje na praznite mesta sto kje se otvorat so nuli
            for (i = 0; i < br; i++) {
                array[i] = 0;
            }
        }
    } else if (br < 0) {
        if (abs(br) > N) {
            for (i = 0; i < N; i++) {
                array[i] = 0;
            }
        } else {
            // Pomestuvanje na el vo levo
            for (i = 0; i < N + br; i++) {
                array[i] = array[i - br];
            }
            // Popolnuvanje na praznite mesta sto kje se otvorat so nuli
            for (i = N + br; i < N; i++) {
                array[i] = 0;
            }
        }
    }
}
int main() {
    int m, i, j, n, prvEl, VkNuli=0, Nuli=0;
    int arr[100];
    // Vnesuvame br na nizi
    scanf("%d", &m);
    // Vnes na sekoja niza
    for (i = 0; i < m; i++) {
        scanf("%d", &n);
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        Nuli=0;
        // Vrednost na prv el.,odnosno za kolku da bide pomestuvanjeto
        prvEl = arr[0];
        // Povikuvanje na fja koja gi pomestuva el
        pomestuvanje(arr, n, prvEl);
        //proverka na brojot na nizi na koi site el im se samo '0'
        for (j = 0; j < n; j++) {
            if(arr[j]==0){
                Nuli++;
            }
        }
        if(Nuli==n){
            VkNuli++;
        }
        //printanje na transformiranata niza
        for (j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
    //printanje na br na nizi polni so samo el '0'
    printf("%d\n", VkNuli);
    return 0;
}

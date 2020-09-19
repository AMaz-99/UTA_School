/* Aamir Mazumdar 1001523593 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>


int main () {
    int i, k, t, counter = 0;
    int N = 2;
    for (i = 0; i <= N; i++){
        for (k = 1; k < pow(3,i); k = k*2){
            printf("A");
            counter++;
        }
    }
    printf("\n\n%d", counter);
    return 0;
}

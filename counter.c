#include <stdio.h>

int main(){



    while((i < 4) ){
        printf("%d", array[i++]);
    }
}

int * bincounter(int * arr, int len){
    int i = 0;
    while ((arr[i] == 1) && i < len) {
        arr[i] = 0;

        i++;
    }
        if( i < len)
        arr[i] = 1;
}
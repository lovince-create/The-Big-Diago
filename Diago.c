/*This code generates a 2D-Array, we will call it a matrix. A matrix where n is the order.

n is given through the command line.

Then with option O, the two diagonals will be swapped.
But that's not the matter.

The idea is to push the limits to make n the biggest possible.

I reached 10 000, and the stdout refused to print even one character of this nonsense, so I had to redirect it to a file, for a decent size of 889 MB. But it's on my phone, not too much space so I had to play it low.

My goal is order 1 billion, it's just crazy to imagine a matrix of 10^18 elements, but I cannot yet estimate the size of the files.*/


#include <stdio.h>
#include <stdlib.h>                                                               int main(int argc, char* argv[]) {

    int n = atoi(argv[1]);
    int** tab = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n;i++) {
        tab[i] = (int*)malloc(sizeof(int*) * n);
    }
    int elements = 1;
    int lindex = n - 1;
    int temp = 0;
    char opt = argv[2] ? argv[2][0] : 'N';
    for(int i = 0; i < n;i++) {
        for(int j = 0; j < n;j++) {
            tab[i][j] = elements;
            elements++;
        }
    }

    if(opt == 'O') {
        for(int i = 0; i < n;i++) {
            temp = tab[i][i];
            tab[i][i] = tab[i][lindex];
            tab[i][lindex] = temp;
            lindex--;
        }
    }

    if(opt == 'O' || opt == 'N') {
        for(int i = 0; i < n;i++) {
            for(int j = 0; j < n;j++) {
                printf("%d ",tab[i][j]);
            }
            printf("\n");
        }
    }
    for(int i = 0; i < n;i++) {
        free(tab[i]);
    }
    free(tab);
    return 0;
}

#include <stdio.h>
#include "tris.h"


/***************************** Algo 3 : Tri rapide *****************************/

void sousTriRapide(long * A,size_t p, size_t r){
    if(p - r != 0){
        size_t q = partition(A,p,r); //q la position du pivot dans la partition
        printf("Pivot %ld à la position : %ld \n",A[q],q);
        //tri partie gauche
        printf("Sous tri gauche  de %ld à %ld : ",p,q);
        afficheTab(A,p,q);
        sousTriRapide(A,p,q);
        //tri partie droite
        printf("Sous tri droit  de %ld à %ld : ",q+1,r);
        afficheTab(A,q+1,r);
        sousTriRapide(A,q+1,r);
    }
}

size_t partition(long * A, size_t p, size_t r){
    long pivot = A[r-1]; //le pivot est le dernier élément du tableau
    printf("Pivot %ld \n",pivot);
    size_t i = p;
    for (size_t j = p; j <= r-2; j++){
        printf("    i = %ld et A[i] = %ld   j = %ld et A[j] = %ld \n",i,A[i],j,A[j]);
        if(A[j] <= pivot){
            printf("    Permutation de %ld et %ld : ",A[i],A[j]);
            long tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
            afficheTab(A,p,r);
        }
    }
    printf("    Permutation du pivot : ");
    long tmp = A[i];
    A[i] = A[r-1];
    A[r-1] = tmp;
    afficheTab(A,p,r);
    return i;
}

void triRapide(long * A, size_t n){
    sousTriRapide(A,0,n);
    printf("Tableau trié : ");
    afficheTab(A,0,n);
}


/***************************** Utils *****************************/

void afficheTab(long * A, size_t p, size_t q){
    if((p - q != 0)){
        printf("[");
        for(size_t i = p; i < q-1; i++){
            printf("%ld,",A[i]);
        }
        printf("%ld]\n",A[q-1]);
    }
    else{
        printf("Tab vide \n");
    }
}
#include "tri_rapide_decompte.h"

void sousTriRapide(long * A,size_t p, size_t r, perf* pe){
    pe->nb_comp += 1;
    if(p - r != 0){
        size_t q = partition(A,p,r,pe); //q la position du pivot dans la partition
//        printf("Pivot %ld à la position : %ld \n",A[q],q);
        //tri partie gauche
//        printf("Sous tri gauche  de %ld à %ld : ",p,q);
//        afficheTab(A,p,q);
        sousTriRapide(A,p,q,pe);
        //tri partie droite
//        printf("Sous tri droit  de %ld à %ld : ",q+1,r);
//        afficheTab(A,q+1,r);
        sousTriRapide(A,q+1,r,pe);
    }
}

size_t partition(long * A, size_t p, size_t r, perf* pe){
    pe->appels_partition +=1;
    long pivot = A[r-1]; //le pivot est le dernier élément du tableau
//    printf("Pivot %ld \n",pivot);
    size_t i = p;
    long tmp;

    pe->nb_ecriture +=2;
    pe->nb_alloc += sizeof(long)*2 + sizeof(size_t)*2;

    for (size_t j = p; j+2 <= r; j++){

        pe->nb_comp += 2; //comparaison boucle et if
        pe->nb_ecriture ++; //incrémentation boucle

//        printf("    i = %ld et A[i] = %ld   j = %ld et A[j] = %ld \n",i,A[i],j,A[j]);
        if(A[j] <= pivot){
//            printf("    Permutation de %ld et %ld : ",A[i],A[j]);
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;

            pe->nb_echange +=1;
            pe->nb_ecriture +=2;
            pe->nb_ecriture_tab +=2;
//            afficheTab(A,p,r);
        }
    }
//    printf("    Permutation du pivot : ");
    tmp = A[i];
    A[i] = A[r-1];
    A[r-1] = tmp;

    pe->nb_echange +=1;
    pe->nb_ecriture_tab +=2;
    pe->nb_ecriture ++;
//    afficheTab(A,p,r);
    return i;
}

void triRapide(long * A, size_t n){
    perf pe = init_perf();
//    afficheTab(A,0,n);
    sousTriRapide(A,0,n,&pe);
//    printf("Tableau trié : ");
//    afficheTab(A,0,n);
    printf("********* Tri rapide **********\n");
    printPerf(pe);
}
/*
ID: yangsiw1
LANG: C
TASK: ride
*/
#include <stdlib.h>
#include <stdio.h>
int decodeName(char *name) {
    int result = 1;
    while(*name) {
        result *= (*name - 64);
        result %= 47;
        name++;
    }
    
    return result;
}

main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char comet [7];
    char group [7];
    
    fscanf (fin, "%s", comet);
    fscanf (fin, "%s", group);
    if (decodeName(comet) == decodeName(group)) {
        fprintf (fout, "GO\n");
    } else {
        fprintf (fout, "STAY\n");
    }
    
    exit (0);
}


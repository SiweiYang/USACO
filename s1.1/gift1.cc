/*
ID: yangsiw1
LANG: C
TASK: gift1
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int find_index(char **group, int size, char *name) {
    int index = 0;
    while (strcmp(group[index], name)) {
        if (index == size)break;
        index += 1;
    }
    
    return index;
}

main () {
    char group_name [150];
    char *group [10];
    int balance [10];
    //printf("Data Area starts at %x\n", group_name);
    //printf("Index Area starts at %x\n", group);
    {
        char **group_pointer = group;
        char *group_name_pointer = group_name + 135;
        int *balance_pointer =balance;
        while (1) {
            *group_pointer = group_name_pointer;
            *balance_pointer = 0;
            //printf("Index: %x\n", *group_pointer);
            if (group_name_pointer == group_name)break;
            
            group_pointer += 1;
            group_name_pointer -= 15;
            balance_pointer += 1;
        }
        //printf("Initialization Done!!!\n");
    }
    
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    int total;
    fscanf (fin, "%d", &total);
    //printf("There are a total of %d members...\n", total);
    
    {
        int total_counter = total;
        while(total_counter--) {
            fscanf (fin, "%s", group[total_counter]);
        }
    }
    //printf("Loaded a total of %d members...\n", total); 
       
    {
        int total_counter = total;
        char name [15];
        while(total_counter--) {
            fscanf (fin, "%s", name);
            //printf("Sender is %s\n", name);
            int sender = find_index(group, total, name);
            
            int sum, number, amount;
            fscanf (fin, "%d %d", &sum, &number);
            
            if (number) {
                amount = sum / number;
                //printf("Sending %d to %d with each receiving %d\n", sum, number, amount);
                
                while(number--) {
                    fscanf (fin, "%s", name);
                    int receiver = find_index(group, total, name);
                    balance[sender] -= amount;
                    balance[receiver] += amount;
                }
            }
        }

    }
    
    while(total--) {
        fprintf(fout, "%s %d\n", group[total], balance[total]);
    }
    exit (0);
}


/*
ID:szfan1
LANG:C
TASK:gift1
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char name[10][15];
    int final[10];

    int np;
    FILE *fin = fopen("gift1.in", "r");
    FILE *fout = fopen("gift1.out", "w");
    fscanf(fin, "%d\n", &np);
    
    int i;
    for(i = 0; i < np; i++){
	final[i] = 0;
    }

    for(i = 0; i < np; i++){
        fscanf(fin, "%s\n", name[i]);
    }

    char giver[15], getter[15];
    int money, gnp;
    int eachGetter, giverLeft;
    int j, k;
    for(i = 0; i < np; i++) {
	fscanf(fin, "%s\n", giver);
	fscanf(fin, "%d %d\n", &money, &gnp);
	if(gnp == 0) {
	    eachGetter = 0;
	    giverLeft = money;
	}else {
	    eachGetter = money/gnp;
	    giverLeft = money%gnp;
	}
	for(k = 0; k < np; k++) {
	    if(strcmp(name[k], giver) == 0) {
		final[k] -= money - giverLeft;		
	    }
	}
	for(j = 0; j < gnp; j++){
	    fscanf(fin, "%s\n", getter);
	    for(k = 0; k < np; k++){
		if(strcmp(name[k], getter) == 0) {
		    final[k] += eachGetter;
		}
	    }
	}
    }

    for(i = 0; i < np; i++){
	fprintf(fout, "%s %d\n", name[i], final[i]);
    }

    fclose(fin);
    fclose(fout);
    exit(0);
}

/*
ID:szfan1
LANG:C
TASK:ride
*/

#include<stdio.h>
#include<stdlib.h>

int locHash(char *s){
    int result = 1;
    while(*s != '\0'){
        result *= *s - 'A' + 1;
        s++;
    }
    return result%47;
}

int main(){
    FILE *fin = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");
    char str1[8], str2[8];
    fscanf(fin, "%s\n%s", str1, str2);
    if(locHash(str1) == locHash(str2)) {
        fprintf(fout, "GO\n");
    }else {
	fprintf(fout, "STAY\n");
    }
    fclose(fin);
    fclose(fout);
    exit(0);
}

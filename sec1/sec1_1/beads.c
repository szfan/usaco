/*
ID:szfan1
LANG:C
TASK:beads
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE *fin = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");

    char tmp[351];
    char necklace[701];
    int len;

    fscanf(fin, "%d\n", &len);
    fscanf(fin, "%s\n", tmp);
    strcpy(necklace, tmp);
    strcat(necklace, tmp);
    
    int i, j;
    int leftCnt, rightCnt, total = 0;
    char leftC, rightC;
    for(i = 0; i < len; i++){
	leftCnt = 0;
	rightCnt = 0;
        
	leftC = necklace[i];
	rightC = necklace[i+1];

        for(j = i; j >=0; j--){
    	    if(leftC == 'w'){
		leftCnt++;
		if(necklace[j] != 'w'){
		    leftC = necklace[j];
		}
	    }else if(necklace[j] == 'w' || necklace[j] == leftC){
		leftCnt++;
	    }else{
		break;
	    }	
	}

	for(j = i+1; j < i+len; j++){
	    if(rightC == 'w'){
		rightCnt++;
		if(necklace[j] != 'w'){
		    rightC = necklace[j];
		}
	    }else if(necklace[j] == 'w' || necklace[j] == rightC){
		rightCnt++;
	    }else{
		break;
	    }
	}
//	printf("at position %d, left = %d, right = %d\n", i, leftCnt, rightCnt);

	if(leftCnt+rightCnt > total) {
	    total = leftCnt + rightCnt;
	}
	if(total > len){
	    total = len;
	}
    }

    fprintf(fout, "%d\n", total);
    fclose(fin);
    fclose(fout);
    exit(0);
}

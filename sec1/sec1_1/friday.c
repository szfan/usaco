/*
ID:szfan1
LANG:C
TASK:friday
*/

#include<stdio.h>
#include<stdlib.h>

// return the DayNumber, 0 for monday and 6 for sunday, etc.
int dayOfWeek(int year, int month, int day){
    if(month < 3) {
	month += 12;
	year -= 1;
    }
    return (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7;
}

int main(){
    FILE *fin = fopen("friday.in", "r");
    FILE *fout = fopen("friday.out", "w");

    int passYear;
    fscanf(fin, "%d\n", &passYear);

    int dayWeekCnt[7];
    int i;
    for(i = 0; i < 7; i++){
	dayWeekCnt[i] = 0;
    }

    int endYear = 1900 + passYear - 1;
    int endMonth = 12;
    int endDay = 31;

    int j;
    for(i = 1900; i <= endYear; i++){
        for(j = 1; j <= 12; j++){
	    dayWeekCnt[dayOfWeek(i, j, 13)]++;
	}
    }

    for(i = 5; i < 12; i++){
	if(i == 11){
            fprintf(fout, "%d\n", dayWeekCnt[i%7]);
        }else{
	    fprintf(fout, "%d ", dayWeekCnt[i%7]);
	}
    }

    fclose(fin);
    fclose(fout);
    exit(0);
}

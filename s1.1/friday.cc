/*
ID: yangsiw1
LANG: C
TASK: friday
*/
#include <stdlib.h>
#include <stdio.h>

int gapDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int process(int isLeap, int startDay, int* accumulateDays) {
  int month = 0;
  while(month < 12) {    
    accumulateDays[startDay]++;

    startDay = (startDay + gapDays[month]) % 7;
    if (month == 1)
    {
      startDay = (startDay + isLeap) % 7;
    }
    month++;
  }

  return startDay;
}

main () {
  FILE *fin  = fopen ("friday.in", "r");
  FILE *fout = fopen ("friday.out", "w");

  int totalYear, currentYear = 1900, endYear = 1900, startDay = 5;
  int accumulateDays[7] = {0, 0, 0, 0, 0, 0, 0};
  fscanf (fin, "%d", &totalYear);
  endYear += totalYear;
  while (currentYear < endYear)
  {
    if (currentYear % 4)
    {
      startDay = process(0, startDay, accumulateDays);
    } else if (currentYear % 100)
    {
      startDay = process(1, startDay, accumulateDays);
    } else if (currentYear % 400)
    {
      startDay = process(0, startDay, accumulateDays);
    } else {
      startDay = process(1, startDay, accumulateDays);
    }

    currentYear++;
  }

  fprintf(fout, "%d %d %d %d %d %d %d\n", accumulateDays[5], accumulateDays[6], accumulateDays[0], accumulateDays[1], accumulateDays[2], accumulateDays[3], accumulateDays[4]);
  exit (0);
}


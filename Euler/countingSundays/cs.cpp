#include <stdio.h>
#include <stdbool.h>

enum days {MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY,SUNDAY};
enum months {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};

void checkDate(enum months &m, int &d, int &y){

  bool isLeap = ( (y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0)) );
  bool thirtyDays = false, isFeb = false;
  switch(m){
    case FEB:
      isFeb = true;
      break;
    case APR:
      thirtyDays = true;
      break;
    case JUN:
      thirtyDays = true;
      break;
    case SEP:
      thirtyDays = true;
      break;
    case NOV:
      thirtyDays = true;
      break;
  }
  int dayMod = 31;
  if(thirtyDays) dayMod = 30;
  if(isFeb) dayMod = 28;
  if(isFeb && isLeap) dayMod = 29;

  if(d > dayMod){
    d = d % dayMod;
    if(m == DEC){
      m = JAN;
      y++;
    }else{
      m = months(m + 1);
    }
  }

}

int main(){

  int sundayCount = 0, year = 1900, dayOfMonth = 1;
  enum days day = MONDAY;
  enum months month = JAN;
  
  while(year != 2001){

    if(dayOfMonth == 1 && day == SUNDAY && year >= 1901){
      printf("Found a Sunday on Month %d of year %d\n",month,year);
      sundayCount++;
    }

    if(day == SUNDAY){
      day = MONDAY;
    }else{
      day = days(day + 1);
    }
    dayOfMonth++;
    checkDate(month,dayOfMonth,year);

  }
  

  printf("%d Sundays fell on the first of the month between 1 Jan 1901 - 31 Dec 2000.\n",sundayCount);

  return 0;
}

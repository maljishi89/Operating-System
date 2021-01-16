#include <stdio.h>
#include <stdlib.h>

int main(void){

    double work_days;
    double work_hours;
    double work_hourly_wage;
    double salary_earned;

    printf("Enter number of days worked:\n");
    scanf("%lf", &work_days);
    printf("Enter number of hours worked per day:\n");
    scanf("%lf", &work_hours);
    printf("Enter hourly wage in Saudi Riyals:\n");
    scanf("%lf", &work_hourly_wage);

    salary_earned = work_days * work_hours * work_hourly_wage;

    printf("Salary Earned = %.2lf Saudi Riyals \n", salary_earned);

    printf("Enter to terminate . . .");


    return 0;
}


#include <stdio.h>
enum WeekDayType {Monday = 1, Tuesday, Wednesday,
Thursday, Friday, Saturday, Sunday};

int main()
{
    enum WeekDayType week_day;

    int day;
    scanf("%d", &day);
    week_day = (enum WeekDayType)day;

    switch (week_day) {
    case Monday:        printf("Monday\n"); break;
    case Tuesday:       printf("Tuesday\n"); break;
    case Wednesday:     printf("Wednesday\n"); break;
    case Thursday:      printf("Thursday\n"); break;
    case Friday:        printf("Friday\n"); break;
    case Saturday:      printf("Saturday\n"); break;
    case Sunday:        printf("Sunday\n"); break;
    default:            printf("Never can be!...\n");
    }
    return 0;
}

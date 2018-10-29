#include <stdio.h>

int main()
{
    int day;
    scanf("%d", &day);
    switch (day) {
    case 1:  printf("Sunday\n"); break;
    case 2:  printf("Monday\n"); break;
    case 3:  printf("Tuesday\n"); break;
    case 4:  printf("Wednesday\n"); break;
    case 5:  printf("Thursday\n"); break;
    case 6:  printf("Friday\n"); break;
    case 7:  printf("Saturnday"); break;
    default:
        printf("Strange day...\n");
}
return 0;
}


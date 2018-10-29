#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char line[100];
    char * input_lines[100];
    int n = 0;
    scanf("%s", line);
    while (strcmp(line, "The_End!") != 0) {
            size_t line_len = sizeof(char) * (strlen(line) + 1);
            input_lines[n] = (char *)malloc(line_len);
            memcpy(input_lines[n], line, line_len);
            n++;
            scanf("%s", line);
    }
    for (int i = 0; i < n; i++)
        printf(">> %s\n", input_lines[i]);
    return 0;
}

#include <stdio.h>
#define MAX_STACK_SIZE 1000

int A[MAX_STACK_SIZE];
int top = 0; //уровень заполненности стека

void push(int x)
{
    A[top] = x;
    top++;
}

int pop()
{
    top--;
   return A[top];
}

//return 1 если стек пуст
int isEmpty()
{
    return top == 0;
}

//return 1 если стек почти переполнен
int isFull()
{
    return top == MAX_STACK_SIZE;
}

isLeftBrace(char symbol)
{
    if (symbol == '(' || symbol == '['
        || symbol == '<' || symbol == '{')
        return 1;
    else
        return 0;
}

isRightBrace(char symbol)
{
    if (symbol == ')' || symbol == ']'
        || symbol == '>' || symbol == '}')
        return 1;
    else
        return 0;
}

isPairBraces(char a, char b)
{
    if (a == '(' && b == ')' ||
        a == '[' && b == ']' ||
        a == '<' && b == '>' ||
        a == '{' && b == '}')
        return 1;
    else
        return 0;
}

int isCorrectBracesStructure(char str[])
{
    for(int i=0; i < strlen(str); i++) {
            if (isLeftBrace(str[i]))
                push(str[i]);
            else if (isRightBrace(str[i])) {
                if (isEmpty()) {
                    return 0; //not correct
            }
            char lastLeftBrace = pop();
            if (!isPairBraces(lastLeftBrace, str[i]))
                return 0; //not correct
    }
    //если я здесь, значит не было return,
    //т.е. все правые скобки соответствовали левым
    //и их не было больше, чем левых
    if (isEmpty())
        return 1; //стек пуст -- всё чисто
    else
        return 0; //стек не пуст -- лишние левые скобки
}

int main()
{
        char str[1000];
    scanf("%s", str);

    if(isCorrectBracesStructure(str)) {
        printf("correct");
    } else {
        printf("not correct");
    }
    return 0;
}

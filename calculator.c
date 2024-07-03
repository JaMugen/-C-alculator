#include <stdio.h>

void user_input(long int *first_operand, char *operator, long int *second_operand);
long int call_operation(long int *first_operand, char *operator, long int *second_operand);
long int addition(long int *first_operand, long int *second_operand);

int main(void)
{
    long int first_operand, second_operand;
    char operator;

    user_input(&first_operand, &operator, &second_operand);
    printf("%ld %c %ld = %ld\n",first_operand, operator,
        second_operand,  call_operation(&first_operand, &operator, &second_operand));

    return 0;
}

void user_input(long int *first_operand, char *operator, long int *second_operand){

    printf("Enter the opparand, then the operator, and lastly the final operand to get answer. \n");
    scanf(" %ld", first_operand);
    //printf("%ld\n", *first_operand);
    scanf(" %c", operator); //added a space so that the newline value from previous scanf is not accepted as input.
    scanf(" %ld", second_operand);
}

long int call_operation(long int *first_operand, char *operator, long int *second_operand){
    if (*operator == '+') return addition(first_operand, second_operand);
    return 0;
}

long int addition(long int *first_operand, long int *second_operand){
   return *first_operand + *second_operand;
}
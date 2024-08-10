#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void user_input(long int *first_operand, char *operator, long int *second_operand);
long int call_operation(long int *first_operand, char *operator, long int *second_operand);
long int addition(long int *first_operand, long int *second_operand);
long int subtraction(long int *first_operand, long int *second_operand);
long int multiplication(long int *first_operand, long int *second_operand);
long int division(long int *first_operand, long int *second_operand);
long int power(long int *first_operand, long int *second_operand);
long int root(long int *second_operand);

int main(void)
{
    long int first_operand, second_operand;
    char operator;

    while(1){
        user_input(&first_operand, &operator, &second_operand);
        if(operator == 'E'){
            break;
        }
        printf("%ld %c %ld = %ld\n",first_operand, operator,
            second_operand,  call_operation(&first_operand, &operator, &second_operand));
    }
    

    return 0;
}

void user_input(long int *first_operand, char *operator, long int *second_operand){

    char temp_input[100];
    
    printf("Enter a basic calculation of operand, operator, then second operand; to get answer(type exit for a new operation to exit). \n");
    fgets(temp_input, 100, stdin);
    temp_input[strcspn(temp_input, "\n")] = 0;

    if(strcmp(temp_input, "exit") == 0){
        *operator = 'E';
        return;
    }

    if(strcmp(temp_input, "s") == 0){ //if statement for setting up the unique square root operation then early returns.
        *operator = 's';
        scanf(" %ld", second_operand);
        while (getchar() != '\n');
        return;
    }

    *first_operand = atoi(temp_input);
    //scanf(" %ld", first_operand);
    //printf("%ld\n", *first_operand);
    scanf(" %c", operator); //added a space so that the newline value from previous scanf is not accepted as input.
    scanf(" %ld", second_operand);
    //scanf reads all of input as is. It will also buffer input data. FOr example "+ 9" can be entered to fill in each scanf call.
    //Caused an issue where the the buffered /n was being assigned as the input value so the leading space avoids that issue.

    while (getchar() != '\n'); //used to remove any characters from the buffer.
    return;
}

long int call_operation(long int *first_operand, char *operator, long int *second_operand){
    switch (*operator)
    {
    case '+':
        return addition(first_operand, second_operand);
        break;

    case '-':
        return subtraction(first_operand, second_operand);
        break;

    case '*':
        return multiplication(first_operand, second_operand);
        break;

    case '/':
        return division(first_operand, second_operand);
        break;

    case '^':
        return power(first_operand, second_operand);
        break;
    case 's':
        return root(second_operand);
        break;

    default:
        break;
    }
    return 0;
}

long int addition(long int *first_operand, long int *second_operand){
   return *first_operand + *second_operand;
}

long int subtraction(long int *first_operand, long int *second_operand){
   return *first_operand - *second_operand;
}

long int multiplication(long int *first_operand, long int *second_operand){
   return *first_operand * *second_operand;
}

long int division(long int *first_operand, long int *second_operand){
   return *first_operand / *second_operand;
}

long int power(long int *first_operand, long int *second_operand){
    return (pow(*first_operand, *second_operand));
}
long int root(long int *second_operand){
    return sqrtl(*second_operand);
}





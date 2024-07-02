#include <stdio.h>

void user_input(long int *first_opperand, char *opperator, long int *second_opperand);
long int call_operation(long int *first_opperand, char *opperator, long int *second_opperand);
long int addition(long int *first_opperand, long int *second_opperand);

int main(void)
{
    long int first_opperand, second_opperand;
    char opperator;

    user_input(&first_opperand, &opperator, &second_opperand);
    printf("%ld %c %ld = %ld\n",first_opperand, opperator,
        second_opperand,  call_operation(&first_opperand, &opperator, &second_opperand));

    return 0;
}

void user_input(long int *first_opperand, char *opperator, long int *second_opperand){

    printf("Enter the opparand, then the operator, and lastly the final opperand to get answer. \n");
    scanf(" %ld", first_opperand);
    //printf("%ld\n", *first_opperand);
    scanf(" %c", opperator); //added a space so that the newline value from previous scanf is not accepted as input.
    scanf(" %ld", second_opperand);
}

long int call_operation(long int *first_opperand, char *opperator, long int *second_opperand){
    if (*opperator == '+') return addition(first_opperand, second_opperand);
    return 0;
}

long int addition(long int *first_opperand, long int *second_opperand){
   return *first_opperand + *second_opperand;
}
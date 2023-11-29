//a demonstration to convert number from their digit form to pronunciatian form
#include <stdio.h>
#include <string.h>
void master(char *) ;
void controller(char * , int) ;
int main() 
{
    char number[16] ;
    printf("Enter a number : ") ;
    scanf("%s" , number) ;
    int a = strlen(number) % 3 ;
    controller(number , a) ;
    return   0 ;
}

void master(char *start)
{
    char *first[] = {"" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine"} ;
    char *second[] = {"" , "" , "twenty" , "thirty" , "forty" , "fifty" , "sixty" , "seventy" , "eighty" , "ninety"} ;
    char *third[] = {"ten" , "eleven" , "twelve" , "thirteen" , "fourteen" , "fifteen" , "sixteen" , "seventeen" , "eighteen" , "nineteen"} ;
    int a = *start - 48 , b = *(start + 1) - 48 , c = *(start + 2) - 48 ;

    if(a == 1)
        printf("one-hundred ") ;
    else if(a == 0)
        printf("%s" , *(first)) ;
    else
        printf("%s-hundreds " , *(first + a)) ;
    if(b != 1)
    {
        if(c != 0 && b != 0)
            printf("and %s-%s" , *(second + b) , *(first + c)) ;
        else if(c == 0 && b == 0)
            printf("%s%s" , *(second + b) , *(first + c)) ;
        else
            if(a == 0)
                printf("%s%s" , *(second + b) , *(first + c)) ;
            else
                printf("and %s%s" , *(second + b) , *(first + c)) ;
    }
    else
    if(a == 0)
        printf("%s" , *(third + c)) ;
    else
        printf("and %s" , *(third + c)) ;
    printf(" ") ;
}

void controller(char *first , int a)
{
    char format_number[16] ;
    if(a == 1)
    {
        format_number[0] = '0' ;
        format_number[1] = '0' ;
        strcpy(&format_number[2] , first) ;
    }

    else if(a == 2)
    {
        format_number[0] = '0' ;
        strcpy(&format_number[1] , first) ;
    }
    else
        strcpy(format_number , first) ;

    int b = strlen(format_number) / 3 ;
    for(int i = 0 , j = b ; j > 0 ; i = i + 3 , j--)
    {
        int c = format_number[i] + format_number[i + 1] + format_number[i + 2] - (48 * 3) ;
        if(j == 5)
        {
            master(&format_number[i]) ;
            printf("Trillion ") ;
        }
        if(j == 4)
        {
            master(&format_number[i]) ;
            if(c == 1)
                printf("Billion ") ;
            else if(c)
                printf("Billions ") ;
            if(c == 0)
                printf("\b") ;
        }
        if(j == 3)
        {
            master(&format_number[i]) ;
            if(c == 1)
                printf("Million ") ;
            else if(c)
                printf("Millions ") ;
            if(c == 0)
                printf("\b") ;
        }
        if(j == 2)
        {
            master(&format_number[i]) ;
            if(c == 1)
                printf("Thousand ") ;
            else if(c)
                printf("Thousands ") ;
            if(c == 0)
                printf("\b") ;
        }
        if(j == 1)
            master(&format_number[i]) ;
    }
}

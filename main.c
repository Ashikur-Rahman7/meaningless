#include <stdio.h>
#include <stdlib.h>
#include "main.c"
int main( )
{
char string[25] ;
    scanf("%s" , string) ;
    for(int row = 0 ; row < 10 ; row++)
    {
        for(int i = 0 ; string[i] != '\0' ;i++)
        {
            switch(string[i])
            {
                case '0' :
                    zero(row) ;
                    break ;
                case '1' :
                    one(row) ;
                    break ;
                case '2' :
                    two(row) ;
                    break ;
                case '3' :
                    three(row) ;
                    break ;
                case '4' :
                    four(row) ;
                    break ;
                case '5' :
                    five(row) ;
                    break ;
                case '6' :
                    six(row) ;
                    break ;
                case '7' :
                    seven(row) ;
                    break ;
                case '8' :
                    eight(row) ;
                    break ;
                case '9' :
                    nine(row) ;
                    break ;
                default :
                    printf("Invalid Charecter(s).") ;
                    exit(0) ;
            }
            printf("  ") ;
        }
        printf("\n") ;
    }
return 0 ;
}

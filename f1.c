#include <stdio.h>
int yeartoday(int) ;
int monthtoday(int , int) ;
int leapyear(int) ;
int notleapyear(int) ;
void final(int , int , int) ;
int main() 
{
int year , month ;
printf("Year and Month : ") ;
scanf("%d %d" , &year , &month) ;
int day = yeartoday(year - 1) + monthtoday(year , month);
final(day % 7 , month , year) ;

return 0 ;
}

int yeartoday(int year)
{
int day = 0 ;
int temp1 = year ;
if(year > 400)
    {
        for(int i = 0 ; i < (temp1 / 400) ; i++)
        {
        year = year - 400 ;
        day = day + 146097 ;
        }
    }
int temp2 = year ;
if(year > 100)
{
    for(int i = 0 ; i < (temp2 / 100) ; i++)
    {
        year = year - 100 ;
        day = day + 36524 ;
    }
}
day = day + (year % 4) * 365 ;
day = day + (year / 4) * 1461 ;
return day ;
}




int monthtoday(int year , int month)
{
    int n = 0 ;
    (year % 4 == 0) ? ((year % 100 == 0) ? ((year % 400 == 0) ? (n = 1) : (n = 0)) : (n = 1)) : (n = 0) ;
    if(n == 1)
        return leapyear(month) ;
    else
        return notleapyear(month) ;
}

int leapyear(int month)
{
    if(month == 1)
        return 0 ;
    else if(month == 2)
        return 31 ;
    else if(month == 3)
        return 60 ;
    else if(month == 4)
        return 91 ;
    else if(month == 5)
        return 121 ;
    else if(month == 6)
        return 152 ;
    else if(month ==7)
        return 182 ;
    else if(month ==8)
        return 213 ;
    else if(month ==9)
        return 244 ;
    else if(month ==10)
        return 274 ;
    else if(month ==11)
        return 305 ;
    else
        return 335 ;

}

int notleapyear(int month)
{
    if(month == 1)
        return 0 ;
    else if(month == 2)
        return 31 ;
    else if(month == 3)
        return 59 ;
    else if(month == 4)
        return 90 ;
    else if(month == 5)
        return 120 ;
    else if(month == 6)
        return 151 ;
    else if(month ==7)
        return 181 ;
    else if(month ==8)
        return 212 ;
    else if(month ==9)
        return 243 ;
    else if(month ==10)
        return 273 ;
    else if(month ==11)
        return 304 ;
    else
        return 334 ;   
}


void final(int start , int month , int year)
{
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            printf("Monday       Tuesday         Wendsday       Thrusday         Friday         Saturday          Sunday\n") ;
            int n = 1 , k = 0;
            for(int i = 1 ; i <= 31 ; i++ , k++)
                {
                    if(n == 1)
                    {
                    for(int j = 0 ; j < start ; j++ , k++)
                        printf("\t\t") ;
                    }
                    n = 0 ;
                    if(k % 7 == 0)
                        printf("\n  ") ;
                    printf("%d\t\t" , i) ;
                }
        }
    else if(month == 2)
    {
    int n = 0 ;
    (year % 4 == 0) ? ((year % 100 == 0) ? ((year % 400 == 0) ? (n = 1) : (n = 0)) : (n = 1)) : (n = 0) ;
    if(n == 0)
    {
        printf("Monday       Tuesday         Wendsday       Thrusday         Friday         Saturday          Sunday\n") ;
            int n = 1 , k = 0;
            for(int i = 1 ; i <= 28 ; i++ , k++)
                {
                    if(n == 1)
                    {
                    for(int j = 0 ; j < start ; j++ , k++)
                        printf("\t\t") ;
                    }
                    n = 0 ;
                    if(k % 7 == 0)
                        printf("\n  ") ;
                    printf("%d\t\t" , i) ;
                }
    }
    else
    {
        printf("Monday       Tuesday         Wendsday       Thrusday         Friday         Saturday          Sunday\n") ;
            int n = 1 , k = 0;
            for(int i = 1 ; i <= 29 ; i++ , k++)
                {
                    if(n == 1)
                    {
                    for(int j = 0 ; j < start ; j++ , k++)
                        printf("\t\t") ;
                    }
                    n = 0 ;
                    if(k % 7 == 0)
                        printf("\n  ") ;
                    printf("%d\t\t" , i) ;
                }
    }
    }
    else
    {
        printf("Monday       Tuesday         Wendsday       Thrusday         Friday         Saturday          Sunday\n") ;
            int n = 1 , k = 0;
            for(int i = 1 ; i <= 30 ; i++ , k++)
                {
                    if(n == 1)
                    {
                    for(int j = 0 ; j < start ; j++ , k++)
                        printf("\t\t") ;
                    }
                    n = 0 ;
                    if(k % 7 == 0)
                        printf("\n  ") ;
                    printf("%d\t\t" , i) ;
                }
    }
}






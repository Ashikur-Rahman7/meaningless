#include <stdio.h>
#include <string.h>
int check(char * , int) ;
void manage(char * , int , int) ;
void binary_to_octal(char * , int) ;
void binary_to_decimal(char * , int) ;
void binary_to_hex(char * , int) ;
void octal_to_binary(char *) ;
void octal_to_decimal(char * , int) ;
void octal_to_hex(char * , int) ;
void decimal_to_binary(char * , int) ;
void decimal_to_octal(char * , int) ;
void decimal_to_hex(char * , int) ;
void hex_to_binary(char *) ;
void hex_to_octal(char * , int) ;
void hex_to_decimal(char * , int) ;
int main()
{
    char snum[64] ;
    int n , m = 0 ;
    while(1)
    {
        printf("\nChose what you want to do : \n\n") ;
        printf("  01....Binary to Ocatal        07...Decimal to Binary\n  02....Binary to Decimal       08...Decimal to octal\n  03....Binary to Hex           09...Decimal to Hex\n") ;
        printf("  04.....Octal to Binary        10.......Hex to Binary\n  05.....Octal to Decimal       11.......Hex to Octal\n  06.....Octal to Hex           12.......Hex to Decimal\n") ;
        if(m == 0)
            printf("\n  Chose : ") ;
        else
            printf("\n  You have to chose from '1' to '12' : ") ;
        m++ ;
        scanf("%d" , &n) ;
        getchar() ;
        if(n > 12 || n < 1)
            continue ;
        else
            break ;
    }
    int n1 = n ;
    char a[64] ;
    if(n > 0 && n < 4)
        strcpy(a , "a binary") ;
    else if(n > 3 && n < 7)
        strcpy(a , "an octal") ;
    else if(n > 6 && n < 10)
        strcpy(a , "a decimal") ;
    else if(n > 9 && n < 13)
        strcpy(a , "a hexadecimal") ;
    while(1)
    {
        printf("  Input %s number you want to convert : " , a) ;
        int i = 0 ;
        while(1)
        {
            scanf("%1c", &snum[i]);
            if (snum[i] == '\n')
            {
                snum[i] = '\0' ;
                break ;
            }
            i++ ;
        }
        int hold = check(snum , n1) ;
        //hold check start from here
        if(hold == 1)
            printf("\n  In binary numbering system you can only use '0' or '1' to consist a number.\n") ;
        else if(hold == 4)
            printf("\n  In octal numbering system you can only use '0' to '7' to consist a number.\n") ;
        else if(hold == 7)
            printf("\n  In decimal numbering system you can only use '0' to '9' to consist a number.\n") ;
        else if(hold == 10)
            printf("\n  In hexadecimal numbering system you can only use '0' to 'F' to consist a number.\n") ;
        else
            break ;
    }
    manage(snum , strlen(snum) , n1) ;

return 0 ;
}
int check(char *snum , int n)
{
    if(n == 1 || n == 2 || n == 3)
    {
        while(*snum != '\0')
        {
            if(*snum != '1' && *snum != '0')
                return 1 ;
            snum++ ;
        }
        return 0 ;
    }

    else if(n == 4 || n == 5 || n == 6) //octal
    {
        while(*snum != '\0')
        {
            if(*snum < 48 || *snum > 55)
                return 4 ;
            snum++ ;
        }
        return 0 ;
    }
    else if(n == 7 || n == 8 || n == 9) //decimal
    {
        while(*snum != '\0')
        {
            if(*snum < 48 || *snum > 57)
                return 7 ;
            snum++ ;
        }
        return 0 ;
    }
    else //hex
    {
        while(*snum != '\0')
        {
            if ((*snum < '0' || *snum > '9') && (*snum < 'A' || *snum > 'F') && (*snum < 'a' || *snum > 'f'))
                return 10 ;
            snum++ ;
        }
        return 0 ;
    }
}
void manage(char *snum , int p , int n)
{
    switch(n)
    {
        case 1 :
            binary_to_octal(snum , p) ;
            break ;
        case 2 :
            binary_to_decimal(snum , p) ;
            break ;
        case 3 :
            binary_to_hex(snum , p) ;
            break ;
        case 4 :
            octal_to_binary(snum) ;
            break ;
        case 5 :
            octal_to_decimal(snum , p) ;
            break ;
        case 6 :
            octal_to_hex(snum , p) ;
            break ;
        case 7 :
            decimal_to_binary(snum , p) ;
            break ;
        case 8 :
            decimal_to_octal(snum , p) ;
            break ;
        case 9 :
            decimal_to_hex(snum , p) ;
            break ;
        case 10 :
            hex_to_binary(snum) ;
            break ;
        case 11 :
            hex_to_octal(snum , p) ;
            break ;
        case 12 :
            hex_to_decimal(snum , p) ;
            break ;
    }
}

//--------------------------1------------------------------

void binary_to_octal(char *snum , int p)
{
    char num[64] ;
    for(int j = p - 1 ; j >= 0 ; j-- , snum++)
        num[j] = *snum ;
    int i = 1 , sum = 0 ;
    for(int j = 0 ; j < p ; j++ , i *= 2)
        sum = sum + (num[j] - '0') * i ;
    if(sum == 0)
        printf("Equivalent octal : 0\n") ;
    else 
    {
        int octal[64] ;
        int index = 0 ;
        while(sum > 0)
        {
            octal[index++] = sum % 8 ;
            sum = sum / 8 ;
        }
        printf("Equivalent octal : ") ;
        while(index)
        {
            printf("%d" , octal[--index]) ;
        }
    }
}

//--------------------------2------------------------------

void binary_to_decimal(char *snum , int p)//2
{
    char num[64] ;
    for(int j = p - 1 ; j >= 0 ; j-- , snum++)
        num[j] = *snum ;
    int i = 1 , sum = 0 ;
    for(int j = 0 ; j < p ; j++ , i *= 2)
        sum = sum + (num[j] - '0') * i ;
    printf("Equivalent decimal : %d" , sum) ;
}

//----------------------------3---------------------------

void binary_to_hex(char *snum , int p)
{
    char num[64] ;
    for(int j = p - 1 ; j >= 0 ; j-- , snum++)
        num[j] = *snum ;
    int i = 1 , sum = 0 ;
    for(int j = 0 ; j < p ; j++ , i *= 2)
        sum = sum + (num[j] - '0') * i ;
    if(sum == 0)
        printf("Equivalent hexadecimal : 0\n") ;
    else 
    {
        int hex[64] ;
        int index = 0 ;
        while(sum > 0)
        {
            hex[index++] = sum % 16 ;
            sum = sum / 16 ;
        }
        printf("Equivalent hexadecimal : ") ;
        while(index)
        {
            --index ;
            if (hex[index] >= 10 && hex[index] <= 15)
                printf("%c", 'A' + (hex[index] - 10));
            else
                printf("%d" , hex[index]) ;
        }
    }
}

//----------------------------4---------------------------

void octal_to_binary(char *snum) //4
{
    int i = 0 ;
    printf("Equivalent binary : ") ;
    while(*snum != '\0')
    {
        switch(*snum)
        {
            case 48 :
            if(i == 0)
                printf("0") ;
            else
                printf("000") ;
            break ;
            case 49 :
            if(i == 0)
                printf("1") ;
            else
                printf("001") ;
            break ;
            case 50 :
            if(i == 0)
                printf("10") ;
            else
                printf("010") ;
            break ;
            case 51 :
            if(i == 0)
                printf("11") ;
            else
                printf("011") ;
            break ;
            case 52 :
                printf("100") ;
                break ;
            case 53 :
                printf("101") ;
                break ;
            case 54 :
                printf("110") ;
                break ;
            case 55 :
                printf("111") ;
                break ;
        }
        snum++ ;
        i++ ;
    }
}

//--------------------------5---------------------------

void octal_to_decimal(char *snum , int p) //5
{
    char num[64] ;
    for(int j = p - 1 ; j >= 0 ; j-- , snum++)
        num[j] = *snum ;
    int i = 1 , sum = 0 ;
    for(int j = 0 ; j < p ; j++ , i *= 8)
        sum = sum + (num[j] - '0') * i ;
    printf("Equivalent decimal : %d" , sum) ;
}

//---------------------------6----------------------------

void octal_to_hex(char *snum , int p)
{
    char num[64] ;
    for(int j = p - 1 ; j >= 0 ; j-- , snum++)
        num[j] = *snum ;
    int i = 1 , sum = 0 ;
    for(int j = 0 ; j < p ; j++ , i *= 8)
        sum = sum + (num[j] - '0') * i ; 
    if(sum == 0)
        printf("Equivalent hexadecimal : 0\n") ;
    else 
    {
        int hex[64] ;
        int index = 0 ;
        while(sum > 0)
        {
            hex[index++] = sum % 16 ;
            sum = sum / 16 ;
        }
        printf("Equivalent hexadecimal : ") ;
        while(index)
        {
            --index ;
            if (hex[index] >= 10 && hex[index] <= 15)
                printf("%c", 'A' + (hex[index] - 10));
            else
                printf("%d" , hex[index]) ;
        }
    }
}

//---------------------------7----------------------------

void decimal_to_binary(char *snum , int p) //7
{
    char num[64] ;
    for(int j = p - 1 ; j >= 0 ; j-- , snum++)
        num[j] = *snum ;
    int i = 1 , sum = 0 ;
    for(int j = 0 ; j < p ; j++ , i *= 10)
        sum = sum + (num[j] - '0') * i ;
    if(sum == 0)
        printf("Equivalent binary : 0\n") ;
    else 
    {
        int binary[64] ;
        int index = 0 ;
        while(sum > 0)
        {
            binary[index++] = sum % 2 ;
            sum = sum / 2 ;
        }
        printf("Equivalent binary : ") ;
        while(index)
        {
            printf("%d" , binary[--index]) ;
        }
    }

}

//------------------------------8--------------------------------

void decimal_to_octal(char *snum , int p) //8
{
        char num[64] ;
    for(int j = p - 1 ; j >= 0 ; j-- , snum++)
        num[j] = *snum ;
    int i = 1 , sum = 0 ;
    for(int j = 0 ; j < p ; j++ , i *= 10)
        sum = sum + (num[j] - '0')* i ;
    if(sum == 0)
        printf("Equivalent octal : 0\n") ;
    else 
    {
        int octal[64] ;
        int index = 0 ;
        while(sum > 0)
        {
            octal[index++] = sum % 8 ;
            sum = sum / 8 ;
        }
        printf("Equivalent octal : ") ;
        while(index)
        {
            printf("%d" , octal[--index]) ;
        }
    }
}

//-----------------------------9---------------------------------

void decimal_to_hex(char *snum, int p) //9
{
        char num[64] ;
    for(int j = p - 1 ; j >= 0 ; j-- , snum++)
        num[j] = *snum ;
    int i = 1 , sum = 0 ;
    for(int j = 0 ; j < p ; j++ , i *= 10)
        sum = sum + (num[j] - '0')* i ;
    if(sum == 0)
        printf("Equivalent hexadecimal : 0\n") ;
    else 
    {
        int hex[64] ;
        int index = 0 ;
        while(sum > 0)
        {
            hex[index++] = sum % 16 ;
            sum = sum / 16 ;
        }
        printf("Equivalent hexadecimal : ") ;
        while(index)
        {
            --index ;
            if (hex[index] >= 10 && hex[index] <= 15)
                printf("%c", 'A' + (hex[index] - 10));
            else
                printf("%d" , hex[index]) ;
        }
    }
}

//--------------------------10------------------------------
void hex_to_binary(char *snum) //10
{
    while(*snum != '\0')
    {
        switch(*snum)
        {
            case 48 :
                printf("0000") ;
                break ;
            case 49 :
                printf("0001") ;
                break ;
            case 50 :
                printf("0010") ;
                break ;
            case 51 :
                printf("0011") ;
                break ;
            case 52 :
                printf("0100") ;
                break ;
            case 53 :
                printf("0101") ;
                break ;
            case 54 :
                printf("0110") ;
                break ;
            case 55 :
                printf("0111") ;
                break ;
            case 56 :
                printf("1000") ;
                break ;
            case 57 :
                printf("1001") ;
                break ;
            case 65 :
            case 97 :
                printf("1010") ;
                break ;
            case 66 :
            case 98 :
                printf("1011") ;
                break ;
            case 67 :
            case 99 :
                printf("1100") ;
                break ;
            case 68 :
            case 100 :
                printf("1101") ;
                break ;
            case 69 :
            case 101 :
                printf("1110") ;
                break ;
            case 70 :
            case 102 :
                printf("1111") ;
        }
        snum++ ;
    }
}

//--------------------------11---------------------------

void hex_to_octal(char *snum , int p)
{
    char num[64] ;
    for(int j = p - 1 ; j >= 0 ; j-- , snum++)
        num[j] = *snum ;
    int i = 1 , sum = 0 ;
    for(int j = 0 ; j < p ; j++ , i *= 16)
        sum = sum + (num[j] - '0') * i ;
    if(sum == 0)
        printf("Equivalent octal : 0\n") ;
    else 
    {
        int octal[64] ;
        int index = 0 ;
        while(sum > 0)
        {
            octal[index++] = sum % 8 ;
            sum = sum / 8 ;
        }
        printf("Equivalent octal : ") ;
        while(index)
        {
            printf("%d" , octal[--index]) ;
        }
    }
}

//--------------------------12---------------------------

void hex_to_decimal(char *snum , int p)
{
    char num[64] ;
    for(int j = p - 1 ; j >= 0 ; j-- , snum++)
        num[j] = *snum ;
    int i = 1 , sum = 0 ;
    for(int j = 0 ; j < p ; j++ , i *= 16)
        sum = sum + (num[j] - '0') * i ;
    printf("Equivalent decimal : %d" , sum) ;
}
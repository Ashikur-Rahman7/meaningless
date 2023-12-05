//a very simple programe to check the occurence of the letters and represent them as a silly graph
#include <stdio.h>
#include <string.h>
void storing(char *) ;
void displaying(int * , int) ;
int main()
{
    char str[1000] ;
    scanf("%[^\n]s" , str) ;
    storing(str) ;
    
return 0 ;
}

void storing(char *str)
{
    int arr2[26] , arr[26] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ;
    for( ; *str != '\0' ; str++)
    {
        int a = *str ;
        if((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
        {
            if(a == 65 || a == 97)
                arr[0] = arr[0] + 1 ;
            else if(a == 66 || a == 98)
                arr[1] = arr[1] + 1 ;
            else if(a == 67 || a == 99)
                arr[2] = arr[2] + 1 ;
            else if(a == 68 || a == 100)
                arr[3] = arr[3] + 1 ;
            else if(a == 69 || a == 101)
                arr[4] = arr[4] + 1 ;
            else if(a == 70 || a == 102)
                arr[5] = arr[5] + 1 ;
            else if(a == 71 || a == 103)
                arr[6] = arr[6] + 1 ;
            else if(a == 72 || a == 104)
                arr[7] = arr[7] + 1 ;
            else if(a == 73 || a == 105)
                arr[8] = arr[8] + 1 ;
            else if(a == 74 || a == 106)
                arr[9] = arr[9] + 1 ;
            else if(a == 75 || a == 107)
                arr[10] = arr[10] + 1 ;
            else if(a == 76 || a == 108)
                arr[11] = arr[11] + 1 ;
            else if(a == 77 || a == 109)
                arr[12] = arr[12] + 1 ;
            else if(a == 78 || a == 110)
                arr[13] = arr[13] + 1 ;
            else if(a == 79 || a == 111)
                arr[14] = arr[14] + 1 ;
            else if(a == 80 || a == 112)
                arr[15] = arr[15] + 1 ;
            else if(a == 81 || a == 113)
                arr[16] = arr[16] + 1 ;
            else if(a == 82 || a == 114)
                arr[17] = arr[17] + 1 ;
            else if(a == 83 || a == 115)
                arr[18] = arr[18] + 1 ;
            else if(a == 84 || a == 116)
                arr[19] = arr[19] + 1 ;
            else if(a == 85 || a == 117)
                arr[20] = arr[20] + 1 ;
            else if(a == 86 || a == 118)
                arr[21] = arr[21] + 1 ;
            else if(a == 87 || a == 119)
                arr[22] = arr[22] + 1 ;
            else if(a == 88 || a == 120)
                arr[23] = arr[23] + 1 ;
            else if(a == 89 || a == 121)
                arr[24] = arr[24] + 1 ;
            else
                arr[25] = arr[25] + 1 ;
        }
    }

    for(int i = 0 ; i < 26 ; i++)
    {
        arr2[i] = arr[i] ;
    }

    for(int a = 0 ; a < 25 ; a++)
    {
        for(int i = 0 ; i < 25 ; i++)
        {
            if(arr2[i] > arr2[i + 1])
            {
                int temp = arr2[i] ;
                arr2[i] = arr2[i + 1] ;
                arr2[i + 1] = temp ;
            }
        }
    }
    displaying(arr , arr2[25]) ;
}

void displaying(int *arr , int a)
{
    for(int i = 0 , k = a ; i < a ; i++ , k--)
    {
         for(int j = 0 ; j < 26 ; j++)
         {
            if(*arr >= k)
                printf("   |  ") ;
            else
                printf("      ") ;
            arr++ ;
         }
         arr = arr - 26 ;
         printf("\n") ;
    }
    printf("\n") ;

    for(int i = 0 ; i < 26 ; i++)
    {
        printf("   %c  " , 65 + i) ;
    }   
    printf("\n") ;

    for(int i = 0 ; i < 26 ; i++)
    {
        if(*arr < 10)
            printf("  0%d  " , *arr) ;
        else
            printf("  %d  " , *arr) ;
        arr++ ;
    }
}

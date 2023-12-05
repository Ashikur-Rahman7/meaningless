//Simple implementation of ciser cipher
#include <stdio.h>
void ciser_encode_decode(char * , int) ;
int main()
{
    char arr[1000] ;
    printf("Whats the message : \n") ;
    scanf("%[^\n]s" , arr) ;
    int choice ;
    printf("Want to encode or decode ? \n1)Encode.\n2)Decode.\n\n") ;
    scanf("%d" , &choice) ;
    int key ;
    printf("Whats your key : \n") ;
    scanf("%d" , &key) ;
    if(choice == 1)
        ciser_encode_decode(arr , key) ;
    else if(choice == 2)
        ciser_encode_decode(arr , -key) ;
}

void ciser_encode_decode(char *arr , int key)
{
    while(*arr != '\0')
    {
        if(*arr >= 65 && *arr <= 90)
        {
            if(*arr + key > 90)
                printf("%c" , *arr + key - 26) ;
            else if(*arr + key < 65)
                printf("%c" , *arr + key + 26) ;
            else
                printf("%c" , *arr + key) ;
        }

        else if(*arr >= 97 && *arr <=122)
        {
            if(*arr + key > 122)
                printf("%c" , *arr + key - 26) ;
            else if(*arr + key < 97)
                printf("%c" , *arr + key + 26) ;
            else
                printf("%c" , *arr + key) ;
        }
        else if(*arr == 32)
            printf(" ") ;
        arr++ ;
    }
}

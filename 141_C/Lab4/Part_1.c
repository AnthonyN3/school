#include <stdio.h>
#define SIZE 80

int main()
{
    //Variables

    //First character array is intialized to "this is the first buffer"
    char Buffer1[] = {'t', 'h', 'i', 's', ' ', 'i','s',' ', 't', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'b', 'u', 'f', 'f', 'e', 'r','.', '\0'};
    //Second character array is intialized to "this is the second buffer"
    char Buffer2[] = {'t', 'h', 'i', 's', ' ', 'i','s',' ', 't', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'b', 'u', 'f', 'f', 'e', 'r','.', '\0'};
    //Last buffer array is of size 80 and is not intialized
    char Buffer3[SIZE];

    //Promts user to input a string for char Buffer3[]
    printf("Enter some string: ");
    scanf("%[^\n]", Buffer3);
   // fgets(Buffer3,SIZE, stdin);

    //Pritns all three buffers
    printf("\n%s", Buffer1);
    printf("\n%s", Buffer2);
    printf("\n%s", Buffer3);
}

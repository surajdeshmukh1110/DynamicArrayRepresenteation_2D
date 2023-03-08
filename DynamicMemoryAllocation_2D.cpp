#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

int main()
{
    int *(*pArray) = NULL;
    int i,j,row,column;

    printf("Enter  The Array Dimention You Want's...");
    scanf("%d%d", &row, &column);

    pArray = (int **) malloc (row * (sizeof(int)));
    
    if(pArray == NULL)
    {
        printf("Array is Empty...");

    }
    
    for(i = 0; i < row; i++)
    {
        pArray[i] = (int *) malloc (column * (sizeof(int)));

        if(pArray[i] == NULL)
        {
            for(; i - 1 >= 0; --i)
            {
                free(pArray[i - 1]);
            }
            free(pArray);
            pArray = NULL;
            printf("Array is Empty...");
            return -1;
        }
    } 
    
    printf("Size of Pointer Array is... %d ", sizeof(pArray));
    
   
    printf("\n Enter The Array Element's...\n");
    for(int k = 0; k < row; k++)
    {
        for(int m = 0; m < column; m++)
        {
            scanf("%d", &pArray[k][m]);
        }
    }

    printf("Giveen Array is... ");
    for(int k=0;k<row;k++){
        for(int m=0;m<column;m++){

            printf("%d ",pArray[k][m]);
        }
    }
    
    for(i = 0; i < row; i++)
    {
        free(pArray[i]);
    }
    free(pArray);
    return 0;
}
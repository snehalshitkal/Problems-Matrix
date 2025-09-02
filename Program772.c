/*

    Author      :   Snehal Rohit Shitkal
    Program     :   Matrix Problems
    Description :   Accept number of rows and columns from user 
                    Display summetion of border element  in  matrix.

*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef int * IPTR;
typedef int ** IPPTR;

int SummetionBorder(IPPTR Arr,int iRow,int iCol)
{
    int i = 0, j = 0, iSum = 0;

    printf("Enter the elements: \n");

    for(i = 0 ; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            if(i == 0 || i == iRow -1 || j == 0|| j == iCol-1)
            {
                iSum = iSum + Arr[i][j];
            }
        }  
    }
    return iSum;
}

void Accept(IPPTR Arr,int iRow,int iCol)
{
    int i = 0,j = 0;
     printf("Enter the elements: \n");

    for(i = 0 ;i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            scanf("%d",&Arr[i][j]);
        }
    }

}
void Display(IPPTR Arr,int iRow,int iCol)
{
     int i = 0, j = 0;
    printf("Elements of the matrix are: \n");

    for(i =0 ;i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            printf("%d\t",Arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int iRow = 0;
    int iCol = 0,i = 0,j = 0;

    IPPTR Arr = NULL;
    
    printf("Enter number of rows");
    scanf("%d",&iRow);

    printf("Enter number of Col");
    scanf("%d",&iCol);

    Arr = (IPPTR) malloc(sizeof(IPTR)*iRow);

    for(i = 0;i < iRow; i++)
    {
        Arr[i] = (IPTR)malloc(sizeof(int)*iCol);
    }

        Accept(Arr,iRow,iCol);
        Display(Arr,iRow,iCol);

        int iRet = SummetionBorder(Arr,iRow,iCol);
        printf("Summetion of Border : %d",iRet);

        //Deallocate memory of matrix

        for(i = 0;i<iRow;i++)
        {
            free(Arr[i]);
        }
        free(Arr);
     
    return 0;
}
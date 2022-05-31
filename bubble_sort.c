#include <stdio.h>
void main()
{
    int a[10]={12,5,3,7,6},n=5,i,j;
    for(j=0;j<n-1;j++)
    {
        for(i=0;i<n-1-j;i++)
        {
            if(a[i]>a[i+1])
            {
                int temp;
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
	}
    
}


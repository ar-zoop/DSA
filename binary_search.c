#include <stdio.h>
void main()
{
    int arr[9]={1,2,4,5,6,7,8,9,10},ele=3,i,low=0,high=9,mid;
    printf("Enter the element to find: ");
    scanf("%d", &ele);
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==ele)
        {
            printf("%d found at %d position",ele,mid+1);
            break;
        }
        else if(arr[mid]>ele)
          high=mid-1;
        else
            low=mid+1;
    }
    if(low>high)
        printf("\nNot found");
}

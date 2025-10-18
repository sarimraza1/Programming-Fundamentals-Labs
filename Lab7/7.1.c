#include <stdio.h>


int main() {

    int i,len=14;
    int arr[14];
    int end=14,temp;
    int elm;
    

    for(i=0;i<15;i++) {
        printf("Enter Element  %d: ",i+1);
        scanf("%d",arr+i);
    }

    for (i=6;i>=0;i--) {
        temp=arr[i];
        arr[end-i]=temp;
    }
    
    for(i=0;i<15;i++) {
        printf(" %d ",arr[i]);
      
    }

    printf("\nSearch for an element in the array: ");
    scanf("%d",&elm);

    printf("\n");

    for(i=0;i<15;i++) {
        if (elm==arr[i]) {
            printf("Element Found At Index %d of the array\n",i);
        }
    }
    
    return 0;
}
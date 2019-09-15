#include <stdio.h>
#include <stdlib.h>
void Input(int a[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
   {
    printf("Enter value a[%d]=",i);
    scanf("%d",&a[i]);
   }
}
void Output(int a[],int n)
{
    int i=0;
    printf("Show the elements of the set :\n");
    for(i=0;i<n;i++)
    printf("a[%d]=%d\n",i,a[i]);
}
void Delete(int a[],int n,int k)
{
    int i=0;
    printf("Enter the location to be deleted :");
    scanf("%d",&k);
   for(i=k-1;i<n;i++)
   {
       a[i]=a[i+1];
   }
   n--;
   Output(a,n);
}

void Add(int a[],int n,int x,int y)
{
    int i;
    for(i=n-1;i>=y;i--)
    {
        a[i+1]=a[i];
    }
    a[y]=x;
    n++;
}

int main()
{
    int n,k;
    int a[100];
    printf("Enter the element number of the set :");
    scanf("%d",&n);
    Input(a,n);
    Output(a,n);
    Delete(a,n,k);

    int x;
    printf("Additional element x = ");
    scanf("%d",&x);
    int y;
    printf("Enter the location :");
    scanf("%d",&y);
    Add(a,n,x,y);
    Output(a,n);
    return 0;
}

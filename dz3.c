#include<stdio.h>
#include<conio.h>

int main()
{
    char c;
    do 
    {
        int n,t,k=0,g[10][10],dem=0;
        printf("\nThe number of vertices: n= ");
        scanf("%d", &n);
        char x[n];
        printf("\nEnter the names of the vertices: ");
        for(int i=0; i<n; i++)
        {
            printf("\nx[%d]=",i+1);
            x[i]=getche(); // nhap vao va hien thi ko can enter
        }
        printf("\nEnter adjacentry matrix: \n");
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                scanf("%d", &t);
                g[i][j]=t;
            }
        for(int i=0; i<n; i++)
            {
                if (g[i][i] > 0)
                {
                    printf("Graf multigrf \n");
                    dem=dem+1;
                    goto exit;
                }
            }     
        for(int i=0; i<n; i++)
            for(int j=0;j<n;j++)
            { 
                if(g[i][j]>1)
                {
                    printf("Multigraph \n");
                    dem=dem+1;
                    goto exit;
                }
            }
        printf("Simple graph\n");
        goto exit;

        exit:
        if(dem==0)
        {
            for (int i=0; i<n; i++)
            {  
                for(int j=0; j<n; j++) 
                if(g[i][j]>0) k+=1; 
            }
            if(k>=((n-1)*(n-2)/2))
            printf("\nConnected graph \n");
            else 
            printf("\nGraph is not connected \n");
            getch();
        }
        // file
        FILE *f;
        f= fopen("grap.dot","w");
        fprintf(f,"graph mygrap{ \n");
        for(int i=0; i<n; i++)
            for(int j=0;j<=i;j++)
            {
                if(g[i][j]!=0)
                {
                    for(int d=0; d<g[i][j]; d++)
                    fprintf(f,"%c--%c\n",x[i],x[j]);
                }
            }
        fprintf(f,"}");
        printf("\n\n Do you want to do again? (yes (y) or no (n))");
        c=getche();   
    }while ((c=='y')||(c=='Y'));
    getch();
    return 0;
}

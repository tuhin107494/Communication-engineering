
#include<stdio.h>
int n,m;

int a[10004],b[10004],cnt[10004];

void FIRST()
{
    int i,j,sum=0;
    int c[n+1];
    for( j=1; j<=n; j++)c[j]=a[j];
    for(i=1; i<=m; i++)
    {
        for( j=1; j<=n; j++)
        {
            if(a[j]==c[j] && b[i]<=c[j])
            {
                c[j]-=b[i];
                break;
            }
        }
    }
      printf("Available space for \n");
    for( i=1;i<=n;i++)
    {      sum+=c[i];
          printf("Partition %d = %d\n",i,c[i]);
    }
    printf("Total available space= %d\n",sum);
}

void BEST()
{
    int i,j,mn=1e9,sum=0,indx;
    int c[n+1];
    for( j=1; j<=n; j++)c[j]=a[j];
    for(i=1; i<=m; i++)
    {
        mn=1e9;
        for( j=1; j<=n; j++)
        {
            if(a[j]==c[j] && b[i]<=c[j])
            {

                if(c[j]<mn)
                {
                    mn=c[j];
                    indx=j;
                }
            }
        }
        if(mn!=1e9)
        {
            c[indx]-=b[i];

        }
    }
    printf("Available space for \n");
    for( i=1;i<=n;i++)
    {   sum+=c[i];
          printf("Partition %d = %d\n",i,c[i]);
    }
     printf("Total available space= %d\n",sum);
}
void WORST()
{
    int i,j,mx=0,sum=0,indx;
    int c[n+1];
    for( j=1; j<=n; j++)c[j]=a[j];
    for(i=1; i<=m; i++)
    {
        mx=0;
        for( j=1; j<=n; j++)
        {
            if( a[j]==c[j] && b[i]<=c[j])
            {

                if(c[j]>mx)
                {
                    mx=c[j];
                    indx=j;
                }
            }
        }
        if(mx!=0)
        {
            c[indx]-=b[i];
        }

    }

    printf("Available space for \n");
    for( i=1;i<=n;i++)
    {     sum+=c[i];
          printf("Partition %d = %d\n",i,c[i]);
    }
     printf("Total available space= %d\n",sum);
}
int main()
{

    printf("Number of memory Partition/Block= ");
    scanf("%d",&n);
    int i;
    for(i=1; i<=n; i++)
    {
        printf("Partition %d Size =",i);
        scanf("%d",&a[i]);
        //printf(" Kb\n");
    }
    printf("No of Process: ");
    scanf("%d",&m);
    for(i=1; i<=m; i++)
    {
        printf("Process %d need =",i);
        scanf("%d",&b[i]);
        // printf("Kb\n");
    }
    int check;
    while(scanf("%d",&check)==1)
    {
        if(check==1)
        {
            printf("\nFIRST FIT Variable\n");
            FIRST();
        }
        else if(check==2)
        {
            printf("\nBEST FIT Variable\n");
            BEST();
        }
        else  if(check==3)
        {
            printf("\nWORST FIT Variable\n");
            WORST();
        }
        else exit(0);
    }

    /*
       5
       50 150 300 350 600
       4
       300 25 125 50

    */
    return 0;
}

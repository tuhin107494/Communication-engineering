#include<stdio.h>
int n,m;
int F[20][100];
char FH[1000];
int L[20][100];
char LH[1000];
int O[20][100];
char OH[1000];
int a[10004];
void FIFO()
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for( j=0; j<n; j++)
        {
            if(i>=j)F[j][i]=a[j];
            else F[j][i]=-1;
        }
        FH[i]='F';
    }
    int indx=0,hit=0;
    for(i=n; i<m; i++)
    {
        int flag=1;
        for( j=0; j<n; j++)
        {
            if(F[j][i-1]==a[i])
            {
                hit++;
                flag=0;
                break;
            }
        }
        for( j=0; j<n; j++)F[j][i]=F[j][i-1];

        if(flag)
        {
            F[indx][i]=a[i];
            indx++;
            indx%=n;

            FH[i]='F';
        }
        else FH[i]='H';
    }

    for(i=0; i<n; i++)
    {
        for( j=0; j<m; j++)
        {
            if(F[i][j]!=-1)printf("%d ",F[i][j]);
            else printf("  ");
        }
        printf("\n");
    }
    for( j=0; j<m; j++)
    {
        printf("%c ",FH[j]);
    }
    printf("\n");
    printf("Total Page Hit= %d\n",hit);
    printf("Total Page Fault= %d\n",m-hit);
}
void LRU()
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for( j=0; j<n; j++)
        {
            if(i>=j)L[j][i]=a[j];
            else L[j][i]=-1;
        }
        LH[i]='F';
    }
    int indx=0,hit=0;
    for(i=n; i<m; i++)
    {
        int flag=1;
        for( j=0; j<n; j++)
        {
            if(L[j][i-1]==a[i])
            {
                hit++;
                flag=0;
                break;
            }
        }
        for( j=0; j<n; j++)L[j][i]=L[j][i-1];

        if(flag)
        {
            int k,mn=1e9;

            int l;
            for(l=0; l<n; l++)
            {
                for(k=i-1; k>=-1; k--)
                {
                    if(k>=0 && a[k]==L[l][i-1])
                    {
                        if(mn>k)
                        {
                            indx=l;
                            mn=k;
                        }

                        break;
                    }
                    else if(k==-1)
                    {
                        indx=l;
                        mn=k;
                    }
                }
            }
            L[indx][i]=a[i];

            LH[i]='F';
        }
        else LH[i]='H';
    }

    for(i=0; i<n; i++)
    {
        for( j=0; j<m; j++)
        {
            if(L[i][j]!=-1)printf("%d ",L[i][j]);
            else printf("  ");
        }
        printf("\n");
    }
    for( j=0; j<m; j++)
    {
        printf("%c ",LH[j]);
    }
    printf("\n");
    printf("Total Page Hit= %d\n",hit);
    printf("Total Page Fault= %d\n",m-hit);
}

void OPTIMAL()
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for( j=0; j<n; j++)
        {
            if(i>=j)O[j][i]=a[j];
            else O[j][i]=-1;
        }
        OH[i]='F';
    }
    int indx=0,hit=0;
    for(i=n; i<m; i++)
    {
        int flag=1;
        for( j=0; j<n; j++)
        {
            if(O[j][i-1]==a[i])
            {
                hit++;
                flag=0;
                break;
            }
        }
        for( j=0; j<n; j++)O[j][i]=O[j][i-1];

        if(flag)
        {
            int k,mx=-1;

            int l;
            for(l=0; l<n; l++)
            {
                for(k=i+1; k<=m; k++)
                {
                    if(k<m && a[k]==O[l][i-1])
                    {
                        if(mx<k)
                        {
                            indx=l;
                            mx=k;
                        }

                        break;
                    }
                    else if(k==m)
                    {
                        indx=l;
                        mx=k;
                    }
                }
            }
            O[indx][i]=a[i];

            OH[i]='F';
        }
        else OH[i]='H';
    }

    for(i=0; i<n; i++)
    {
        for( j=0; j<m; j++)
        {
            if(O[i][j]!=-1)printf("%d ",O[i][j]);
            else printf("  ");

        }
        printf("\n");
    }
    for( j=0; j<m; j++)
    {
        printf("%c ",OH[j]);
    }
    printf("\n");
    printf("Total Page Hit= %d\n",hit);
    printf("Total Page Fault= %d\n",m-hit);
}
int main()
{

    printf("Number of Page Frame = ");
    scanf("%d",&n);
    printf("string size= ");
    scanf("%d",&m);
    printf("Reference String = ");

    int i;
    for( i=0; i<m; i++)
    {
        scanf("%d",&a[i]);

    }
    printf("\nFIFO Page replacement algorithm\n");
    FIFO();
    printf("\nLRU Page replacement algorithm\n");
    LRU();
    printf("\nOptimal Page replacement algorithm\n");
    OPTIMAL();




    /*
        20
        1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6
    */


    return 0;
}

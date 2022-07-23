#include<stdio.h>
int main()
{
    int  processes,res,i=0,j=0;
    printf("Enter the Number of Process  :  ");
    scanf("%d",&processes);
    printf("Enter the Number of Resource  :  ");
    scanf("%d",&res);
    int totalRes[res+2], allocated[processes+2][res+2];
    int remainNeed[processes+2][res+2], maxNeed[processes+2][res+2];
    printf ("Enter  total  Resources: \n");
    for(i=0; i<res; i++)
    {
        scanf ("%d",&totalRes[i]);
    }
    printf ("Enter  allocated  resources  for processors :\n");
    for(i=0; i<processes; i++)
    {
        for(j=0; j<res; j++)
        {
            scanf("%d",&allocated[i][j]);
        }
    }
    printf("Enter  Max_Need  resources  for processors :\n");
    for(i=0; i<processes; i++)
    {
        for(j=0; j<res; j++)
        {
            scanf("%d",&maxNeed[i][j]);
        }
    }
    for(i=0; i<processes; i++)
    {
        for(j=0; j<res; j++)
        {
            remainNeed[i][j]=(maxNeed[i][j]-allocated[i][j]);
        }
    }
    int availableRes[res+2], totalAllocatedRes[res+2];

    for(i=0; i<res; i++)
    {
        int  x=0;
        for(j=0; j<processes; j++)
        {
            x+=allocated[j][i];
        }
        totalAllocatedRes[i]=x;
    }
    for(i=0; i<res; i++)
    {
        availableRes[i]=totalRes[i]-totalAllocatedRes[i];
    }
    int  rem=processes;
    int  ans[processes+2],idx=0; int ok=1;
    while(1)
    {
    int  cnt=0;
    for(i=0; i<processes; i++)
        {
            if(remainNeed[i][0]==-1)  continue;
            int cnt1=0;
            for(j=0; j<res; j++)
            {
                if(remainNeed[i][j]<=availableRes[j]) cnt1++;
            }
            if(cnt1==res)
            {
                ans[idx++]=i;
                remainNeed[i][0]=-1;
                int k;
                for( k=0; k<res; k++)
                {
                    availableRes[k]+=allocated[i][k];
                }
                rem--;
            }
        }
        if(rem==processes)
        {
            ok=0;
            break;
        }
        if(idx==processes) break;
    }

    if(ok==1)
    {
        printf("Safe  Sequence  of  Processes  :  ");
        for(i=0; i<processes-1; i++)
        {
            printf("P%d  ->  ",ans[i]);
        }
        printf("P%d\n",ans[processes-1]);
    }
    else
    {
        printf("The  processes  are in  unsafe state.\n");
    }
    return  0;
}

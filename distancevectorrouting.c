#include<stdio.h>
struct node{
    unsigned int dist[10];
    unsigned int via[10];
}rt[10];

int main()
{
    int i,j,k,count=0,costmat[10][10],nodes;
    printf("Enter the no. of nodes:");
    scanf("%d",&nodes);
    printf("Enter the cost matrix:\n");
    for(i=0;i<nodes;i++)
    for(j=0;j<nodes;j++)
    {
        scanf("%d",&costmat[i][j]);
        costmat[i][i]=0;
        rt[i].dist[j]=costmat[i][j];
        rt[i].via[j]=j;
    }
    do
    {
        count=0;
        for(i=0;i<nodes;i++)
        for(j=0;j<nodes;j++)
        for(k=0;k<nodes;k++)
        {
            if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
            {
                rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                rt[i].via[j]=k;
                count++;
            }
        }
    }
        while(count!=0);
        {
            for(i=0;i<nodes;i++)
            {
            printf("------Nodes %d--------",i+1);
            printf("\nTarget\tvia\tdistance");
            for(j=0;j<nodes;j++)
            {
            printf("\n%d\t%d\t%d",j+1,( rt[i].via[j])+1, rt[i].dist[j]);
            }
        }
    }
    
    printf("\n");

}

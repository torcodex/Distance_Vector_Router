#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
int dist[20],from[20];
}rt[10];
int main(void)
{
    int costmat[20][20],n,i,c;
    printf("enter the no. of nodes: \n");
    scanf("%d",&n);
    printf("enter the cost matrix:\n");
    for(i=0;i<n;i++){
        costmat[i][i]=0;
        for(j=0;j<n;j++){
            scanf("%d",&costmat[i][j]);
            rt[i].dist[j]=costmat[i][j];
            rt[i].from[j]=j;
        }
    }
    do{
        c=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j]){
                        rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                        rt[i].from[j]=k;
                        c++;
                    }
                }
            }
        }
    }while(c!=1);
    for(i=0;i<n;i++){
        printf("\nFor rounter: %d\t",i+1);
        for(j=0;j<n;j++){
            printf("\t\nNode %d via %d Distance %d\t",j+1,j+1,rt[i].dist[j]);
        }
        printf("\n\n");
    }
}

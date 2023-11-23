/**********************************************************************************/  
/*  Problem: d589 "B. 水之國的奇幻冒險" from 2009 NPSC 國中組初賽    */  
/*  Language: C++                                                                 */  
/*  Result: AC (38ms, 746KB) on ZeroJudge                                         */  
/*  Author: leopan0922 at 2010-01-04 23:01:14                                     */  
/**********************************************************************************/  
  
#include <stdio.h>   
#include <stdlib.h>   
int max(int a,int b){   
    if(a>b)   
    return a;   
    else  
    return b;}   
int min(int a,int b){   
    if(a<b)   
    return a;   
    else  
    return b;}           
int t,m,n;   
int main(){   
    while(scanf("%d",&t)==1){   
        while(t--){   
            scanf("%d%d",&m,&n);   
            int flag[101]={},i,j;   
            int dist[101],map[101][101],x,y,t,mini,w,p=m;   
            for(i=1;i<=m;i++)   
            	for(j=1;j<=m;j++){   
                	map[i][j]=201;}       
            	for(i=0;i<n;i++){   
                	scanf("%d%d%d",&x,&y,&t);   
                	map[x][y]=map[y][x]=t;}   
            	for(i=1;i<=m;i++){   
                	flag[i]=0;   
                	dist[i]=map[1][i];}   
            	flag[1]=1;   
            while(p--){   
                mini=201;   
                for(i=1;i<=m;i++){   
                    if(mini>dist[i]&&flag[i]==0){   
                        mini=dist[i];   
                        w=i;}}   
                flag[w]=1;   
                for(i=1;i<=m;i++){   
                    if(flag[i]==0){   
                        dist[i]=min(dist[i],max(dist[w],map[w][i]));}}}   
            printf("%d\n",dist[m]);}}   
        return 0;}  

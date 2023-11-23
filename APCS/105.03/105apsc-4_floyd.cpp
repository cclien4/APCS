#include <stdio.h>
#include <cstdio>
#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;

void outmatrix();
void outDij();
//----------全域變數宣告----------------// 
int dis[10][10],n,m,i,j,a,b,x,y;
int inf=999;   //表示無窮大的數 
int a1,a2;
int t1,t2,t3;

//----------執行floyd-----------------// 
void floyd ()
{
     for(i=0;i<n-1;i++)
         {
              for(m=0;m<n;m++)
              {
                  for(a=0;a<n;a++)
                  {
                       if((dis[m][a]>dis[m][i]+dis[i][a]))
                       {
					   	dis[m][a]=dis[m][i]+dis[i][a];
					   	//----印出 ---有改變時的陣列 
					   //	printf("---陣列改變了--%d到%d改變-\n",m,a); 
					   //	outmatrix();
						}
                       
                  }
              }
         }
}

void outmatrix()
{
	for(a1=0;a1<n;a1++)
    	printf("\t%d",a1);
        printf("\n");
    for(a1=0;a1<n;a1++)
    {
    	printf("%d\t",a1);
        for(a2=0;a2<n;a2++)
        {
            printf("%d\t",dis[a1][a2]);
        }
        printf("\n");
    }
}

int main()
{

     for(a1=0;a1<10;a1++)
     {
         for(a2=0;a2<10;a2++)
         {
              if(a1==a2) dis[a1][a2]=0;
			  else dis[a1][a2]=inf;
         }
     }
     scanf("%d %d",&n,&x);
     for(a1=0;a1<x;a1++)
     {
          scanf("%d %d",&t1,&t2);
          dis[t1][t2]=1;
          dis[t2][t1]=1; // 無向圖雙向時需要 
     }
     //----------印出一開始輸入的陣列------------// 
    printf("-------------------------\n");
    outmatrix();
    printf("--------------------------\n");

    //----------選擇排序方式------------// 
		 floyd();
    	 //dijkstra (1);
    	//label_correcting(1);
    //----------印出排序後的陣列------------// 
    	//printf("------ floyd--------\n");  
    	 outmatrix();
    //	outDij();
    	//printf("-------- floyd--------\n");

    system("pause");
	return 0;
}

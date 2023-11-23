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
//----------�����ܼƫŧi----------------// 
int dis[10][10],n,m,i,j,a,b,x,y;
int inf=999;   //��ܵL�a�j���� 
int a1,a2;
int t1,t2,t3;

//----------����floyd-----------------// 
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
					   	//----�L�X ---�����ܮɪ��}�C 
					   //	printf("---�}�C���ܤF--%d��%d����-\n",m,a); 
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
          dis[t2][t1]=1; // �L�V�����V�ɻݭn 
     }
     //----------�L�X�@�}�l��J���}�C------------// 
    printf("-------------------------\n");
    outmatrix();
    printf("--------------------------\n");

    //----------��ܱƧǤ覡------------// 
		 floyd();
    	 //dijkstra (1);
    	//label_correcting(1);
    //----------�L�X�Ƨǫ᪺�}�C------------// 
    	//printf("------ floyd--------\n");  
    	 outmatrix();
    //	outDij();
    	//printf("-------- floyd--------\n");

    system("pause");
	return 0;
}

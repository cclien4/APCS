#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int N,G,A,H,W;
    int i;
    float BMR;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d %d %d %d",&G,&A,&H,&W); 
        if(G==1)
          BMR=(float)W*13.7+(float)H*5-(float)A*6.8+66;
        else
          BMR=(float)W*9.6+(float)H*1.8-(float)A*4.7+655;
        printf("%.2f\n",BMR);       
    }
    //system("pause");
}

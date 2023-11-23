#include <iostream>
#include <algorithm> 
using namespace std;
#define m 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[14], step[14];
int x;

void dfs(int, int);

int main(int argc, char** argv) {
	
while(cin>>x&&x!=0){
	for(int i=0;i<x;i++)	cin>>a[i];
	sort(a, a+x);
	dfs(0,0);
}
	return 0;
}
void dfs(int currStep, int start){
	if(currStep == m){
		for(int i = 0;i<m;i++)	cout<<a[step[i]]<<" ";
		cout<<endl; 
	}
	for(int j = start; j<x;j++){
		step[currStep] = j;
		dfs(currStep+1, j+1);
	}
}

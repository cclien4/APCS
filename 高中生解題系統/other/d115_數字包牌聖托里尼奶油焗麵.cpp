#include <iostream>
#include <algorithm>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[101], step[101];
int n, m;
void dfs(int, int);

int main(int argc, char** argv) {
while(cin>>n&&n!=0){
	for(int i = 0;i<n;i++)	cin>>a[i];
	cin>>m;
	sort(a, a+n);
	dfs(0,0);
	cout<<endl;
}
	return 0;
}

void dfs(int currStep, int start){
	int j;
	if(currStep == m){
		for(int i=0;i<m;i++)	cout<<a[step[i]]<<" ";
		cout<<endl;
		return;
	}
	for(j=start;j<n;j++){
		step[currStep] = j;
		dfs(currStep+1, j+1);
	}			
} 

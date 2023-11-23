#include<cstdio>
#include<deque> 
using namespace std;
int a,b,c,d,sourse,depth,md;
deque<int> a1[100000];//main array
int a2[100000];//links of each node
bool a3[100000];//visited
void dfs(int e){
	a3[e]=true;
	depth++;
	if(depth>md)
	md=depth;//new max depth
	for(int f=0;f<a1[e].size();f++){
		if(a3[a1[e][f]]==false)//visited?
		dfs(a1[e][f]);//next level
	}
	depth--;
	a3[e]=false;//back
	return;
} 
int main(){
	depth=0;
	md=0;
	scanf("%d",&a);
	for(b=1;b<a;b++){
		scanf("%d %d",&c,&d);
		a1[c].push_back(d);
		a1[d].push_back(c);
		a2[c]++;
		a2[d]++;
	}//data feeding
	for(b=0;b<a;b++){
		if(a2[b]==1){
			dfs(b);
		}
	}
	printf("%d",md-1);
	return 0;
}
 

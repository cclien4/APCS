// Solver: Jiun-Jie Liao
// Expected running time: 0.8 seconds

#include<cstdio>
#include<vector>
#include<utility>
#include<cstring>
#include<algorithm>
#define N 25000
#define M 16
using namespace std;
int depth[N];
int mx[N][M],par[N][M],f[N];
vector<int> g[N],h[N];
struct edge{
	int x;
	int y;
	int w;
	bool operator<(edge rhs)const{return w<rhs.w;}
}e[150000];
void DFS(int a,int l){
	depth[a]=l;
	for(int i=0;i<g[a].size();i++){
		if(depth[g[a][i]]) continue;
		par[g[a][i]][0]=a;
		mx[g[a][i]][0]=h[a][i];
		DFS(g[a][i],l+1);
	}
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
inline void uni(int x,int y){
	f[find(x)]=find(y);
}
inline pair<int,int> go(int x,int k){
	int y=0,j;
	for(j=0;j<M;j++){
		if(k&(1<<j)){
			y=max(y,mx[x][j]);
			x=par[x][j];
		}
	}
	return make_pair(x,y);
}
int qry(int x,int y){
	pair<int,int> fix;
	if(depth[x]>depth[y]){
		fix=go(x,depth[x]-depth[y]);
		x=fix.first;
	}
	else{
		fix=go(y,depth[y]-depth[x]);
		y=fix.first;
	}
	if(x==y) return fix.second;
	int r=15,ans=fix.second;
	while(r>=0){
		if(par[x][r]!=par[y][r]){
			ans=max(ans,max(mx[x][r],mx[y][r]));
			x=par[x][r];
			y=par[y][r];
		}
		r--;
	}
	return ans=max(ans,max(mx[x][0],mx[y][0]));
}
int main(){
	int t,n,m,i,j,ans,tmp;
	vector<int> ax,ay,aw;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			g[i].clear();
			h[i].clear();
			f[i]=i;
		}
		for(i=0;i<m;i++){
			scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
		}
		ax.clear();
		ay.clear();
		aw.clear();
		sort(e,e+m);
		for(i=0;i<m;i++){
			if(find(e[i].x)==find(e[i].y)){
				ax.push_back(e[i].x);
				ay.push_back(e[i].y);
				aw.push_back(e[i].w);
			}
			else{
				uni(e[i].x,e[i].y);
				g[e[i].x].push_back(e[i].y);
				g[e[i].y].push_back(e[i].x);
				h[e[i].x].push_back(e[i].w);
				h[e[i].y].push_back(e[i].w);
			}
		}
		memset(depth,0,sizeof(depth));
		DFS(0,1);
		mx[0][0]=0;
		par[0][0]=0;
		for(j=1;j<M;j++){
			for(i=0;i<n;i++){
				par[i][j]=par[par[i][j-1]][j-1];
				mx[i][j]=max(mx[par[i][j-1]][j-1],mx[i][j-1]);
			}
		}
		ans=0;
		for(i=0;i<ax.size();i++){
			tmp=aw[i]-qry(ax[i],ay[i]);
			if(tmp>0&&(ans==0||tmp<ans)) ans=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}

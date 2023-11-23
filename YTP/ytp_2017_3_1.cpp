#include <bits/stdc++.h>

using namespace std;

int main(){
	multimap <int,int,greater<int> > mmx,mmy;
	multimap <int,int>::iterator itx,ity,minit;
	int a, b,reg_x=0,reg_y=0,anscount=0,ct3,min=999;
	cin >> a >> b;
	int map[a][b];
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			cin >> map[i][j];
			switch(map[i][j]){
				case 1:
					mmx.insert(pair<int,int>(1,i));
					mmy.insert(pair<int,int>(1,j));
					break;
				case 2:
					mmx.insert(pair<int,int>(2,i));
					mmy.insert(pair<int,int>(2,j));
					break;
				case 3:
					mmx.insert(pair<int,int>(3,i));
					mmy.insert(pair<int,int>(3,j));
					break;
			}
		}
	}
	
	
	for(itx=mmx.begin(),ity=mmy.begin();itx!=mmx.end();itx++,ity++)
	{
					anscount=anscount+abs(itx->second-reg_x)+abs(ity->second-reg_y);			
					reg_x=itx->second;
					reg_y=ity->second;
			
	}
	cout<<anscount<<endl;
	anscount=anscount+abs(a-1-reg_x)+abs(b-1-reg_y);
	cout<<anscount<<endl;
	cout<<"(0,0)"; 
	for(itx=mmx.begin(),ity=mmy.begin();itx!=mmx.end();itx++,ity++)
	{
		cout<<"("<<itx->second<<","<<ity->second<<")"; 
	}
	cout<<"("<<a-1<<","<<b-1<<")";
	return 0;
}

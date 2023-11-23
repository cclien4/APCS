#include <bits/stdc++.h>

using namespace std;

int main(){
	multimap <int,int,greater<int> > mmx,mmy;
	multimap <int,int>::iterator itx,ity,minitx,minity;
	int a, b,reg_x=0,reg_y=0,anscount=0,ct3=0,min=999;
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
	int outx[mmx.size()],outy[mmx.size()];


		for(int i=3;i>=1;i--) //優先權一共一到3 
		{
			
			while(mmx.count(i)!=0)
			{
				itx=mmx.upper_bound(i+1);
				ity=mmy.upper_bound(i+1);
				for(int j=0;j<mmx.count(i);j++)//搜尋每個優先權該做的次數 
				{
					if(min>abs(itx->second-reg_x)+abs(ity->second-reg_y)) //比較目前優先權 距離最近的 
					{
					min=abs(itx->second-reg_x)+abs(ity->second-reg_y);
					minitx=itx;
					minity=ity;
					}
					else if(min==abs(itx->second-reg_x)+abs(ity->second-reg_y))
					{
						cout<<"aaaaaaaaaa"<<itx->second<<ity->second<<endl;
					}
					itx++;
					ity++;
				}
					itx=minitx;
					ity=minity;
					anscount=anscount+abs(itx->second-reg_x)+abs(ity->second-reg_y);
		
					reg_x=itx->second;
					reg_y=ity->second;
				//	cout<<i<<itx->second<<","<<ity->second<<endl; 
					outx[ct3]=itx->second;
					outy[ct3]=ity->second;
					ct3++;
					min=999;
					mmx.erase(itx);
					mmy.erase(ity);	
			}	
							
		}	
		//cout<<anscount<<endl;

	anscount=anscount+abs(a-1-reg_x)+abs(b-1-reg_y);
	cout<<anscount<<endl;
	cout<<"(0,0)"; 
	for(int i=0;i<ct3;i++)
		cout<<"("<<outx[i]<<","<<outy[i]<<")"; 
	cout<<"("<<a-1<<","<<b-1<<")";
	return 0;
}

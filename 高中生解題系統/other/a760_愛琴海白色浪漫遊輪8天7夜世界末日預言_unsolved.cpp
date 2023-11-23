#include <bits/stdc++.h>
using namespace std;
int main(){
	int ans[14];
	char input[10001];
	while(cin.getline(input,10001)){
		int turned[1001],turnedflg=0,lol=0;
		long long diedate=0,die=LONG_LONG_MAX,now=20130918133000;
		for(int i=0;i<strlen(input);i++){
			if(input[i]<='Z'&&input[i]>='A'){
				turned[turnedflg++]=input[i]%3;
			}
			if(input[i]<='z'&&input[i]>='a')
				turned[turnedflg++]=input[i]%3;
		}
		for(int i=0;i<1001;i++){
			if(turned[1000-i]!=0){
				lol=1001-i;
				break;
			}
		}
		for(int i=0;i<lol/14;i++){
			for(int j=0;j<14;j++){
			cout<<diedate<<endl;
			diedate=diedate*10+turned[i*14+j];}
		//	cout<<diedate<<endl<<now<<endl;
			if(turned[i*14+4]==2){
				diedate=0;
				continue;
			}
			if(turned[i*14+4]==0&&turned[i*14+5]==0){
				diedate=0;
				continue;
			}
			if(diedate>now&&diedate<die){
				die=diedate;
				for(int j=0;j<14;j++){
					ans[j]=turned[i*14+j];
				}
			}
			diedate=0;
		}
		printf("%d%d%d%d/%d%d/%d%d %d%d:%d%d:%d%d\n",ans[0],ans[1],ans[2],ans[3],ans[4],ans[5],ans[6],ans[7],ans[8],ans[9],ans[10],ans[11],ans[12],ans[13]);
	}
	return 0;
}


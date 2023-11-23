// Author: Min-Zheng Shieh

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>

using namespace std;

int eval(char * str)
{
	int i, x=0;
	char next[32];
	for(i = 0; str[i]; i++) x+=str[i]-'0';
	if(x<10) return x;
	sprintf(next,"%d",x);
	return eval(next);
}

int main()
{
	int i, j, n, r, miss;
	char str[32]={0};
	set<string> ans;
	scanf("%d%d%s",&n,&r,str+1);
	for(i = 0; i < 10; i++)
	{
		str[0]='0'+i;
		if(r==eval(str))
		{
			string pat(str+1);
			for(j = 0; j < n; j++)
			{
				string cand = pat.substr(0,j)+to_string(i)+pat.substr(j);
				ans.insert(cand);
			}
		}
	}
	ans.erase(ans.begin());
	ans.erase(--ans.end());
	for(auto it: ans) cout << it << endl;
	return 0;
}

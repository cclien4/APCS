// Author: Min-Zheng Shieh

#include<cstdio>
#include<set>

using namespace std;

int main()
{
	int x;
	multiset<int> s;
	for(scanf("%d",&x); x; scanf("%d",&x))
	{
		if(x==-1)
		{
			if(s.size()==0) continue;
			printf("%d ",*s.begin());
			s.erase(s.begin());
		}
		else if(x==-2)
		{
			if(s.size()==0) continue;
			multiset<int>::iterator it = s.end();
			it--;
			printf("%d ",*it);
			s.erase(it);
		}
		else s.insert(x);
	}
	return 0;
}

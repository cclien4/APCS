//Delivering.cpp
#include<stdio.h>
#include<queue>
using namespace std;
typedef long long ll;

struct point{
	int f, d;
	point(int f, int d) : f(f), d(d) {}
	bool operator < (const point &rhs) const {
		return (ll)f*(ll)rhs.d < (ll)d*(ll)rhs.f;
	}
};

int main()
{
	int n, m, a;
	priority_queue<point> pq;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &a);
		if(a > 1) pq.push(point(a, 1));
	}
	for(int i=0; i<m && pq.size(); ++i)
	{
		point p = pq.top(); pq.pop();
		p.d *= 2;
		if(p.f > p.d)
		{
			pq.push(p);
			pq.push(p);
		}
	}
	if(pq.empty()) printf("1\n");
	else printf("%d\n", pq.top().f/pq.top().d + (pq.top().f%pq.top().d!=0));
	return 0;
}

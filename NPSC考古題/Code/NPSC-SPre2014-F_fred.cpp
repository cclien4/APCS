/*
npsc 2014初賽-高中組-F：校園偶像計劃

*/
#include <iostream>
#include <iomanip>
#include <algorithm> 
#include <set>
using namespace std;
struct mb { 
	int u;
	double spc[3], tot;
} r[25];
bool cmp(mb x , mb y )
{
	if(x.tot>y.tot) return true;
	return false;	
}
int main()
{
   	int t,n,m , i,j,k;
   	char a , y ;
   	cin >> t;
   	while(t--)
   	{
	  	cin >> n >> a >> m;
	  	for(i=0; i<n; ++i)
	  	{
			cin >> r[i].u >> a >> r[i].spc[0] >> a 
			    >> r[i].spc[1] >> a >> r[i].spc[2];
			r[i].tot = 0;
		}
		for(j=0; j<m ; ++j)
		{
			if(j) cin >> a;
			cin >> y;
			if ( y=='s' ) k=0;
			else if ( y=='p' ) k=1;
			else k=2;
		  	for(i=0; i<n; ++i)
		  	{
				r[i].tot += r[i].spc[k];		
			}
		}
		sort ( r , r+n , cmp );
		double sum=0;
		int rout[9];
		for( i=0; i<9; ++i )  // 前九位的總分、將學號加入 set
		{
			rout[i]=r[i].u;
		   sum += r[i].tot;
		}
	  	cout << fixed << setprecision(3) << sum / 9 << endl;
	  	sort ( rout , rout+9);
		for( i=0; i<9; ++i ) 
		{
			if(i<8)
		   	cout<<rout[i]<<",";
		   	else
		   	cout<<rout[i];
		}
	  	cout << endl;
   }
  return 0;
}


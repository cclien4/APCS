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
   	char a , y ; // 逗號 , 歌曲類
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
		set <int> uo;
		set <int>::iterator is;
		double sum=0;
		for( i=0; i<9; ++i )  // 前九位的總分、將學號加入 set
		{
		   uo.insert(r[i].u);
		   sum += r[i].tot;
		}
	  	cout << fixed << setprecision(3) << sum / 9 << endl;
	  	is=uo.begin(); cout << (*is) ;
	  	for(++is; is!=uo.end(); ++is) cout << "," << (*is) ;
	  	cout << endl;
   }
  return 0;
}
/*
2
10,3
1,2000.000,5000.000,3000.000
2,4000.000,2000.000,2000.000
3,1000.000,5000.000,3000.000
4,3000.000,2000.000,3000.000
5,2000.000,1000.000,5000.000
6,1000.000,3000.000,1000.000
7,1000.000,5000.000,3000.000
8,5000.000,3000.000,5000.000
9,4000.000,4000.000,4000.000
10,5000.000,1000.000,2000.000
s,p,c
12,5
1,796.501,13.025,994.582
2,676.916,409.636,561.610
3,848.811,443.469,586.526
4,221.629,653.935,608.985
5,589.992,555.418,413.737
6,539.929,334.949,46.011
7,547.726,103.542,559.104
8,934.054,673.369,373.407
9,860.740,995.345,3.964
10,553.694,620.526,438.781
11,48.880,503.052,638.534
12,213.942,398.149,963.539
s,p,s,c,c
-----------------------
9444.444
1,2,3,4,5,7,8,9,10
2894.192
1,2,3,5,7,8,9,10,12
*/


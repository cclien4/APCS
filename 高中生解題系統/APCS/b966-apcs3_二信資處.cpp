#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const int MaxN = 10000; // < 10000
const int MaxM = 1e8; 
struct seg  //線段
{
 int st; //起點
 int ed; //起點
 
} a[MaxN];
bool cmp(seg x, seg y)
{
 if(x.st != y.st)
      return x.st < y.st;
 else return x.ed < y.ed;
}
int main(void)
{
   int i,j,k , n;
   while( cin >> n )
   {
 // 讀 n 筆 線段
 for(j=0;j<n;++j)
  cin >> a[j].st >> a[j].ed;
 a[n].st = a[n].ed = MaxM;  //最後加 1筆 自成一段(長度為0)
 sort(a,a+n, cmp);
 int st=a[0].st , ed=a[0].ed;
 int ans = 0;
 for(j=1; j<=n; ++j)
 {
  if(a[j].st <= ed) // 有覆蓋或連接
     ed = max(ed, a[j].ed);
  else //分離 另一段，將前一段的長度加入 and
  {
   ans += (ed-st);
   st = a[j].st;  ed = a[j].ed;
  }
 }
 cout << ans << endl;
   }
   return 0;
}

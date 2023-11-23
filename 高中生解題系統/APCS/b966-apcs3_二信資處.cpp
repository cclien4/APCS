#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const int MaxN = 10000; // < 10000
const int MaxM = 1e8; 
struct seg  //�u�q
{
 int st; //�_�I
 int ed; //�_�I
 
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
 // Ū n �� �u�q
 for(j=0;j<n;++j)
  cin >> a[j].st >> a[j].ed;
 a[n].st = a[n].ed = MaxM;  //�̫�[ 1�� �ۦ��@�q(���׬�0)
 sort(a,a+n, cmp);
 int st=a[0].st , ed=a[0].ed;
 int ans = 0;
 for(j=1; j<=n; ++j)
 {
  if(a[j].st <= ed) // ���л\�γs��
     ed = max(ed, a[j].ed);
  else //���� �t�@�q�A�N�e�@�q�����ץ[�J and
  {
   ans += (ed-st);
   st = a[j].st;  ed = a[j].ed;
  }
 }
 cout << ans << endl;
   }
   return 0;
}

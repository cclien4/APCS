#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(){
	char c;
	int h, m;
	cin >> h >> c >> m;
	h%=12;
	float am, ah;
	am = m*6;
	ah = h*30;
	ah += m*0.5;
	float ans = ah>am?ah-am:am-ah;
	if(ans>180){
		ans = 360-ans;
	}
	cout << fixed << setprecision(2) << ans;
}

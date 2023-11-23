#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	float d, x1, x2;
	if(b*b-4*a*c>0){
		d = sqrt(b*b-4*a*c);
		x1 = ((-1)*b+d)/(2*a);
		x2 = ((-1)*b-d)/(2*a);
		cout << "Two different roots x1=" << fixed << setprecision(2) << x1 << " , x2=" << x2 << endl;
	}else if(b*b-4*a*c==0){
		x1 = ((-1)*b)/(2*a);
		cout << "Two same roots x=" << fixed << setprecision(2) << x1 << endl;
	}else if(b*b-4*a*c<0){
		cout << "No real root" << endl;
	}
}
//Two different roots x1=0.41 , x2=-2.41
//Two same roots x=0.00
//No real root

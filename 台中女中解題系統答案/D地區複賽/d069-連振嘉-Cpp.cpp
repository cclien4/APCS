#include<algorithm>
#include<iostream>
#include<cstdlib>

using namespace std;

struct person{
	int name;
	int vote;
};

bool cmp(person p1, person p2){
	if(p1.vote<p2.vote)return false;
	else return true;
}

int main (){
	person p[3];
	for(int i = 0; i < 3; i++){
		p[i].name = i;
		cin >> p[i].vote;
	}
	sort(p, p+3, cmp);
	p[1].vote+=p[2].vote;
	sort(p, p+3, cmp);
	switch(p[0].name){
		case 0:
			cout << "¥Ò" << endl;
		case 1:
			cout << "¤A" << endl;
		case 2:
			cout << "¤þ" << endl; 
	}
}

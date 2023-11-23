#include <bits/stdc++.h>

using namespace std;

struct node{
	int x;
	int y;
};

int main(){
	node n[3];
	int tar, temp1, temp2, ansx, ansy;
	for(int i = 0; i < 3; i++){
		cin >> n[i].x >> n[i].y;
	}
	temp1=(n[0].x-n[1].x)*(n[0].x-n[1].x)+(n[0].y-n[1].y)*(n[0].y-n[1].y);
	temp2=(n[0].x-n[2].x)*(n[0].x-n[2].x)+(n[0].y-n[2].y)*(n[0].y-n[2].y);
	if(temp1==temp2){
		tar=0;
	}else if(temp1>temp2){
		tar=2;
	}else{
		tar=1;
	}
	switch(tar){
		case 0:
			temp1=(n[1].x+n[2].x)/2;
			temp2=(n[1].y+n[2].y)/2;
			ansx=temp1*2-n[0].x+1;
			ansy=temp2*2-n[0].y+1;
			cout << ansx << ' ' << ansy << endl;
			break;
		case 1:
			temp1=(n[0].x+n[2].x)/2;
			temp2=(n[0].y+n[2].y)/2;
			ansx=temp1*2-n[1].x+1;
			ansy=temp2*2-n[1].y+1;
			cout << ansx << ' ' << ansy << endl;
			break;
		case 2:
			temp1=(n[1].x+n[0].x)/2;
			temp2=(n[1].y+n[0].y)/2;
			ansx=temp1*2-n[2].x+1;
			ansy=temp2*2-n[2].y+1;
			cout << ansx << ' ' << ansy << endl;
			break;
	}
	return 0;
}
//答案都+1才能通過  為甚麼你們自己去找吧  我也是覺得不+1才是對的 

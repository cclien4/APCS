#include <bits/stdc++.h>

using namespace std;
int top;
struct board{
	int x1;
	int x2;
	int y1;
	int y2;
	int ball = 0;
	int down = -1;
	int join = 0;//0為未加入，1為已加入，-1為已離開
	//懶得再寫遞迴函數來尋找了
	//結果還是要寫== 
};

struct point{
	int bnum;
	int x;
	int y;
	bool low;
};

bool cmp(point p1, point p2){
	if(p1.x<p2.x){
		return true;
	}else{
		return false;
	}
}

bool lower(point p, board b){
	double d1, d2;
	if(p.y-b.y1>0){
		if(p.x-b.x1>0){
			d1 = (p.y-b.y1)/(p.x-b.x1);
		}else{
			d1 = (p.y-b.y1)/(b.x1-p.x);
			d1*=-1;
		}
	}else{
		if(p.x-b.x1>0){
			d1 = (b.y1-p.y)/(p.x-b.x1);
			d1*=-1;
		}else{
			d1 = (b.y1-p.y)/(b.x1-p.x);
		}
	}
	if(b.y2-p.y>0){
		if(b.x2-p.x>0){
			d2 = (b.y2-p.y)/(b.x2-p.x);
		}else{
			d2 = (b.y2-p.y)/(p.x-b.x2);
			d2*=-1;
		}
	}else{
		if(b.x2-p.x>0){
			d2 = (p.y-b.y2)/(b.x2-p.x);
			d2*=-1;
		}else{
			d2 = (p.y-b.y2)/(p.x-b.x2);
		}
	}
	if(d1<d2){
		return true;
	} else {
		return false;
	}
}

int lowerthanwhat(point p, board* topb, board* zero){
	bool b = lower(p, *topb);
	if(!b&&topb-zero==top){
		return -1;
	}else if(!b){
		return -2;
	}else{
		if(topb->down==-1){
			return topb-zero;
		}else if(lowerthanwhat(p, zero+(topb->down), zero)==-2){
			return topb-zero;
		}else{
			lowerthanwhat(p, zero+(topb->down), zero);
		}
	}
}

int count(bool* b, int n){
	int c = 0;
	for(int i = 0; i < n; i++){
		if(*(b+i)) c++;
	}
	return c;
}

int countball(int cur, bool* zero, board* bzero, int n){
	int c = (bzero+cur)->ball;
	for(int i = 0; i < n; i++){
		if(*(zero+cur*n+i)){
			c+=countball(i, zero, bzero, n);
			*(zero+cur*n+i)=false;
		}
	}
	return c;
}

int main(){
	int n, temp, w;
	cin >> n >> temp >> w >> temp;
	board b[n];
	point p[n*2];
	bool map[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			map[i][j] = false;
		}
	}
	for(int i = 0; i < n; i++){
		bool l;
		cin >> b[i].x1 >> b[i].y1 >> b[i].x2 >> b[i].y2;
		l = b[i].y1<b[i].y2? true:false;
		p[i*2].x = b[i].x1;
		p[i*2].y = b[i].y1;
		p[i*2].bnum = i;
		p[i*2].low = l;
		p[i*2+1].x = b[i].x2;
		p[i*2+1].y = b[i].y2;
		p[i*2+1].bnum = i;
		p[i*2+1].low = !l;
	}
	sort(p, p+n*2, cmp);
	int tar;
	top = p[0].bnum;
	tar = p[0].x;
	b[p[0].bnum].join = 1;
	//開始處理 
	for(int i = 1; i < n*2; i++){
		//接球部分
		//先接球再處理TOP 
		temp = p[i].x - tar;
		b[top].ball+=temp;
		tar = p[i].x;
		//空的，直接加入
		if(top == -1){
			top = p[0].bnum;
			b[p[i].bnum].join = 1;
			tar = p[i].x;
		} 
		//板子已加入，離開
		else if(b[p[i].bnum].join==1){
			//找板子
			if(p[i].bnum==top){
				//先傳遞才離開
				if(p[i].low&&b[p[i].bnum].down!=-1){
					map[b[p[i].bnum].down][p[i].bnum] = true;
				}
				top = b[p[i].bnum].down;
				b[p[i].bnum].down = -1;
			}else{
				//先傳遞才離開 
				if(p[i].low&&b[p[i].bnum].down!=-1){
					map[b[p[i].bnum].down][p[i].bnum] = true;
				}
				temp = top;
				while(b[temp].down!=p[i].bnum){
					temp = b[temp].down;
				}
				b[temp].down = b[p[i].bnum].down;
				b[p[i].bnum].down = -1;
			}
			b[p[i].bnum].join = -1;
		}
		//板子未加入，加入
		else if(b[p[i].bnum].join==0){
			temp = lowerthanwhat(p[i], b+top, b);
			if(temp==-1){
				b[p[i].bnum].down = top;
				top = p[i].bnum;
			}else{
				b[p[i].bnum].down = b[temp].down;
				b[temp].down = p[i].bnum;
			}
			b[p[i].bnum].join = 1;
			//先加入才傳遞
			if(p[i].low&&b[p[i].bnum].down!=-1){
				map[b[p[i].bnum].down][p[i].bnum] = true;
			}
		}
	}
	/*for(int i = 0; i < n; i++){
		cout << b[i].ball << endl;
	}
	cout << endl;*/
	//map[i][j]表示i收到j的球 
	for(int i = 0; i < n; i++){
		b[i].ball=countball(i, map[0], b, n);
	}
	//記得把答案乘以w
	for(int i = 0; i < n; i++){
		temp = b[i].ball*w;
		cout << temp << endl;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct task{
	int start;
	int end;
	int time;
};

inline bool cmp(task t1, task t2){
	if(t1.end < t2.end) return true;
	else if(t1.end == t2.end)
		if(t1.time < t2.time) return true;
		else return false;
	else return false;
}

int main(){
	int a, b, big = 0, c = 0;
	bool bad;
	cin >> a;
	task t[a];
	
	for(int i = 0; i < a; i++){
		cin >> t[i].end >> t[i].time;
		t[i].start = t[i].end - t[i].time;
	}
	/*
	//x
	for(int i = 0; i < a; i++){
		cin >> b >> t[i].time;
		if(b > big) big = b;
		t[i].end = b - t[i].time;
	}
	//
	*/
	sort(t, t+a, cmp);
	int p = 0, j;
	for(int i = 0; i < a; i++){
		bad = false;
		if(t[i].start < p){
			continue;
		}
		j = i;
		while(t[j].end<t[i].end+t[i].time-1&&j!=(a-1)){
			++j;
			if(t[j].start<t[i].end&&t[j].time<t[i].time){
				bad = true;
				break;
			}
		}
		if(bad){
			continue;
		}
		p += t[i].time;
		++c;
	}
	/*//x
	bool m[big+1];
	for(int i = 0; i < big+1; i++){
		m[i] = false;
	}
	*/
	/*//
	bool yes = true;
	for(int i = 0; i < a; i++){
		for(int j = 0; j < t[i].time; j++){
			if(t[i].end<0) continue;
			if(!m[t[i].end+j]){
				m[t[i].end+j] = true;
			} else {
				yes = false;
				break;
			}
		}
		if(yes){
			++c;
		}
		yes = true;
	}
	*/
	cout << c << endl;
	return 0;
}


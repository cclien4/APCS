#include <bits/stdc++.h>

using namespace std;

struct car{
	int v;
	car *front = NULL;
};

int m, n, t, g, ip = 0, op = 0;
car *tar=NULL, *inl=NULL, *outl=NULL, *inf=NULL, *outf=NULL, *backtar=NULL;

void beoutfirst(car *cur, int v){
	//把cur的值換掉、第一名指標換掉、檢查是不是最後一名，把最後一名指標換掉
	//cur就是第一名，只要把值換掉就可以 
	if(cur->v==outf->v){
		cur->v = v;
		return;	
	}
	if(cur->v==outl->v){//cur就是最後一名
		outl = cur->front;
	}
	cur->v = v;
	outf->front = cur;
	cur->front = NULL;
	outf = cur;
}

void beinfirst(car *cur, int v){
	//把cur的值換掉、第一名指標換掉、檢查是不是最後一名，把最後一名指標換掉
	//cur就是第一名，只要把值換掉就可以 
	if(cur->v==inf->v){
		cur->v = v;
		return;
	} 
	if(cur->v==inl->v&&cur->v!=inf->v){//cur就是最後一名，而且不是第一名 
		inl = cur->front;
	}
	cur->v = v;
	inf->front = cur;
	cur->front = NULL;
	inf = cur;
}

bool isin(int v, car* carp){
	if(carp == NULL){
		return false;
	}else if(isin(v, carp->front)){
		if(carp->front->v==v){
			backtar = carp;
		}
		return true;
	}else if(carp->v==v){
		tar = carp;
		return true;
	}
	return false;
}

bool isout(int v, car* carp){
	if(carp == NULL){
		return false;
	}else if(isout(v, carp->front)){
		if(carp->front->v==v){
			backtar = carp;
		}
		return true;
	}else if(carp->v==v){
		tar = carp;
		return true;
	}
	return false;
}

int main(){
	int temp;
	bool ii, io;
	cin >> m >> n >> t >> g;
	car in[n], out[m];
	for(int i = 0; i < t; i++){
		cin >> temp;
		io = isout(temp,outl);
		ii = isin(temp,inl);
		//不在外圈也不在內圈
		if(!io&&!ii){
			//外圈是空的 
			if(op==0){
				out[0].v = temp;
				out[0].front = NULL;
				outf = out;
				outl = out;
				op++;
			}
			//外圈已滿，跑到外圈第一名，擠掉最後一名 
			else if(op==m){
				tar = outl->front;
				beoutfirst(outl, temp);
				if(op!=1){
					outl = tar;
				}
			}
			//外圈還有空位，跑到外圈第一名
			else{
				beoutfirst(out+op, temp);
				op++;
			} 
		}
		//在外圈
		else if(io){
			//跑到內圈第一名
			//內圈是空的
			if(ip==0){
				//處理解放的車輛 
				if(tar->v==outf->v){
					if(op==1){
						outf = NULL;
					}else{
						outf = backtar;
					}
				}
				if(tar->v==outl->v){
					if(op==1){
						outl = NULL;
					}else{
						outl = backtar;
					}
				}
				backtar->front = tar->front;
				tar->front = out[op-1].front;
				tar->v = out[op-1].v;
				//如果解放車輛是第一名或最後一名，第一名或最後一名指標更新 
				if(out[op-1].v==outl->v){
					outl = tar;
				}
				if(out[op-1].v==outf->v){
					outf = tar;
				}
				out[op-1].front = NULL;
				out[op-1].v = NULL;
				//處理內圈 
				in[0].v = temp;
				in[0].front = NULL; 
				inf = in;
				inl = in;
				ip++;
				op--;
			}
			//內圈已滿，擠掉最後一名
			else if(ip==n){
				beoutfirst(tar, inl->v);
				beinfirst(inl, temp);
			}
			//內圈還有空位
			else{
				//重點：要把外圈陣列解放的車輛放到最後一名(out[op]) 
				backtar->front = tar->front;
				tar->v = out[op-1].v;
				tar->front = out[op-1].front;
				out[op-1].v = NULL;
				out[op-1].front = NULL;
				op--;
				beinfirst(in+ip, temp);
				ip++;
			} 
		}
		//在內圈
		else if(ii){
			//原本不是第一名 
			//跑到內圈第一名 
			if(tar->v!=inf->v){
				beinfirst(tar, temp);	
			}
		}
	}
	for(int i = 0; i < g; i++){
		cin >> temp;
		ii = isin(temp, inl);
		if(ii){
			cout << "Y ";
		}else{
			cout << "N ";
		}
	}
	cout << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct car{
	int v;
	car *front = NULL;
};

int m, n, t, g, ip = 0, op = 0;
car *tar=NULL, *inl=NULL, *outl=NULL, *inf=NULL, *outf=NULL, *backtar=NULL;

void beoutfirst(car *cur, int v){
	//��cur���ȴ����B�Ĥ@�W���д����B�ˬd�O���O�̫�@�W�A��̫�@�W���д���
	//cur�N�O�Ĥ@�W�A�u�n��ȴ����N�i�H 
	if(cur->v==outf->v){
		cur->v = v;
		return;	
	}
	if(cur->v==outl->v){//cur�N�O�̫�@�W
		outl = cur->front;
	}
	cur->v = v;
	outf->front = cur;
	cur->front = NULL;
	outf = cur;
}

void beinfirst(car *cur, int v){
	//��cur���ȴ����B�Ĥ@�W���д����B�ˬd�O���O�̫�@�W�A��̫�@�W���д���
	//cur�N�O�Ĥ@�W�A�u�n��ȴ����N�i�H 
	if(cur->v==inf->v){
		cur->v = v;
		return;
	} 
	if(cur->v==inl->v&&cur->v!=inf->v){//cur�N�O�̫�@�W�A�ӥB���O�Ĥ@�W 
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
		//���b�~��]���b����
		if(!io&&!ii){
			//�~��O�Ū� 
			if(op==0){
				out[0].v = temp;
				out[0].front = NULL;
				outf = out;
				outl = out;
				op++;
			}
			//�~��w���A�]��~��Ĥ@�W�A�����̫�@�W 
			else if(op==m){
				tar = outl->front;
				beoutfirst(outl, temp);
				if(op!=1){
					outl = tar;
				}
			}
			//�~���٦��Ŧ�A�]��~��Ĥ@�W
			else{
				beoutfirst(out+op, temp);
				op++;
			} 
		}
		//�b�~��
		else if(io){
			//�]�줺��Ĥ@�W
			//����O�Ū�
			if(ip==0){
				//�B�z�ѩ񪺨��� 
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
				//�p�G�ѩ񨮽��O�Ĥ@�W�γ̫�@�W�A�Ĥ@�W�γ̫�@�W���Ч�s 
				if(out[op-1].v==outl->v){
					outl = tar;
				}
				if(out[op-1].v==outf->v){
					outf = tar;
				}
				out[op-1].front = NULL;
				out[op-1].v = NULL;
				//�B�z���� 
				in[0].v = temp;
				in[0].front = NULL; 
				inf = in;
				inl = in;
				ip++;
				op--;
			}
			//����w���A�����̫�@�W
			else if(ip==n){
				beoutfirst(tar, inl->v);
				beinfirst(inl, temp);
			}
			//�����٦��Ŧ�
			else{
				//���I�G�n��~��}�C�ѩ񪺨������̫�@�W(out[op]) 
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
		//�b����
		else if(ii){
			//�쥻���O�Ĥ@�W 
			//�]�줺��Ĥ@�W 
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

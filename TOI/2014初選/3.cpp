#include <bits/stdc++.h>

using namespace std;

int n, l;


int main(){
	int a, sp = 0, temp1, temp, p = 0;
	cin >> n >> l;
	int map[n][l], t[l];
	for(int i = 0; i < n; i++){
		cin >> temp1;
		sp = 0, p = 0;
		for(int j = 0; j < temp1; j++){
			cin >> temp;
			if(temp==0){
				sp++;
				t[p] = 0;
				p++;
			}else{
				for(int k = 1; k <= temp; k++){
					t[p] = k;
					++p;
				}
			}
		}
		//�s�@�ťզ�m�Ϫ� 
		int sparr[sp+1], c = 0, cc = 0;
		for(int j = 0; j < l; j++){
			if(t[j]==0){
				sparr[cc] = c;
				++cc;
				c = 0;
			}else if(t[j]==1){
				++c;
			}
			if(j==l-1){
				sparr[cc] = c;
			}
		}
		//�}�l�j�M 
		int where[] = {0,0}, len, temp2;
		c = 0; cc = 0;
		//where{�ĴX�ӪŮ�᭱,�ӪŮ�᭱���ĴX�x����}
		for(int j = 0; j < l; j++){
			if(t[j]==1){
				where[1]++;
			}else if(t[j]==0){
				where[0]++;
				where[1] = 0;
			}
			int x = t[j];
			if(x==0){
				map[i][j] = 0;
				continue;
			}
			//������L,��������X��n�ťX�ӫh�ݭn�k��X��,�άO����L-X+1��
			//�]�N�O���k��X�ӪŮ�,�άO������L-X+1�ӪŮ� 
			if(t[j]==1){ 
				for(int k = 1; 1; k++){
					if(j==l-1){
						len = t[j];
						break;
					}
					if(t[j+k]==1||t[j+k]==0){
						len = t[j+k-1];
						break;
					}
				//�䧹����
				}
			}
			if(len-x+1>where[0]&&x>sp-where[0]){
				map[i][j] = -1;
				continue;
			}
			//�����M�k�� 
			int left = 0, right = 0;
			if(x>sp-where[0]){
				right = 1e7;
			}else{
				//�V�k�j�M 
				for(int k = 1; k <= x-1; k++){
					right += sparr[where[0]+k];
				}
			}
			if(len-x+1>where[0]){
				left = 1e7;
			}else{
				//�V���j�M 
				for(int k = 1; k <= len-x; k++){
					left += sparr[where[0]-k];
				}
			}
			left += where[1];
			right += sparr[where[0]] - where[1]+1;
			map[i][j] = left<right?left:right;
		}
	}
	int ansn = -1, ansp = -1, c = 0;
	bool out = false;
	for(int i = 0; i < l; i++){
		for(int j = 0; j < n; j++){
			if(map[j][i] == -1){
				c = 0;
				out = true;
				break;
			}
			c+=map[j][i];
			if(c>ansn&&ansn!=-1){
				out = true;
				break;
			}
		}
		if(out){
			c = 0;
			out = false;
			continue;
		}
		if(ansn == -1){
			ansn = c;
			ansp = i+1;
			c = 0;
		}else if(c<ansn){
			ansn = c;
			ansp = i;
			c = 0;
		}
	}
	cout << ansn << endl << ansp << endl;
	return 0;
}


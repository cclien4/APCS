#include <iostream>
#include <map>
#include <algorithm>
using namespace std;



int main(void){
   multimap<int, int, greater<int> > mmap;
   multimap<int, int, greater<int> >::iterator it;	

	int n,k;
	int max;
	cin>>n>>k;
	int i,ptr[n];//ptr�����ϥΪ̿�J���I
	int d[k+2]; //d�����̤j���|�t���X�Ӯy���I  �[�W  
	int dis[k+2];
	for(i=0;i<n;i++)
	   cin>>ptr[i];
	
	sort(ptr,ptr+n); //�Ƨǿ�J�����
    //��Z���̤j��̤p�i��Ƨ� 
    for(i=1; i<n; i++)
    	mmap.insert(pair<int,int>(ptr[i] - ptr[i-1],i));
/*   �h�ݥثemap�ҰO�����Z�� 
    for (it=mmap.begin(); it!=mmap.end(); ++it){
       cout << it->first << " => " << it->second << endl;
    }*/ 
    //k�Ӱ�a  �i����k-1�ӳ̪��Z��   �̪������bd�}�C  k=2 �ݭn����1��   
    for (i=1,it=mmap.begin();i<k; it++,i++){
    	d[i]=it->second;
    } 
   
   /* for (i=1;i<k;i++){
        cout<<d[i]<<endl;
    }*/
    /* 
    d[0]=ptr[0];
     sort(d,d+k);//�Ƨ�d�}�C�w�Ƴ̭p��*/ 
	 //��q0���I��d�}�C�������C�@�ӭȡA�̤j�Z����X�� 
	 //k=1 ���@�q  k=2 ���T�q  k=3  ���|�q 
	 d[0]=0;
	 d[k]=n;//�̫�@���I
	 sort(d,d+k);//�Ƨ�d�}�C�w�Ƴ̭p��*/
	 //�����T�Ӱ϶���J 
     for(i=1;i<=k;i++){ 
		dis[i]=ptr[d[i]-1]-ptr[d[i-1]];
	}
	//�ƧǨC�ӰϬq�Һ�X���� 
	dis[0]=0;
    sort(dis,dis+k+1);
   /* for (i=0;i<=k;i++){
        cout<<dis[i]<<endl;
    }  */  
    //�L�X�̤j�� 
    //�e���O�L�S���p  �p:  100 2 ==> 1 2 5 6 7 8 9 10 11 12 13.... 
    if(dis[k]< ((ptr[n-1]-ptr[0]) / k))
       cout<<dis[k];
    else
        cout<<((ptr[n-1]-ptr[0]) / k);
    system("pause");
    
	return 0;
} 

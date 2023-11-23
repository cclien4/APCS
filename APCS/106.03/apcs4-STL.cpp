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
	int i,ptr[n];//ptr紀錄使用者輸入的點
	int d[k+2]; //d紀錄最大路徑差的幾個座標點  加上  
	int dis[k+2];
	for(i=0;i<n;i++)
	   cin>>ptr[i];
	
	sort(ptr,ptr+n); //排序輸入的資料
    //把距離最大到最小進行排序 
    for(i=1; i<n; i++)
    	mmap.insert(pair<int,int>(ptr[i] - ptr[i-1],i));
/*   去看目前map所記錄的距離 
    for (it=mmap.begin(); it!=mmap.end(); ++it){
       cout << it->first << " => " << it->second << endl;
    }*/ 
    //k個基地  可忽略k-1個最長距離   最長紀錄在d陣列  k=2 需要切割1個   
    for (i=1,it=mmap.begin();i<k; it++,i++){
    	d[i]=it->second;
    } 
   
   /* for (i=1;i<k;i++){
        cout<<d[i]<<endl;
    }*/
    /* 
    d[0]=ptr[0];
     sort(d,d+k);//排序d陣列預備最計算*/ 
	 //把從0個點到d陣列紀錄的每一個值，最大距離算出來 
	 //k=1 分一段  k=2 分三段  k=3  分四段 
	 d[0]=0;
	 d[k]=n;//最後一個點
	 sort(d,d+k);//排序d陣列預備最計算*/
	 //分成三個區塊輸入 
     for(i=1;i<=k;i++){ 
		dis[i]=ptr[d[i]-1]-ptr[d[i-1]];
	}
	//排序每個區段所算出的值 
	dis[0]=0;
    sort(dis,dis+k+1);
   /* for (i=0;i<=k;i++){
        cout<<dis[i]<<endl;
    }  */  
    //印出最大值 
    //前提是無特殊狀況  如:  100 2 ==> 1 2 5 6 7 8 9 10 11 12 13.... 
    if(dis[k]< ((ptr[n-1]-ptr[0]) / k))
       cout<<dis[k];
    else
        cout<<((ptr[n-1]-ptr[0]) / k);
    system("pause");
    
	return 0;
} 

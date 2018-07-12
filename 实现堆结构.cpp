http://dsalgo.openjudge.cn/binarytree/1/
#include <iostream>
using namespace std;
void sift(int r[],int low,int high){
	int i = low,j = 2*i;
	int temp = r[i];
	while(j <= high){
		if(j < high && r[j] > r[j + 1])
			++j;
		if(temp > r[j]){
			r[i] = r[j];
			i = j;
			j = i*2;
		}
		else break;
	}
	r[i] = temp;
}
int main(){
	int n ;
	cin >> n;
	while(n != 0){
		n--;
		int length = 1;
		int a[100000];
		int m;
		cin >> m;
		for(int i = 0;i < m;i++){
			int temp1,temp2;
			cin >>temp1;
			if(temp1 == 1){
				cin >> temp2;
				a[length] = temp2;
				for(int i = length/2;i >= 1;--i)
					sift(a,i,length);
				length++;
			}
			else if(temp1 == 2){
				length--;	
				cout << a[1] << endl;
				a[1] = a[length];
				sift(a,1,length);
			}
		}
	}
	return 0;
}

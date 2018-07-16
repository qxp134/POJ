#include<iostream>
using namespace std;
int main(){
	int n,s,temp;
	cin >> n >> s;
	int a[10001],c[10001];
	long sum;
	for(int i = 0;i != n;i++){
		cin >>a[i] >> c[i];
		if(i == 0)sum = a[i] * c[i];
		else{
			temp = a[i - 1] + s;
			if(temp > a[i])sum += a[i] * c[i];
			else{
				sum += temp * c[i];
				a[i] = temp;
			}
		}
	}
	cout << sum;
}

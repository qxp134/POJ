http://bailian.openjudge.cn/practice/4080/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int a[101];
	int n;
	cin >> n;
	for(int i = 0; i != n;++i){
		cin >> a[i];
	}
	sort(a,a+n);
	vector<int> ans;
	for(int i = 0;i != n - 1;++i){
		int temp = a[i] + a[i + 1];
		ans.push_back(temp);
		a[i + 1] = temp;
		sort(a + i + 1,a + n);
	}
	long res = ans[0] * ans.size();
	for(int i = 0;i + 1 != ans.size();i++){
		res += (ans[i + 1] - ans[i])*(ans.size() -i - 1);
	}
	cout << res;
}

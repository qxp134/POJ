//http://bailian.openjudge.cn/practice/2746/
#include<iostream>
using namespace std;
int m;
int joseph(int n) {
if (n == 1)
return 0;
return (joseph(n - 1) + m) % n;
}
int main() {
int n;
while (true) {
cin >> n >> m;
if (n == 0 && m == 0)
return 0;
int res = joseph(n) + 1;
cout << res << endl;
}
return 0;
}


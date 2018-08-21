#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	double a;
	cin >> a;
	cout << setiosflags(ios::fixed) << setprecision(5) << a << endl;
	cout << resetiosflags(ios::fixed) << setiosflags(ios::scientific) << setprecision(7);//这个是要加RE
	cout << a << endl;
	return 0;
}
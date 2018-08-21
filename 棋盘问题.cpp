#include <iostream>
//棋盘问题http://bailian.openjudge.cn/practice/1321/
using namespace std;
char chess[8][8];
long c;
int row[8] = {0};
int col[8] = {0};
bool dfs(int n,int hang,int l){
	if(l == 0){
		c++;
		return true;
	}
	int temp1,temp2;
	for(int i = hang;i < n;++i){
		if(i + l > n)break;
		for(int j = 0;j < n;++j){
			temp1 = row[i];
			temp2 = col[j];
			if(chess[i][j] == '#'&&row[i] != 1&&col[j] != 1){
				row[i] = 1;col[j] = 1;
				dfs(n,hang + 1,l - 1);
			}
			row[i] = temp1;col[j] = temp2;	
		}
	}
}
int main(){
	int n,l;	
	while(cin >> n >> l){
		if(n == -1)break;
		for(int i = 0;i < n;++i){
			row[i] = 0;
			col[i] = 0;
			for(int j = 0;j < n;++j)
				cin >> chess[i][j] ;
		}
		c = 0;
		if(l == 0)
			cout << '0' << endl;
		else{
			dfs(n,0,l);
			cout << c << endl;
		}	
			
	}
}


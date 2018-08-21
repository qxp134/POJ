#include <iostream>
#include <string>
#include <vector>
using namespace std;
int total;
int optimum ;
string theres;
bool rejectflag = false;
int stringtoint(string s){
	int ans = 0;
	for(int i = 0;i < s.length();i++){
		ans = ans * 10 + s[i] - '0';
	}
	return ans;
}
//先把串分解到最开，放入一个vector中，然后一个个合并，合并到只有一个字符串为止（这个办法不行，有重复）
//在想，多一个控制的参数吧，前面那个合并了的空格的位置，只往后合并，避免重复 
void dfs(vector<string> num,int index){//字符串，上次合并的是哪个空 
	int sum = 0;
	for(int i = 0;i < num.size();++i){
		sum += stringtoint(num[i]);
	}
	if(sum > total)return;
	if((total - sum) <= (total - optimum)){
		theres.clear();
		if(optimum == sum)rejectflag = true;
		else rejectflag = false;
		optimum = sum;
		for(int i = 0;i < num.size();++i){
			theres = theres  + ' ' + num[i];
		}
	}		
	for(int i = index;i < num.size();++i){
		vector<string> temp;
		for(int j = 0;j < i - 1;j++){
			temp.push_back(num[j]);
		}
		string s;
		s = num[i - 1] + num [i];
		temp.push_back(s);
		for(int k = i + 1;k < num.size();k++){
			temp.push_back(num[k]);
		}
		dfs(temp,i);
	}
}
int main(){	
	string num;	
	while(cin >> total >> num){
		optimum = -1;
		if(total == 0 && num == "0")break;
		//if(total == stringtoint(num))cout << total <<' '<< num << endl;
		else {
			vector<string> res;
			for(int i = 0;i < num.length();i++){
				string a;
				a.push_back(num[i]);
				res.push_back(a);
			}
			dfs(res,1);
			if(optimum == -1)cout << "error" << endl;
			else if(rejectflag)cout <<"rejected"<<endl;
			else
				cout << optimum << theres << endl;
		}		
	}
	return 0;
}

//http://dsalgo.openjudge.cn/binarytree/4/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//递归函数 
void bianli(vector<string> zhong,vector<string> hou){
	if(hou.empty()) return;
	cout << hou[hou.size() - 1] <<" ";
	for(int i = 0;i < zhong.size();i++){
		if(zhong[i] == hou[hou.size() - 1]){
			vector<string> v1,v2,v3,v4;
			v1.assign(zhong.begin(), zhong.begin() + i);
			v2.assign(zhong.begin() + i + 1,zhong.end());
			v3.assign(hou.begin(), hou.begin() + i);
			v4.assign(hou.begin() + i ,hou.end()-1);		
			bianli(v1,v3);
			bianli(v2,v4);
		}
	}
}
int main(){
	vector <string> zhong, hou;
	string s;
	getline(cin,s);
	s = s + " ";
	int k = 0;
	for(int i = 0;i < s.size();++i){
		if(s[i] == ' '){
			string temp = "";
			for(int j = k;j < i;++j){
				temp = temp + s[j];
			}
			zhong.push_back(temp);
			k = i + 1;
		}
	}
	getline(cin,s);
	s = s + " ";
	k = 0;
	for(int i = 0;i < s.size();++i){
		if(s[i] == ' '){
			string temp = "";
			for(int j = k;j < i;++j){
				temp = temp + s[j];
			}
			hou.push_back(temp);
			k = i + 1;
		}
	}
	bianli(zhong,hou);
	return 0;
}

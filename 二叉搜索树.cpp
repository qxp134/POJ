http://bailian.openjudge.cn/practice/4079/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct node{
	int key;
	node* leftchild;
	node* rightchild;
};
int btinsert(node *&bt,int key){
	if(bt == NULL){
		bt = new(node);
		bt->leftchild = NULL;
		bt->rightchild = NULL;
		bt->key = key;
		return 1;
	}
	else{
		if(key == bt->key)return 0;
	    else if(key < bt->key){
			return btinsert(bt->leftchild,key);
		}		
		else
			return btinsert(bt->rightchild,key);
	}
}

void bianli(node* bt){
	if(bt == NULL)return;
	else{
		cout << bt->key<<' ';
		bianli(bt->leftchild);
		bianli(bt->rightchild);
	}
}

int main(){
	node *a;
	a = NULL;
	string s;
	vector<string> zhong;
	getline(cin,s);
	if(s=="")return 0;
	//s = s + " ";
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
	for(int i = 0;i < zhong.size();++i){
		int n = 0;
		for(int j = 0;j < zhong[i].size();j++){
			n = n * 10 + (zhong[i][j] - '0');
		}
		btinsert(a,n);
	}
	bianli(a);
	return 0;
}

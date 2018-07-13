//http://bailian.openjudge.cn/practice/4117/
#include<cstdio>
#include<iostream>
using namespace std;
#define N 55
int f[N][N],n,ans;//列表示要划分的整数，行表示划分后的项数
int main(){
    while(scanf("%d",&n)!=EOF){
        f[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                f[i][j]=f[i-1][j-1]+f[i-j][j];//每一个数划分为i项都分为两部分，数比它小一，项也比它小一，直接
					      //加过来，另一部分就是项数相同，每一项都加一
            }
        }
        ans=0;
        for(int i=1;i<=n;i++) ans+=f[n][i];
        printf("%d\n",ans);
    }
    return 0;
}

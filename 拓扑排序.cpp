//http://bailian.openjudge.cn/practice/4084/
#include<stdio.h>
#include<string.h>
int main()
{
int v,a,i,j;
int s[101][101],g[101],q[101];//q判断删了没
memset(s,0,sizeof(s));
memset(g,0,sizeof(g));
memset(q,0,sizeof(q));
scanf("%d%d",&v,&a);
while(a--)
{
     scanf("%d%d",&i,&j);
     s[i][j]++;
     g[j]++;
}
for(i=0;i<v;i++)
{
	for(j=1;j<=v;j++)
		if(!g[j]&&!q[j]){q[j]=1;printf("v%d ",j);break;}//找入度为零的点j，删掉，总会有入度为零的
	for(a=1;a<=v;a++)//把有从j过来的所有弧删掉
		if(s[j][a]>=1){
			g[a]--;
			s[j][a]--;
			a--;
		} 
}
printf("\n");
return 0;
}

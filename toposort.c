#include<stdio.h>
int a[10][10],n,indegre[10];
void find_indegre()
{
int j,i,sum;
for(j=0;j<n;j++)
{
sum=0;
for(i=0;i<n;i++)
sum+=a[i][j];
indegre[j]=sum;
}
}
void topology()
{
int i,u,v,t[10],s[10],top=-1,k=0;
find_indegre();
for(i=0;i<n;i++)
{
if(indegre[i]==0) s[++top]=i;
}
while(top!=-1)
{
u=s[top--];
t[k++]=u;
for(v=0;v<n;v++)
{
if(a[u][v]==1)
{
indegre[v]--;
if(indegre[v]==0) s[++top]=v;
}
	}
		}
printf("the topological sequence is:\n");
for(i=0;i<n;i++)
printf("%d",t[i]);
}
void main()
{
int i,j;
printf("enter number of jobs:");
scanf("%d",&n);
printf("\nenter the adjacency matrix:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
}
topology();
}


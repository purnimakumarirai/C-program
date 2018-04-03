#include<stdio.h>
int s[10],x[10],d;
void sumofsub(int,int,int);
void main()
{
int n,sum=0;
int i;
printf("enter the size of the set:");
scanf("%d",&n);
printf("\n enter the set in the increasing order:\n");
for(i=1;i<=n;i++)
scanf("%d",&s[i]);
printf("\n enter the value of d :\n");
scanf("%d",&d);
for(i=1;i<=n;i++)
sum=sum+s[i];
if(sum<d||s[1]>d)
printf("\n no subset possible :");
else
sumofsub(0,1,sum);
}
void sumofsub(int m,int k,int r)
{
int i=1;
x[k]=1;
if((m+s[k])==d)
{
printf("subset :");
for(i=1;i<=k;i++)
if(x[i]==1)
printf("\t%d",s[i]);
printf("\n");
}
else
if(m+s[k]+s[k+1]<=d)
sumofsub(m+s[k],k+1,r-s[k]);
if((m+r-s[k]>=d)&&(m+s[k+1]<=d))
{
x[k]=0;
sumofsub(m,k+1,r-s[k]);
}
}

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
	int ar[5]={8,1,7,6,0};
	sort(ar,ar+5);
	queue<int> zero;
	queue<int> one;
	queue<int> two;
	int sum=0;
	for(int i=0;i<5;i++)
	{
		if(ar[i]%3==0)
		zero.push(ar[i]);
		else if (ar[i]%3==1)
		one.push(ar[i]);
		else
		two.push(ar[i]);
		sum+=ar[i];
	}
	if(sum%3==1)
	{
		if(!one.empty())
		one.pop();
		else
		{
			if(two.size()>=2)
			{
				two.pop();
				two.pop();
			}
			else
			{
				printf("NOT POSSIBLE");
				return 0;
			}
		}
	}
	else if(sum%3==2)
	{
		if(!two.empty())
		two.pop();
		else
		{
			if(one.size()>=2)
			{
				one.pop();
				one.pop();
			}
			else
			{
				printf("NOT POSSIBLE");
				return 0;
			}
		}
	}
	int j=0;
	while (!one.empty())
	{
		ar[j]=one.front();
		one.pop();
		j++;
	}
	while(!two.empty())
	{
		ar[j]=two.front();
		two.pop();
		j++;
	}
	while(!zero.empty())
	{
		ar[j]=zero.front();
		zero.pop();
		j++;
	}	
	sort(ar,ar+j);
	for(int k=j-1;k>=0;k--)
	{
		cout<<ar[k];
	}
}

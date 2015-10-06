#include<iostream>
#include<queue>

using namespace std;

struct PetrolPump{
	int quantity;
	int distance;
};
int tour(struct PetrolPump *ar)
{
	queue<int> start;
	int sum=0;
	int i=0;
	while(start.size()!=3)
	{
		if(sum>0||sum==0)
		{
			start.push(i%3);
			sum+=ar[i%3].quantity-ar[i%3].distance;
			i++;
			//cout<<sum<<endl;
		}
		
			while(sum<0)
			{
				int k=start.front();
				start.pop();
				sum-=ar[k].quantity-ar[k].distance;
			}
							
			
	}
	return start.front();
	
}

int main()
{
	struct PetrolPump array[]={{6,4},{3,6},{7,3}};
	cout<<"The Starting Point Of the Circular Tour is "<<tour(array)<<endl;
	return 0;
}

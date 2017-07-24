#include <iostream>

using namespace std;

int count_one(int n)
{
    if(n<1)
       return 0;
    int round = n;
    int base = 1;
    int count = 0;
    while(round>0)
    {
       int weight = round%10;
       round/=10;
       //count+=round;
       if(weight==1)
          count+=round*base+(n%10)+1;
       else if(weight>1)
          count+=round*base+base;
        else if(weight==0)
            count+=round*base;
       base*=10;
    }
    return count;
}


/*
	若weight为0，则1出现次数为round*base
	若weight为1，则1出现次数为round*base+former+1
	若weight大于1，则1出现次数为rount*base+base
*/
int main()
{
	int n;
	while(cin>>n)
	{
		cout<<count_one(n)<<endl;
	}
	return 0;
}
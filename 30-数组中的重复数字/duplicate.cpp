#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

 
void find_dup(int *a,int n)
{
	//int *count= new int[n]();
	vector<int>count(n,0);
	unordered_set<int>res;
	for(int i=0;i<n;i++){
		count[a[i]]++;
	}
	for(int i=0;i<n;++i)
	{
		if(count[a[i]]>1)
			res.insert(a[i]);
	}
	for(unordered_set<int>::iterator it = res.begin();it!=res.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

int main()
{
	int n;
	while(cin>>n)
	{
		int *a = new int[n];
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
		}
		find_dup(a,n);
	}
	return 0;
}


//方法二 空间复杂度优化

#include <iostream>
 
using namespace std;
 
bool duplicate(int numbers[],int length,int* duplication){
    if(numbers==NULL || length<=1){
        duplication=NULL;
        return false;
    }
 
    for(int i=0;i<length;i++){
        while(numbers[i]!=i){
            if(numbers[i]==numbers[numbers[i]]){
                *duplication=numbers[i];
                return true;
            }
            int tmp=numbers[i];
            numbers[i]=numbers[tmp];
            numbers[tmp]=tmp;
        }
    }
 
    return false;
}
 
int main()
{
    int A[]={2,3,1,0,2,5,3};
    int len=sizeof(A)/sizeof(A[0]);
 
    int duplication;
    cout << duplicate(A,len,&duplication) << endl;
    cout << duplication << endl;
    return 0;
}
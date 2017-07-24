#include <iostream>
#include <vector>
using namespace std;

void print_circle(vector<vector<int> >arr,int cols,int rows,int start);
void print_wisely(vector<vector<int> >arr,int cols,int rows);


int main()
{
	int col,row;
	while(cin>>col>>row)
	{
		vector<vector<int> >arr(row);
		for(int i=0;i<arr.size();++i)
		{
			arr[i].resize(col);
		}
		for(int i=0;i<row;++i)
		{
			for(int j=0;j<col;++j)
			{
				cin>>arr[i][j];
			}
		}
		
		print_wisely(arr,col,row);
	}
	return 0;
}

void print_wisely(vector<vector<int> >arr,int cols,int rows)
{
	if(arr.size()==0||cols<=0||rows<=0)
		  return ;
	int start = 0;
	while(cols>start*2&&rows>start*2)
	{
		print_circle(arr,cols,rows,start);
		++start;
	}
}

void print_circle(vector<vector<int> >arr,int cols,int rows,int start)
{
	int endX = cols-start-1;
	int endY = rows-start-1;
	for(int i=start;i<=endX;++i)
	{
		cout<<arr[start][i]<<" ";
	}
	if(start<endY)
	{
		for(int i=start+1;i<=endY;++i)
		{
			cout<<arr[i][endX]<<" ";
		}
	}
	if(start<endX&&start<endY)
	{
		for(int i=endX-1;i>=start;--i)
		{
			cout<<arr[endY][i]<<" ";
		}
	}
	if(start<endX&&start<endY-1)
	{
		for(int i=endY-1;i>start;--i)//第一个数字不再打印
		{
			cout<<arr[i][start]<<" ";
		}
	}
	//cout<<endl;
}
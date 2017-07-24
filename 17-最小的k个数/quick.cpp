#include <iostream>
#include <vector>
using namespace std;

class Solution {  
public:  
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {  
       vector<int> out;  
       int size = input.size();  
       if(size == 0 || size < k||k < 1)   
         return out;  
         
       int start = 0;  
       int end = size - 1;  
           
       int index =  partition(input, start, end);  
       while(index != k-1)  
       {  
          if(index < k-1)  
          {  
             start = index + 1;  
             index =  partition(input, start, end);  
          }  
          else if(index > k-1)  
          {  
             end = index - 1;  
             index =  partition(input, start, end);  
          }  
       }  
       out.insert(out.begin(),input.begin(),input.begin()+k);  
       return out;   
    }  
      
    //快排中的partition函数  
    int partition(vector<int> &numbers,int start, int end)  
    {  
        if(start == end)  
            return start;  
           
        int temp = numbers[end];  
           
        //跳出迭代的时候start = end  
        while(start < end)  
        {  
          while(start < end && numbers[start] < temp)  
            ++start;  
          numbers[end] = numbers[start];  
                 
          while(start < end && numbers[end] >= temp)  
            --end;  
          numbers[start] = numbers[end];  
        }  
           
        numbers[end] = temp;  
        return end;  
    }  
};  


int main()
{
	Solution s;
	vector<int>arr,dst;
	for(int i=0;i<7;++i)
	{
		int t;
		cin>>t;
		arr.push_back(t);
	}
	dst = s.GetLeastNumbers_Solution(arr,6);
	for(auto i:dst)
		cout<<dst[i]<<" ";
	cout<<endl;
	return 0;
}
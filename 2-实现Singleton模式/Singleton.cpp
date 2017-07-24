#include <iostream>

using namespace std;

class Single{
private:
    Single(){
		cout<<"construct"<<endl;
	}
public:
    static Single* Instance;
    static void getInstance(){
		cout<<"calling"<<endl;
        Single();
	};
    ~Single(){
		cout<<"deconstruct"<<endl;
	};
};

int main()
{
    Single::getInstance();
	return 0;
}

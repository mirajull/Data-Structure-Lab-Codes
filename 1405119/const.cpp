#include<iostream>
using namespace std;

class myclass{
    int a;
public:
    myclass();
    void show();
};
myclass::myclass()
{
    cout<<"In constructor"<<endl;
    a=10;
}
void myclass::show()
{
    cout<<a<<endl;
}
int main()
{
    myclass on;

    return 0;
}

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
class strtype{
    char*p;
    int len;
public:
    strtype(char*ptr);
    ~strtype();
    void show();
};
strtype::~strtype()
{
    cout<<"freeing......"<<endl;
    free(p);
}
void strtype::show()
{
    cout<<p<<"  -length: "<<len<<endl;

}
strtype::strtype(char*ptr)
{
    len=strlen(ptr);
    p=(char*)malloc(len+1);
    if(!p)
    {
        cout<<"allocation error"<<endl;
        exit(1);
    }
    strcpy(p,ptr);
}
int main()
{
    strtype s1("This is test"),s2("i like C++");
    s1.show();
    s2.show();
    return 0;
}

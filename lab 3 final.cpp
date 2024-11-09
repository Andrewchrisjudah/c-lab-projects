#include<iostream>
#include<conio.h>
using namespace std;
class businfo{
    int busid;
    string bustype;
    int capacity;
    int POS;
    public:
    	businfo()
    	{
    		busid=0;
    		bustype="";
    		capacity=0;
		}
businfo(int busid,string bustype="AC",int capacity=90,int POS= 1500)
{
    this->busid=busid;
    this->bustype=bustype;
    this->capacity=capacity;
    this->POS=POS;
}
void display()
{
    cout<<"Bus Id:" <<busid<<endl<<"capacity="<<capacity<<endl<<"price of the seat= "<<POS;
}
};
int main()
{
    businfo x1(10,"AC");
    businfo x2(2);
    x2.display();
	businfo z(x1);
    z.display();
    }

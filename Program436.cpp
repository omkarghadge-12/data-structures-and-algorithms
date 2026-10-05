#include<iostream>
using namespace std;

class Arithmatic
{
    private :
        int no1, no2;

    public :
        Arithmatic(int A , int B);
        
        int Addition();

        int Substraction();
};

Arithmatic :: Arithmatic(int A , int B)
{
    this->no1 = A;
    this->no2 = B;
}
int Arithmatic :: Addition()
{
    return no1 + no2;
}
int Arithmatic ::   Substraction()
{
    return no1 - no2;
}


int main()
{
    Arithmatic aobj(11 , 10);

    cout<<aobj.Addition()<<"\n";
    cout<<aobj.Substraction()<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<long long>_inv{1,1};
template<int M=1000000007,int N=0>
struct modInt
{
    long long val=0;
    modInt()
    {
        val=0;
        if(_inv.size()<=N)
        {
            int from=_inv.size();
            _inv.resize(N+1);
            for(int i=from;i<=N;i++)
            {
                _inv[i]=M-M/i*_inv[M%i]%M;
            }
        }
    }
    modInt(long long a)
    {
        val=(a)%M;
        val=(val+M)%M;
        if(_inv.size()<=N)
        {
            int from=_inv.size();
            _inv.resize(N+1);
            for(int i=from;i<=N;i++)
            {
                _inv[i]=M-M/i*_inv[M%i]%M;
            }
        }
    }
    void operator=(long long a){val=a;val=(val+M)%M;}
    long long& operator*(){return val;}
    modInt operator+(modInt b){return val+b.val;}
    modInt operator-(modInt b){return val-b.val;}
    modInt operator*(modInt b){return val*b.val;}
    modInt operator/(modInt b){return val*_inv[b.val];}
    explicit operator bool(){return bool(val);}
    bool operator==(modInt b)const{return val==b.val;}
    bool operator>(modInt b)const{return val>b.val;}
    bool operator<(modInt b)const{return val<b.val;}
    bool operator<=(modInt b)const{return val<=b.val;}
    bool operator>=(modInt b)const{return val>=b.val;}
    modInt operator++(){return *this=*this+1;}
    modInt operator--(){return *this=*this-1;}
    modInt operator++(int){auto tmp=*this; *this=*this+1;return tmp;}
    modInt operator--(int){auto tmp=*this; *this=*this-1;return tmp;}
    void operator+=(modInt a){*this=*this+a;}
    void operator-=(modInt a){*this=*this-a;}
    void operator*=(modInt a){*this=*this*a;}
    void operator/=(modInt a){*this=*this/a;}
    modInt operator^(modInt a)
    {
        if(a==0)
        {
            return 1;
        }
        modInt p=*this^(a.val/2);
        if(a.val%2==1)
            return p*p*val;
        else
            return p*p;
    }
    friend ostream& operator<<(ostream & os,modInt  a){return os<<a.val;}
    friend istream& operator>>(istream& is,modInt &a)
    {
    long long tm;
    is>>tm;
    a=tm;
    return is;
    }
};
int main()
{
    //Tutorial to use the modInt
    //The first argument of templete takes a constant integer which is the modulo the default is 1000000007 and second one is the maximum number by which 
    //we could have to divide  not the second value should be in range such that it can come in array, at max maybe 10^6;
    modInt<> a;
    cout<<a<<"\n";
    modInt<59> b;
    cout<<b<<endl;
    modInt<107,100>c=345996976;
    cout<<c<<" \n";

    cout<<"Static trial ends\n";
    //second argument is the number which takes value so that inverse can be found for division opertion
    cout<<"Enter how many element do you need for trial\n";
    int n;
    cin>>n;
    vector<modInt<107,110>>arr(n);
    for(auto &it:arr)
        cin>>it;
    //simple transversal
    for(modInt<> i=arr.size();i--;)
        cout<<arr[*i]<<" ";//*i returns integer value of i
    cout<<endl;

    //finding power(i,i+1) 
    for(auto it:arr)cout<<(it^(it+1))<<" ";
    cout<<endl;

    //updating values

    for(int i=1;i<arr.size();i++)
    {
        arr[i]+=3;
        ++arr[i];
        arr[i]-=arr[i-1];
        arr[i]/=8;//note it is inverse modulo division
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    //division if divisor is greater than 10^6 using little fermat theorem
    cout<<arr[0]*(modInt<107,110>(1000000067)^(107-2))<<endl;
    //factorial
    cout<<"Factorial upto 100 mod 107\n";
    for(modInt<107> i=1,prev=1;i<100;i++)
    {
        prev*=i;
        cout<<prev<<" ";
    }
    cout<<endl;

    // inveres Factorial 
    for(modInt<107,100> i=1,prev=1;i<100;++i)
    {
        prev/=i;
        cout<<prev<<" ";
    }
    //many more you can Explore your self
}

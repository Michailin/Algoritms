#include <iostream>
#include <utility>
long long extEuclid(unsigned long long a,unsigned long long b,std :: pair <long long ,long long > & answer)
{
    std :: pair <long long ,long long> tmp;
    std :: pair <long long , long long> r1(1,0);
    std :: pair <long long , long long> r2(0,1);
    while(b)
    {
        unsigned long long r = a%b;
        unsigned long long q = (a - r)/b;
        tmp.first = r1.first - q*r2.first;
        tmp.second = r1.second - q*r2.second;
        r1 = r2;
        r2 = tmp;
        a = b;
        b = r;
    }
    answer = r1;
    return a;
}
int main()
{
    long long a,b;
    std :: cin >> a >> b;
    std :: pair <long long,long long> answer;
    long long nod;
    nod = extEuclid(a,b,answer);
    std :: cout << nod << " nod " << std :: endl;
    std :: cout << nod << " = " << a << " * " << answer.first << " + " << b << " * " << answer.second;
}

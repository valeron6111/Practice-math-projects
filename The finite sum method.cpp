//The finite sum method, Andrei Bakanov
#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;

const int N=10;

void fun(double x, double e, double &s1, double &s2)
{
double u1;
int k1=0;

u1=1;
s1=0;

while( fabs(u1) > e)
	{
		s1+=u1;
		u1=(-x)/((2*x+2)*(2*x+3));
		k1++;
	}

double u2;
int k2=1;
u2=-1/6;
s2= 0;

while( fabs(u2) > e)
	{
		s2+=u2;	
		u2=(k2+1)/((2*x+2)*(2*x+3));
		k2++;
		}

}

int main()
{
double s1, s2, x[N], f[N] ,fp[N], e=0.0001, h, a = 0.1,b= 1.7;
h=(b-a)/(N-1);

cout<<"	x" << "	f" << "	ft" << "	fp" << "	fpt" << endl;

for(int i=0;i<=N; i++)
	{
		x[i]=a+(h*i);
		fun(x[i],e,s1,s2);
		f[i]=s1;
		fp[i]=s2;
		cout<<fixed<<setprecision(5)<<x[i]<<" " <<f[i]<<" "<< (1./sqrt(x[i]))*sin(sqrt(x[i]))<<" "<<fp[i]<<" "<< ((cos(sqrt(x[i]))/(2*x[i]))-((sin(sqrt(x[i])))/(pow(2*x,3)))) <<endl;
	}

return 0;
}
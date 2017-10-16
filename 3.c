#include <stdio.h>
#include <math.h>
#define PI 3.141592
struct functionVars{
    double c,m,d,eval,t,res;
};
struct signal
{
    struct functionVars v;
    float T,Vp,Vpp,VRms,a,b;
}s;
double f(double x)
{
    return pow(sin(x),2);
}
double integrate(double a,double b)
{
	 s.v.res=0;
	 s.v.t=0.001;
	//printf("c\t c+t\t f(c)\t f(c+t)\t m\t eval\t res\n");
	for(int i=a;i<(b*1000);i++)
	{
	     s.v.c=(double)i/1000;
		 s.v.m= (	f(s.v.c+s.v.t)-f(s.v.c)	) / (	(s.v.c+s.v.t)-(s.v.c)	);
		 s.v.d= (-s.v.m*s.v.c)+f(s.v.c);
		 s.v.eval= (  (s.v.m*pow(s.v.c+s.v.t,2)/2) + s.v.d*(s.v.c+s.v.t)  )- (  ((s.v.m*pow(s.v.c,2))/2) + s.v.d*s.v.c   );
		s.v.res+=s.v.eval;
		//printf("%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n",c,c+t,f(c),f(c+t),m,eval,res);
	}
	return s.v.res;
}

int main()
{
    s.a=0;
    s.b=2*PI;
    s.T=2*PI;
    s.Vp=5;
    s.VRms=sqrt(   (s.Vp*s.Vp/s.T) * integrate(s.a,s.b)   );
    printf("%f",s.VRms);
}

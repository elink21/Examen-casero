#include <stdio.h>
#define SIZE 100
double x[SIZE]={0};

void sortArray(double x[SIZE],int n)
{
    float aux;
    for(int i=0;i<100;i++)
    {
        for(int j=i+1;j<100;j++)
        {
            if(x[j]>x[i])
            {
                aux=x[j];
                x[j]=x[i];
                x[i]=aux;
            }
        }
    }
}

struct range
{
    int li;
    int ls;
}r;

double filterChaos(double pv,double B)
{
    double a=(B*pv)-B*pow(pv,2);
    return a;
}

double myChaos(int li, int ls)
{
    double rand_range;
    rand_range=rand()%10000;
    rand_range/=10000;
    return (li+  (rand_range*(ls-li)));
}

void printArray(double x[SIZE],int n)
{
    printf("N\n");
    for(int i=0;i<n;i++)
    {
        printf("%f\n",x[i]);
    }
}

int main()
{
    int n=100;
    srand(time(NULL));
    r.li=0;
    r.ls=100;

    for(int i=0;i<n;i++)
    {
        //double pv=myChaos(r.li,r.ls);
        x[i]=myChaos(r.li,r.ls);
       // x[i]=filterChaos(pv,x[i])*10;
        //x[i]=filterChaos(pv,x[i]);
    }
    sortArray(x,n);

    //printArray(x,y,z,n);
    printArray(x,n);
}

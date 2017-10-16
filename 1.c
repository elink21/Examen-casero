#include <stdio.h>
#define INF 9e9
#define SIZE 100

struct stackData{
    float monthTemperature[SIZE];
    int top;
}stack={{INF},0};

struct fileData{
    char name[50];
    char mode[4];
}file={"changes.data","w+"};

struct GlobalwheatherFeatures{
    float avgTemp,maxTemp,minTemp,sum;
}w;

int isEmpty()
{
    return stack.top==0;
}
int isFull()
{
    return stack.top==SIZE-1;
}

float back()
{
    if(!isFull() && !isEmpty() ) return stack.monthTemperature[stack.top];
}
float pop()
{
    if(!isEmpty())
    {
        stack.monthTemperature[stack.top--]=INF;
    }
}

float push(float data)
{
    if(!isFull())
    {
        stack.monthTemperature[++stack.top]=data;
    }
}

// Stack end//
float toFar(float c)
{
    return (c*1.8)+32;
}

float toCelcius(float f){
    return (f-32)/1.8;
}

void writeData(int isCelsi   us)
{
   FILE *f;
   f=fopen(file.name,file.mode);
   w.maxTemp=-INF;w.minTemp=INF;w.avgTemp=0;w.sum=0;
   float n=0;
   while(!isEmpty())
   {
       w.sum+=back();
       if(w.maxTemp<back())w.maxTemp=back();
       if(w.minTemp>back())w.minTemp=back();
       if(isCelsius){ fprintf(f,"%.2f grados C\tMes %d\n",back(),stack.top);}
       else fprintf(f,"%.2f grados F\tMes %d\n",toFar(back()),stack.top);
        pop();
        n++;
   }
    if(isCelsius){ fprintf(f,"--El promedio de temperatura fue %f Celsius, el minimo fue %f Celsius y el maximo fue %f Celsius--",
                          w.sum/n,w.minTemp,w.maxTemp);}
   else fprintf(f,"--El promedio de temperatura fue %f Fareheit, el minimo fue %f Farenheit y el maximo fue %f Farenheit--",
                          toFar(w.sum/n),toFar(w.minTemp),toFar(w.maxTemp));
   fclose(f);
}
int main()
{
    float aux;
    int option;
    for(int i=0;i<12;i++)
    {
        printf("Ingrese la temperatura del mes %d (Celsius): ",i+1);
        scanf("%f",&aux);
        push(aux);
    }
    printf("Deseas que los datos se impriman en Farenheit o Celsius? (0=F ,1=C): ");
    scanf("%f",&option);
    writeData(option);
}

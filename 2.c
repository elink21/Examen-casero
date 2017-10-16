#include <stdio.h>

struct Event{
	float day,month,year;
	long uniqueId;
	double weight;
};

struct Weeding
{
	struct Event event;
	char  name1[50];
	char  name2[50];
}w[100];

struct Born
{
	struct Event event;
	char name[50];
}b[100];

struct Death
{
	struct Event event;
	char name[50];
}d[100];

struct Separation{
	struct Event event;
	char name1[50];
	char name2[50];
}s[100];

void sort(int iw,int id)
{
    for(int i=0;i<iw;i++)
    {
        for(int j=i+1;j<iw;j++)
        {
            struct Weeding aux;
            if(w[i].event.weight>w[j].event.weight)
            {
                aux=w[i];
                w[i]=w[j];
                w[j]=aux;
            }
        }
    }
     for(int i=0;i<id;i++)
    {
        for(int j=i+1;j<id;j++)
        {
            struct Death aux;
            if(d[i].event.weight>d[j].event.weight)
            {
                aux=d[i];
                d[i]=d[j];
                d[j]=aux;
            }
        }
    }
}

void printData(int is,int iw,int ib,int id)
{
    for(int i=0; i<ib;i++)
    {
        printf("Nacimiento de %s el %.0f/%.0f/%.0f con clave %d\n",b[i].name,b[i].event.day,
               b[i].event.month,b[i].event.year,b[i].event.uniqueId);
    }
    for(int i=0; i<id;i++)
    {
        printf("Defuncion de %s el %.0f/%.0f/%.0f con clave %d\n",d[i].name,d[i].event.day,
               d[i].event.month,d[i].event.year,d[i].event.uniqueId);
    }
    for(int i=0; i<iw;i++)
    {
        printf("Matrimonio de %s y %s, el %.0f/%.0f/%.0f con clave %d\n",w[i].name1,w[i].name2,w[i].event.day,
               w[i].event.month,w[i].event.year,w[i].event.uniqueId);
    }
     for(int i=0; i<is;i++)
    {
        printf("Separacion de %s y %s, el %.0f/%.0f/%.0f con clave %d\n",s[i].name1,s[i].name2,s[i].event.day,
               s[i].event.month,s[i].event.year,s[i].event.uniqueId);
    }

}

int main()
{

	int n,option,iw=0,ib=0,is=0,id=0;
	long incrementKey=0;
    printf("Ingrese el numero de eventos a registrar\n");
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		printf("Que tipo de evento se registrara?\n");
		printf("1-Boda 2-Nacimiento 3-Divorcio 4-Defuncion\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Ingrese la fecha en formato DD MM AA(solo numeros separados): ");
				scanf("%f%f%f",&w[iw].event.day,&w[iw].event.month,&w[iw].event.year);
				printf("Ahora ingrese el primer nombre de cada persona separados por espacios:\n");
				scanf("%s%s",&w[iw].name1,&w[iw].name2);
                w[iw].event.uniqueId=incrementKey++;
                w[iw].event.weight=(w[iw].event.day/100)+(w[iw].event.month/10)+w[iw].event.year*10;
				iw++;
				break;
			case 2:
				printf("Ingrese la fecha en formato DD MM AA(solo numeros separados): ");
				scanf("%f%f%f",&b[ib].event.day,&b[ib].event.month,&b[ib].event.year);
				printf("Ahora ingrese el primer nombre de la persona:\n");
				scanf("%s",&b[ib].name);
				b[ib].event.uniqueId=incrementKey++;
				b[ib].event.weight=(b[ib].event.day/100)+(b[ib].event.month/10)+b[ib].event.year*10;
				ib++;
				break;
			case 3:
				printf("Ingrese la fecha en formato DD MM AA(solo numeros separados): ");
				scanf("%f%f%f",&s[is].event.day,&s[is].event.month,&s[is].event.year);
				printf("Ahora ingrese el primer nombre de cada persona separados por espacios:\n");
				scanf("%s%s",&s[is].name1,&s[is].name2);
				s[is].event.uniqueId=incrementKey++;
				s[is].event.weight=(s[is].event.day/100)+(s[is].event.month/10)+s[is].event.year*10;
				is++;
				break;
			case 4:
				printf("Ingrese la fecha en formato DD MM AA(solo numeros separados): ");
				scanf("%f%f%f",&d[id].event.day,&d[id].event.month,&d[id].event.year);
				printf("Ahora ingrese el primer nombre de la persona:\n");
				scanf("%s",&d[id].name);
				d[id].event.uniqueId=incrementKey++;
				d[id].event.weight=(d[id].event.day/100)+(d[id].event.month/10)+d[id].event.year*10;
				id++;
				break;
		}
	}
	sort(iw,id);
	printData(is,iw,ib,id);
}

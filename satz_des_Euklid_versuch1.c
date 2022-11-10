#include <stdio.h>
#include <math.h>
//primzahl finden algorithm versuch
// 2 3 5 7 11 13 17
/*
    2*3*5= 30 +1 =31
    neue primzahl
    2 ist vorher angegeben.
    x darf nur durch sich selbst oder durch eins geteilt werden.
*/

/* for FUNC primzahl_ob_2_geteilt
    die Primzahlen darf nur durch sich selbst oder
    durch eins geteilt werden.


*/
int ob_primzahl(int num1)
{
//2den n-1 e kadar olan sayýlara kalansýz bölünmüyorsa asaldýr.
    int TRUE=1;
    int FALSE=0;
    for(int i=2;i<num1;i++)
    {
        if(num1%i==0)
        {
            //printf("Diese Zahl wurde an %d geteilt.",i);
            //printf("Das ist keine Primzahl.\n"); //kalansýz bölünüyorsa asal deðildir.
            return FALSE;
        }
    }
    //printf("das ist eine Primzahl.\n");
    return TRUE;
}

int closest_primzahlen(int num1)
{
    /* wegen Satz von Jitsuro Nagura
    wenn x!<25 ist, da gibt's immer einen primzahl
    zwischen x und 6*x/5
    */
    if(num1<25)     // 2 3 5 7 11 13 17 19 23 "25" 29
    {
        int p1=num1-1;
        int p2=num1+1;

        int value1=5,value2=5;
        start:
        value1=ob_primzahl(p1); //donut eðer prim ise 1 versin         // bu kodlarý main içine atmam gerekebilir fonksiyon içinde
        value2=ob_primzahl(p2); //donut eðer prim ise 1 versin         // fonksiyon çaðýrmak hata verir ise
        while(value1!=1 || value2!=1)
        {
        if(value1==1 && value2!=1)
        {
            p2++;
            value2=ob_primzahl(p2);
            goto start;
        }
        else if(value1!=1 && value2==1)
        {
            p1--;
            value1=ob_primzahl(p1);
            goto start;
        }
        else if(value1!=1 && value2!=1)
        {
            p1--;
            p2++;
            value1=ob_primzahl(p1);
            value2=ob_primzahl(p2);
            goto start;
        }
        }
        if(value1==1 && value2==1)
        {
            printf("%d %d %d",p1,num1,p2);
        }
    }
    else            //num1>=25  sonraki primzahl x ve 6x/5 arasýnda olacak.
    {

        int max=num1+1;
        int min=num1-1;
        int vmin=5,vmax=5;

        //once min icin.
        while(vmin!=1 || vmax!=1)
        {
                vmin=ob_primzahl(min);   //eðer min primzahl ise 1 verecek. deðilse 0.
                vmax=ob_primzahl(max);   //eðer max primzahl ise 1 verecek. deðilse 0.
            if(vmin!=1 || vmax!=1)
            {
               if(vmin!=1 && vmax!=1)
               {
                    min--;
                    max++;
               }
               else if(vmin==1 && vmax!=1)
               {
                   max++;
               }
               else if(vmin!=1 && vmax==1)
               {
                   min--;
               }
            }
        }
        printf("%d %d %d\n",min,num1,max);
    }




}



int main()
{
    int n=0,sum=0,x=2;
    const int SIZE=x;
    printf("\n\tBitte geben Sie eine Zahl\n");
    printf("\n\tum zu finden ob es eine Primzahl ist.\n");
    scanf("%d",&n);
    printf("\n");
    //ob_primzahl(n);
    //printf("%d",ob_primzahl(n));
    closest_primzahlen(n);
    /*
    for(int i=1;i <= SIZE;i++){

        printf(" %d \n",i);
    }*/
    return 0;
}

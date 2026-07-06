/*

    freopen("test.in","r",stdin);
    freopen("test1.out","w",stdout);

*/
#include<cstdio>
#include<cstdlib>
#include<iostream>

int main()
{
    int tmp=0;
    for(int i=1;i<=10000;i++)
    {
        system("./data");
        system("./A");
        system("./AA");

        // if(i/100>tmp) {printf("-- %d --\n",i);tmp=i/100;}
        if(system("diff -b test1.out test2.out"))
        {
            printf("wrong in --> %d \n",i);
            break;
        }
        printf("process %d is correct\n",i);
    }
    return 0;
}



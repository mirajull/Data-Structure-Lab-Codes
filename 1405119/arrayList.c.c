#include<stdio.h>
#include<stdlib.h>

struct kop{
    int id;
    int frequency;
};
//struct kop*joss;
int currpos=0;
void print(struct kop*joss)
{
    int i=0;
    while(joss+i)
    {
        printf("<%d, %d> ",(joss+i)->id,(joss+i)->frequency);
    }
}
void insert(int x,struct kop*joss)
{
    int f=0,i=0;
    while(joss+i)
    {
        if((joss+i)->id=x){
            (joss+i)->frequency++;
            f++;
        }
    }
    if(f==0)
    {
        (joss+currpos)->id=x;
        (joss+currpos)->frequency=1;
        currpos++;
    }
    print(joss);
}
void Delete(int x,struct kop*joss)
{
    int i=0,f=0,j;
    while(joss+i)
    {
        if((joss+i)->id=x){
            (joss+i)->frequency--;
            if( (joss+i)->frequency==0){
                j=i;
                while(joss+i+1)
                {
                    *(joss+i)=*(joss+i+1);
                }
            }
        f++;
        }
    }
    if(f==0)
    {
        printf("Not Found");
    }
}
void Find(int x,struct kop*joss)
{
    int i=0;
    if((joss+i)->id=x)
    {
        printf("frequency of data with id = %d is %d",(joss+i)->id,(joss+i)->frequency);
    }
    else{
        printf("frequency of data with id = %d is %d",(joss+i)->id,0);
    }
}
void Reverse(struct kop*joss)
{
    int i=0;
    struct kop temp;
    while(joss+i)
    {
        temp=*(joss+i);
        *(joss+i)=*(joss+i+1);
        *(joss+i+1)=temp;
    }
    print(joss);
}
struct kop*reallocate(struct kop*p,int n)
{
    int i=0;
    struct kop*q;
    q=(struct kop*)malloc(n*sizeof(struct kop));
    while(p+i)
    {
        *(q+i)=*(p+i);
    }
    currpos=i;
    free(p);
    return q;
}

int main()
{
    int n=1,x,i=0;
    struct kop*p;
    p=(struct kop*)malloc(sizeof(struct kop));
    while(1)
    {
        char ch;
        scanf("%c",&ch);
        if(ch=='T')break;
        i++;
        if(ch!='R')
        {
            scanf(" %d",&x);
            getchar();
            if(ch=='I')
            {
                insert(x,p);
            }
            else if(ch=='F')
            {
                Find(x,p);
            }
            else if(ch=='D')
            {
                Delete(x,p);
            }
        }
        else{
            if(ch=='R')
            {
                Reverse(p);
            }
        }
        printf("\n");
        n=n*2;
        //maxsize=maxsize+n;
        if(i<=n)
        {
            p=reallocate(p,n);
            i=0;
        }
    }
    free(p);
    return 0;
}

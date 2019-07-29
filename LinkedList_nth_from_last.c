#include<stdio.h>
#include<stdlib.h>

struct node *insert(struct node *start,int data);
struct node *create_node(int data);
struct node
{
    int info;
    struct node *link;
};
int main()
{
    int data,count=1,ch,n;
    struct node *start=NULL;
    while(1)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d",&data);
        start=insert(start,data);
        printf("\nEnter '0' to continue enter any other key to quit: ");
        scanf("%d",&ch);
        if(ch!=0)
            break;
    }
    struct node *t1=start,*t2=start;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    while(count!=n)
    {
        t1=t1->link;
        count++;
    }
    while(t1->link!=NULL)
    {
        t1=t1->link;
        t2=t2->link;
    }
    printf("\n%d",t2->info);
    return 0;
}
struct node *create_node(int data)
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->info=data;
    t->link=NULL;
    return t;
}
struct node *insert(struct node *start,int data)
{
    if(start==NULL)
    {
        start=create_node(data);
        return start;
    }
    struct node *t=start,*temp;
    while(t->link!=NULL)
        t=t->link;
    temp=create_node(data);
    t->link=temp;
    return start;
}

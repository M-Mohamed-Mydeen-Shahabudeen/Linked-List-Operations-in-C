#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *head, *p, *old, *n, *Newnode,*s;
//create head node
int createHead()
{
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &head->data);
    head->next = NULL;
    old = head;

}
//create N node
int CreateN()
{
    int i, count;
    printf("Enter Count: ");
    scanf("%d", &count);


    for (i = 1; i <= count; i++)
    {
        n = (struct node *)malloc(sizeof(struct node));
        printf("Enter N Data: ");
        scanf("%d", &n->data);
        n->next = NULL;
        old->next = n;
        old = n;
    }
}
//insert at beginning
void InsertAtBegin()
{
    printf("\n--Insert At Begin--\n");
    Newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Element to Insert: ");
    scanf("%d", &Newnode->data);
    Newnode->next = head;
    head = Newnode;
}
//insert at middle
void InsertAtMiddle()
{
    int i, pos;
    printf("\n--Insert At Middle--\n");
    printf("\nEnter Position: ");
    scanf("%d", &pos);
    Newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Element to Insert at Middle: ");
    scanf("%d", &Newnode->data);
    Newnode->next = NULL;
    p=old=head;
    for(i=1; i<pos; i++)
    {
        old=p;
        p=p->next;
    }
    old->next=Newnode;
    Newnode->next=p;
}
//Insert at End
int InsertAtEnd()
{
    printf("\n--Insert At End--\n ");
    Newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data:");
    scanf("%d",&Newnode->data);
    Newnode->next=NULL;
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=Newnode;

}
//Delete at Beginning
int DeleteAtBegin()
{
    p=head;
    head=head->next;
    free(p);
    return 0;


}
//Delete at Middle
int DeleteAtMiddle()
{

    printf("\n--Deletion From Middle--\n");
    p=old=head;
    int pos,i;
    printf("\nEnter Position:");
    scanf("%d",&pos);
    for(i=1; i<pos; i++)
    {
        old=p;
        p=p->next;


    }
    s=p->next;
    old->next=s;
    printf("Deleted Element: %d",p->data);
    free(p);


}
//Delete At End
int DeleteAtEnd()
{
    p=old=head;
    while(p->next!=NULL)
    {
        old=p;
        p=p->next;


    }
    old->next=NULL;
    free(p);


}
//Display
void display()
{
    p = head;
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
int  count()
{
    int counter=0;
    p=head;
    while(p!=NULL)
    {
        counter++;
        p=p->next;
    }
    printf("Number Of Node In Linked List : %d",counter);
}
int sum()
{
    int sums=0,a;
    p=head;
    while(p!=NULL)
    {
       a=p->data;
       sums+=a;
       p=p->next;

    }
    printf("Sum of Linked List: %d",sums);
    return 0;


}

int main()
{
    int choice;

    do
    {
        printf("\n 1.Create Head Node");
        printf("\n 2.Create N Nodes");
        printf("\n 3.Insert At Begin");
        printf("\n 4.Insert At Middle");
        printf("\n 5.Insert At End");
        printf("\n 6.Delete At Begin");
        printf("\n 7.Delete At Middle");
        printf("\n 8.Delete At End");
        printf("\n 9.Display");
        printf("\n 10.Count");
        printf("\n 11.Sum");
        printf("\n 0.Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createHead();
            break;
        case 2:
            CreateN();
            break;
        case 3:
            InsertAtBegin();
            break;
        case 4:
            InsertAtMiddle();
            break;
        case 5:
            InsertAtEnd();
            break;
        case 6:
            DeleteAtBegin();
            break;
        case 7:
            DeleteAtMiddle();
            break;
        case 8:
            DeleteAtEnd();
            break;
        case 9:
            display();
            break;
        case 10:
            count();
            break;
        case 11:
            sum();
            break;
        case 12:
            printf("Exiting...\n");
            break;
        default:
            printf("Enter a valid choice!\n");
        }
    }
    while (choice != 0);

    return 0;
}


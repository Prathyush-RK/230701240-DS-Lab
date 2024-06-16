#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int pow;
    struct node *next;
};

struct node* create_node()
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    if(p!=NULL)
    { 
       printf("Enter the coefficient:-");
       scanf("%d",&p->coeff);
      printf("Enter the power of x:-");
      scanf("%d",&p->pow);
      p->next=NULL;
    }
    return p;
}

struct node* create_list(int n)
{
    struct node *temp, *L1,*new;
    L1 = (struct node*)malloc(sizeof(struct node));
    temp =L1;
    while(n--)
    { 
        new = create_node();
        new->next = NULL;
 
        temp->next = new;
        temp = new; 
     }
     temp->next=NULL;
     return L1;
}

void display(struct node *L)
 {
    struct node *p;
    p= L->next;
    while(p!=NULL)
    {
       printf("%dx^",p->coeff);
       printf("%d",p->pow);
       if(p->next!=NULL)
       {
        printf("+");
       }
       p = p->next;
    }
    printf("\n");
 }

struct node* addition(struct node *L1,struct node *L2)
 {
    struct node *p1,*p2,*new, *L3,*temp;
   
    L3 = (struct node*)malloc(sizeof(struct node));
    L3->next=NULL;
    temp = L3;
    p1=L1->next;
    p2 = L2->next;
 
    while(p1!=NULL && p2!=NULL )
    {
         if(p1->pow == p2->pow)
         {
             new = (struct node*)malloc(sizeof(struct node));
             new->coeff = p1->coeff+p2->coeff;
             new->pow = p1->pow;
             p1 = p1->next;
             p2 = p2->next;
         }
         else if(p1->pow > p2->pow)
         { 
             new = (struct node*)malloc(sizeof(struct node));
             new->coeff = p1->coeff;
             new->pow = p1->pow;
             p1 = p1->next;
         }
         else if(p1->pow < p2->pow)
         { 
             new = (struct node*)malloc(sizeof(struct node));
             new->coeff = p2->coeff;
             new->pow = p2->pow;
             p2 = p2->next;
         }
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
    }

    if(p1==NULL)
    {
        while(p2!=NULL)
        {
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = p2->coeff;

         new->pow = p2->pow;
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
          p2 = p2->next;
        }
    }
     else if(p2==NULL)
    {
        while(p1!=NULL)
        {
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = p1->coeff;
         new->pow = p1->pow;
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
          p1 = p1->next;
        }
    }  
    return L3;
 }

struct node* subtraction(struct node *L1,struct node *L2)
 {
    struct node *p1,*p2,*new, *L3,*temp;
   
    L3 = (struct node*)malloc(sizeof(struct node));
    L3->next=NULL;
    temp = L3;
    p1=L1->next;
    p2 = L2->next;
 
    while(p1!=NULL && p2!=NULL )
    {
      if(p1->pow == p2->pow)
     {
        new = (struct node*)malloc(sizeof(struct node));
         new->coeff = p1->coeff - p2->coeff;
         new->pow = p1->pow;
         p1 = p1->next;
          p2 = p2->next;
         }
     else if(p1->pow > p2->pow)
     {  new = (struct node*)malloc(sizeof(struct node));
        new->coeff = p1->coeff;
         new->pow = p1->pow;
          p1 = p1->next;
         }
     else if(p1->pow < p2->pow)
     {  new = (struct node*)malloc(sizeof(struct node));
        new->coeff = -p2->coeff;
         new->pow = p2->pow;
          p2 = p2->next;
     }
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
    }

    if(p1==NULL)
    {
        while(p2!=NULL)
        {
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = p2->coeff;
         new->pow = p2->pow;
 
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
          p2 = p2->next;
        }
    }
     else if(p2==NULL)
    {
        while(p1!=NULL)
        {
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = p1->coeff;
         new->pow = p1->pow;
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
          p1 = p1->next;
        }
    }
    return L3;
 }

struct node* multiplication(struct node *L1,struct node *L2)
 {
    struct node *p1,*p2,*new, *L3,*temp;
   
    L3 = (struct node*)malloc(sizeof(struct node));
    L3->next=NULL;
    temp = L3;
    p1=L1->next;
    p2 = L2->next;
    while(p1!=NULL)
    {  
        p2 = L2->next;
 
        while(p2!=NULL)
        { 
         new = (struct node*)malloc(sizeof(struct node));
         new->coeff = p2->coeff*p1->coeff;
         new->pow = p1->pow+p2->pow;
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
         p2 =p2->next;
        }
        p1 = p1->next;
    }    
    return L3;
 }

struct node* add(struct node *l3)
{
    struct node *temp,*p,*ref;
    temp = l3->next;
    while(temp!=NULL)
    {
        p = temp->next;
        ref =temp;
        while(p!=NULL)
        {
            if(temp->pow==p->pow)
            {
                temp->coeff = temp->coeff + p->coeff;
                ref->next = p->next;
                free(p);
               p=ref->next;
           }
 
           else
           {
               ref=ref->next;
               p=p->next;
           }
     }
        temp = temp->next;
    }
    return l3;
}

int main()
{
    struct node *l1 , *l2,*la,*ls,*lm;
    int n;

    printf("Enter the polynomials in Descending order only");
    printf("\nNO. of terms in polynomial 1:-");
    scanf("%d",&n);
    l1 = create_list(n);

    printf("\nNO. of terms in polynomial 2:-");
    scanf("%d",&n);
    l2 = create_list(n);
    
    printf("L1=");
    display(l1);
    printf("L2=");
    display(l2);

    printf("\nThe Sum of the two polynomial is=");
    la=addition(l1,l2);
    display(la);
 

    printf("The difference of the two polynomial is=");
    ls=subtraction(l1,l2);
    display(ls);

    printf("The product of the two polynomial is=");
    lm=multiplication(l1,l2);
    lm=add(lm);
    display(lm);   

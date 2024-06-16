include <stdio.h>
#include <stdlib.h>

struct Node
{
    char sign;
    struct Node* next;
};

int priority(char sym)
{
    if(sym=='*'||sym=='/'||sym=='%')
    return 2;
    else if(sym=='+'||sym=='-')
    return 1;
    else
    return 0;
}

void push(struct Node* L,char sym)
{
    struct Node*n = (struct Node*) malloc(sizeof(struct Node));
    if(n!=NULL)
    {
        n->sign=sym;
        if(L->next!=NULL)
        {
            n->next=L->next;
            L->next=n;
        }
 
        else
        L->next=n;
    }
}

void pop(struct Node* L)
{
    if(L->next==NULL)
    printf("\n---Stack Underflow---\n");
    else
    {  
        struct Node* temp=L->next;
        L->next = L->next->next;
        free(temp);
    }
}

char peek(struct Node* L)
{
    if(L->next==NULL)
    return '\0';
    else
    return L->next->sign;
}

void display(struct Node* L)
{
    if(L->next==NULL)
    printf("\nThe stack is empty\n");
    else
    {
        struct Node* temp=L->next;
 
        while(temp!=NULL)
        {
            printf(" | %c |\n",temp->sign);
            temp=temp->next;
        }
    }
}

void check_precedence(struct Node*L,char in_exp)
{
    char in_stack=peek(L);
   
    if(priority(in_stack) >= priority(in_exp))
    {
        printf("%c",in_stack);
        pop(L);
        check_precedence(L,in_exp);
    }
   
    else
    {
        push(L,in_exp);
    }
}

int main() {
    char str[100],sym;
    struct Node list;
    list.next=NULL;
    printf("Enter expression containing lowercase alphabets and operators (+,-,*,/,%)\n");
    scanf("%[^\n]s",str);
 
    for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]>='a'&& str[i]<='z')||(str[i]>='A' && str[i]<='Z'))
        {
            printf("%c",str[i]);
        }
       
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
        {
            check_precedence(&list,str[i]);
        }
       
        else if(str[i]==' ')
        continue;
       
        else if(str[i]=='(')
        push(&list,str[i]);
       
        else if(str[i]==')')
        {
            while(peek(&list)!='(')
            {
                printf("%c",peek(&list));
                pop(&list);
            }
            pop(&list);
        }
        else
        {
            printf("Invalid expression ");
            break;
        }
    }
   
    while(list.next)
    {
        printf("%c",peek(&list));
        pop(&list);
    }
    return 0;
}

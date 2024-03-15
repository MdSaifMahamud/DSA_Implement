#include<bits/stdc++.h>
using namespace std;
#define STACK_MAX 10
// implement using linekd list
typedef struct Stack{
    typedef struct node{
        int val;
        node* next;
        node(int x){
            val=x;
            next=NULL;
        }
    };
    node* head=NULL;
    node* tail=NULL;
    void push(int x){
        node* p=new node(x);
        if(head==NULL){
            head=p;
            tail=p;
        }else{
            p->next=head;
            head=p;
        }
    }
    int pop(){
        if(head==NULL){
            return -1;
        }
        int x=head->val;
        head=head->next;
        return x;
    }
    void print(){
        node* p=head;
        if(p==NULL){
            return;
        }
        while(p){
            cout<<p->val<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    int size(){
        node* p=head;
        int c=0;
        while(p)
        {   
            c++;
            p=p->next;
        }
        return c;
    }
    int peek(){
        if(head==NULL){
            return -1;
        }
        return head->val;
    }
    bool isEmpty(){
        return head==NULL;
    }
};
// implement using array
typedef struct stack{                         // make a structure for stack
    int top=0;
    int data[STACK_MAX];
};

void push(stack *s,int item){       // push the element of the stack
    if(s->top < STACK_MAX){
        s->data[s->top]=item;
        s->top++;
    }else{
        printf("Stack is full\n");
        return;
    }
    return;
}
int pop(stack *s){          // return the last or top  element of the stack 
    int item=0;
    if(s->top==0){
        printf("Stack is empty ");
        return -1;
    }else{
        s->top--;
        item=s->data[s->top];
    }
    return item;
}
void print_stack(stack *S){     // print the stack
    for(int i=0;i<S->top;i++){
        cout<<S->data[i]<<" ";
    }
    cout<<endl;
    return ;
}
bool isempty(stack *S){         // return true if the stack is empty
    if(S->top==0){
        return true;
    }else{
        return false;
    }
}
int size(Stack *S){             // return the size of the stack
    return S->top;
}
int top_element(Stack *S){      //return the top element of the stack 
    return S->data[S->top-1];
}
int main()
{
    Stack A;
    A.push(1);
    A.push(3);
    A.push(2);
    A.push(4);
    A.print();
    cout<<A.pop()<<endl;
    A.print();
    return 0;
}
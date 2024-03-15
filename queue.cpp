#include<bits/stdc++.h>
using namespace std;
#define Q_size 5
typedef struct Queue{
    int data[Q_size+1];
    int head,tail;
    void enqueue(int item){
        if(tail==Q_size){
            cout<<"Queue is full "<<endl;
            return ;
        }
        data[tail] =item;
        tail++;
        return;
    }
    int dequeue(){
        if(head == tail){
            cout <<"Queue is empty"<<endl;
            return -1;
        }
        int item=data[head];
        head++;
        return item;
    } 
    void print_queue(){
        for(int i=head;i<tail;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
        return;
    }
};
typedef struct Queue_ll{
    typedef struct  node
    {
        node* next;
        int val;
    };
    node* head=NULL;
    node* tail=NULL;
    void enqueue(int x){
        node* p=new node();
        p->val=x;
        p->next=NULL;
        if(head==NULL){
            head=p;
            tail=p;
            return ;
        }else{
            tail->next=p;
            tail=p;
        }
    }
    bool isEmpty(){
        return head==NULL;
    }
    int dequeue(){
        if(!isEmpty()){
            int x=head->val;
            head=head->next;
            return x;
        }
    }
    int size(){
        int c=0;
        node* p=head;
        while(p){
            c++;
            p=p->next;
        }
        return c;
    }
};

typedef struct Cir_Queue{
    int data[Q_size];
    int front =-1;
    int rear=-1;

void enqueue(Cir_Queue* Q, int x){
    if((Q->rear+1)%Q_size==Q->front){
        cout<<"Full"<<endl;
        return;
    }
    if(Q->front==-1)Q->front=0;
    Q->rear=(Q->rear+1)%Q_size;
    Q->data[Q->rear]=x;
}
int dequeue(Cir_Queue* Q){
    if(Q->front==-1){
        cout<<"Empty"<<endl;
        return -1;
    }
    int r=Q->data[Q->front];
    if(Q->front==Q->rear){
        Q->front=Q->rear=-1;
    }else{
        Q->front=(Q->front+1)%Q_size;
    }
    return r;
}
void print(Cir_Queue* Q){
    for(int i=Q->front;i<=Q->rear;i=(i+1%Q_size)){
        cout<<Q->data[i]<<" ";
    }
    cout<<endl;
}
};
int main()
{
    // Queue a;
    // a.enqueue(1);
    // a.enqueue(2);
    // cout<<a.dequeue()<<endl;
    // a.print_queue();

}
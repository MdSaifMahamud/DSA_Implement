#include<bits/stdc++.h>
using namespace std;
typedef struct LinkedList{
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
    void insertFirst(int x){
        node* p=new node(x);
        if(head==NULL){
            head=p;tail=p;
        }else{
            p->next=head;
            head=p;
        }
        return ;
    }
    void insertLast(int x){
        node* p=new node(x);
        if(head==NULL){
            head=p;
            tail=p;
        }else{
            tail->next=p;
            tail=p;
        }
    }
    int deleteFirst(){
        if(head==NULL){
            return -1;
        }
        int x=head->val;
        node* p=head;
        head=head->next;
        free(p);    
        return x;
    }
    int deleteLast(){
        if(head==NULL){
            return -1;
        }
        node* p=head;
        while(p->next!=tail){
            p=p->next;
        }
        int x=p->next->val;
        node* tem=tail;
        tail=p;
        tail->next=NULL;
        free(tem);
        return x;
    }
    void printList(){
        if(head==NULL){
            cout<<"Empty List"<<endl;
            return;
        }
        node* p=head;
        while(p){
            cout<<p->val<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    void delete_specific(int x){        // delete the first x
        node* p = head;
        if(head==NULL){
            return;
        }
        if(head->val==x){
            head=head->next;
            return;
        }
        while(p->next->val!=x){
            p=p->next;
        }
        p->next=p->next->next;
        return;
    }
    LinkedList concatenate(LinkedList A,LinkedList B){
        A.tail->next=B.head;
        A.tail=B.tail;
        return A;
    }
    void insert_value_after_x(int x, int y){   // insert y after x // consider x is exist in list
        node* new_node=new node(y);      
        new_node->next=NULL;
        new_node->val=y;        
        node* p=head;               
        while(p->val != x){
            p=p->next;
        } 
        new_node->next=p->next;
        p->next=new_node;
        return;

    }
    void insert_value_before_x(int x,int y){    // insert y before x
        node* new_node=new node(y);      // allocate in heap
        new_node->next=NULL;
        new_node->val=y; 
        node* p=head;
        if(head->val==x){
            new_node->next=head;
            head=new_node;
            return;
        }
        while(p->next->val!=x){
            p=p->next;
        }
        new_node->next=p->next;
        p->next=new_node;
        return;
    }
    void Reverse(){
        if(head==NULL){
            return ;
        }
        int x=deleteFirst();
        Reverse();
        insertLast(x);
    }
    void reversePrint(node* h){
        if(h==NULL){
            return;
        }
        reversePrint(h->next);
        cout<<h->val<<" ";
    }
    void insert_specific_index(int a,int x){// for 1 base  indexing

        node* new_node=new node(x);
        if(a==1){
            new_node->next=head;
            head=new_node;
            return;
        }
        node* p=head;
        for(int i=1;i+1<a;i++){
            p=p->next;
        }
        new_node->next=p->next;
        p->next=new_node;
    }
    void insert_decending_sorted_list(int x){
        node* p=head;
        node* Node=new node(x);
        if(head==NULL){
            head=Node;
            tail=Node;
            return;
        }
        if(head->val < x){
            Node->next = head;
            head = Node;
            return;
         }
         while(p->next != NULL){
            if(p->next->val < x){
                Node->next=p->next;
                p->next=Node;
                return;
            }else{
                p=p->next;
            }
         }
         p->next=Node;
        
    }
    void insert_sorted_list(int x){
        node* Node=new node(x);
        node* p=head;
        if(head==NULL){
            head=Node;
            tail=Node;
            return;
        }
        if(head->val > x){
            Node->next = head;
            head = Node;
            return;
        }
         while(p->next != NULL){
            if(p->next->val > x){
                Node->next=p->next;
                p->next=Node;
                return;
            }else{
                p=p->next;
            }
         }
         p->next=Node;
       
    }
    void reverse_list_iterative(){
        if(head==NULL || head->next==NULL){
            return;
        }
        node* curr_node=head->next;
        node* prev_node=head;
        while(curr_node){
            node* next_node=curr_node->next;
            curr_node->next=prev_node;
            prev_node=curr_node;
            curr_node=next_node;
        }
        head->next=NULL;
        head=prev_node;
    } 

};
int main()
{
    LinkedList A,B;   
    // A.insertFirst(1);
    // A.insertFirst(4);
    // A.insertFirst(3);
    // A.insertFirst(2);
    // A.insertLast(1);
    // A.insertLast(2);
    // A.insertLast(3);
    // A.insertLast(4);
    // A.insertLast(5);
    // A.insert_decending_sorted_list(4);
    // A.insert_decending_sorted_list(5);
    // A.insert_decending_sorted_list(4);
    // A.insert_decending_sorted_list(4);
    // A.insert_decending_sorted_list(21);
    // A.insert_decending_sorted_list(3);
    A.insert_sorted_list(1);
    A.insert_sorted_list(2);
    A.insert_sorted_list(2);
    A.insert_sorted_list(2);
    A.insert_sorted_list(6);
    A.insert_sorted_list(3);
    // A.insert_value_after_x(2,100);
    // A.insert_value_before_x(1,4);
    // B.insertLast(6);
    // B.insertLast(7);
    // B.insertLast(8);
    // B.insertLast(9);
    // A.deleteFirst();
    // A.deleteLast();
    // A.deleteLast();
    // A.deleteLast();
    // A.printList();
    // A.delete_specific(2);
    // A.delete_specific(1);
    // A.delete_specific(5);
    A.printList();
    A.reverse_list_iterative();
    A.printList();
    // A=A.concatenate(A,B);
    // A.Reverse();
    // A.reversePrint(A.head);
    // A.printList();
    // A.insert_specific_index(2,1000);
    // A.insert_specific_index(2,10);
    // A.printList();
    // LinkedList* l1=new  LinkedList();
    // l1->insert_sorted_list(1);
    // l1->insert_sorted_list(2);
    // l1->insert_sorted_list(3);
    // l1->insert_sorted_list(2);
    // l1->insert_sorted_list(5);
    // l1->printList();
   
    return 0;
}
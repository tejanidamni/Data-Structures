#include <iostream>
using namespace std;

struct node{
    int data;
    node * next;
};
node * first;

class linkedlist{
public:
    linkedlist(){
        first= NULL;
    }
    static void insert(int val,int pos){
        node * temp=new node;
        temp->data=val;
        
        if (first==NULL){
            first=temp;
            temp->next=NULL;
        }else if(pos==0){
            node * p = first;
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=temp;
            temp->next=NULL;
        }else{
            node * p = first;
            for (int i=0;i<pos-1;i++){
                 p=p->next;
            }
            temp->next=p->next;
            p->next=temp;
            
        }
        
    }
    
    static void output(){
        node * p = first;
        while(p->next!=NULL){
            cout<< p->data<<endl;
        }
        cout<<p->data<<endl;
        
    }
    
    static void del(int pos){
        if (pos==1){
            first=first->next;
        }else{
            node * p = first;
            for (int i=0;i<pos-2;i++){
                p=p->next;
            }
            node * temp=p->next;
            p->next=p->next->next;
            delete temp;
        }
        
        
    }
    
    static void reverse(int a,int b){
        node * p = first;
        for (int i=0;i<a-1;i++){
            p=p->next;
        }
        int arr[1000];
        for (int i=0;i<(b-a+1);i++){
            arr[i]=p->data;
            p=p->next;
        }
        node * q = first;
        for (int i=0;i<a-1;i++){
            q=q->next;
        }
        for (int i=(b-a);i>=0;i--){
            q->data=arr[i];
            q=q->next;
        }
        
        
        
    }
    
    static void query(int pos){
        node * p = first;
        for (int i=0;i<pos-1;i++){
            p=p->next;
        }
        cout<<p->data<<endl;
        
    }
    
    
};




int main() {
    int initial_num, value;
    cin>> initial_num;
    
    for (int i=0;i<initial_num;i++){
        cin >> value;
        linkedlist::insert(value, 0);
    }
    
    
    int num_of_operation;
    cin >> num_of_operation;
    for (int i=0;i<num_of_operation;i++){
        int option;
        cin>> option;
        int a, b;
        
        switch(option){
            case 1:
                cin>>a>>b;
                linkedlist::insert(b,a);
                break;
            case 2:
                cin>>a;
                linkedlist::del(a);
                break;
            case 3:
                cin>>a>>b;
                linkedlist::reverse(a,b);
                break;
            case 4:
                cin>>a;
                linkedlist::query(a);
                break;
            default:
                cout <<"wrong case"<<endl;
                break;
        }
        
    }
    return 0;
    
    
}
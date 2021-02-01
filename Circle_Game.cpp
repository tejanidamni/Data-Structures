#include <iostream>
using namespace std;

struct node {
    int data;
    node * next;
} ;

node * last;

class mylinkedlist{
    
public:
    mylinkedlist(){
        last = NULL;
    }
    
    static void addstudent(int tag, int pos, int num_stu){
        node * temp=new node;
        temp->data=tag;
        if (last==NULL){
            last=temp;
            temp->next= last;
        }else{
            pos=pos%num_stu;
            for (int i=0;i<pos-1;i++){
                last=last->next;
            }
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
        
    }
    
    static void delStudent(int pos,int num_stu){
        pos=pos%num_stu;
        for (int i=0;i<pos-1;i++){
            last=last->next;
        }
        node *temp=last->next;
        last->next=last->next->next;
        delete temp;
        
    }
    
    static void displayStudent(int pos,int num_stu){
        if (last==NULL){
            cout<<"list is empty"<<endl;
        }else{

            pos=pos%num_stu;
            for (int i=0;i<pos-1;i++){
                last=last->next;
            }
            cout<<last->data<<endl;
            
        }
        
        
    }
    
    
};

int main(int argc, const char * argv[]){
    int n;
    int tag;
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        
        cin>>tag;
        mylinkedlist::addstudent(tag,0,n);
    }
    
    last=last->next;
    
    int num_of_operation;
    cin>>num_of_operation;
    for (int i=0;i<num_of_operation;i++){
        int option, a,b;
        
        cin>>option;
        switch (option){
            case 1:
                cin>>a>>b;
                mylinkedlist::addstudent(b,a,n);
                break;
            case 2:
                cin >> a;
                mylinkedlist::delStudent(a,n);
                break;
            case 3:
                cin >> a;
                mylinkedlist::displayStudent(a,n);
                break;
                
            
        }
        
        
    }
    return 0;
}
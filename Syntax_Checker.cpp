#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
   
    string mystring;
    while (getline(cin,mystring)){
        stack <char> s;
        stack <int> index;
        bool issuccess=true;
        int i;
        for (i=0;i<mystring.length();i++){
            if (mystring.at(i)=='['||mystring.at(i)=='{'||mystring.at(i)=='('){
                s.push(mystring.at(i));
                index.push(i+1);
                
            }else if (mystring.at(i)==']'){
                if(s.top()=='['){
                    s.pop();
                    index.pop();
                }else{
                    issuccess=false;
                    break;
                }
                
            }else if(mystring.at(i)=='}'){
                if(s.top()=='{'){
                    s.pop();
                    index.pop();
                }else{
                    issuccess=false;
                    break;
                }
                
                
            }else if(mystring.at(i)==')'){
                if(s.top()=='('){
                    s.pop();
                    index.pop();
                }else{
                    issuccess=false;
                    break;
                }
        
            }
        }
        
        if (issuccess==false){
            cout<<i+1<<endl;
        }else if(s.empty()){
            cout<< "Success" <<endl;
        }else{
            while(s.size()>1){
                s.pop();
                index.pop();
            }
            cout<<index.top()<<endl;
        }
        
    }
    
    return 0;
}
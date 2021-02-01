#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T;
    cin>>T;
    
    for (int i=0;i<T;i++){
        stack <int> poker;
        stack <int> maximum;
        
        while(!poker.empty()){
            poker.pop();
        }
        while(!maximum.empty()){
            maximum.pop();
        }
        
        int n;
        cin>>n;
        maximum.push(0);
        for(int j=0;j<n;j++){
            int value;
            cin>>value;
            poker.push(value);
            
            if (value>maximum.top()){
                maximum.push(value);
            }else{
                maximum.push(maximum.top());
            }
            
            
        }
        int m;
        cin >>m;
        for(int k=0;k<m;k++){
            char operation;
            cin>>operation;
            switch(operation){
                case 'm':
                    if(!maximum.empty()){
                        cout<<maximum.top()<< endl;
                    }
                    break;
                    
                case 'r':
                    if (!poker.empty()){
                        poker.pop();
                        maximum.pop();
                    }
                    
                    break;
                    
                case 'a':
                    int add_value;
                    cin>>add_value;
                    poker.push(add_value);
                    if (add_value>maximum.top()){
                        maximum.push(add_value);
                    }else{
                        maximum.push(maximum.top());
                    }
                    break;
                default:
                    cout<<"not correct"<<endl;
                    break;
                    
            }
                
                    
            
        }
    }
    
    return 0;
}
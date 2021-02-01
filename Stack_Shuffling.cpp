#include <iostream>
#include <stack>
using namespace std;

int main(){
    int no_of_cases;
    cin >> no_of_cases;
    
    while (no_of_cases--){
        int total_elements;
        stack<int> stack_A;
        
        cin >> total_elements;
        
        for (int a=0; a<total_elements; a++){
            int temporary;
            cin >> temporary;
            stack_A.push(temporary);
        }
        
        int permutation;
        cin >> permutation ;
        
        while (permutation--)
        {
            int output[3000];
            stack<int> stack_S;
            stack<int> temporaryA;
            
            for (int i = 0; i < total_elements; i++){
                cin >> output[i];
            }
            temporaryA = stack_A;
            
            bool is_possible = false;
            
            for (int j = 0; j < total_elements; j++){
                if (stack_S.empty()==false && stack_S.top()== output[j]){
                    stack_S.pop();
                    is_possible = true;
                    
                }else{
                    
                    while (temporaryA.empty()==false && temporaryA.top() != output[j]){
                        stack_S.push(temporaryA.top());
                        temporaryA.pop();
                        
                    }
                    
                    if (temporaryA.empty()==false && temporaryA.top() == output[j]){
                        temporaryA.pop();
                        is_possible = true;
                    }
                }
                
                if (is_possible==true && j != total_elements-1){
                    is_possible = false;
                }else{
                    break;
                }
            }
            
            if (is_possible==true)
                cout << "Aye" << endl;
            else
                cout << "Impossible" << endl;
        }
    }
    

}
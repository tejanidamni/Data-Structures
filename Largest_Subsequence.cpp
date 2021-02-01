#include <iostream>
#include <string>
using namespace std;

int main(){
    int number_of_cases;
    cin>> number_of_cases;
    
    for (int i=0;i<number_of_cases;i++){
        string input_string;
        cin >> input_string;
        string output_string="";
        
        
        for (int m=0;m<input_string.length();m++){
            char compare=' ';
            for (int j=m;j<input_string.length();j++){
                
                if (input_string.at(j)>compare){
                    compare=input_string.at(j);
                    m=j;
                    
                }
                
            }
            output_string+=input_string.at(m);
            
        }
        cout<<output_string<<endl;
        
        
    }
}
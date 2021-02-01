#include <iostream>
using namespace std;

int main(){
    
    int n;
    while (cin >> n){
        int first=0;
        int second=1;
        if (n>=2){
            for (int i=2;i<=n;i++){
                int next=(first+second)%10;
                first=second;
                second=next;
                
            }
            cout<<second<<endl;
        }else if (n==1){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
    
}
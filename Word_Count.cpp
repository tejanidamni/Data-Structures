#include <iostream>
#include <string>

using namespace std;

int main()
{
    string words[10000];
    int count[10000];
    int length = 0;
    string word;

    while(cin>>word){
        
        bool foundFlag = false;
        for(int i=0;i<length;i++){
            if(words[i]==word){
                foundFlag = true;
                count[i]++;
            }
        }
        if(foundFlag==false){
            words[length]=word;
            count[length++]=1;
        }
    }
    
    for(int j=1;j<length;j++){
        string currentkey=words[j];
        int currentcount=count[j];
        int i=j-1;
        while(i>=0 && words[i]>currentkey){
            words[i+1]=words[i];
            count[i+1]=count[i];
            i=i-1;
        }
        words[i+1]=currentkey;
        count[i+1]=currentcount;

    }

    for(int i=0;i<length;i++){
        cout<<words[i]<<" "<<count[i]<<endl;
    }



}
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

static int calculate(int array[1024][1024], int starti, int endi, int startj, int endj){
    int count1=0;
    int count0=0;
    
    for(int i=starti;i<=endi;i++){
        for(int j=startj;j<=endj;j++){
            if (array[i][j]==0){
                count0+=1;
            }else{
                count1+=1;
            }
        }
    }
    if (count1==0 or count0==0){
        return 1;
    }else{
        return 1 + calculate(array, starti,(starti+(endi-starti)/2), startj,(startj+(endj-startj)/2))+
        calculate(array,starti,(starti+(endi-starti)/2),(startj+(endj-startj+1)/2),endj)+
        calculate(array,(starti+(endi-starti+1)/2),endi,startj,(startj+(endj-startj)/2))+
        calculate(array,(starti+(endi-starti+1)/2),endi,(startj+(endj-startj+1)/2),endj);
    }

    

}

int main(int argc, const char * argv[]) {
    int k;
    
    while (cin>>k){
        int n;
        n = pow(2,k);
        static int array[1024][1024];
        for (int i=0;i<n;i++){
            string mystring;
            cin >> mystring;
            for(int j=0;j<n;j++){
                array[i][j]=mystring.at(j)-'0';
            }
            
        }
        
        cout << calculate(array,0,n-1,0,n-1)<<endl;
        
        
        
    }
    
    return 0;
}
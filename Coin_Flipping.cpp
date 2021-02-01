#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
using namespace std;

void flipcolumn(int array[100][10],int colnum,int row){
    for(int i=0;i<row;i++){
        if (array[i][colnum]==1){
            array[i][colnum]=0;
        }else{
            array[i][colnum]=1;
        }
        
    }
    
}

int checkrowsum(int array[100][10],int rownum, int col){
    int num_of_zeros=0;
    int num_of_ones=0;
    for (int i=0;i<col;i++){
        if (array[rownum][i]==1){
            num_of_zeros+=1;
        }else{
            num_of_ones+=1;
        }
        
    }
    if (num_of_ones>num_of_zeros){
        return num_of_ones;
    }else{
        return num_of_zeros;
    }
    
}

int main(int argc, const char * argv[]) {
    int row, col;
    
    
    while(cin>>row){
        char val=' ';
        int array[100][10];
        int maxsum=0;
        
        cin>>col;
        for (int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin >> val;
                array[i][j]=val-'0';
            }
        }
        
        for(int i=0;i<pow(2,col);i++){
            int sum=0;
            bool isflip[10]={false};
            string mystring= bitset<10>(i).to_string();
            int y=0;
            for(int j=10-col;j<10;j++){
                if ((mystring[j]-'0')==1){
                    isflip[y]=true;
                    flipcolumn(array,y,row);
                }
                y++;
            }
            
            for(int j=0;j<row;j++){
                sum+=checkrowsum(array,j, col);
                
            }
            if (sum>maxsum){
                maxsum=sum;
            }
            
            for(int j=0;j<col;j++){
                if (isflip[j]==true){
                    flipcolumn(array,j,row);
                }
            }
            
        }
        cout<<maxsum<<endl;
        
    }
    
    
    return 0;
}
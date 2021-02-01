#include <iostream>
#include <vector>
using namespace std;

int ancestors[30000];
int positions[30000]={0};
int my_max = 1;

int search(int f1){
    if(ancestors[f1] != f1){
        ancestors[f1] = search(ancestors[f1]);
    }
    return ancestors[f1];
}

void gathering(int f1, int f2){

    int ancestor_of_f1, ancestor_of_f2;
    ancestor_of_f1 = search(f1);
    ancestor_of_f2 = search(f2);

    if(ancestor_of_f1==ancestor_of_f2){
        return;
    }
    ancestors[ancestor_of_f2] = ancestor_of_f1;
    positions[ancestor_of_f1] =positions[ancestor_of_f1]+ positions[ancestor_of_f2];

    if(positions[ancestor_of_f1]>my_max){
        my_max = positions[ancestor_of_f1];
    }
}

int main(){
    int no_of_cases;
    cin>>no_of_cases;
    for(int j=0;j<no_of_cases;j++){
        int total_citizens;
        int pairs_of_people;
        cin>>total_citizens;
        cin>>pairs_of_people;
        for(int k=1;k<=total_citizens;k++){
            ancestors[k] = k;
            positions[k] = 1;
        }
        for(int i=0;i<pairs_of_people;i++){
            int friend_A,friend_B;
            cin>>friend_A>>friend_B;
            gathering(friend_A,friend_B);
        }
        cout<<my_max<<endl;
    }
    return 0;
}

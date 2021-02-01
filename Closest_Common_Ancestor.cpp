#include <iostream>
using namespace std;

struct Member {
    int Name;
    int Parent;
    Member() {
        Name = -1;
        Parent = -1;
    }
    Member(int name, int parent) {
        Name = name;
        Parent = parent;
    }
};

int findDepth(int my_member, Member my_family[101]) {
    if (my_family[my_member].Name == my_family[my_member].Parent){
        return 1;
    }else{
        
        int depth = findDepth(my_family[my_member].Parent, my_family);
        return ++depth;
    }
}

int main() {
    int no_of_cases;
    cin >> no_of_cases;
    for (int i = 0; i < no_of_cases; i++)
    {
        Member my_family[101];
        int my_root;
        int my_members;
        
        cin >> my_root;
        cin >> my_members;
        
        my_family[my_root] = Member(my_root, my_root);
        
        for (int j = 0; j < my_members - 1; j++)
        {
            int member_no, parent_no;
            cin >> member_no >> parent_no;
            my_family[member_no] = Member(member_no, parent_no);
        }
        
        int member1, member2;
        cin >> member1 >> member2;
      
        int depth1 = findDepth(member1, my_family);
        int depth2 = findDepth(member2, my_family);
        
        
        if (depth2 > depth1)
        {
            while (depth1 != depth2)
            {
                member2 = my_family[member2].Parent;
                depth2--;
            }
        } else if (depth1 > depth2){
            while (depth1 != depth2)
            {
                member1 = my_family[member1].Parent;
                depth1--;
            }
        }
            
        
        while (1){
            if (member1 == member2){
                cout << member1 << endl;
                break;
            }
            member1 = my_family[member1].Parent;
            member2 = my_family[member2].Parent;
        }
    }
    return 0;
}
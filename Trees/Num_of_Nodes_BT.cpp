// Max. Number of Nodes at a level i in a Binary Tree
// 2^(i-1) if root is level 1
// 2^i if root is level 0 which it is typically

// This is also the total number of nodes in a Perfect BT

class Solution {
  public:
    int countNodes(int i) {
        // your code here
        
        if(i == 1){
            return 1;
        }
        
        int count = 1;
        int level = 1;
        
        while(level<i){
            count *= 2;
            level += 1;
        }
        
        return count;
    }
};


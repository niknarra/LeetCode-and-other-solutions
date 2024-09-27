// Max. Number of Nodes at a level i in a Binary Tree
// 2^(i-1)

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


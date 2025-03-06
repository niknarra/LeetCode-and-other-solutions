class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // Build the set for faster lookups
        unordered_set<string> genes(bank.begin(), bank.end());

        // As the choices are only ACGT, it is better to iterate over them rather than all 26
        vector<char> choices{'A','C','G','T'};

        // Initialize the queue and start BFS 
        queue<pair<string,int>> q;
        q.push({startGene, 0});

        // While q is not empty,
        while(!q.empty()){
            string current = q.front().first; // Get the current gene
            int steps = q.front().second; // and the current steps
            q.pop();

            // Check if we reached the target gene
            if(current == endGene) return steps;

            // Loop over the current gene word and replace each character to see if there's a mutated gene
            for(int i=0;i<current.size();i+=1){
                char original = current[i]; // Store the character to reset the current gene string
                for(char ch:choices){
                    current[i] = ch;
                    if(genes.find(current) != genes.end()){
                        q.push({current, steps+1}); // If there is a mutated string in our bank, push to queue
                        genes.erase(current); // Remove the mutated gene as we've already used it
                    }
                }
                current[i] = original; // Reset the current string to its original state
            }
        }
        return -1;
    }
};

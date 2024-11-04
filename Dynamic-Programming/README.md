# Dynamic Programming Notes
## Memoization Recipe
1. Make it work
- Visualize the problem as a tree: how can the large problem be broken down into chunks; the nodes are problems and the edges should shrink the size as the depth increases leading to the base case(s)
- Implement the tree: leaves -> base case
- Test!
2. Make it efficient
- Memoize it: add a memo into the mix (map, vector etc.)
- Add a new base case to return memo values

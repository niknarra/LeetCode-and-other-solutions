#  Time Complexity: O(n * L) L -> length of the word
# Space Complexity: O(n)

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # 1. Build a set of the words list for O(1) lookups
        words = set(wordList)

        # 2. Initialize a queue for BFS and push the starting word with a step count of 1
        # and also remove the begin word from the list if present
        q = deque()
        q.append((beginWord, 1))

        if beginWord in words:
            words.remove(beginWord)
        
        # 3. Start BFS
        while q:
            word, steps = q.popleft()

            # Check if we reached the end/target word
            if word == endWord:
                return steps

            # If not, for each character in the current word,
            for i in range(len(word)):
                # Replace it with an letter from a-z
                for ch in range(26):
                    new_word = word[:i] + chr(ord('a') + ch) + word[i+1:]
                    # and check if the newly formed word is in the list of words so that we can mutate the word
                    if new_word in words:
                        # if yes, push the mutated word to the queue with the steps incremented by 1
                        q.append((new_word, steps+1))
                        # Then as we've already formed the new word, remove it from the words list
                        words.remove(new_word)
                        
        # In case we don't reach the target word, we simply return 0
        return 0
        


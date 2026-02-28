class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None

class LRUCache:

    def removeNode(self, remNode):
        prevNode = remNode.prev
        nextNode = remNode.next

        prevNode.next = nextNode
        nextNode.prev = prevNode
    
    def updateHead(self, newNode):
        tmp = self.head.next

        self.head.next = newNode
        tmp.prev = newNode
        newNode.next = tmp
        newNode.prev = self.head

    def __init__(self, capacity: int):
        self.size = capacity
        self.head = Node(-1,-1)
        self.tail = Node(-1,-1)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.cache = {}

    def get(self, key: int) -> int:
        if key in self.cache:
            ans = self.cache[key]
            self.removeNode(ans)
            self.updateHead(ans)

            return ans.val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            existingNode = self.cache[key]
            existingNode.val = value
            self.removeNode(existingNode)
            self.updateHead(existingNode)
            return
        if self.size == len(self.cache):
            removeKey = self.tail.prev.key
            self.removeNode(self.tail.prev)
            self.cache.pop(removeKey)
        newNode = Node(key, value)
        self.cache[key] = newNode
        self.updateHead(newNode)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

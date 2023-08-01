# o(1) both dll + map (cache) key to addr of node mapping
class Node:
    def __init__(self, key, value, prev = None, next = None):
        self.key = key
        self.value = value
        self.prev = prev
        self.next = next

class LRUCache:
    def __init__(self, capacity: int):
        # dic of key->node gives addr of node 
        self.cache = {}    
        # dll has a head and a tail pointer, though consider them at inf
        # a node with key, value is always added after the head.
        # so lru is always the node one before tail
        self.head = Node(-1,-1)
        self.tail = Node(-1,-1)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.capacity = capacity
    
    def add(self, key, value):
        node = Node(key, value)
        
        node.next = self.head.next
        node.prev = self.head
       
        self.head.next.prev = node
        self.head.next = node
        
    def delete(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def get(self, key: int) -> int:
        # how to perform get
        # 1) check if key exists in cache, if yes then return its value
        # 2) if key exists then the node with this key is now most recent
        # accessed so del it from the dll and move it after head.

        if key in self.cache:
            node = self.cache.get(key)
            value = node.value
            self.delete(node)
            self.add(key, value)
            # this node must be at head.next, add this again in cache because
            # its address got updated
            self.cache[key] = self.head.next
            return value
        else:   
            return -1

    def put(self, key: int, value: int) -> None:
        # if it exists just update its entry
        # if it doesnt exists check if capacity is not full, if full remove lru 
        # cache entry and then add
        # if cache not full simply add cache
        if key in self.cache:    
            node = self.cache[key]
            self.delete(node)
            self.add(key, value)
            self.cache[key] = self.head.next

        elif self.capacity == 0:
            # lru at tail.prev
            # delete entry from cache table 
            self.cache.pop(self.tail.prev.key)
            self.delete(self.tail.prev)
            self.add(key, value)
            # value at head.next, add in cache
            self.cache[key] = self.head.next
        
        else:
            self.add(key, value)
            self.cache[key] = self.head.next
            self.capacity -= 1


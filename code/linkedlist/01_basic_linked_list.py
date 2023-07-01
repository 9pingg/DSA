# why use linked list instead of array
# 1) array insertion at pos 0, would cause entire array to shift forward this makes array insertion o(n)
"""
Advantages of linked list:
1) Fast Insertion/Deletion Time:
LL: inserting /deleting a new node to the beginning or end (only if tail pointer) of a linked list takes constant time (O(1)) 
insertion to the middle of the linked list takes linear time (O(n)) as iteration over n elements is required to get
to the correct location before inserting the node SAME AS ARRAY. 
ARR: whether we insert at start or middle order is always o(n)

2) Better use of Memory: 
From a memory allocation point of view, linked lists are more efficient than arrays. 
Unlike arrays which are alloted space at compile time, the size for a linked list is not pre-defined.

Disadvantages of Linked List

1) no random access slow search O(n))
2) Extra memory space for a pointer is required for each element of the list

                    Array linked list
indexing            O(1)    O(n)
ins/del at start    o(n)    o(1)
ins/del at end      o(1)    o(n) / o(1) if tail pointer
ins/del in middle   o(n)    o(n)
"""

class Node:
    def __init__(self,data=None, next = None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None
    
    def print(self):
        if(self.head is None):
            return "empty linked list"
        temp = self.head
        res = ""
        while temp:
            res += str(temp.data) + " -> "
            temp = temp.next
        return res
    
    def insert_at_beginning(self, data):
        node = Node(data, self.head)
        self.head = node
    
    def insert_at_end(self, data):
        # if list is empty
        if(self.head is None): 
            node = Node(data)
            self.head = node
            return 
        
        # not the best way to do this
        # temp = self.head
        # temp1 = self.head
        # while temp1:
        #     temp1 = temp1.next
        #     if(temp1 is None):
        #         temp.next = Node(data)
        #     temp = temp.next

        # instead try this
        itr = self.head
        while itr.next:
            itr = itr.next
        itr.next = Node(data)
        return
    
    # follows 0 based indexing
    def insert_at(self, pos, data):
        print(pos, data)
        if(pos < 0 or pos > self.size()):
            return "invalid position"
        itr = self.head
        cnt = 0
        if pos == 0:
            self.insert_at_beginning(data)
            return 
        # loop doesnt work when pos = 0
        # stopping at the previous element 
        while itr:
            if cnt == pos-1:
                temp = itr.next
                itr.next = Node(data)
                itr.next.next = temp
                return
            else: 
                itr = itr.next
                cnt+=1    

    # takes in a list of values and insert them into the linked list
    def insert_values(self, data_list):
        self.head = None
        for data in data_list:
            self.insert_at_end(data) 

    def remove_at(self, pos):
        # validate position
        # notice the difference btw the two insert_at and remove_at base condition
        # we cannot delete anything at self.size() position but we can insert there 
        if(pos < 0 or pos >= self.size()):
            return "invalid position"
        if(pos == 0):
            self.head = self.head.next
            return 
        cnt = 0
        itr  = self.head
        # stop at element prior to the elemtent we are trying to remove
        while itr:
            if cnt == pos-1:
                itr.next = itr.next.next
                return
            else:
                cnt+=1
                itr = itr.next
    def size(self):
        itr = self.head
        cnt = 0
        while itr:
            itr = itr.next
            cnt += 1
        return cnt
    
    def insert_after_value(self, data_after, data_to_insert):
        if self.head is None:
            return
        itr = self.head
        while itr:
            if(itr.data == data_after):
                node = Node(data_to_insert)    
                temp = itr.next
                itr.next = node
                node.next = temp
            itr = itr.next
    
    def remove_by_value(self, data):
        if self.head is None:
            return

        if self.head.data == data:
            self.head = self.head.next
            return

        itr = self.head

        while itr.next:
            if(itr.next.data == data):
                itr.next = itr.next.next
                return
            itr = itr.next


if(__name__ == "__main__"):
    listt = LinkedList()
    listt.insert_at_beginning(10)
    listt.insert_at_beginning(11)
    listt.insert_at_end(19)
    listt.insert_at(1,19)
    print(listt.print())
    listt.insert_at(listt.size(),0)
    print(listt.print())
    listt.insert_values(["a", "b", "c", "d", "a", "a"])
    listt.remove_by_value("a")
    print(listt.print())
    listt.remove_at(4)
    print(listt.print())
    listt.insert_after_value("a")
    print(listt.size())



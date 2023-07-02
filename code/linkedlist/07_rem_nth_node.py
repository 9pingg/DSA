"""
2 ways to do this 
1) find size of the list and rem (size-n) element T: O(size) + O(size-n)
2) slow and fast pointer one itr
"""
def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]: 
    if(head is None):
        return None        
    #find the size of the list
    cur = head
    size = 0
    while cur:
        cur = cur.next
        size+=1

    # remove element at pos (size-n) 0 based indexing here
    n = size - n
    # always rem this edge case, when removing element at index, the loop doesnt work for elements at pos 0
    if(n == 0):
        head = head.next
        return head
    cur = head
    pos = 0
    while cur.next:
        if pos == n-1:
            cur.next = cur.next.next
            return head
        else:
            pos += 1
            cur = cur.next
    return head

# optimal way 2) slow and fast pointer one itr

"""
the position of the nth node from the end is (size - n)
When you move the fast pointer to nth node , the remaining nodes to traverse is (size_of_linked_list - n). 
After that, when you start moving slow pointer and fast pointer by 1 node each, it is guaranteed that 
slow pointer will cover a distance of (size_of_linked_list - n) nodes. And that's node we want to remove.

basically move f from dummy node n times ahead
then start moving s and f, till f reaches none
so s and f together would move  size-n times
now s points at node which is just previous of the node to be removed


"""

def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
    dummy = ListNode()
    dummy.next = head
    f = dummy
    s = dummy
    cnt = 0
    while True:
        if(cnt == n):
            break
        f = f.next
        cnt += 1    
    
    while f.next:
        s = s.next
        f = f.next
    
    s.next = s.next.next
    return dummy.next
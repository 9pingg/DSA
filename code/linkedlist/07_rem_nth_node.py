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


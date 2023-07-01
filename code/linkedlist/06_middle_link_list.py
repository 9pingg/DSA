# two ways to do this:
# find the size of the linked list and give the element at n // 2
# o(n) + o(n/2)
def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
    itr = head
    size = 0
    while itr:
        size+=1
        itr = itr.next
    pos = size // 2
    itr = head
    while itr:
        if(pos == 0):
            return itr
        itr = itr.next
        pos = pos -1
    return None


# optimal way to have two pointers : fast and slow 
# slow moves 1 node, and fast moves 2 nodes
# when fast is at end of the list, teh slow would be at the middle of the list
# complexity:  O(n/2)

def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
    f = head
    s = head
    # why f and f.next
    # we have to check if (f) crosses the boundary of list (f),   or it is at the last element of list (f.next)
    while f and f.next: 
        s = s.next
        f = f.next.next
    return s


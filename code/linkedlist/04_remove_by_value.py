def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
    if(head is None): return None
    itr = head
    # again we have to know the previous element so we loop itr.next
    # this doesnt check for value of head
    while itr.next:
        if(itr.next.val == val):
            itr.next = itr.next.next
        else:
            itr = itr.next
    # edge case : check if head is eq to val
    if(head.val == val): 
        head = head.next
    return head

# in the prev soln, we had to check for head mutiple times
# any way to solve this without that? YES WITH A DUMMY NODE

def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
    if(head is None): return None
    res = ListNode()
    res.next = head # now head is not the first element in the linked list res is so the loop can access it now
    itr = res
    # again we have to know the previous element so we loop itr.next
    # this doesnt check for value of head
    while itr.next:
        if(itr.next.val == val):
            itr.next = itr.next.next
        else:
            itr = itr.next
    return res.next
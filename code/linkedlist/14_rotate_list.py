# like every rotate list question, always do k = k % size

def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
    
    size = getSize(head)
    if(head is None or head.next is None or size == 0): return head
    k = k % size
    if(k == 0): return head # the loop doesnt work when k = 0

    # get the kth node from the back, and break the list
    # into two such that [0 k-1] [k, n]
    # now append the second list to the start of first list
    # this requires to know  the node n.
    # two ways to find n 1) itr through k to n (second list), 2) save the nth node when finding out nth node


    # step 1 get prev element of nth node (same question as nth node question)

    f = head
    s = head # but we need to stop iterating at the previous node of kth node, 
    # nodes from kth node have to removed
    cnt = k
    while cnt != 0 and f:
        cnt = cnt - 1
        f = f.next
    
    while f.next: # previous node reqd so f.next taken
        s = s.next
        f = f.next
    
    # f points to the last node after this iter (smart way to find end of list)
    

    l2 = s.next
    s.next = None
    l1 = head

    # basically l1 -> l2
    f.next = l1
    return l2
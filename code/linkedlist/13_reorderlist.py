
# 3 steps: find middle element, reverse 2nd part of list, merge both the lists

def reorderList(self, head: Optional[ListNode]) -> None:

    f = head
    s = head
    # middle element left side when size of list is even.
    # same as palindorme ques
    while f.next and f.next.next:
        f = f.next.next
        s = s.next
    
    rev = s.next
    s.next = None # break both the lists here


    # step 2 find reverse of part 2 of list
    prev = None
    cur = rev

    while cur:
        temp = cur.next
        cur.next = prev
        prev = cur
        cur = temp
    
    
    # step 3 intersection of list (new list using ListNode() cannot be made as return type is None)
    # so changes to be made in place
    
    res = head
    while head and prev:
        # save the next nodes in temp vars
        temp = head.next
        temp1 = prev.next

        # change the next of head and prev
        prev.next = head.next
        head.next = prev

        # iterate ahead
        head = temp
        prev = temp1
    
    return res
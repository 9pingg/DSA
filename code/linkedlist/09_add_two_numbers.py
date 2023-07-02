# very similar to merge two numbers
# T O(n) S O(n) making a new list can be done in o(1) space also
def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    t1 = l1 # no need to make these acn use l1 and l2 directly
    t2 = l2
    res = curr = ListNode() # dummy node to store
    carry = 0 # carry 
    while t1 and t2:
        val = t1.val + t2.val + carry
        carry = val // 10
        val = val % 10
        curr.next = ListNode(val) # add the node
        curr = curr.next
        t1 = t1.next
        t2 = t2.next

    # now one of list is done, find the one which is not and add its remaining elements and also check for carry value
    if(t1 is None):
        while t2:
            val = t2.val + carry
            carry = val // 10
            val = val % 10
            curr.next = ListNode(val)
            curr = curr.next
            t2 = t2.next
    if(t2 is None):
        while t1:
            val = t1.val + carry
            carry = val // 10
            val = val % 10
            curr.next = ListNode(val)
            curr = curr.next
            t1 = t1.next
    # note the carry might still be there so add it
    if(carry != 0):
        curr.next = ListNode(carry)
    return res.next
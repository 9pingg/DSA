
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    # O(N)
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        if(list1 is None): return list2
        if(list2 is None): return list1

        itr1 = list1
        itr2 = list2
        # notice here we defined two poitners to start one cur and res.
        # so cur we itr, res would not we attach node to cur and move ahead
        # so after all elements are added we return res.next 
        res = cur = ListNode()
        
        while itr1 and itr2:
            if(itr1.val < itr2.val):
                cur.next = itr1
                itr1 = itr1.next
            else:
                cur.next = itr2
                itr2 = itr2.next
            cur = cur.next
        # this is not necessary better way to do this 
        if itr1 is None:
            while itr2:
                cur.next = itr2
                itr2 = itr2.next
                cur = cur.next
        if itr2 is None:
            while itr1:
                cur.next = itr1
                itr1 = itr1.next
                cur = cur.next

        return res.next

# best approach
def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
    if(list1 is None): return list2
    if(list2 is None): return list1

    itr1 = list1
    itr2 = list2
    res = cur = ListNode()
    
    while itr1 and itr2:
        if(itr1.val < itr2.val):
            cur.next = itr1
            itr1 = itr1.next
        else:
            cur.next = itr2
            itr2 = itr2.next
        cur = cur.next
    if itr1 is None:
        cur.next = itr2
    if itr2 is None:
        cur.next = itr1

    return res.next
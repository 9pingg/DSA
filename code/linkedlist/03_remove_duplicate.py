"""
Given the head of a sorted linked list, delete all duplicates such that each element appears 
only once. Return the linked list sorted as well.
"""

from pyparsing import Optional

# when we generally have to remove elements or need to access a compare two elemens(prev and now)
# we itr from itr.next
def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if(head is None): return head
    itr = head
    while itr.next:
        if(itr.val == itr.next.val):
            itr.next = itr.next.next
        else:
            itr = itr.next

    return head
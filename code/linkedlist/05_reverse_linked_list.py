def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    # iterative 2 pointers prev and cur
    prev = None
    cur = head
    while cur:
        # store cur.next somewhere because it is updated
        temp = cur.next
        cur.next = prev
        # move both one step ahead
        prev = cur
        cur = temp

    return prev

def reverseListRecursive(self, head):
    def reverse(cur, prev):
        if cur is None:
            return prev
        else:
            temp = cur.next
            cur.next = prev
            return reverse(temp, cur)

    return reverse(head, None)
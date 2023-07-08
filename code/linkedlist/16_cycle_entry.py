# there are two aproaches to this
# 1) simple use of hash, iterate through the linked list add every node to map
# if a node comes which already exists in map, then that is the entry point of the cycle 
# this is the exact soln given in find if list has cycle
# t: o(n) s: o(n)

# 2) two pointer approach used in find if list has cycle, but the point where f and s meet isnt always the starting point of
# the cycle, so do slight modifications of the code

"""
Fast and slow pointers meet at 6 and cycle starts at 4

1-->2-->3-->4-->5-->6-->7-->8-->9-->Back to 4

I<-----x1----->I<---x2--->I<-------x3------->|

Let x be the distance from the head to the start of the cycle at 4
y is the distance from the start of the cycle to the intersection point of fast and slow pointers i.e at 6
z is the distance from the intersection till the start of the cycle at 4

Distance travelled by slow pointer = x1 + x2
Distance travelled by fast pointer = x1 + x2 + x3 + x2

velocity_f = 2 * velocity_s
v proportional to distance

2 (x1 + x2) = x1 + x2 + x3 + x2
x1 = x3
"""

def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if(head is None): return None
    f = head
    s = head
    while f and f.next:
        f = f.next.next
        s = s.next
        if f == s:
            # x1 = x3, find entry point basically itr head and s till they are same
            while head:
                if head == s: return s
                head = head.next
                s = s.next
    # no cycle
    return None
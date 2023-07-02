# brute force hashing just store the elements in a hash table and check if elements exists.
# this way we can get the first cycle node Starting point of the loop in a Linked List
# optimal fast and slow pointer O(N)

# NOTE HERE S == F condition doesnt mean that the this is the cycle node where the loop starts, this could be any node
# S==F is done to show that even when f is faster it can still met s it means a loop exists in the list
def hasCycle(self, head: Optional[ListNode]) -> bool:
    # two pointers fast moves by 2 nodes and slow moves by 1 node
    # similar to middle of the linked lsit

    # no node means no cycle so return false
    if head is None: return False
    # even if there is one node there can be a cycle
    s = head # starts at pos 0
    f = head.next # starts at pos 1
    while f and f.next:
        if s == f: return True
        s = s.next
        f = f.next.next
    return False
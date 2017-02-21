"""
Detect a cycle in a linked list. Note that the head pointer may be 'None' if the list is empty.

A Node is defined as:

    class Node(object):
        def __init__(self, data = None, next_node = None):
            self.data = data
            self.next = next_node
"""


def has_cycle(head):
    it = head
    fast_iter = head.next
    while it is not None and fast_iter is not None:
        if it == fast_iter:
            return 1
        it = head.next
        fast_iter = fast_iter.next.next
    return 0
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {              // cycle found
            slow = head;
            while (slow != fast) {       // meet at cycle entry
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;                         // no cycle
}
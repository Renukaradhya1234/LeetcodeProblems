/**
 * Definition for singly-linked list.  */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
    private:
        ListNode* mergeTwoSortedNodes(ListNode* left_node, ListNode* right_node) {
            ListNode dummy(0);
            ListNode* tail = &dummy;

            while (left_node != nullptr && right_node != nullptr) {
                if (left_node->val < right_node->val) {
                    tail->next = left_node;
                    left_node = left_node->next;
                } else {
                    tail->next = right_node;
                    right_node = right_node->next;
                }
                tail = tail->next;
            }

            tail->next = (left_node != nullptr) ? left_node : right_node;

            return dummy.next;
        }

        ListNode* mergeSort(ListNode* node) {
            if (node == nullptr || node->next == nullptr) {
                return node;
            }

            ListNode* slow_iterator = node;
            ListNode* fast_iterator = node->next;
            while (fast_iterator != nullptr && fast_iterator->next != nullptr) {
                slow_iterator = slow_iterator->next;
                fast_iterator = fast_iterator->next->next;
            }

            ListNode* mid_node = slow_iterator->next;
            slow_iterator->next = nullptr;
            ListNode* sorted_left_nodes = this->mergeSort(node);
            ListNode* sorted_right_nodes = this->mergeSort(mid_node);
            ListNode* sorted_merged_nodes = this->mergeTwoSortedNodes(sorted_left_nodes, sorted_right_nodes);
            return sorted_merged_nodes;
        }

    public:
        ListNode* sortList(ListNode* head) {
            if (head == nullptr) {
                return head;
            }

            ListNode* merged_nodes = this->mergeSort(head);
            return merged_nodes;
        }
};
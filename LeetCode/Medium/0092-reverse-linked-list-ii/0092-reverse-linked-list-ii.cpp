/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* current = head;
        ListNode* leftPrev = nullptr;
        
        // left 위치까지 이동
        for (int i = 1; i < left; i++) {
            leftPrev = current;
            current = current->next;
        }

        // 리버스
        ListNode* start = current;
        ListNode* reversePrev = nullptr;
        for (int i = 0; i < right - left + 1; i++) {
            ListNode* nextNode = current->next;
            
            current->next = reversePrev;
            reversePrev = current;
            current = nextNode;
        }

        // 연결
        if (leftPrev != nullptr) {
            leftPrev->next = reversePrev;
        } else {
            head = reversePrev;
        }

        start->next = current;

        return head;        
    }
};
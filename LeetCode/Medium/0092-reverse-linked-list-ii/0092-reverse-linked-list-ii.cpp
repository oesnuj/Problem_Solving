class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* current = head;
        ListNode* prev = nullptr;

        // left 위치까지 이동
        for (int i = 1; i < left; i++) {
            prev = current;
            current = current->next;
        }

        ListNode* leftStart = prev;
        ListNode* start = current;

        // reverse 시작
        prev = nullptr;
        for (int i = 0; i < right - left + 1; i++) {
            ListNode* next = current->next;

            current->next = prev;
            prev = current;
            current = next;
        }

        // 연결
        if (leftStart != nullptr) {
            leftStart->next = prev;
        } else {
            head = prev;
        }
        start->next = current;

        return head;
    }
};
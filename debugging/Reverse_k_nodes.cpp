#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse k nodes of the linked list
ListNode* reverseKGroup(ListNode* head, int k) {
    // Step 1: Check if there are at least k nodes
    ListNode* node = head;
    for (int i = 0; i < k; ++i) {
        if (!node) return head;  // Not enough nodes, return as is
        node = node->next;
    }

    // Step 2: Reverse k nodes
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    for (int i = 0; i < k; ++i) {
        next = curr->next;  // Store the next node
        curr->next = prev;  // Reverse the current node
        prev = curr;        // Move the prev pointer
        curr = next;        // Move to the next node
    }

    // Step 3: Recursively reverse the remaining groups
    if (next) {
        head->next = reverseKGroup(next, k);
    }

    // Step 4: Return the new head of the reversed group
    return prev;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// Helper function to create a linked list from user input
ListNode* createList(int n) {
    if (n == 0) return nullptr;
    cout << "Enter " << n << " elements: ";
    int val;
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* curr = head;
    for (int i = 1; i < n; ++i) {
        cin >> val;
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return head;
}

int main() {
    int n, k;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n == 0) {
        cout << "Empty list!" << endl;
        return 0;
    }

    ListNode* head = createList(n);

    cout << "Enter the value of k: ";
    cin >> k;

    if (k <= 0) {
        cout << "Invalid value of k!" << endl;
        return 0;
    }

    cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}

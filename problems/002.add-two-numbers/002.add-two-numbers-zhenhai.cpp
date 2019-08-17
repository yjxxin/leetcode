#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

// QUESTION
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order
 and each of their nodes contain a single digit. Add the two numbers and return it as a linked users.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // get l1 value
        string l1_val = "0";
        int l1_digits = 0;
        ListNode *r1 = l1;
        while(r1 != NULL){
            l1_val += r1->val * pow(10, l1_digits);
            l1_digits += 1;
            r1 = r1->next;
        }
        // get l2 value
        long l2_val = 0;
        int l2_digits = 0;
        ListNode *r2 = l2;
        while(r2 != NULL){
            l2_val += r2->val * pow(10, l2_digits);
            l2_digits += 1;
            r2 = r2->next;
        }

//        cout << l1_val << endl;
//        cout << l2_val << endl;

        // get l3 ListNode
        long long l3_value = l1_val + l2_val;
        ListNode *l3 = new ListNode(l3_value % 10);
        ListNode *r3 = l3;

        l3_value = l3_value / 10;
        while(l3_value != 0){
            int current_value = l3_value % 10;
            l3_value = l3_value / 10;
            l3->next = new ListNode(current_value);
            l3 = l3->next;
        }
        return r3;
    }
};

void print_list(ListNode* p){
    while(p != NULL){
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
}

int main(){
    // input data
    ListNode *l1 = new ListNode(2);
    ListNode *r1 = l1;
    l1->next = new ListNode(4);
    l1 = l1->next;
    l1->next = new ListNode(3);
    l1 = l1->next;

    ListNode *l2 = new ListNode(5);
    ListNode *r2 = l2;
    l2->next = new ListNode(6);
    l2 = l2->next;
    l2->next = new ListNode(4);
    l2 = l2->next;

//    print_list(r1);

    Solution solution;
    ListNode* result;
    result = solution.addTwoNumbers(r1, r2);
    print_list(result);
}



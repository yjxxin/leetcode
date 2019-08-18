#include <iostream>
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

// Tips
/*
 * 数值太大，不能利用数字进行直接相加。可利用字符串进行表示，或边读取边进行加法运算，注意进位表示。
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_current_value = 0, l2_current_value = 0, carry = 0;
        ListNode *l3 = new ListNode(0);
        ListNode *res = l3;

        while(l1 != NULL || l2 != NULL){
            l1_current_value = getCurrentIntegerValue(l1);
            l2_current_value = getCurrentIntegerValue(l2);

            int current_sum = l1_current_value + l2_current_value;
            if (carry != 0){
                current_sum = current_sum + carry;
                carry = 0;
            }
            if (current_sum > 9){
                carry = (current_sum / 10) % 10;
                current_sum = current_sum % 10;
            }
            l3->next = new ListNode(current_sum);
            l3 = l3->next;
        }
        if(carry != 0){
            l3->next = new ListNode(carry);
            l3 = l3->next;
        }
        return res->next;
    }
private:
    int getCurrentIntegerValue(ListNode* &l){
        int value = 0;
        if(l != NULL){
            value = l->val;
            l = l->next;
        }
        return value;
    }
};

void print_list(ListNode* p){
    while(p != NULL){
        cout << p->val << "->";
        p = p->next;
    }
    cout << endl;
}

int main(){
    // input l1 data
    ListNode *l1 = new ListNode(1);
    ListNode *r1 = l1;
    l1->next = new ListNode(2);
    l1 = l1->next;
    l1->next = new ListNode(3);
    l1 = l1->next;
    // input l3 data
    ListNode *l2 = new ListNode(1);
    ListNode *r2 = l2;
    l2->next = new ListNode(2);
    l2 = l2->next;
    l2->next = new ListNode(3);
    l2 = l2->next;
    // get result
    Solution solution;
    ListNode* result;
    result = solution.addTwoNumbers(r1, r2);
    print_list(result);
}



#include <iostream>
using namespace std;

/**
* 给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
* 请你将两个数相加，并以相同形式返回一个表示和的链表。
* 你可以假设除了数字0之外，这两个数都不会以0开头。
*
* 由于输入的两个链表都是逆序存储数字的位数的，因此两个链表中同一位置的数字可以直接相加。
* 我们同时遍历两个链表，逐位计算它们的和，并与当前位置的进位值相加。具体而言，如果当前两个链表处相应位置的数字为 n1,n2,
* 进位值为carry，则它们的和为 n1+n2+carry；其中，答案链表处相应位置的数字为(n1+n2+carry) mod 10，
* 而新的进位值为 (n1+n2+carry) / 10。
* 如果两个链表的长度不同，则可以认为长度短的链表的后面有若干个 00 。
* 此外，如果链表遍历结束后，有carry>0，还需要在答案链表的后面附加一个节点，节点的值为carry。
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head)
            {
                head = tail = new ListNode(sum % 10);
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        if (carry > 0)
        {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    ListNode firstl1{2};
    ListNode firstl2{4};
    ListNode firstl3{3};
    firstl1.next = &firstl2;
    firstl2.next = &firstl3;
    ListNode secondl1{5};
    ListNode secondl2{6};
    ListNode secondl3{4};
    secondl1.next = &secondl2;
    secondl2.next = &secondl3;
    Solution solution;
    ListNode *result = solution.addTwoNumbers(&firstl1, &secondl1);
    cout << "result:";
    while (result)
    {
        cout << result->val;
        result = result->next;
    }
    cout << endl;
    return 0;
}

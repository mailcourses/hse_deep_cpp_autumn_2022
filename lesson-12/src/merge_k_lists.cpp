#include <vector>
#include <queue>
#include <functional>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//O( k log k + k * n * log k )
ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    ListNode *head, *cur = new ListNode(0);
    head = cur;
    std::function<bool(ListNode*, ListNode*)> comp = [](ListNode* lhs, ListNode* rhs) {
        return lhs->val > rhs->val;
    };
    
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comp)> pq(comp);
    for (size_t i = 0; i < lists.size(); ++i ) {
        if (lists[i] != nullptr)
        {
            pq.push(lists[i]);
        }
    }
    
    // Что-то, 
    while ( !pq.empty() )
    {
        ListNode *node = pq.top();
        pq.pop();
        
        cur->next = new ListNode(node->val);
        cur = cur->next;
        
        if (node->next != nullptr)
        {
            pq.push(node->next);
        }
    }
    ListNode *result = head->next;
    delete head;
    return result;
}

int main()
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);
    
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(10);
    
    
    std::vector<ListNode *> lists = {list1, list2};
    ListNode* actual = mergeKLists( lists );
    
    while(actual != nullptr) 
    {
        std::cout << actual->val << "->";
        actual = actual->next;
    }
    std::cout << std::endl;
    
    return 0;
}

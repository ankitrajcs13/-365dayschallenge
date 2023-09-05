if (!head)
    return nullptr;
Node *iter = head;
Node *next;

while (iter)
{
    next = iter->next;
    Node *copy = new Node(iter->val);
    iter->next = copy;
    copy->next = next;

    iter = next;
}

iter = head;
while (iter){
    if (iter->random)
    {
        iter->next->random = iter->random->next;
    }
    iter = iter->next->next;
}

iter = head;
Node *pseudoHead = new Node(0);
Node *copy;
Node *copyIter = pseudoHead;
while (iter)
{
    next = iter->next->next;
    copy = iter->next;
    copyIter->next = copy;
    copyIter = copy;
    iter->next = next;
    iter = next;
}
return pseudoHead->next;
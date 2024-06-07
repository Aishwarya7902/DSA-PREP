PROBLEM :https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
VIDEO:https://www.youtube.com/watch?v=Q05ZTiqgBtw&list=PLpIkg8OmuX-IBcXsfITH5ql0Lqci1MYPM
Expected Time Complexity: O(N*N*M)
Expected Auxiliary Space: O(N) //recursion stack space



Node *mergerTwoSortedList(Node *l1,Node *l2){
    if(!l1)return l2;
    if(!l2)return l1;
    
    Node *result;
    if(l1->data< l2->data)
     {
         result=l1;
         result->bottom=mergerTwoSortedList(l1->bottom,l2);
     }
    else{
        result=l2;
        result->bottom=mergerTwoSortedList(l1,l2->bottom);
    }
    
    return result;
    
}


Node *flatten(Node *head)
{
   // Your code here
   if(!head)return NULL;
   Node *head2=flatten(head->next);
   return mergerTwoSortedList(head,head2);
}

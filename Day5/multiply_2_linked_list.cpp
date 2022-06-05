Problem: https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1/#

Code:
long long  multiplyTwoLists (Node* l1, Node* l2)
{
    long long N = 1000000007;
 long long digit1 = 0, digit2 = 0;
 while(l1!=NULL){
     digit1 =( digit1*10)%N+l1->data;
     l1 = l1->next;
 }
 while(l2!=NULL){
     digit2 = (digit2*10)%N+l2->data;
     l2 = l2->next;
 }
 return ((digit1%N)*(digit2%N))%N;
}

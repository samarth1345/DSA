/*LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15*/
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    while(head1 || head2)
    {
        if(head1)
        {
        if(head1->data>1000)
        {
            return head1->data-2001;
        }
        
        head1->data=2001+head1->data;

            head1=head1->next;
        
        }
        if(head2)
        {
        if(head2->data>1000)
        {
            return head2->data-2001;
        }
        
        head2->data=2001+head2->data;

        head2=head2->next;
        }
    }
    return -1;
}

class Node
{
    public:
        int data = 0; 
        Node* next = NULL; 
        Node* prev = NULL;  
        Node(int user_data)
        {
            data = user_data; 
        }
};

class Solution {
    public:
        int findTheWinner(int n, int k) {
            Node* head =  new Node(1);
            Node* temp = NULL;
            for(int i=1;i<n;i++)
            {
                Node* new_node =  new Node(i+1);
                if(i==1)
                {
                    head->next = new_node;
                    temp =new_node;
                }     
                else if(i==(n))
                    temp->next=head;
                else
                {
                    temp-> next = new_node;
                    temp= new_node;
                }

            }
            temp-> next = head;
            head->prev=temp;
            temp = head;
            int skip;
            for(int i=0;i<n;i++)
            {
                if(k==1)
                {
                    return head->prev->data;
                     /*   Node * deletedNode=head;
                        deletedNode->prev->next=deletedNode->next;
                        head=deletedNode->next;
                        head->prev=deletedNode->prev;
                        skip++;
                    if((temp->data)==(temp->next->data))
                        break;*/
                }
                    
                else
                    skip=1;
                while(skip!=k)
                {
                    if(skip==k-1)
                        temp->next=temp->next->next;
                    temp=temp->next;
                    skip++;
                }
                if((temp->data)==(temp->next->data))
                    break;
            }
            return temp->data;
        }
        
};
class Node
{
    public:
        int data = 0; 
        Node* next = NULL; 
        Node(int user_data)
        {
            data = user_data; 
        }
};

class Solution {
    public:
        int findTheWinner(int n, int k) {
            if(k==1)
                return n;
            Node* head =  new Node(1);
            Node* temp = head;
            for(int i=1;i<n;i++)
            {
                Node* new_node =  new Node(i+1);
                temp->next =new_node;  
                temp= new_node;
            }
            temp-> next = head;
            temp = head;
           
            for(int i=0;i<n;i++)
            {
                int skip=1;
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
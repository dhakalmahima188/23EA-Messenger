typedef struct node {
    int data;
    node *next;
} n;

class LinkList {
    private:
        n *head;
        n *tail;
        int size;
    public:
        LinkList(){
            head = NULL;
            tail = NULL;
            size = 0;
        };
        ~LinkList(){
            n *temp;
            while(head != NULL){
                temp = head;
                head = head->next;
                delete temp;
            }
        };
        
        void initialize(int s){
            for(int i=0; i < s ; i++){
                n *temp = new n;
                temp->data = i;
                temp->next = NULL;
                if(head == NULL){
                    head = temp;
                    tail = temp;
                }
                else{
                    tail->next = temp;
                    tail = temp;
                }
            }
            size = s;
        }
        void deleteallnode(){
            n *temp;
            while(head != NULL){
                temp = head;
                head = head->next;
                delete temp;
            }
            head=tail=NULL;
        }
        void add(int data){
            n *temp = new n;
            temp->data = data;
            temp->next = NULL;
            if(head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
            size++;
        };
        bool oneNode(){
            if(head->next == NULL){
                return true;
            }
            else if(head == tail){
                return true;
            }
            else{
                return false;
            }
        }

        int getHeadIndex(){
            return head->data;
        }

        void removeatindex(int index){
            if(index == 0){
                n *temp = head;
                head = head->next;
                delete temp;
            }
            else{
                n *temp = head;
                for(int i = 0; i < index - 1; i++){
                    temp = temp->next;
                }
                n *temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
            }
            size--;
        };
        int getdataatindex(int index){
            n *temp = head;
            for(int i = 0; i < index; i++){
                temp = temp->next;
            }
            return temp->data;
        };

        void print(){
            n *temp = head;
            while(temp != NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout<<endl;
        };
        int getSize(){
            return size;
        };
};
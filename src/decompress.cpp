#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "compress.cpp"
#include "convert_to_hex.cpp"
#include "convert_to_binary.cpp"
using namespace std;
class Node{
    public:
    int index;
    Node *next;
};
Node *create_node(int value){
    Node *temp= new Node;
    if(temp == NULL){
        cout<<"Memory couldn't be allocated to create a node"<<endl;
        return NULL;
    }else{
        temp->index= value;
        temp->next= NULL;
        return temp;
    }
}
class LinkedList{
    public:
    Node *head;
    LinkedList(){
        head = NULL;
    }
    void add_beginning(int value){
        Node *ptr;
        ptr=create_node(value);
        if(ptr != NULL){
            if(head == NULL){
                head =ptr;
            }else{
                ptr->next = head;
                head=ptr;
            }
            cout<<"index added"<<endl;
        }   
    }
    void add_end(int value){
        Node *ptr, *temp;
        temp =create_node(value);
        if(temp != NULL){
            if(head == NULL){
                head =temp;
            }else{
                ptr=head;
                while(ptr->next != NULL){
                    ptr= ptr->next;
                }
                ptr->next =temp;
            }
            cout<<"index added"<<value<<endl;
        }
    }
    void add_after_index(int value, int index_to_be_added){
        Node *ptr, *temp;
        temp =create_node(index_to_be_added);
        if(temp != NULL){
            if(head == NULL){
                head =temp;
            }else{
                ptr=head;
                while(ptr->index != value ){
                    ptr= ptr->next;
                }
                temp->next= ptr->next;
                ptr->next =temp;
                
            }
            cout<<value<<" index added"<<endl;
        }
    }
    
    void add_before_index(int value,int index_to_be_added){
        Node *ptr, *temp, *immediate;
        temp =create_node(index_to_be_added);
        if(temp != NULL){
            if(head == NULL){
                head =temp;
            }else{
                ptr=head;
                while(ptr->index != value ){
                    immediate=ptr;
                    ptr= ptr->next;
                }
                immediate->next= temp;
                temp->next= ptr;
            }
            cout<<"index added"<<endl;
        }
    }
    void delete_beginning(){
        Node *ptr;
        if(head == NULL){
            cout<<"No list to delete"<<endl;
        }else{
            ptr= head;
            head= head->next;
            cout<<ptr->index<<" is deleted"<<endl;
            delete ptr;
        }
    }
    void delete_end(){
        Node *ptr, *immediate;
        if(head == NULL){
            cout<<"No list to delete"<<endl;
        }else{
            ptr= head;
            while(ptr->next != NULL){
                immediate= ptr;
                ptr= ptr->next;
            }
            immediate->next =NULL;
            cout<<ptr->index<<" is deleted"<<endl;
            delete[] ptr;
        }
    } 
     
    void delete_after_index(int value){
        Node *ptr, *temp, *temptr;
        if(head == NULL){
            cout<<"No list to delete"<<endl;
        }    else
    {
        temp=head;
        
        do
        {
            temptr=temp;
            temp=temp->next;
        }while(temptr->index!=value);
        if(temp==NULL)
            cout<<"There is no index after "<<value<<" to delete.\n";
        else
        {   cout<<"The index "<<temp->index<<" is deleted.\n";
            temptr->next=temp->next;
            
            delete[] temp;
        }
    }
    }
    //delete specific index
	void delete_index(int x)
    {
        Node *ptr, *temptr;
        ptr = head;
        temptr = head;
     
        if (ptr == NULL)
        {
            cout << "NO index available";
        }
        else if (head->index == x)
        {
            head = head->next;
            cout << "index deleted  head wala: " << x << " is: " << ptr->index << endl;
            delete ptr;

        }        
    
        else
        {
            cout<<"delete index ko else bhitra"<<endl;
            while (ptr->index != x)
            {
                temptr=ptr;
                ptr = ptr->next;
         
            }
             temptr->next=ptr->next;
          
           
            cout << "index deleted : " << x << " is: " << ptr->index << endl;

            delete ptr;
        }
    }
    //check if there is only one node 
    bool check_single(){
        if(head == NULL){
            return false;
        }else{
            if(head->next == NULL){
                return true;
            }else{
                return false;
            }
        }
    }
   
    void show_list(){
        Node *ptr;
        ptr=head;
        while(ptr != NULL){
            cout<<ptr->index<<"\t";
            ptr=ptr->next;
        }
        cout<<endl;
    } 
    
};


void decompress(){
	fstream receiverFile;
	receiverFile.open("../data/decompressThis/compressed.bin", ios::in);
	
	while(!receiverFile.eof()){
		huffmanTable h;
		receiverFile>>h;
        string encodedString;
	
		cout<<h.rawstring<<endl;
        encodedString=h.rawstring;
        string decodedString="";
        LinkedList l;
        int i=0;
        for(int k=0; k<h.size;k++){
               l.add_end(k);
        }
        char c;
        cout<<encodedString.length()<<endl;
        for(int j=0;j<encodedString.length();j++){
            l.show_list();
            c=encodedString[j];
           cout<<"Character is :"<<c;           
           
                Node *ptr;
                //loop:
                ptr=l.head;
                //    cout<<"while bhitra"<<encodedString.length()<<endl;
                if(l.check_single()){      
                    // cout<<"check bhitra"<<endl;              
                    decodedString+=h.huffTable[ptr->index].data;
                    // cout<<decodedString<<endl;
                    l.delete_beginning();                   
                        for(int k=0; k<h.size;k++){
                        cout<<"2nd while bhitra ko check single ko bhitra nodes add garney"<<endl;
                          l.add_end(k);   
                        
                       
                    }
                    cout<<"yespaxi i 0 hunxa first"<<endl;
                    i=0;
                    ptr=l.head;
                    goto lm;
                      //kun loop bata niskeo??
                }
                while(ptr->next != NULL){
                     cout<<"2nd while bhitra: ptr index ko value "<<ptr->index<<endl;
                     cout<<"code ko value: "<<(h.huffTable[ptr->index]).code[i]<<endl;
                    n:
                    if((h.huffTable[ptr->index]).code[i] != c &&  ptr==l.head){                        
                        l.delete_beginning();
                        ptr=l.head;
                        cout<<"Head delete bhayepaxi ptr ko value "<<ptr->index<<endl;
                        goto n;

                    }else if(h.huffTable[ptr->next->index].code[i] != c){                      
                        l.delete_after_index(ptr->index);
                    }
                   m:
                    cout<<"check single agadi"<<endl;
                    if(l.check_single()){
                        cout<<"2nd while bhitra ko check single"<<endl;
                        decodedString+=h.huffTable[ptr->index].data;
                        cout<<decodedString<<endl;                        
                        l.delete_beginning();                   
                        for(int k=0; k<h.size;k++){
                        cout<<"2nd while bhitra ko check single ko bhitra nodes add garney"<<endl;
                          l.add_end(k);   
                        
                       
                    }   cout<<"yespaxi i 0 hunxa second"<<endl;
                        i=0;
                        ptr=l.head;
                       goto lm;
                }   
                    cout<<"ptr ko value"<<ptr->index<<endl;
                    
                        ptr= ptr->next;
                    
                    
                
                    cout<<"ptr-> next bhayesi ptr ko value"<<ptr->index<<endl;
                    
                    
                };
                if(ptr-> next == NULL){
                    
                     cout<<"last node ko lagi check: ptr index ko value "<<ptr->index<<endl;
                     cout<<"code ko value: "<<(h.huffTable[ptr->index]).code[i]<<endl;
                    if(h.huffTable[ptr->index].code[i] != c){                        
                        l.delete_end();
                    }
                    cout<<"last ko lagi garda check single agadi"<<endl;
                    if(l.check_single()){
                        cout<<"2nd while bhitra ko check single"<<endl;
                        decodedString+=h.huffTable[ptr->index].data;
                        cout<<decodedString<<endl;  
                        l.delete_beginning();                   
                        for(int k=0; k<h.size;k++){
                        cout<<"2nd while bhitra ko check single ko bhitra nodes add garney"<<endl;
                          l.add_end(k);   
                        
                       
                    }
                    cout<<"yespaxi i 0 hunxa third"<<endl;
                        i=0;
                        ptr=l.head;
                       goto lm;
                }   
                    cout<<"ptr ko value"<<ptr->index<<endl;
                    
                        ptr= l.head;
                    
                    
                    x:
                    cout<<"ptr-> next bhayesi ptr ko value"<<ptr->index<<endl;
                    
                    
               
                }
              
                
                i++;
                lm:
                cout<<"i: "<<i;
                
            }
            cout<<decodedString<<endl;
}



		
	
	receiverFile.close();
}
#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "compress.cpp"
#include "convert_to_hex.cpp"
#include "convert_to_binary.cpp"
using namespace std;


void decompress(){
	fstream receiverFile;
	receiverFile.open("../data/decompressThis/compressed.bin", ios::in);
	
	while(!receiverFile.eof()){
		huffmanTable h;
		receiverFile>>h;
	    h.printHuffmanTable();
	    cout<<h.rawstring<<endl;		
		
	}






	receiverFile.close();
}

class Node{
    public:
    int data;
    Node *next;
};
Node *create_node(int value){
    Node *temp= new Node;
    if(temp == NULL){
        cout<<"Memory couldn't be allocated to create a node"<<endl;
        return NULL;
    }else{
        temp->data= value;
        temp->next= NULL;
        return temp;
    }
}
class LinkedList{
    private:
    Node *head;
    public:
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
            cout<<"Data added"<<endl;
        }   
    }
    void add_end(int data){
        Node *ptr, *temp;
        temp =create_node(data);
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
            cout<<"Data added"<<endl;
        }
    }
    void add_after_data(int value, int data_to_be_added){
        Node *ptr, *temp;
        temp =create_node(data_to_be_added);
        if(temp != NULL){
            if(head == NULL){
                head =temp;
            }else{
                ptr=head;
                while(ptr->data != value ){
                    ptr= ptr->next;
                }
                temp->next= ptr->next;
                ptr->next =temp;
                
            }
            cout<<"Data added"<<endl;
        }
    }
    void add_before_data(int value,int data_to_be_added){
        Node *ptr, *temp, *immediate;
        temp =create_node(data_to_be_added);
        if(temp != NULL){
            if(head == NULL){
                head =temp;
            }else{
                ptr=head;
                while(ptr->data != value ){
                    immediate=ptr;
                    ptr= ptr->next;
                }
                immediate->next= temp;
                temp->next= ptr;
            }
            cout<<"Data added"<<endl;
        }
    }
    void delete_beginning(){
        Node *ptr;
        if(head == NULL){
            cout<<"No list to delete"<<endl;
        }else{
            ptr= head;
            head= head->next;
            cout<<ptr->data<<" is deleted"<<endl;
            delete ptr;
        }
    }
     
    void delete_after_data(int value){
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
        }while(temptr->data!=value);
        if(temp==NULL)
            cout<<"There is no data after "<<value<<" to delete.\n";
        else
        {
            temptr->next=temp->next;
            cout<<"The data after "<<value<<" is deleted.\n";
            delete[] temp;
        }
    }
    }
	//delete specific data
	void delete_data(int x)
    {
        Node *ptr, *temptr;
        ptr = head;
     
        if (ptr == NULL)
        {
            cout << "NO data available";
        }
        else
        {
            while (ptr->data != x)
            {
                temptr=ptr;
                ptr = ptr->next;
         
            }
             temptr->next=ptr->next;
          
           
            cout << "Data deleted : " << x << " is: " << ptr->data << endl;

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
            cout<<ptr->data<<"\t";
            ptr=ptr->next;
        }
        cout<<endl;
    } 
    
};

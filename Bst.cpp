#include <stdio.h>
using namespace std;
#include <bits/stdc++.h>

struct Node{
    
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data=data;
        left=right=nullptr;
    }
};

class Solution {
    public:

    // SEARCH INSIDE BST
    Node* searchBST(Node* root,int val)
    {
        if(root==nullptr) return nullptr;

        if(root->data==val)return root;
        if(root->data>val) return searchBST(root->left,val);
        else return searchBST(root->right,val);
    }
    
    // INSERTING A VALUE IN BST
    Node* insert(Node* root, int key) 
    {
        Node* curr=root;
        Node* prev=nullptr;
        while(curr)
        {
            if(curr->data==key) return root;
            prev=curr;
            if(curr->data<key) curr=curr->right;
            else curr=curr->left;
        }
        Node* temp=new Node(key);
        
        if(!prev) return temp;
        
        if(prev->data<key)prev->right=temp;
        else prev->left=temp;
        return root;
    }

    // DELETE NODE FROM BST 

    Node *deleteNode(Node *root, int key) 
    {
  
        if(!root) return root;
        
        if(key>root->data)
        root->right=deleteNode(root->right,key);
        else if(key<root->data)
        root->left=deleteNode(root->left,key);
        else
        {
            // IF LEFT CHILD NOT EXIST RETURN RIGHT CHILD
            if(root->left==nullptr)
            {
            Node* temp=root->right;
            delete(root);
            return temp; 
            }
            // IF RIGHT CHILD NOT EXIST RETURN LEFT CHILD
            else if(root->right==nullptr)
            {
                Node* temp=root->left;
                delete(root);
                return temp;
            }
            // IF BITH CHILD EXIST 
            // 1.FIND INORDER SUCESSOR/PREDICESSOR 
            // 2.REPLACE THE VALUE 
            // 3.DELTE THE SUCCESOR/PREDICESSOR
            else
            {
                Node * temp=root->right;
                while(temp && temp->left)temp=temp->left;
                root->data=temp->data;
                root->right=deleteNode(root->right,temp->data);
                
            }
            
        }
        return root;
    }

};
/*

Given a sorted doubly-linked list of distinct integers, in-place convert it into a height-balanced binary search tree (BST) where the difference between its left and right subtree height is at most 1.

The conversion should be done such that the previous child pointer of a doubly-linked list node should act as a left pointer for a binary tree node, and the next child pointer should act as the right pointer for a binary tree node. The conversion should also be done by only exchanging the pointers without allocating any memory for the BST nodes.

Input: 8 ⇔ 10 ⇔ 12 ⇔ 15 ⇔ 18 ⇔ 20 ⇔ 25

Output:

	  15
	/	 \
   10	  20
  /  \   /  \
 8   12 18  25

OR

	  12
	/	 \
   10	 20
  /		/  \
 8	   18  25
	  /
	 15

Any other possible representation.

*/

class Solution
{
public:

	/*
		A doubly linked list node is defined as:

		class Node
		{
		public:
			int data;					// data field
			Node* prev = nullptr;		// pointer to the prev child
			Node* next = nullptr;		// pointer to the next child

			Node() {}
			Node(int data): data(data) {}
			Node(int data, Node *prev, Node *next): data(data), prev(prev), next(next) {}
		};
	*/
	Node* solve(Node* &head,int n){
		//base case
		if(head==NULL || n<=0) return NULL;
		
		//1 case to solve
		//LNR
		//L
		Node* LST =solve(head,n/2); //get n/2 nodes
		
		//N 
		Node* root=head; //current node ko head banalo
		root->prev=LST;
		//head update karo
		head=head->next;
		
		//R 
		Node* RST=solve(head,n- n/2 -1);
		root->next=RST;
		
		return root;
		
	}
	
	int len(Node * head){
		Node* temp=head;
		int count=0;
		while(temp!=NULL){
			count++;
			temp=temp->next;
		}
		return count;
	}

	Node* constructBalancedBST(Node* head)
	{
		// Write your code here...
		//use fast slow and get mid 
		// Node* slow=head;
		// Node* fast=head;
		// while(fast!=NULL){
		// 	fast=fast->next;
		// 	if(fast!=NULL){
		// 		fast=fast->next;
		// 		slow=slow->next;
		// 	}
		// }
		int n=len(head);
		solve(head,n);
		 
	}
};

// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
  public:
	int data;
	Node* left;
	Node* right;


	Node(int val) {
	  this->data = val;
	  this->left = NULL;
	  this->right = NULL;
	}
};

Node* createTree() {
  cout << "Enter the value for Node : " ;
  int value;
  cin >> value;

  if(value == -1) {
	return NULL;
  }

  //create Node;
  Node* root = new Node(value);
  cout << "Entering in left of: "<< value << endl;
  root->left = createTree() ;
  cout << "Entering in right of: "<< value << endl;
  root->right = createTree();
  return root;
}

void preOrder(Node* root) {
  if(root == NULL) 
	return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right); 
}

void inOrder(Node* root) {
  if(root == NULL) 
	return;   
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right); 
}

void postOrder(Node* root) {
  if(root == NULL) 
	return;
	postOrder(root->left);
	postOrder(root->right); 
	cout << root->data << " ";
}

void levelOrderTraversal(Node* root) {
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  cout << endl;
  while(!q.empty()) {
	Node* temp = q.front();
	q.pop();

	if(temp == NULL) {
	  cout << endl;
	  if(!q.empty()) {
		q.push(NULL);
	  }
	}
	else {
	  cout << temp->data << " ";
	  if(temp->left != NULL) {
		q.push(temp->left);
	  }
	  if(temp->right != NULL) {
		q.push(temp->right);
	  }
	}


  }
}

void printLeftView(Node* root, int level, vector<int>& leftView) {
  if(root == NULL) 
	return;

  if(level == leftView.size()) {
	//iska matlab left view ki node milgyi h , store karlo
	leftView.push_back(root->data);
  }
  printLeftView(root->left, level+1, leftView);
  printLeftView(root->right, level+1, leftView);
}

void printRightView(Node* root, int level, vector<int>& rightView) {
  if(root == NULL) 
	return;

  if(level == rightView.size()) {
	//iska matlab left view ki node milgyi h , store karlo
	rightView.push_back(root->data);
  }
  printRightView(root->right, level+1, rightView);
  printRightView(root->left, level+1, rightView);
}

void  printTopView(Node* root){
    map<int,int> hdToNodemap;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0)); //first node
    
    while(!q.empty()){
        pair<Node*,int> temp=q.front();
        q.pop();
        
        Node* frontNode=temp.first;
        int hd=temp.second;
        
        if(hdToNodemap.find(hd)==hdToNodemap.end()){ //check map for hd value
            hdToNodemap[hd]=frontNode->data; //agar nhi hai toh hee add karo
        }
        
        if(frontNode->left!=NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right!=NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    
    for(auto it: hdToNodemap){
        cout<<it.second<<" ";
    }
}

void printBottomView(Node* root) {
	map<int,int> hdToNodemap;
	queue< pair<Node* , int> > q;
	q.push(make_pair(root, 0));

	while(!q.empty()) {
		pair<Node* ,int> temp = q.front();
		q.pop();

		Node* frontNode = temp.first;
		int hd = temp.second;

		//overwrite answers so that the deeper nodes can be stored
		//only diff is to not check for entry sidha update karte chalo
		hdToNodemap[hd] = frontNode->data;

		//child ko dekhna h 
		if(frontNode->left != NULL) {
			q.push(make_pair(frontNode->left, hd-1));
		}
		if(frontNode->right != NULL) {
			q.push(make_pair(frontNode->right, hd+1));
		}

	}
	cout << "printing bottom view: " << endl;
	for(auto i: hdToNodemap) {
		cout << i.second << " ";
	}

}

void printLeftBoundary(Node* root) {
	if(root == NULL) {
		return;
	}
	if(root->left == NULL && root->right == NULL) {
		return;
	}
	cout << root->data << " ";
	if(root->left != NULL) {
		printLeftBoundary(root->left);
	}
	else {
		printLeftBoundary(root->right);
	}
}

void printRightBoundary(Node* root) {
	if(root == NULL) {
		return;
	}
	if(root->left == NULL && root->right == NULL) {
		return;
	}
	
	if(root->right != NULL) {
			printRightBoundary(root->right);
	}
	else {
			printRightBoundary(root->left);
	}
	cout << root->data << " ";
}

void printLeafBoundary(Node* root) {
	if(root == NULL )
		return;

	if(root->left == NULL && root->right == NULL) {
		cout << root->data <<" ";
	}
	printLeafBoundary(root->left);
	printLeafBoundary(root->right);
}

void boundaryTraversal(Node* root ) {
	if(root == NULL)
		return;
		
	cout << root->data << " "; //root node lelo 
	printLeftBoundary(root->left); //then take left branch
	
	printLeafBoundary(root->left); //leaf nodes of left side
	printLeafBoundary(root->right); //right side leafs
	
	printRightBoundary(root->right); //right side branch
}

int main() {
  Node* root = createTree();
	//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 
  //levelOrderTraversal(root);

  //boundaryTraversal(root);
  //printBottomView(root);

	boundaryTraversal(root);

	// vector<int> rightView;
	//   printRightView(root, 0, rightView);

	//   cout << "Printing rightView: " << endl;
	//   for(int i=0; i<rightView.size(); i++) {
	// 	  cout << rightView[i] << " ";
	//   }
  
  // vector<int> leftView;
  // printLeftView(root, 0, leftView);

  // cout << "Printing Left View: " << endl;
  // for(int i=0; i<leftView.size(); i++) {
	 //  cout << leftView[i] << " ";
  // }

	

  return 0;
}

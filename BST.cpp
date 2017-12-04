#include<iostream>
using namespace std;


template<class Type>
class Node
{
	private:
		Type value;
		Node<Type>* left;
		Node<Type>* right;
	public:
		Node(Type num,Node<Type>* left=NULL,Node<Type>* right=NULL);
		Node(Node<Type>* left=NULL,Node<Type>* right=NULL);
		void setLeft(Node<Type>* leftchild); 
		void setRight(Node<Type>* rightchild);
		void setValue(Type key);
		Node<Type>* getLeft();
		Node<Type>* getRight();
		Type getValue();
};



template<class Type>
Node<Type>::Node(Type num,Node<Type>*left,Node<Type>*right)
{
	value=num;
	this->left=left;
	this->right=right;
}



template<class Type>
Node<Type>::Node(Node<Type>* left,Node<Type>* right)
{
	this->left=left;
	this->right=right;
}

template<class Type>
void Node<Type>::setLeft(Node<Type>* leftchild)
{
	left=leftchild;
}


template<class Type>
void Node<Type>::setRight(Node<Type>* rightchild)
{
	right=rightchild;
}



template<class Type>
void Node<Type>::setValue(Type key)
{
	value=key;
}




template<class Type>
Node<Type>* Node<Type>::getLeft()
{
	return left;
}


template<class Type>
Node<Type>* Node<Type>::getRight()
{
	return right;
}







template<class Type>
Type Node<Type>::getValue()
{
	return value;
}





template<class Type>
class BST
{
	private:
		Node<Type>* root;
		void destroy(Node<Type>* root);
		Node<Type>* InsertHelp(Node<Type>* root,Type key);
		Node<Type>* deleteMinHelp(Node<Type>* root);
		Node<Type>* getMin(Node<Type>* root);
		Node<Type>* removeNodeHelp(Node<Type>* root,Type key);
		Node<Type>* removeRootHelp(Node<Type>* root);
	public:
		BST();
		~BST();
		void insert(Type key);
		void deletemin();
		void removeNode(Type key);
		void removeRoot();
		Node<Type>* getRoot();
		void preorderTraversal(Node<Type>* root);
		void postorderTraversal(Node<Type>* root);
		void inorderTraversal(Node<Type>* root);
};



template<class Type>
void BST<Type>::destroy(Node<Type>* root)
{
	if(root==NULL)
	{
		return;
	}
	destroy(root->getLeft());
	destroy(root->getRight());
	delete root;
	root=NULL;
}



template<class Type>
BST<Type>::BST()
{
	root=NULL;
}



template<class Type>
BST<Type>::~BST()
{
	destroy(root);
}



template<class Type>
Node<Type>* BST<Type>::InsertHelp(Node<Type>* root,Type key)
{
	if(root==NULL)
	{
		return new Node<Type>(key);
	}
	if(key<root->getValue())
	{
		root->setLeft(InsertHelp(root->getLeft(),key));
	}
	else
	{
		root->setRight(InsertHelp(root->getRight(),key));
	}
	return root;
}




template<class Type>
Node<Type>* BST<Type>::deleteMinHelp(Node<Type>* root)
{
	if(root->getLeft()==NULL)
	{
		return root->getRight();
	}
	root->setLeft(deleteMinHelp(root->getLeft()));
	return root;
}


template<class Type>
Node<Type>* BST<Type>::getMin(Node<Type>* root)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->getLeft()==NULL)
	{
		return root;
	}
	return getMin(root->getLeft());
}



template<class Type>
Node<Type>* BST<Type>::removeNodeHelp(Node<Type>* root,Type key)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->getValue()<key)
	{
		root->setRight(removeNodeHelp(root->getRight(),key));
	}
	else if(root->getValue()>key)
	{
		root->setLeft(removeNodeHelp(root->getLeft() ,key));
	}
	else
	{
		Node<Type>* temp=root;
		if(root->getLeft()==NULL)
		{
			root=root->getRight();
		}
		else if(root->getRight()==NULL)
		{
			root=root->getLeft() ;
		}
		else
		{
			temp=getMin(root->getRight());
			root->setValue(temp->getValue());
			root->setRight(deleteMinHelp(root->getRight()));
		}
		delete temp;
	}
	return root;
}



template<class Type>
Node<Type>* BST<Type>::removeRootHelp(Node<Type>* root)
{
	Type temp=root->getValue();
	return removeNodeHelp(root,temp);
}



template<class Type>
Node<Type>* BST<Type>::getRoot()
{
	return root;
}




template<class Type>
void BST<Type>::insert(Type key)
{
	root=InsertHelp(root,key);
}


template<class Type>
void BST<Type>::deletemin()
{
	root=deleteMinHelp(root);
}



template<class Type>
void BST<Type>::removeNode(Type key)
{
	root=removeNodeHelp(root,key);
}

template<class Type>
void BST<Type>::removeRoot()
{
	root=removeRootHelp(root);
}






template<class Type>
void BST<Type>::preorderTraversal(Node<Type>* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->getValue()<<"  ";
	preorderTraversal(root->getLeft());
	preorderTraversal(root->getRight());
}


template<class Type>
void BST<Type>::postorderTraversal(Node<Type>* root)
{
	if(root==NULL)
	{
		return;
	}
	postorderTraversal(root->getLeft() );
	postorderTraversal(root->getRight());
	cout<<root->getValue() <<"  ";
}


template<class Type>
void BST<Type>::inorderTraversal(Node<Type>* root)
{
	if(root==NULL)
	{
		return;
	}
	postorderTraversal(root->getLeft() );
	cout<<root->getValue() <<"  ";
	postorderTraversal(root->getRight());
	
}




int main(void)
{
	BST<int> bstTree;
	Node<int>* temp=bstTree.getRoot();
	bstTree.insert(37);
	bstTree.insert(24);
	bstTree.insert(32);
	bstTree.insert(7);
	bstTree.insert(2);
	bstTree.insert(42);
	bstTree.insert(40);
	bstTree.insert(42);
	bstTree.insert(120);
	cout<<"preorder traversal this BST:";
	bstTree.preorderTraversal(bstTree.getRoot());
	cout<<endl<<"postorder traversal this BST:";
	bstTree.postorderTraversal(bstTree.getRoot());
	cout<<endl<<"inorder traversal this BST:";
	bstTree.inorderTraversal(bstTree.getRoot()); 
	cout<<endl<<endl<<"After we insert 5,we traversal it:"<<endl;
	bstTree.insert(5);
	cout<<"preorder traversal this BST:";
	bstTree.preorderTraversal(bstTree.getRoot());
	cout<<endl<<endl<<"After we delete 5,we traversal it:"<<endl;
	bstTree.removeNode(5);
	cout<<"preorder traversal this BST:";
	bstTree.preorderTraversal(bstTree.getRoot());
	cout<<endl<<endl<<"After we delete min element,we traversal it:"<<endl;
	bstTree.deletemin();
	cout<<"preorder traversal this BST:";
	bstTree.preorderTraversal(bstTree.getRoot());
	cout<<endl<<endl<<"After we remove 120,we traversal it:"<<endl;
	bstTree.removeNode(120);
	cout<<"preorder traversal this BST:";
	bstTree.preorderTraversal(bstTree.getRoot());
	cout<<endl<<endl<<"After we remove root,we traversal it:"<<endl;
	bstTree.removeRoot();
	cout<<"preorder traversal this BST:";
	bstTree.preorderTraversal(bstTree.getRoot());
	cout<<endl<<endl<<"After we insert 37,we traversal it:"<<endl;
	bstTree.insert(37);
	cout<<"preorder traversal this BST:";
	bstTree.preorderTraversal(bstTree.getRoot());
	return 0;
}

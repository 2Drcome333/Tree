#include<iostream>
using namespace std;
#include<cstdlib>



template<class Type>
class Node
{
	public:
		Node<Type>* parent;
		Node<Type>* leftchild;
		Node<Type>* rightchild;
		Type value;
		Node(Type num,Node<Type>* tleft=NULL,Node<Type>* tright=NULL,Node<Type>* tparent=NULL);
		Node(Node<Type>* tleft=NULL,Node<Type>* tright=NULL,Node<Type>* tparent=NULL);
};



template<class Type>
Node<Type>::Node(Type num,Node<Type>* tleft,Node<Type>* tright,Node<Type>* tparent)
{
	value=num;
	parent=tparent;
	leftchild=tleft;
	rightchild=tright;
}



template<class Type>
Node<Type>::Node(Node<Type>* tleft,Node<Type>* tright,Node<Type>* tparent)
{
	parent=tparent;
	leftchild=tleft;
	rightchild=tright;
}






template<class Type>
class BinaryTree
{
	private:
		Node<Type>* root;//����� 
		Node<Type>* curr;//ָ��ǰ��� 
		Node<Type>* copyTree(Node<Type>* tree); 
		void destroyTree(Node<Type>* root);//���ٵ�ǰ�� 
	public:
		BinaryTree();
		BinaryTree(BinaryTree<Type>* tree);  // ���ݵ�ǰ�������� 
		~BinaryTree();   
		void setRoot(Type num);  //���ø���� 
		void setLeftTree(BinaryTree<Type> lefttree); //���������� 
		void setRightTree(BinaryTree<Type> righttree);  //�����Һ����� 
		void setLeft(Type leftchild); //��������ֵ��� 
		void setRight(Type rightchild);  //�����Һ��� ֵ��� 
		Node<Type>* Left();  //�������� 
		Node<Type>* Right(); //�����Һ��� 
		Node<Type>* Parent();//���ظ���� 
		Node<Type>* Root();//���ظ��ڵ� 
		void moveToRoot();//��ǰcurrָ������ 
		void moveToParent();//��ǰcurrָ�򸸽�� 
		void moveToLeft();//��ǰcurrָ�����ӽ�� 
		void moveToRight();//��ǰcurrָ���Һ��ӽ�� 
		void setValue(Type num);  //���õ�ǰ���ڵ�ֵ 
		Type getValue();  //���ص�ǰ���ڵ�ֵ 
		void preorderTraverse(Node<Type>* root);  //ǰ����� 
		void postorderTraverse(Node<Type>* root);  //������� 
		void inorderTraverse(Node<Type>* root); //������� 
		int getNodeNum(Node<Type>* root);//�������Ľ���� 
		int getHeight(Node<Type>* root);//�������ĸ߶� 
};



template<class Type>
Node<Type>* BinaryTree<Type>::copyTree(Node<Type>* tree)
{
	if(tree==NULL)
	{
		return NULL;
	}
	Node<Type>* leftchild=copyTree(tree->leftchild);
	Node<Type>* rightchild=copyTree(tree->rightchild);
	Node<Type>* temp=new Node<Type>(tree->value,leftchild,rightchild);
	if(leftchild!=NULL)
	{
		leftchild->parent=temp;
	}
	if(rightchild!=NULL)
	{
		rightchild->parent=temp;
	}
	return temp;
}


template<class Type>
void BinaryTree<Type>::destroyTree(Node<Type>* root)
{
	if(root==NULL)
	{
		return;
	}
	destroyTree(root->leftchild);
	destroyTree(root->rightchild);
	delete root;
	root=NULL;
}



template<class Type>
BinaryTree<Type>::BinaryTree()
{
	root=curr=NULL;
}

template<class Type>
BinaryTree<Type>::BinaryTree(BinaryTree<Type>* tree)
{
	root=curr=tree;
}


template<class Type>
BinaryTree<Type>::~BinaryTree()
{
	destroyTree(root);	
} 




template<class Type>
void BinaryTree<Type>::setRoot(Type num)
{
	root=curr=new Node<Type>(num);
}


template<class Type>
void BinaryTree<Type>::setLeftTree(BinaryTree<Type> lefttree)
{
	curr->leftchild=copyTree(lefttree.Root());
	curr->leftchild->parent=curr;
	curr=curr->leftchild;
}


template<class Type>
void BinaryTree<Type>::setRightTree(BinaryTree<Type> righttree)
{
	curr->rightchild=copyTree(righttree.Root());
	curr->rightchild->parent=curr;
	curr=curr->rightchild;
}


template<class Type>
void BinaryTree<Type>::setLeft(Type leftchild)
{
	curr->leftchild=new Node<Type>(leftchild);
	curr->leftchild->parent=curr;
	curr=curr->leftchild; 
}


template<class Type>
void BinaryTree<Type>::setRight(Type rightchild)
{
	curr->rightchild=new Node<Type>(rightchild);
	curr->rightchild->parent=curr;
	curr=curr->rightchild;
}




template<class Type>
Node<Type>* BinaryTree<Type>::Left()
{
	return curr->left; 
}


template<class Type>
Node<Type>* BinaryTree<Type>::Right()
{
	return curr->right;	
} 



template<class Type>
Node<Type>* BinaryTree<Type>::Parent()
{
	return curr->parent;	
} 


template<class Type>
Node<Type>* BinaryTree<Type>::Root()
{
	return root;
} 


template<class Type>
void BinaryTree<Type>::moveToLeft()
{
	if(curr==NULL||curr->leftchild==NULL)
	{
		return;
	}
	curr=curr->leftchild;
}


template<class Type>
void BinaryTree<Type>::moveToRight()
{
	if(curr==NULL||curr->rightchild==NULL)
	{
		return;
	}
	curr=curr->rightchild;
}



template<class Type>
void BinaryTree<Type>::moveToParent()
{
	if(curr==NULL)
	{
		return;
	}
	curr=curr->parent;
}


template<class Type>
void BinaryTree<Type>::moveToRoot()
{
	curr=root;	
} 





template<class Type>
Type BinaryTree<Type>::getValue()
{
	return curr->value;
}


template<class Type>
void BinaryTree<Type>::setValue(Type num)
{
	curr->value=num;
}


template<class Type>
void BinaryTree<Type>::preorderTraverse(Node<Type>* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->value<<"   ";
	system("pause");
	preorderTraverse(root->leftchild);
	preorderTraverse(root->rightchild);
}


template<class Type>
void BinaryTree<Type>::postorderTraverse(Node<Type>* root)
{
	if(root==NULL)
	{
		return ;
	}
	postorderTraverse(root->leftchild);
	postorderTraverse(root->rightchild);
	cout<<root->value<<"   ";
}




template<class Type>
void BinaryTree<Type>::inorderTraverse(Node<Type>* root)
{
	if(root==NULL)
	{
		return;
	}
	inorderTraverse(root->leftchild);
	cout<<root->value<<"   ";
	inorderTraverse(root->rightchild);
}




template<class Type>
int BinaryTree<Type>::getNodeNum(Node<Type>* root)
{
	if(root==NULL)
	{
		return 0;
	}
	return 1+getNodeNum(root->leftchild)+getNodeNum(root->rightchild);
}



template<class Type>
int BinaryTree<Type>::getHeight(Node<Type>* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lheight,rheight;
	lheight=getHeight(root->leftchild);
	rheight=getHeight(root->rightchild);
	return 1+((lheight>rheight)?lheight:rheight);
}




int main(void)
{
	BinaryTree<char> tree1;
	BinaryTree<char> tree2;
	//////////////////////////construct tree1
	tree1.setRoot('A');
	tree1.setLeft('B');
	tree1.setLeft('D');
	
	tree1.setRight('G');
	tree1.moveToRoot();
	tree1.setRight('C');
	
	tree1.setLeft('E');
	tree1.moveToParent();
	tree1.setRight('F');
	/////////////////////////construct tree2 and let tree1 become the leftchild of tree2'root
	tree2.setRoot('W');
	tree2.setLeftTree(tree1);
	tree2.moveToRoot();
	tree2.setRight('W');
	///////////////////////////////////////////operation on tree1
	cout<<"preorder traverse this tree1:";
	tree1.preorderTraverse(tree1.Root());
	cout<<endl<<"postorder traverse this tree1:";
	tree1.postorderTraverse(tree1.Root());
	cout<<endl<<"inorder traverse this tree1:";
	tree1.inorderTraverse(tree1.Root());
	cout<<endl<<"current root value is:";
	tree1.moveToRoot();
	cout<<tree1.getValue();
	cout<<endl<<"the node number of current tree1 is:"<<tree1.getNodeNum(tree1.Root());
	cout<<endl<<"the height of current tree1 is:"<<tree1.getHeight(tree1.Root())<<endl;
	///////////////////////////////operation on tree2
	cout<<"preorder traverse this tree2:";
	tree2.preorderTraverse(tree2.Root());
	cout<<endl<<"postorder traverse this tree2:";
	tree2.postorderTraverse(tree2.Root());
	cout<<endl<<"inorder traverse this tree2:";
	tree2.inorderTraverse(tree2.Root());
	cout<<endl<<"current root value is:";
	tree2.moveToRoot();
	cout<<tree2.getValue();
	cout<<endl<<"the node number of current tree2 is:"<<tree2.getNodeNum(tree2.Root())<<endl;
	cout<<endl<<"the height of current tree2 is:"<<tree2.getHeight(tree2.Root())<<endl;

	return 0;
}




















#include<iostream>
using namespace std;

template<class Type>
class KVNode
{
	public:
		Type value;
		int frequence;
		KVNode<Type>* parent;
		KVNode<Type>* left;
		KVNode<Type>* right;
		KVNode(int frequence,Type value,KVNode<Type>* p=NULL,KVNode<Type>* l=NULL,KVNode<Type>* r=NULL);
		KVNode(int frequence,KVNode<Type>* p=NULL,KVNode<Type>* l=NULL,KVNode<Type>* r=NULL);
		KVNode(KVNode<Type>* p=NULL,KVNode<Type>* l=NULL,KVNode<Type>* r=NULL);
};


template<class Type>
KVNode<Type>::KVNode(int frequence,Type value,KVNode<Type>* p,KVNode<Type>* l,KVNode<Type>* r)
{
	this->value=value;
	this->frequence=frequence;
	parent=p;
	left=l;
	right=r;
}


template<class Type>
KVNode<Type>::KVNode(int frequence,KVNode<Type>* p,KVNode<Type>* l,KVNode<Type>* r)
{
	this->frequence=frequence;
	parent=p;
	left=l;
	right=r;
}

template<class Type>
KVNode<Type>::KVNode(KVNode<Type>*p,KVNode<Type>* l,KVNode<Type>* r)
{
	parent=p;
	left=l;
	right=r;	
}




template<class Type>
class Huffman
{
	private:
		KVNode<Type>* root;
		int sum;
		void destroy(KVNode<Type>* root);
		void select(KVNode<Type>* num,int& r1,int& r2,int size);
	public:
		Huffman(KVNode<Type>* leaf,int n);
		~Huffman();
		void BuildHuffman(KVNode<Type>* leaf,int n);
		void preorderTraverse(KVNode<Type>* node);
		void postorderTraverse(KVNode<Type>* node);
		void inorderTraverse(KVNode<Type>* node);
		KVNode<Type>* getRoot();
};




template<class Type>
void Huffman<Type>::destroy(KVNode<Type>* root)
{
	if(root==NULL)
	{
		return;
	}
	destroy(root->left);
	destroy(root->right);
	delete root;
	root=NULL;
}


template<class Type>
void Huffman<Type>::select(KVNode<Type>* num,int& r1,int& r2,int size)
{
	int k=0;
	while(num[k].parent!=NULL)
	{
		k++;
	}
	r1=r2=k;
	for(int i=r1;i<size-1;i++)
	{
		if(num[i+1].parent==NULL&&(num[r1].frequence>num[i+1].frequence))
		{
			r1=i+1;
		}
	}
	if(r1==r2)
	{
		while(num[++r2].parent!=NULL);
	}
	for(int i=r2;i<size-1;i++)
	{
		if((i+1)!=r1&&num[i+1].parent==NULL&&(num[r2].frequence>num[i+1].frequence))
		{
			r2=i+1;
		}
	}
}




template<class Type>
Huffman<Type>::Huffman(KVNode<Type>* leaf,int n)
{
	sum=2*n-1;
	BuildHuffman(leaf,n);
}


template<class Type>
Huffman<Type>::~Huffman()
{
	destroy(root);
}


template<class Type>
void Huffman<Type>::BuildHuffman(KVNode<Type>* leaf,int n)
{
	int k=0;
	while(n+k<sum)
	{
		int r1=0,r2=0;
	//	cout<<"n+k= "<<n+k<<endl;
		select(leaf,r1,r2,n+k);
		cout<<"r1=  "<<r1<<"  r2=  "<<r2<<endl;
		cout<<leaf[r1].frequence<<"   "<<leaf[r2].frequence<<endl;
	//	system("pause");
		leaf[n+k].frequence=leaf[r1].frequence+leaf[r2].frequence;
		leaf[n+k].left=&leaf[r1];
		leaf[n+k].right=&leaf[r2];
		leaf[r1].parent=&leaf[n+k];
		leaf[r2].parent=&leaf[n+k];
		k++;
	}
	root=&leaf[sum-1];
}




template<class Type>
void Huffman<Type>::preorderTraverse(KVNode<Type>* node)
{
	if(node==NULL)
	{
		return;
	}
	cout<<root->frequence<<"  ";
	preorderTraverse(node->left);
	preorderTraverse(node->right);
}




template<class Type>
void Huffman<Type>::postorderTraverse(KVNode<Type>* node)
{
	if(node==NULL);
	{
		return ;
	}
	postorderTraverse(node->left);
	postorderTraverse(node->right);
	cout<<node->frequence<<"  ";
}


template<class Type>
void Huffman<Type>::inorderTraverse(KVNode<Type>* node)
{
	if(node==NULL)
	{
		return;
	}
	inorderTraverse(node->left);
	cout<<node->frequence<<"  ";
	inorderTraverse(node->right);
}




template<class Type>
KVNode<Type>* Huffman<Type>::getRoot()
{
	return root;
}


int main(void)
{
	KVNode<char>* num=new KVNode<char>[100];
	num[0].value='a';
	num[0].frequence=3;
	num[1].value='b';
	num[1].frequence=2;
	num[2].value='c';
	num[2].frequence=4;
	num[3].value='d';
	num[3].frequence=1;
	num[4].value='e';
	num[4].frequence=1;
	num[5].value='f';
	num[5].frequence=5;
	num[6].value='g';
	num[6].frequence=4;
	num[7].value='h';
	num[7].frequence=7;
	Huffman<char> huffmantree(num,8);
//	cout<<huffmantree.getRoot()->frequence<<"****"<<endl;
	system("pause");
	KVNode<char>* temp=huffmantree.getRoot();
	cout<<"preorder traverse this huffman tree:";
	huffmantree.preorderTraverse(temp);
	cout<<endl<<"postorder traverse this huffman tree:";
	huffmantree.postorderTraverse(temp);
	cout<<endl<<"inorderTraverse this huffman tree:";
	huffmantree.inorderTraverse(temp);
	return 0;
}















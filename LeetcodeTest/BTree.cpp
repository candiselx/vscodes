#include "stdafx.h"
#include "BTree.h"
#include <iostream>
#include <stack>
#include <vector>
#include "CommonFunction.h"
using namespace std;

BTree::BTree(void)
{
	m_pRoot = NULL;
}


BTree::~BTree(void)
{
}

void BTree::SetRoot( BTreeNode* r )
{
   m_pRoot = r;
}

BTreeNode* BTree::GetRoot()
{
	return m_pRoot;
}

void BTree::Create(int k)
{
   BTreeNode* pNewNode = new BTreeNode(k);
   if (m_pRoot == NULL)
   {
	   m_pRoot = pNewNode;
   }
   else
   {
	   BTreeNode*pCur = m_pRoot;
	   BTreeNode*pMark = NULL;

	   //找到合适的可以插入的父节点的位置
		   while (pCur != NULL)
		   {
			   pMark = pCur;
			   if (pCur->iData>k)  
				   pCur = pCur->plChild;			   
			   else		   
				   pCur = pCur->pRChild;	   
		   }

	   //根据大小判断到底是左子树还是右子树
	   if (pMark->iData>k)
		   pMark->plChild = pNewNode;	
	   else
	        pMark->pRChild = pNewNode;
	   
   }

}

BTreeNode* BTree::RebuildTree(vector<int> &VecpreOrder,vector<int>&VecinOrder,int preBegin,int preEnd,int InBegin,int InEnd)
{
	if (preBegin<preEnd&&InBegin<InEnd)
	{
		BTreeNode* rev = new BTreeNode(VecpreOrder[preBegin]);
		vector<int> ::iterator mid = find(VecinOrder.begin()+InBegin,VecinOrder.begin()+InEnd,VecpreOrder[preBegin]);
		int span = mid - (VecinOrder.begin() + InBegin);
		rev->plChild = RebuildTree(VecpreOrder,VecinOrder,preBegin+1,preBegin+1+span,InBegin,InBegin+span);
		rev->pRChild = RebuildTree(VecpreOrder,VecinOrder,preBegin+1+span,preBegin,InBegin+span+1,InEnd);
		return rev;

	}
    return NULL;
}

void BTree::PreOrder()
{
	cout<<"PreOrder:";
	PreOrder(m_pRoot);
	cout<<endl;
}
void BTree::PreOrder( BTreeNode* r)
{
	if (r != NULL)
	{
		cout<<r->iData<<" ";
		PreOrder(r->plChild);	
		PreOrder(r->pRChild);

	}
}



void BTree::NotRePreOrder()
{
	//思路：判断当前节点，如果有右孩子，那么将右孩子push到堆栈中，如果有左孩子，那么当前节点为当前节点的左孩子，如果左孩子为空，那么从堆栈中pop一个作为当前的节点
	cout<<"NotRePreOrder:";
	if (m_pRoot == NULL)
	return;
	stack<BTreeNode*>s;
	BTreeNode* pCurrentNode = m_pRoot;//二叉树分左右支。所以光有栈是不行的，合理的运用遍历指针是关键之一
	while (pCurrentNode!= NULL)
	{
		cout<<pCurrentNode->iData<<" ";
		if (pCurrentNode->pRChild != NULL)
		{
			s.push(pCurrentNode->pRChild);
		}
		if (pCurrentNode->plChild != NULL)
		{
			pCurrentNode = pCurrentNode->plChild;
		}
		else
		{
			if (s.empty())
			break;
			pCurrentNode = s.top();
			s.pop();
		}
	}
	cout<<endl;
}

void BTree::InOrder()
{
	cout<<"InOrder:";
	InOrder(m_pRoot);
	cout<<endl;
}

void BTree::InOrder( BTreeNode* r)
{
	if (r != NULL)
	{
		
		InOrder(r->plChild);
		cout<<r->iData<<" ";
		InOrder(r->pRChild);

	}
}



void BTree::NotReInOrder()
{
	cout<<"NotReInOrder:";
	if (m_pRoot == NULL)
	return;
	stack<BTreeNode*> s;
	BTreeNode* pCurrentNode = m_pRoot;
	do 
	{
		while (pCurrentNode != NULL)
		{
			s.push(pCurrentNode);
			pCurrentNode = pCurrentNode->plChild;
		}
		//这样将左子树完全如栈
		if (!s.empty())//stack不空时退栈，然后访问该节点
		{
			pCurrentNode = s.top();
			s.pop();
			cout<<pCurrentNode->iData<<" ";
			pCurrentNode = pCurrentNode->pRChild;
		}
	} while (pCurrentNode!= NULL||!s.empty());
	//这里的pCurrentNode!= NULL表示右子树为空，然后堆栈也为空
	cout<<endl;
}

void BTree::PostOrder()
{
	cout<<"PostOrder:";
	PostOrder(m_pRoot);
	cout<<endl;
}

void BTree::PostOrder( BTreeNode*r )
{
	if (r != NULL)
	{

		PreOrder(r->plChild);
		PreOrder(r->pRChild);
		cout<<r->iData<<" ";

	}
}



void BTree::NotRePostOrder()
{
	cout<<"NotRePostOrder ";
	//注意：在遍历完左子树时还不能访问根节点，需要在遍历右子树、待右子树遍历完后才能访问根节点，所以在辅助栈工作是记录中必须注明是左子树还是右子树
	//二叉树后续遍历的非递归需要使用pair类型，因为需要记录是左进还是右进，所以每个节点必然会进栈两次
	if (m_pRoot == NULL)
	return;
	pair<BTreeNode*,char>w;
	stack<pair<BTreeNode*,char> >s;
	BTreeNode* p = m_pRoot;
	do 
	{
		while ( p != NULL)
		{
			w.first = p;
			w.second = 'L';
			s.push(w);
			p = p->plChild;
		}
		bool bContinue = true;//继续循环编制，用于将L改为R的时候就开始向右遍历
		while (bContinue && !s.empty())
		{
			w= s.top();
			s.pop();
			p = w.first;
			if (w.second == 'L')//标记为L表示左子树遍历完
			{
				w.second = 'R';
				s.push(w);
				bContinue = false;
				p = p->pRChild;
			}
			else
			{
				cout<<p->iData<<" ";//如果标记为R，表示右子树遍历完
			}
		}
	} while (!s.empty());
	cout<<endl;
}
int BTree::BTreeHeight( BTreeNode* )
{
	return 0;
}

int BTree::BTreeHeight()
{
	return 0;
}

int BTree::BTreeLeaves( BTreeNode* r)
{
	if (r == NULL)
		return 0;
	else if (r->plChild == NULL &&r->pRChild == NULL)
		return 1;
	else
	{
		return BTreeLeaves(r->plChild)+ BTreeLeaves(r->pRChild);
	}
}

int BTree::BTreeLeaves()
{
	 return BTreeLeaves(m_pRoot);

}

int BTree::BTreeSize( BTreeNode* )
{
	return 0;
}

int BTree::BTreeSize()
{
	return 0;
}

int BTree::LayerHeight()
{
	return 0;
}

bool BTree::hasPathSum( BTreeNode* root, int sum )
{
   return true;
}

int BTree::MaxDepth()
{
	return MaxDepth(m_pRoot);
}

int BTree::MaxDepth( BTreeNode*r )
{
	if (r == NULL)
	return 0;
	int LeftMax = MaxDepth(r->plChild)+1;
	int RightMax = MaxDepth(r->pRChild)+1;
	return CommonFunction::Max(LeftMax,RightMax);
}
//判断两个数是否相等
bool BTree::isSameTree( BTreeNode* p, BTreeNode* q )
{
	if (p==NULL&&q==NULL)
		return true;
	if (p==NULL&&q!=NULL||p!=NULL&&q==NULL)
		return false;
	vector<bool> allLeft;
	vector<bool> allRight;
	bool left;
	bool right;
	if (p->iData==q->iData)
	{
		left =isSameTree(p->plChild,q->pRChild);
		allLeft.push_back(true);
		return true;
	}
	else
	{
		return false;
	}
	if (p->iData==q->iData)
	{
		right =isSameTree(p->pRChild,q->pRChild);
		allRight.push_back(true);
		return true;
	}
	else
	{
		return false;
	}
	return true;
}

int BTree::pOrder( BTreeNode* root )
{
	if (root != NULL)
	{
		pOrder(root->plChild);
		pOrder(root->pRChild);
		return root->iData;
	
		

	}
	return 0;
}

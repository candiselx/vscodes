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

	   //�ҵ����ʵĿ��Բ���ĸ��ڵ��λ��
		   while (pCur != NULL)
		   {
			   pMark = pCur;
			   if (pCur->iData>k)  
				   pCur = pCur->plChild;			   
			   else		   
				   pCur = pCur->pRChild;	   
		   }

	   //���ݴ�С�жϵ���������������������
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
	//˼·���жϵ�ǰ�ڵ㣬������Һ��ӣ���ô���Һ���push����ջ�У���������ӣ���ô��ǰ�ڵ�Ϊ��ǰ�ڵ�����ӣ��������Ϊ�գ���ô�Ӷ�ջ��popһ����Ϊ��ǰ�Ľڵ�
	cout<<"NotRePreOrder:";
	if (m_pRoot == NULL)
	return;
	stack<BTreeNode*>s;
	BTreeNode* pCurrentNode = m_pRoot;//������������֧�����Թ���ջ�ǲ��еģ���������ñ���ָ���ǹؼ�֮һ
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
		//��������������ȫ��ջ
		if (!s.empty())//stack����ʱ��ջ��Ȼ����ʸýڵ�
		{
			pCurrentNode = s.top();
			s.pop();
			cout<<pCurrentNode->iData<<" ";
			pCurrentNode = pCurrentNode->pRChild;
		}
	} while (pCurrentNode!= NULL||!s.empty());
	//�����pCurrentNode!= NULL��ʾ������Ϊ�գ�Ȼ���ջҲΪ��
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
	//ע�⣺�ڱ�����������ʱ�����ܷ��ʸ��ڵ㣬��Ҫ�ڱ����������������������������ܷ��ʸ��ڵ㣬�����ڸ���ջ�����Ǽ�¼�б���ע��������������������
	//���������������ķǵݹ���Ҫʹ��pair���ͣ���Ϊ��Ҫ��¼����������ҽ�������ÿ���ڵ��Ȼ���ջ����
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
		bool bContinue = true;//����ѭ�����ƣ����ڽ�L��ΪR��ʱ��Ϳ�ʼ���ұ���
		while (bContinue && !s.empty())
		{
			w= s.top();
			s.pop();
			p = w.first;
			if (w.second == 'L')//���ΪL��ʾ������������
			{
				w.second = 'R';
				s.push(w);
				bContinue = false;
				p = p->pRChild;
			}
			else
			{
				cout<<p->iData<<" ";//������ΪR����ʾ������������
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
//�ж��������Ƿ����
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

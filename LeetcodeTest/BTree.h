#pragma once
#include <vector>
using namespace std;
class BTreeNode
{
public:
	BTreeNode(){iData = 0;plChild= NULL;pRChild = NULL;};
	BTreeNode(int data){iData =data ;plChild= NULL;pRChild = NULL;};
public:
	int iData;
	BTreeNode* plChild;
	BTreeNode* pRChild;
};
class BTree
{
public:
	
	BTree(void);
	~BTree(void);
	void SetRoot(BTreeNode* r);
	BTreeNode* GetRoot();

    void Create(int k);
	BTreeNode*  RebuildTree(vector<int> &preOrder,vector<int>&inOrder,int preBegin,int preEnd,int InBegin,int InEnd);
	void PreOrder();
	 int pOrder(BTreeNode* root);
	void InOrder();
	void PostOrder();
	bool hasPathSum(BTreeNode* root, int sum);
	void NotRePreOrder();
	void NotReInOrder();
	void NotRePostOrder();

	int BTreeHeight();
	int BTreeLeaves();
	int BTreeSize();
	int LayerHeight();
	int MaxDepth();
	bool isSameTree(BTreeNode* p, BTreeNode* q) ;
	//vector<vector<int>> levelOrder(BTreeNode* root) ;
protected:
	//vector<int>OnelevelOrder(BTreeNode* root,vector<vector<int>>& vec);
	void PreOrder(BTreeNode*);
	void InOrder(BTreeNode*);
	void PostOrder(BTreeNode*);

	int BTreeHeight(BTreeNode*);
	int BTreeLeaves(BTreeNode*);
	int BTreeSize(BTreeNode*);
	int MaxDepth(BTreeNode*r);

private:
	BTreeNode* m_pRoot;
};


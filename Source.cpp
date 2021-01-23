#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int,vector <int>> x;

struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};

void InsertToTree(Node*& pRoot, Node* pNew)
{
	if (!pRoot)
	{
		pRoot = pNew;
		return;
	}

	if (pNew->i <= pRoot->i)
		InsertToTree(pRoot->pLeft, pNew);
	else
		InsertToTree(pRoot->pRight, pNew);
}

void PrintTree(Node* pRoot, int Level)
{
	if (!pRoot)
		return;

	PrintTree(pRoot->pRight, Level + 1);

	for (int i = 0; i < Level; i++)
		cout << "  ";
	cout << pRoot->i << endl;

	PrintTree(pRoot->pLeft, Level + 1);
}

vector<int> AddNode(int i, vector<int> &Nodes) {
	Nodes.push_back(i);
	return Nodes;
}

void SumBranches(Node* pRoot,int sum,vector <int> nodes) {
	
	AddNode(pRoot->i, nodes);
	if (!pRoot->pLeft && !pRoot->pRight) {
		
		x.emplace(sum+pRoot->i,nodes);
	}
	else {
		if(pRoot->pLeft!=NULL)
		SumBranches(pRoot->pLeft, sum + pRoot->i,nodes);
		if(pRoot->pRight!=NULL)
		SumBranches(pRoot->pRight, sum + pRoot->i,nodes);
	}
}

void PrintSum(Node* pRoot, int sum) {
	vector <int> nodes;
	SumBranches(pRoot, sum, nodes);
	int a = 0;
	auto maxB = x.begin()->second;
	for (auto it = x.begin(); it != x.end(); ++it)
	{
		if (it->first > a)
		{
			a = it->first;
			maxB = it->second;
		}
	}
	cout << "branch with the largest sum is ";
	for (int i = 0; i < maxB.size();i++) {
		cout <<" "<< maxB[i];
	}
	cout <<"-> SUM = " <<a;
}


void main()
{
	int i;
	Node* pRoot = nullptr;
	while (true)
	{
		cin >> i;
		if (i == 99)
			break;

		Node* p = new Node(i);
		InsertToTree(pRoot, p);
	}

	PrintTree(pRoot, 1);
	PrintSum(pRoot,0);
}

// 5 4 8 11 13 4 7 2 1 
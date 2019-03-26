/*
		AUTHORS 	: 		 Hrishikesh S.
				  
		DEVELOPER COMMENTS : \/\*  	for describing code
							 \/\/   for removing code
							 vn		v - version, n - version number

*/

#include<bits/stdc++.h>

struct ASTNode{
	std::string symbol;
	std::string addr;
	std::vector<ASTNode *> children;
};

ASTNode *newNode(std::string ASTNode_value)
{
	ASTNode *temp = new ASTNode;
	temp->symbol = ASTNode_value;
	temp->addr = ASTNode_value;
	return temp;
}

void LevelOrderTraversalAST(ASTNode *root)
{
	if(root == NULL)
		return;
	std::queue<ASTNode *> q;
	q.push(root);
	while(!q.empty()){
		int n = q.size();
		while(n>0){
			ASTNode *p = q.front();
			q.pop();

			for(int i=0; i<int(p->children.size()); i++){
				q.push(p->children[i]);
			}
			n--;
		}
	}
	std::cout << std::endl;
}

void push_into_AST(struct ASTNode *root, std::string ASTNode_value)
{
	root->children.push_back(newNode(ASTNode_value));
}

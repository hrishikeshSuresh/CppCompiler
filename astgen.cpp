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

ASTNode *newASTNode(std::string ASTNode_value)
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
			std::cout << p->symbol << std::endl;
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
	(root->children).push_back(newASTNode(ASTNode_value));
}

ASTNode *ast_root = newASTNode("P");
//ASTNode *ast_root = c_root;
ASTNode *c_root = ast_root;

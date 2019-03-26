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
	std::vector<ASTNode *> child;
};

ASTNode *newASTNode(std::string ASTNode_value)
{
	ASTNode *temp = new ASTNode;
	temp->symbol = ASTNode_value;
	temp->addr = ASTNode_value;
	return temp;
}

ASTNode *ast_root = newASTNode("P");
ASTNode *c_root = ast_root;

void move_to_next_level(std::string node_value){
	ASTNode *newASTNode = new ASTNode;
	newASTNode->symbol = node_value;
	(ast_root->child).push_back(newASTNode);
	ast_root = newASTNode;
}

void LevelOrderTraversalAST(ASTNode *root)
{
	if(root == NULL)
		return;
	std::queue<ASTNode*> q;
	q.push(root);
	int i = 0;
	while(!q.empty()){
		int n = q.size();
		std::cout << "Level " << i << std::endl;
		while(n>0){
			ASTNode *p = q.front();
			q.pop();
			std::cout << p->symbol << " ";
			for(int i=0; i<int(p->child.size()); i++){
				q.push(p->child[i]);
			}
			n--;
		}
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
}

void push_into_AST(std::string ASTNode_value)
{
	(ast_root->child).push_back(newASTNode(ASTNode_value));
}

/*
		AUTHORS 	: 		 Hrishikesh S.
				  
		DEVELOPER COMMENTS : /*  	for describing code
							 //    	for removing code
							 vn		 v - version, n - version number

*/

#include<bits/stdc++.h>

struct NODE
{
	std::string symbol;
	std::string addr;
	std::string code;
	std::vector<NODE *> children;
};

Node *newNode(std::string node_value){
	Node *temp = new Node;
	temp->symbol = node_value;
	return temp;
}

void LevelOrderTraversal(Node *root){
	if(root == NULL)
		return;
	std::queue<Node *> q;
	q.push(root);
	while(!q.empty()){
		int n = q.size();
		while(n>0){
			Node *p = q.front();
			q.pop();

			for(int i=0; i<p->children.size(); i++){
				q.push(p->children[i]);
			}
			n--;
		}
	}
	std::cout << std::endl;
}

void push_into_AST(struct NODE node, auto node_value
{
	node.children.push_back(node_value);
	ast.no_of_elements++;
}

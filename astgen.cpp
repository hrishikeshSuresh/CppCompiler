/*
		AUTHORS 	: 		 Hrishikesh S.
				  
		DEVELOPER COMMENTS : \/\*  	for describing code
							 \/\/   for removing code
							 vn		v - version, n - version number

*/

#include<bits/stdc++.h>
#include "astgen.h"

// core
// make a node for AST
ast_node *make_ast_node(std::string op, struct ast_node *left_leaf, struct ast_node *right_leaf){
	ast_node *temp_node = new ast_node;
	temp_node->symbol = op;
	// for the binary tree
	/*
	temp_node->left = left_leaf;
	temp_node->right = right_leaf;
	*/
	// for the generic tree
	temp_node->children.push_back(left_leaf);
	temp_node->children.push_back(right_leaf);
	std::cout << "######AST : node created at " << op << std::endl;
	return temp_node;
}

// core
// make a leaf for AST
ast_node *make_ast_leaf(std::string val){
	ast_node *temp_leaf = new ast_node;
	temp_leaf->symbol = val;
	// for binary tree
	/*
	temp_leaf->left = NULL;
	temp_leaf->right = NULL;
	*/
	// for generic tree
	//temp_leaf->children.push_back(NULL);
	temp_leaf->children.push_back(NULL);
	std::cout << "######AST : leaf created at " << val << std::endl;
	return temp_leaf;
}

// core
// Prints the branch in pre-order like fashion
void LevelOrderTraversalEACHROOT(ast_node *root){
    if (root==NULL) 
        return; 
    std::queue<ast_node *> q;
	std::cout << "||" << std::endl;
	std::cout << "||" << std::endl;
	std::cout << "||" << std::endl;
	std::cout << "||" << std::endl;  
    q.push(root);  
    while (!q.empty()){
        int n = q.size(); 
        // If this node has children 
        while (n > 0){  
            ast_node *p = q.front(); 
            q.pop();
			if(q.size() > 1)
            	std::cout << p->symbol << "		";
			else
				std::cout << p->symbol << " ";
			/*			
			else
				std::cout << p->symbol << std::endl;
			*/
			// if there are not children, move to next sibling
			if((p->children)[0] == NULL)
				break;
            // Enqueue all children of the dequeued item
            for (int i=0; i< p->children.size(); i++) 
                q.push(p->children[i]); 
            n--; 
        }
		/*
		if(q.size() == 0)
			std::cout << std::endl;
		else
			std::cout << " ";
		*/
		std::cout << std::endl;		
		/*
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		*/    
    }
	//std::cout  << std::endl; 
}

// deprecated
// create a branches on node
ast_node *create_branch(ast_node *i_root, ast_node *branch){
	std::cout << "######BRANCH CREATION : " << branch->symbol << std::endl;
	i_root->children.push_back(branch);
	LevelOrderTraversalEACHROOT(i_root);
	std::cout << std::endl;
	return i_root;
}

// core, expression evaluation
// central node creation of exp evaluation
ast_node *central_node_creation(std::string op){
	std::cout << "######NODE CREATION : RL EXPRESSION EVALUATION central_node_creation()" << std::endl;
	ast_node *left_leaf = S_ast.front();
	S_ast.pop_front();
	ast_node *right_leaf = S_ast.front();
	S_ast.pop_front();
	std::cout << "######Popping " << right_leaf->symbol << " and " << left_leaf->symbol << std::endl;
	ast_node *central_node = make_ast_node(op, left_leaf, right_leaf);
	return central_node;
}

// core
// alternate central node creation for exp evaluation
ast_node *central_node_creation_exp(std::string op){
	std::cout << "######NODE CREATION : LR EXPRESSION EVALUATION central_node_creation_exp()" << std::endl;
	ast_node *right_leaf = S_ast.front();
	S_ast.pop_front();
	ast_node *left_leaf = S_ast.front();
	S_ast.pop_front();
	std::cout << "######Popping " << right_leaf->symbol << " and " << left_leaf->symbol << std::endl;
	ast_node *central_node = make_ast_node(op, left_leaf, right_leaf);
	return central_node;
}

// core
// declaration and expression
ast_node *central_node_creation_declaration(std::string op){
	std::cout << "######NODE CREATION : DECLR & EXPRESSION EVALUATION central_node_creation_declaration()" << std::endl;
	ast_node *right_leaf = S_ast.front();
	S_ast.pop_front();
	ast_node *left_leaf = S_ast.front();
	S_ast.pop_front();
	ast_node *next_leaf = S_ast.front();
	S_ast.pop_front();
	std::cout << "######Popping " << right_leaf->symbol << " and " << left_leaf->symbol << " and " << next_leaf->symbol << std::endl;
	ast_node *central_node = make_ast_node(op, left_leaf, right_leaf);
	central_node->children.push_back(next_leaf);
	return central_node;
}
// pre-order traversal for binary tree
/*
void printPreorder(struct ast_node *node){ 
    if (node == NULL) 
        return; 
    std::cout << node->symbol << " "; 
    printPreorder(node->left);  
    printPreorder(node->right); 
}
*/

// post-order traversal for binary tree
/*
void printPostorder(struct ast_node *node){
	if(node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	std::cout << node->symbol << " "; 
}
*/

// core
// branch-wise traversal for syntax tree
void LevelOrderTraversalAST(){
	std::cout << "SYNTAX TREE (BRANCH-WISE - LevelOrder)" << std::endl;
	std::cout << syn_root->head_symbol << std::endl;
	for(auto i:syn_root->children){;
		LevelOrderTraversalEACHROOT(i);
		std::cout << std::endl;
	}
	/*
	std::cout << "SYNTAX TREE (BRANCH - WISE - postOrder)" << std::endl;
	std::cout << syn_root->head_symbol << std::endl;
	for(auto i:syn_root->children){
		std::cout << i->symbol << " ";
		printPostorder(i);
		std::cout << std::endl;
	}
	*/
}

// to print stack elements
// useful for logging
void print_stack_elements(){
	std::cout << "stack contents" << std::endl;
	std::cout << "-----------------" << std::endl;
	if(!S_ast.empty()){
		std::cout << "not empty" << std::endl;
		for(auto i: S_ast){ 
			std::cout << i->symbol << std::endl;
		}
	}
	else{
		std::cout << "empty" << std::endl;
	}
	std::cout << "-----------------" << std::endl;
}

void declare_and_assign_branch(int if_flag, int for_flag, int while_flag){
	std::string op = "DECLR_STAT";
	std::cout << "######DECLR_AND_ASSIGN BRANCH declare_and_assign_branch()" << std::endl;
	// pop int, a, value
	// so there are three pops
	ast_node *first_child = S_ast.front();
	S_ast.pop_front();
	ast_node *second_child = S_ast.front();
	S_ast.pop_front();
	ast_node *third_child = S_ast.front();
	S_ast.pop_front();
	// create NODE with value
	std::cout << "######LEAFS : " <<first_child->symbol << " " << second_child->symbol << " " << third_child->symbol << std::endl; 
	ast_node *temp_node = new ast_node;
	temp_node->symbol = op;
	temp_node->children.push_back(first_child);
	temp_node->children.push_back(second_child);
	temp_node->children.push_back(third_child);
	std::cout << "######AST : node created at " << op << std::endl;	
	if(if_flag > 0 || for_flag > 0 || while_flag > 0){
		S_ast.push_front(temp_node);
		std::cout << "node pushed into stack" << std::endl;
	}
	else{	
		syn_root->children.push_back(temp_node);
		std::cout << "node pushed into tree" << std::endl;	
	}
}

void declare_assign_node_creation(){
	std::string op = "DECLR_STAT";
	std::cout << "######DECLR_AND_ASSIGN BRANCH declare_assign_node_creation()" << std::endl;
	// pop int, a, value
	// so there are three pops
	ast_node *first_child = S_ast.front();
	S_ast.pop_front();
	ast_node *second_child = S_ast.front();
	S_ast.pop_front();
	ast_node *third_child = S_ast.front();
	S_ast.pop_front();
	// create NODE with value
	std::cout << first_child->symbol << " " << second_child->symbol << " " << third_child->symbol << std::endl; 
	ast_node *temp_node = new ast_node;
	temp_node->symbol = op;
	temp_node->children.push_back(first_child);
	temp_node->children.push_back(second_child);
	temp_node->children.push_back(third_child);
	S_ast.push_front(temp_node);
	std::cout << "######DECLR_AND_ASSIGN NODE created" << std::endl;
}

void general_declaration_in_loop(){
	std::cout << "######General declaration in loop" << std::endl;
	std::string declr = "DECLR_STAT";
	ast_node *temp = new ast_node;
	temp->symbol = declr;
	ast_node *branch1 = S_ast.front();
	S_ast.pop_front();
	ast_node *branch2 = S_ast.front();
	S_ast.pop_front();
	temp->children.push_back(branch1);
	temp->children.push_back(branch2);
	S_ast.push_front(temp);
}

// core
// if
void IF_Alternate(int if_cond_flag){
	std::cout << "######Creating new branch" << std::endl;
	std::deque<ast_node*> temp;
	// start with popping
	ast_node *branch1 = S_ast.front();
	S_ast.pop_front();
	std::cout << branch1->symbol << std::endl;
	// pop till we find for
	while(branch1->symbol != "if"){
		std::cout << "adding " << branch1->symbol << std::endl;
		temp.push_front(branch1);
		if(S_ast.size() > 0){
			branch1 = S_ast.front();
			std::cout << "popping ";
			std::cout << branch1->symbol << std::endl;
			S_ast.pop_front();
		}
	}
	// branch1 will contain 'if'
	ast_node *if_struct = new ast_node;
	if_struct->symbol = "IF_STRUCT";
	// for condition
	ast_node *cond = new ast_node;
	cond->symbol = "COND";
	ast_node *branch2 = temp.front();
	cond->children.push_back(branch2);
	temp.pop_front();
	// attach all children 'if'
	// add the statements
	ast_node *statement = new ast_node;
	statement->symbol = "STATEMENT";
	ast_node *tmp_branch = new ast_node;
	std::cout << temp.size() << std::endl;
	while(temp.size() > 0){
		tmp_branch =  temp.front();
		temp.pop_front();
		std::cout << "popping and adding " << tmp_branch->symbol << std::endl;
		statement->children.push_back(tmp_branch);
	}
	if_struct->children.push_back(branch1);
	if_struct->children.push_back(cond);
	if_struct->children.push_back(statement);
	if(if_cond_flag > 1)
		S_ast.push_front(if_struct);
	else
		syn_root->children.push_back(if_struct);
	std::cout << "######IF added to the tree" << std::endl;
	return;
	// popping 'if'
	/*
	ast_node *branch1 = S_ast.front();
	S_ast.pop_front();
	// IF_STRUCT is the header of 'if' statement
	ast_node *if_struct =  new ast_node;
	if_struct->symbol = "IF_STRUCT";
	if_struct->children.push_back(branch1);


	// popping statements till relop
	std::string statement_symbol = "STATEMENT";
	// new node for statement branch
	ast_node *statement = new ast_node;
	statement->symbol = statement_symbol;
	ast_node *branch2 = S_ast.front();
	S_ast.pop_front();
	// pushing statement to STATEMENT node
	statement->children.push_back(branch2);
	LevelOrderTraversalEACHROOT(statement);
	std::cout << std::endl;
	// popping condition
	ast_node *branch3 = S_ast.front();
	S_ast.pop_front();
	while(branch3->symbol != "=="){
		if(branch3->symbol == "int"){
			S_ast.push_front(branch3);
			ast_node *temp = general_declaration_in_loop();
			statement->children.push_back(temp);
		}
		else{
			statement->children.push_back(branch3);
		}
		branch3 = S_ast.front();
		S_ast.pop_front();
	}
	// COND is the header of condition
	std::string condition_symbol = "COND";
	// STATEMENT is the header of statement
	// new node for condition branch
	ast_node *cond = new ast_node;
	cond->symbol = condition_symbol;
	std::cout << "######Added node names" << std::endl;
	/*
	ast_root->children.push_back(create_branch(statement, branch2));
	ast_root->children.push_back(create_branch(cond, branch3));		
	*/
	// pushing condition to COND node
	/*	
	cond->children.push_back(branch3);
	LevelOrderTraversalEACHROOT(if_struct);
	std::cout << std::endl;
	*/	
	/*
	LevelOrderTraversalEACHROOT(branch2);
	LevelOrderTraversalEACHROOT(branch3);
	*/
	/*
	ast_root->children.push_back(branch2);
	ast_root->children.push_back(branch3);
	*/
	/*
	if_struct->children.push_back(cond);
	if_struct->children.push_back(statement);
	syn_root->children.push_back(if_struct);	
	std::cout << "######IF added to the tree" << std::endl;
	*/
}

// for branch execution
void for_creation(int for_flag){
	std::cout << "######BRANCH EXECUTION" << std::endl;
	std::deque<ast_node*> temp;
	// start with popping
	ast_node *branch1 = S_ast.front();
	S_ast.pop_front();
	std::cout << branch1->symbol << std::endl;
	// pop till we find for
	while(branch1->symbol != "for"){
		std::cout << "adding " << branch1->symbol << std::endl;
		temp.push_front(branch1);
		if(S_ast.size() > 0){
			branch1 = S_ast.front();
			std::cout << "popping ";
			std::cout << branch1->symbol << std::endl;
			S_ast.pop_front();
		}
	}
	// branch1 will contain 'for'
	ast_node *for_struct = new ast_node;
	for_struct->symbol = "FOR_STRUCT";
	// for init expression in 'for' loop
	ast_node *init_expr = new ast_node;
	init_expr->symbol = "INIT";
	ast_node *branch2 = temp.front();
	init_expr->children.push_back(branch2);
	temp.pop_front();
	// for condition expression in 'for' loop
	ast_node *cond_expr = new ast_node;
	cond_expr->symbol = "COND"; 
	ast_node *branch3 = temp.front();
	cond_expr->children.push_back(branch3);
	temp.pop_front();
	// for unary expression in 'for' loop
	/*
	ast_node *uop_expr = new ast_node;
	uop_expr->symbol = "UNARYOP" 
	*/
	ast_node *branch4 = temp.front();
	/*
	uop_expr->children.push_back(branch4);
	*/
	temp.pop_front();
	// attach all children 'for'
	for_struct->children.push_back(branch1);
	for_struct->children.push_back(init_expr);
	for_struct->children.push_back(cond_expr);
	for_struct->children.push_back(branch4);
	// add the statements
	ast_node *statement = new ast_node;
	statement->symbol = "STATEMENT";
	ast_node *tmp_branch = new ast_node;
	std::cout << temp.size() << std::endl;
	while(temp.size() > 0){
		tmp_branch =  temp.front();
		temp.pop_front();
		std::cout << "popping and adding " << tmp_branch->symbol << std::endl;
		statement->children.push_back(tmp_branch);
	}
	for_struct->children.push_back(statement);
	if(for_flag > 1)
		S_ast.push_front(for_struct);
	else
		syn_root->children.push_back(for_struct);
	std::cout << "######FOR added to the tree" << std::endl;
	return;
}

// to create nodes for unary expression (post-fix & pre-fix)
void unary_expression_branch(std::string identifier, std::string uop){
	ast_node *unary_expr = new ast_node;
	unary_expr->symbol = "UNARY EXPR";
	unary_expr->children.push_back(make_ast_leaf(identifier));
	unary_expr->children.push_back(make_ast_leaf(uop));
	S_ast.push_front(unary_expr);
	std::cout << "######UOP added to stack" << std::endl;
	return;
}

void while_creation(int while_flag){
	std::cout << "######Creating new branch" << std::endl;
	std::deque<ast_node*> temp;
	// start with popping
	ast_node *branch1 = S_ast.front();
	S_ast.pop_front();
	std::cout << branch1->symbol << std::endl;
	// pop till we find for
	while(branch1->symbol != "while"){
		std::cout << "adding " << branch1->symbol << std::endl;
		temp.push_front(branch1);
		if(S_ast.size() > 0){
			branch1 = S_ast.front();
			std::cout << "popping ";
			std::cout << branch1->symbol << std::endl;
			S_ast.pop_front();
		}
	}
	// branch1 will contain 'if'
	ast_node *while_struct = new ast_node;
	while_struct->symbol = "WHILE_STRUCT";
	// for condition
	ast_node *cond = new ast_node;
	cond->symbol = "COND";
	ast_node *branch2 = temp.front();
	cond->children.push_back(branch2);
	temp.pop_front();
	// attach all children 'if'
	// add the statements
	ast_node *statement = new ast_node;
	statement->symbol = "STATEMENT";
	ast_node *tmp_branch = new ast_node;
	std::cout << temp.size() << std::endl;
	while(temp.size() > 0){
		tmp_branch =  temp.front();
		temp.pop_front();
		std::cout << "popping and adding " << tmp_branch->symbol << std::endl;
		statement->children.push_back(tmp_branch);
	}
	while_struct->children.push_back(branch1);
	while_struct->children.push_back(cond);
	while_struct->children.push_back(statement);
	if(while_flag > 1)
		S_ast.push_front(while_struct);
	else
		syn_root->children.push_back(while_struct);
	std::cout << "######WHILE added to the tree" << std::endl;
	return;
}

void else_creation(){
	std::cout << "######Creating new branch" << std::endl;
	std::deque<ast_node*> temp;
	// start with popping
	ast_node *branch1 = S_ast.front();
	S_ast.pop_front();
	std::cout << branch1->symbol << std::endl;
	// pop till we find for
	while(branch1->symbol != "else"){
		std::cout << "adding " << branch1->symbol << std::endl;
		temp.push_front(branch1);
		if(S_ast.size() > 0){
			branch1 = S_ast.front();
			std::cout << "popping ";
			std::cout << branch1->symbol << std::endl;
			S_ast.pop_front();
		}
	}
	// branch1 will contain 'if'
	ast_node *else_struct = new ast_node;
	else_struct->symbol = "ELSE_STRUCT";
	// attach all children 'if'
	// add the statements
	ast_node *statement = new ast_node;
	statement->symbol = "STATEMENT";
	ast_node *tmp_branch = new ast_node;
	std::cout << temp.size() << std::endl;
	while(temp.size() > 0){
		tmp_branch =  temp.front();
		temp.pop_front();
		std::cout << "popping and adding " << tmp_branch->symbol << std::endl;
		statement->children.push_back(tmp_branch);
	}
	else_struct->children.push_back(branch1);
	else_struct->children.push_back(statement);
	S_ast.push_front(else_struct);
	std::cout << "######IF added to the tree" << std::endl;
	return;
}

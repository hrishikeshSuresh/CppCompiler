/*
		AUTHORS 	: 		 Hrishikesh S.
				  
		DEVELOPER COMMENTS : \/\*  	for describing code
							 \/\/   for removing code
							 vn		v - version, n - version number

*/

#include<bits/stdc++.h>

// for representing all branches
struct ast_node{
	int node_type;
	std::string symbol;
	// for binary tree, use left & right
	/*
	ast_node *left;
	ast_node *right;
	*/
	// for generic tree use, vector of ast_node
	std::vector<ast_node *> children;
};

// syntax tree
struct ast_body{
	const char *head_symbol = "<body>";
	/*
	std::string head_symbol;
	*/
	std::vector<ast_node*> children;
};

// stack to maintain leafs and nodes for AST
std::deque<ast_node*> S_ast;

// root element for syntax tree v1
ast_node *ast_root = new ast_node;
// c-root is not used anywhere right now
ast_node *c_root = ast_root;

// root element for syntax tree v2
ast_body *syn_root = new ast_body;

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
	std::cout << "AST : node created at " << op << std::endl;
	return temp_node;
}

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
	std::cout << "AST : leaf created at " << val << std::endl;
	return temp_leaf;
}

// Prints the branch in pre-order like fashion
void LevelOrderTraversalEACHROOT(ast_node *root){ 
    if (root==NULL) 
        return; 
    std::queue<ast_node *> q;  
    q.push(root);  
    while (!q.empty()){
        int n = q.size(); 
        // If this node has children 
        while (n > 0){  
            ast_node *p = q.front(); 
            q.pop(); 
            std::cout << p->symbol << " "; 
			// if there are not children, move to next sibling
			if((p->children)[0] == NULL)
				break;
            // Enqueue all children of the dequeued item
            for (int i=0; i< p->children.size(); i++) 
                q.push(p->children[i]); 
            n--; 
        } 
		/*
        std::cout << std::endl;
		*/
    }
	/*
	std::cout << "exit" << std::endl;
	*/ 
} 

// create a branches on node
ast_node *create_branch(ast_node *i_root, ast_node *branch){
	std::cout << "BRANCH CREATION : " << branch->symbol << std::endl;
	i_root->children.push_back(branch);
	LevelOrderTraversalEACHROOT(i_root);
	std::cout << std::endl;
	return i_root;
}

ast_node *central_node_creation(std::string op){
	ast_node *left_leaf = S_ast.front();
	S_ast.pop_front();
	ast_node *right_leaf = S_ast.front();
	S_ast.pop_front();
	std::cout << "Popping " << right_leaf->symbol << " and " << left_leaf->symbol << std::endl;
	ast_node *central_node = make_ast_node(op, left_leaf, right_leaf);
	return central_node;
}

ast_node *central_node_creation_exp(std::string op){
	ast_node *right_leaf = S_ast.front();
	S_ast.pop_front();
	ast_node *left_leaf = S_ast.front();
	S_ast.pop_front();
	std::cout << "Popping " << right_leaf->symbol << " and " << left_leaf->symbol << std::endl;
	ast_node *central_node = make_ast_node(op, left_leaf, right_leaf);
	return central_node;
}

ast_node *central_node_creation_declaration(std::string op){
	ast_node *right_leaf = S_ast.front();
	S_ast.pop_front();
	ast_node *left_leaf = S_ast.front();
	S_ast.pop_front();
	ast_node *next_leaf = S_ast.front();
	S_ast.pop_front();
	std::cout << "Popping " << right_leaf->symbol << " and " << left_leaf->symbol << " and " << next_leaf->symbol << std::endl;
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

// branch-wise traversal for syntax tree
// pre-order of each node
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

void IF_node_create_branch(){
	std::cout << "Creating new branch" << std::endl; 
	// popping 'if'
	ast_node *branch1 = S_ast.front();
	S_ast.pop_front();
	// popping exprn/cond
	ast_node *branch2 = S_ast.front();
	S_ast.pop_front();
	// popping statement
	ast_node *branch3 = S_ast.front();
	S_ast.pop_front();
	// IF_STRUCT is the header of 'if' statement
	ast_node *if_struct =  new ast_node;
	if_struct->symbol = "IF_STRUCT";
	if_struct->children.push_back(branch1);
	// COND is the header of condition
	std::string condition_symbol = "COND";
	// STATEMENT is the header of statement
	std::string statement_symbol = "STATEMENT";
	// new node for statement branch
	ast_node *statement = new ast_node;
	statement->symbol = statement_symbol;
	// new node for condition branch
	ast_node *cond = new ast_node;
	cond->symbol = condition_symbol;
	std::cout << "Added node names" << std::endl;
	/*
	ast_root->children.push_back(create_branch(statement, branch2));
	ast_root->children.push_back(create_branch(cond, branch3));		
	*/
	// pushing statement to STATEMENT node
	statement->children.push_back(branch2);
	LevelOrderTraversalEACHROOT(statement);
	std::cout << std::endl;
	// pushing condition to COND node
	cond->children.push_back(branch3);
	LevelOrderTraversalEACHROOT(if_struct);
	std::cout << std::endl;
	/*
	LevelOrderTraversalEACHROOT(branch2);
	LevelOrderTraversalEACHROOT(branch3);
	*/
	/*
	ast_root->children.push_back(branch2);
	ast_root->children.push_back(branch3);
	*/
	syn_root->children.push_back(if_struct);	
	syn_root->children.push_back(cond);
	syn_root->children.push_back(statement);
	std::cout << "Added branches" << std::endl;
}

void declare_and_assign_branch(){
	std::string op = "DECLR_STAT";
	std::cout << "DECLR_AND_ASSIGN BRANCH" << std::endl;
	// pop int, a, value
	// so there are three pops
	ast_node *first_child = S_ast.front();
	S_ast.pop_front();
	ast_node *second_child = S_ast.front();
	S_ast.pop_front();
	ast_node *third_child = S_ast.front();
	S_ast.pop_front();
	// create NODE with value
	std::cout << "LEAFS : " <<first_child->symbol << " " << second_child->symbol << " " << third_child->symbol << std::endl; 
	ast_node *temp_node = new ast_node;
	temp_node->symbol = op;
	temp_node->children.push_back(first_child);
	temp_node->children.push_back(second_child);
	temp_node->children.push_back(third_child);
	syn_root->children.push_back(temp_node);
	std::cout << "AST : node created at " << op << std::endl;
}

void declare_assign_node_creation(){
	std::string op = "DECLR_STAT";
	std::cout << "DECLR_AND_ASSIGN BRANCH" << std::endl;
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
	std::cout << "DECLR_AND_ASSIGN NODE created" << std::endl;
}

ast_node *general_declaration_in_loop(){
	std::cout << "General declaration in loop" << std::endl;
	std::string declr = "DECLR_STAT";
	ast_node *temp = new ast_node;
	temp->symbol = declr;
	ast_node *branch1 = S_ast.front();
	S_ast.pop_front();
	ast_node *branch2 = S_ast.front();
	S_ast.pop_front();
	temp->children.push_back(branch1);
	temp->children.push_back(branch2);
	return temp;
}

void IF_Alternate(){
	std::cout << "Creating new branch" << std::endl; 
	// popping 'if'
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
	std::cout << "Added node names" << std::endl;
	/*
	ast_root->children.push_back(create_branch(statement, branch2));
	ast_root->children.push_back(create_branch(cond, branch3));		
	*/
	// pushing condition to COND node
	cond->children.push_back(branch3);
	LevelOrderTraversalEACHROOT(if_struct);
	std::cout << std::endl;
	/*
	LevelOrderTraversalEACHROOT(branch2);
	LevelOrderTraversalEACHROOT(branch3);
	*/
	/*
	ast_root->children.push_back(branch2);
	ast_root->children.push_back(branch3);
	*/
	if_struct->children.push_back(cond);
	if_struct->children.push_back(statement);
	syn_root->children.push_back(if_struct);	
	std::cout << "Added branches" << std::endl;
}

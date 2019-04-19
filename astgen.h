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

// to indicate the level
int level = 0;	

// stack to maintain leafs and nodes for AST
std::deque<ast_node*> S_ast;

// root element for syntax tree v1
ast_node *ast_root = new ast_node;
// c-root is not used anywhere right now
ast_node *c_root = ast_root;

// root element for syntax tree v2
ast_body *syn_root = new ast_body;

// make a node for AST
ast_node *make_ast_node(std::string op, struct ast_node *left_leaf, struct ast_node *right_leaf);

// make a leaf for AST
ast_node *make_ast_leaf(std::string val);

// Prints the branch in pre-order like fashion
void LevelOrderTraversalEACHROOT(ast_node *root);

// create a branches on node
ast_node *create_branch(ast_node *i_root, ast_node *branch);

// central node creation of exp evaluation
ast_node *central_node_creation(std::string op);

// alternate central node creation for exp evaluation
ast_node *central_node_creation_exp(std::string op);

// declaration and expression
ast_node *central_node_creation_declaration(std::string op);

// brnachwise level order traversal of tree
void LevelOrderTraversalAST();

// print all deue elements
void print_stack_elements();

// deprecated IF branch
/*
void IF_node_create_branch();
*/

// declare and assigned branch
void declare_and_assign_branch();

// declare and assign node
void declare_assign_node_creation();

// popping pattern in loops 
void general_declaration_in_loop();

// if branch execution
void IF_Alternate(int if_cond_flag);

// for branch execution
void for_creation(int for_flag);

// for unary expression (post-fix & pre-fix)
void unary_expression_branch();

// while branch execution
void while_creation(int while_flag);

// else branch execution;
void else_creation();

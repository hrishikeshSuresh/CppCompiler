/*
		AUTHORS 	: 		 Hrishikesh S.
							 Adarsha Nayak
							 Jai Agarwal
				  
		DEVELOPER COMMENTS : \/\*  	for describing code
							 \/\/   for removing code
							 vn		v - version, n - version number

*/

#include<bits/stdc++.h>
#include "symtab.h"

int curr_scope = 0;

/* 1: declaring, 0: not */
int declare = 0; 

Node* current_scope_node = new Node;
Node* root= current_scope_node;

//std::unordered_map<std::string, entry> symbolTable; (v1.1)

/* (v1.1) */
//void insert_entry(char *identifier, unsigned int scope_id = 0, std::string type = "NULL", std::string value = "NULL", unsigned int line = 0, unsigned int size = 0){
	//std::cout << "Inserting " << identifier << std::endl;
	//entry obj;
	//obj.scope_id = scope_id;
	//obj.type = type;
	//obj.value = value;
	//obj.line = line;
	//obj.size = size;
	//symbolTable[identifier] = obj;
//}

/* (v1.1) */
//void delete_entry(std::string identifier){
   	//symbolTable.erase(identifier);
	//return;
//}

/* print symbol table (v2) */
void print_symbolTable(std::unordered_map<std::string, entry> symbolTable){
	std::unordered_map<std::string, entry>::iterator itr;
    for(itr = symbolTable.begin(); itr != symbolTable.end(); ++itr){
		
		std::cout << "Identifier Name\t" << itr->first << std::endl;
		std::cout << "Scope Id\t" << itr->second.scope_id << std::endl;
		std::cout << "Type\t\t" << itr->second.type << std::endl;
		
		if(itr->second.type==UNDEF)
			std::cout << "Value\t\t" << "Not defined" << std::endl;
		else if(itr->second.type==INT_TYPE)
			std::cout << "Value\t\t" << itr->second.st_ival << std::endl;
		else if(itr->second.type==REAL_TYPE)
			std::cout << "Value\t\t" << itr->second.st_fval << std::endl;
		else if(itr->second.type==STR_TYPE)
			std::cout << "Value\t\t" << itr->second.st_sval << std::endl;
		else
			std::cout << "Value\t\t" << "Keyword" << std::endl;
		
		std::cout << "Line Numbers\t" <<std::endl;
		RefList *t = (itr->second).lines;
		//std::cout << t->lineno << " ";
		
		while (t!= NULL){
			std::cout << t->lineno << " ";
			t = t->next;
		}
		
		std::cout << std::endl;
		std::cout << "Size\t\t" << itr->second.size << std::endl;
		std::cout << "---------------------\n";
	}
}

void LevelOrderTraversal(Node * root){ 
    
	if (root==NULL) 
        return; 
    
	/* Standard level order traversal code using queue */ 
    std::queue<Node *> q;  /* Create a queue */ 
    q.push(root); /* Enqueue root */  
    while(!q.empty()){ 
		int n = q.size(); 
        /* If this node has children */ 
		//std::cout<<"HELLO1";
        while (n > 0){ 
            /* Dequeue an item from queue and print it */ 
			//std::cout<<"HELLO2";
            Node * p = q.front(); 
            q.pop(); 
            print_symbolTable(p->symbolTable); 
			//if((p->symbolTable).find("global") != (p->symbolTable).end()){
				//std::cout<<"Present"<<std::endl;
			//}
			//else{
				//std::cout<<"Not Present"<<std::endl;
			//}
            /* Enqueue all children of the dequeued item */ 
            for (int i=0; i<int(p->child.size()); i++) 
                q.push(p->child[i]); 
            n--; 
        }
        std::cout << std::endl; /* Print new line between two levels */ 
    } 
} 

/* Insert into symbol table : v2 */
void insert(char *name, int len, int type, int lineno){	
	//std::unordered_map<std::string, entry> symbolTable = current_scope_node->symbolTable;
	if((current_scope_node->symbolTable).find(name)==(current_scope_node->symbolTable).end()){
		entry obj;
		strncpy(obj.st_name,name,len);  
		obj.type = type;
		obj.scope_id = curr_scope;
		obj.lines = (RefList*) malloc(sizeof(RefList));
		obj.lines->lineno = lineno;
		obj.lines->next = NULL;
		obj.size = 0;
		current_scope_node->symbolTable[name]=obj;
		printf("Inserted %s for the first time with linenumber %d!\n", name, lineno);
	}
	else{
		if(declare == 0){
			auto itr = (current_scope_node->symbolTable).find(name);
			/* find last reference */
			RefList *t = (itr->second).lines;
			while (t->next != NULL) t = t->next;
			/* add linenumber to reference list */
			t->next = (RefList*) malloc(sizeof(RefList));
			t->next->lineno = lineno;
			t->next->next = NULL;
			printf("Found %s again at line %d!\n", name, lineno);
		}
		/* new entry */
		else{
			/* same scope - multiple declaration error! */
			auto itr = (current_scope_node->symbolTable).find(name);
			while(strcmp((itr->first).c_str(),name)==0){
				if(int((itr->second).scope_id) == curr_scope){
					printf("A multiple declaration of variable %s at line %d\n", name, lineno);
					//exit(1);
				}
				itr++;
			}
			/* other scope - create new entry */
				entry obj;
				strncpy(obj.st_name,name,len);  
				obj.type = type;
				obj.scope_id = curr_scope;
				obj.lines = (RefList*) malloc(sizeof(RefList));
				obj.lines->lineno = lineno;
				obj.lines->next = NULL;
				obj.size = 0;
				current_scope_node->symbolTable[name]=obj;
				printf("Inserted %s for a new scope with linenumber %d!\n", name, lineno);
		}
	}
}

/* Create a new scope */
void create_new_scope(){	
	Node* new_scope = new Node;
	(current_scope_node->child).push_back(new_scope);
	new_scope->parent = current_scope_node;
	current_scope_node = new_scope;
	curr_scope++;	
}

/* Exit scope */
void exit_scope(){	
	current_scope_node = current_scope_node->parent;
	curr_scope--;
}

/* Increment scope */
void incr_scope(){	
	curr_scope++;	
}

/* Decrement scope */
void decr_scope(){
	curr_scope--;
}

//void hide_scope(){ 
	//printf("Hiding scope \'%d\':\n", curr_scope);
	
	//for(auto itr = symbolTable.begin(); itr != symbolTable.end(); ++itr){
		//if((itr->second).scope_id==curr_scope){
			//symbolTable.erase(itr->first);
		//}
	//}
	
	//curr_scope--;
//}


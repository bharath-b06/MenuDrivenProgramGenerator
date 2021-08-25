#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef TREE_H
#define TREE_H
struct node                                                                 // Tree Node
{
	char key[1025];
	struct node* left;
	struct node* right;
};
typedef struct node node_t;

struct tree                                                                 // Pointer to root
{
	node_t *root;
};
typedef struct tree tree_t;
void init_tree(tree_t *ptr_tree);
void disp_tree(const tree_t *ptr_tree);
void add_node(tree_t *ptr_tree, char *parent, char *key);

#endif

struct nodelist                                                           // Node to a list
{
    char key[1025];
    int tab;
    struct nodelist *link;
};

struct list                                                                // Pointer to head of the list
{
    struct nodelist *head;
};


void init_list(struct list *ptr_list)                                    // Initialize list
{
    ptr_list->head= NULL;
}


void insert_list(struct list *ptr_list , char *key, int tab)                // Insert into list, at the head
{
    struct nodelist *temp = (struct nodelist*) malloc (sizeof(struct nodelist));
    strcpy(temp -> key,key);
    temp->tab = tab;
    temp -> link = ptr_list -> head;
    ptr_list -> head = temp;
    
}
void display_list( const struct list *ptr_list)                             // Display list
{
    printf("Display list : ");
    struct nodelist *temp = ptr_list -> head;
    while(temp != NULL)
    {
        printf(" %s->%d ", temp->key,temp->tab);
        temp = temp -> link;
    }
    printf("\n");
}
char* find_parent(struct list *ptr_list, int tab )                             // Returns the parent based on the tab count from  the linked list
{
    struct nodelist *temp = ptr_list->head;
    

    while(temp!= NULL)
    {
        if(temp->tab == tab){
            return temp->key;
        }    
        temp = temp->link;
    }
    
    return NULL;
}


void init_tree(tree_t *ptr_tree)                                        // Initialize tree
{
	ptr_tree -> root = NULL;
	//printf("init\n");
}

void disp_r(const node_t *root)                                           // display tree helper func
{
	if(root == NULL)
		return;
	if(root->left!=NULL)
	{
		printf("Parent : %s\n",root->key);
		node_t* temp = root->left;
		while(temp)
		{
			printf("\tChild : %s\n",temp->key);
			temp = temp -> right; 
		}
	}
	if(root->right)
		disp_r(root->right);
	if(root->left)
		disp_r(root->left);
}

void disp_tree(const tree_t *ptr_tree)                                   // display tree
{
	printf("disp\n");
	disp_r(ptr_tree -> root);
}

node_t* search(node_t *root, char *parent)                                  // searches for the parent node of the given key in the tree
{
	if(root == NULL) 
		return NULL;
    if(strcmp(root -> key,parent) == 0)
	{   
		return root;
	}
	if(root->right!=NULL){
        
		return search(root->right,parent);
    } 
    if(root->left!=NULL){
       
		return search(root->left,parent);
    }
    
    return NULL;   
}

void add_node(tree_t *ptr_tree, char *parent, char *key)                        // adds node to tree, child or sibling 
{
	node_t *temp = (node_t*)malloc(sizeof(node_t));
	node_t* par;
	node_t* t;
	
	strcpy(temp->key,key);
	temp -> left = temp -> right = NULL;

	if(ptr_tree -> root == NULL)
		ptr_tree -> root = temp;
    else if(strcmp(parent, " ")==0)
    {
        t = ptr_tree->root;
        while(t->right)
            t = t->right;
        t->right = temp;
    }    
	else
	{
		par = search(ptr_tree -> root,parent);
        
		if(par -> left == NULL)
        {
            
			par -> left = temp;
        }
        else
		{
			par = par -> left;
			while(par -> right)
				par = par ->right;
			
            par -> right = temp; 
        }
	}
}

// Generation functions

void gen_header()
{
	printf("#include <stdio.h>\n");
    printf("\n");
}
void prolog()
{
	printf("int main()\n");
	printf("{\n");
	
}

void gen_while()
{
    	printf("	scanf(\"%%d\", &opt);\n");
	printf("	while(opt)\n");
	printf("	{\n");
	printf("		switch(opt)\n");
	printf("		{\n");
}
void close_while()
{
	printf("		}\n"); // close switch
	printf("		scanf(\"%%d\", &opt);\n");
	printf("	}\n"); // close while
}
void epilog()
{

	printf("}\n");
	
}

void gen_fn(const char *fname)
{
    printf("void fn_%s()\n", fname);
    printf("{\n");
    printf("    printf(\"%s\\n\");\n", fname);
    printf("}\n");
}
void gen_break()
{
    printf("				break;\n");
}

void gen_case(int i, const char* s)
{
	printf("			case %d : \n", i);
	//printf("				printf(\"%s\\n\");\n", s);
	printf("				fn_%s();\n", s);
	
}

void generate_funcs(node_t *root )                      // generates functions for each node of the tree
{
    gen_fn(root->key);
    if(root->left)
        generate_funcs(root->left);
    if(root->right)
        generate_funcs(root->right);

}

void generate_cases(node_t *root, int n)                    // generates cases for the input, follows InOrder Traversal
{
    
    gen_case(n, root->key);
    ++n; 
    if(root->left){
        gen_while();
        generate_cases(root->left,1);
        close_while();
    }
    gen_break();
    if(root->right){
       generate_cases(root->right,n);  
        
    }   
}

#define MAX 1025

int main()
{
    char item[MAX];
    char prev_item[MAX];
    char parent[MAX];
    int curr_tab = 0;
    int prev_tab = -1;
    int count_ele = 0;
    int i=0; int j=0;
    tree_t t;
    struct list l;
    init_list(&l);
    init_tree(&t);

    while(fgets(item, MAX, stdin))
    {
        item[strcspn(item,"\n")] = 0;                       // To remove \n from the item

        while(item[i] == '\t')                              // Counts the tabs
        {
            ++curr_tab;
            ++i;
        }
        while(item[i] != '\0')                              // Strips the tab from item    
        {
            item[j] = item[i];
            ++i;
            ++j;
        }
        item[j] = '\0';
        
        if(count_ele == 0)                                      // Runs only once, to add first element as root of tree
        {

            strcpy(parent, item);
        	node_t *temp = (node_t*)malloc(sizeof(node_t));
        	temp -> left = temp -> right = NULL;
            t.root = temp;
            strcpy(t.root->key, item);
        }
        
        else if(curr_tab > prev_tab)                            // add child ( to the left)
        {
            strcpy(parent, prev_item);
            
            insert_list(&l, prev_item,prev_tab);
            //display_list(&l);
            add_node(&t, prev_item, item);
        }
        else if(curr_tab == prev_tab)                           // add sibling (to the right)
        {
            add_node(&t, parent, item);
        }
        else                                                    // adds items based on the parents, parent found using the linked list
        {
            
            if(curr_tab == 0)
                strcpy(parent, " ");
            else    
                strcpy(parent, find_parent(&l, curr_tab-1));
            add_node(&t, parent, item);
        }
        

        strcpy(prev_item, item);
        prev_tab = curr_tab;
        curr_tab = 0;
        i=0;j=0;
        count_ele++;
    }
    
    //Gen functions
    gen_header();
    
    generate_funcs(t.root);

    prolog();
    
    int n = 1;
    
    printf("	int opt;\n");
    
    gen_while();
    generate_cases(t.root, n);
    close_while(); 
    
    epilog();

}




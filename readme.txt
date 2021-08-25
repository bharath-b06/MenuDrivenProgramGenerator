-Setup a tree node containing a key, and a left and right node.
-Tree struct containing the root.

-Another node struct, but this time as a list node, which is made to hold the parents key as well as the count of tabs it had.(used to search one when needed).
-List struct containg the head node of the list.

-Tree as well as the linked list are initialized.
-For insertion into the list, we add the key at the head(start) of the list. Therefore the first parent will always be at the end of the list.

-find_parent() returns the parent[char] based on the count of tabs.

-search() returns the parent node.

-add_node() is used to add a node to the tree, either as a child or a sibling.

-Generation functions :
	gen_header() : contains the header
	prolog() : contains the int main()
	gen_while() : used to open a while loop containing a switch whenever needed.
	close_while() : closes the while loop appropriately
	epilog() : closes main()
	gen_fn() : generates a function based on the input string.
	gen_break() : issues a break when needed.
	gen_case() : generates the case for input string.

	generate_func() : traverses the whole tree for generates a function for each node using gen_fn() recursively.

	generate_cases() : if root->left exists, the function opens a new gen_while() and a case using gen_case() as it is a child. 
					   Break when necessary
					   if root->right exists, the function generates only a case using gen_case()
					   Tree Traversal done as InOrder

-Int main()

	item[MAX] : to store the item
	parent[MAX] : to store the items parent
	prev_item[MAX] : to store the previous item

	We read the items from menu.dat file using fgets()
	Which means we get the file line by line containing the tab spaces as well

	fgets() consumes the \n character into the buffer
	therefore we can strip it off using the strcspn() function

	count the tabs and store it in the curr_tabs variable.
	Next, strip the tabs from the string.

	Since the first element is always the root, execute an if loop which executes only once and adds the first element as root of the tree. 

	If curr_tabs is greater than the previous tab count, then it means the current item is the child of the previous item.
	Since the previous item is a parent, we add it to the linkedlist.
	Add the current item to the left of the previous item.

	if curr_tabs is equal to previous tab count, then the current item is the sibling to the previous item 
	Add current item to the right of the appropriate parent.

	if curr_tabs is less than prev_tabs, we find the appropriate parent using the linkedlist based on the count of tabs.
	Adds node according to the parent

	Generations functions have been used to generate nested switch cases, and giving 0 as input goes back a level (ie breaks the current while loop it is in)


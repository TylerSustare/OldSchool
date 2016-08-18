#include "bst.h"

#include <stdlib.h>
#include <stdio.h>
/*#include <malloc.h>*/

/*
	printTestResult: function to print the result of a test function
	param1: predicate - the result of the test
	param2: nameTestFunction - name of the function being tested
	param3: message - message passed to the test function
	post: result is printed to standard output
*/
void printTestResult(int predicate, char *nameTestFunction, char *message) {
	if (predicate) {
	   printf("%s(): PASS %s\n",nameTestFunction, message);
    } else {
	   printf("%s(): FAIL %s\n",nameTestFunction, message);
	}
}

/*
	testAddNode: function to test each node of the BST and children
	pre: tree is not null
	param: tree - the tree we are testing
	post: none
*/
void testAddNode(struct BSTree *tree) {
    assert(tree != NULL);

    printf("testing add node... \n");

    addBSTree(tree, 55);
    if (compareValues(tree->root->val,  55) != 0) {
        printf("addNode() test: FAIL to insert 55 as root\n");
    } else if (tree->cnt != 1) { /*check the tree->cnt value after adding a node to the tree*/
        printf("addNode() test: FAIL to increase count when inserting 55 as root\n");
    } else
        printf("addNode() test: PASS when adding 55 as root\n");

    addBSTree(tree, 36);
    if (compareValues(tree->root->left->val, 36) != 0) { /*check the position of the second element that is added to the BST tree*/
        printf("addNode() test: FAIL to insert 36 as left child of root\n");
    } else if (tree->cnt != 2) {
        printf("addNode() test: FAIL to increase count when inserting 36 as left of root\n");
    } else
        printf("addNode() test: PASS when adding 36 as left of root\n");

    addBSTree(tree, 78);
    if (compareValues(tree->root->right->val, 78) != 0) { /*check the position of the third element that is added to the BST tree*/
        printf("addNode() test: FAIL to insert 78 as right child of root\n");
    } else if (tree->cnt != 3) {
        printf("addNode() test: FAIL to increase count when inserting 78 as right of root\n");
    } else
        printf("addNode() test: PASS when adding 78 as right of root\n");

	addBSTree(tree, 20);
    if (compareValues(tree->root->left->left->val, 20) != 0) { /*check the position of the fourth element that is added to the BST tree*/
        printf("addNode() test: FAIL to insert 10 as left child of left of root\n");
    } else if (tree->cnt != 4) {
        printf("addNode() test: FAIL to increase count when inserting 20 as left of left of root\n");
    } else
        printf("addNode() test: PASS when adding 20 as left of left of root\n");

	addBSTree(tree, 85);
    if (compareValues(tree->root->right->right->val, 85) != 0) { /*check the position of the fourth element that is added to the BST tree*/
        printf("addNode() test: FAIL to insert 85 as right right child of left of root\n");
    } else if (tree->cnt != 5) {
        printf("addNode() test: FAIL to increase count when inserting 85 as right right child of root\n");
    } else
        printf("addNode() test: PASS when adding 85 as right right child of root\n");

	addBSTree(tree, 67);
    if (compareValues(tree->root->right->left->val, 67) != 0) { /*check the position of the fourth element that is added to the BST tree*/
        printf("addNode() test: FAIL to insert 67 as right left child of left of root\n");
    } else if (tree->cnt != 6) {
        printf("addNode() test: FAIL to increase count when inserting 67 as right left child of root\n");
    } else
        printf("addNode() test: PASS when adding 67 as right left child of root\n");

    printf("done testing add node... \n");

}

/*
	testContainsBSTree: function to test that the BST contains the elements that we added to it
	pre: tree is not null
	param: tree - the tree we are testing
	post: none
*/
void testContainsBSTree(struct BSTree *tree) {
    assert(tree != NULL);

    printTestResult(containsBSTree(tree, 55), "containsBSTree", "when test containing 55 as root");
    printTestResult(containsBSTree(tree, 36), "containsBSTree", "when test containing 36 as left of root");
    printTestResult(containsBSTree(tree, 78), "containsBSTree", "when test containing 78 as right of root");
    printTestResult(containsBSTree(tree, 20), "containsBSTree", "when test containing 20 as left-left of root");
    printTestResult(containsBSTree(tree, 67), "containsBSTree", "when test containing 20 as right-left of root");
    printTestResult(containsBSTree(tree, 85), "containsBSTree", "when test containing 20 as right-right of root");

    printTestResult(!containsBSTree(tree, 88), "containsBSTree", "when test containing 88, which is not in the tree");
}

/*
	testLeftMost: function to test the left most element
	param: tree - the tree we are testing
	pre: tree is not null
	post: none
*/
void testLeftMost(struct BSTree *tree) {
    assert(tree != NULL);
	printTestResult(compareValues(_leftMostValue(tree->root), 20) == 0, "_leftMostValue", "left most of root");

	printTestResult(compareValues(_leftMostValue(tree->root->left), 20) == 0, "_leftMostValue", "left most of left of root");

	printTestResult(compareValues(_leftMostValue(tree->root->left->left), 20) == 0, "_leftMostValue", "left most of left of left of root");

	printTestResult(compareValues(_leftMostValue(tree->root->right), 67) == 0, "_leftMostValue", "left most of right of root");
}

/*
	testRemoveNode: function to test the left most element
	param: tree - the tree we are testing
	pre: tree is not null
	post: 3 nodes have been removed from the tree
*/
void testRemoveNode(struct BSTree *tree) {

    removeNodeFromTree(tree, 13);
    /* Should output: node is not contained in the tree */

    removeNodeFromTree(tree, 20);
    printTestResult(tree->root->val == 55 && tree->root->left->left == NULL, "removeNodeFromTree", "remove left-left of root");

    removeNodeFromTree(tree, 36);
    printTestResult(compareValues(tree->root->val, 55) == 0 && tree->root->left == NULL, "removeNodeFromTree", "remove left of root");

    removeNodeFromTree(tree, 67);
    printTestResult(compareValues(tree->root->val, 55) == 0 && tree->root->right->left == NULL, "removeNodeFromTree", "remove right-left of root");

    /* Comment out these test cases and try some more interesting ones */


}

/* Main function for testing different functions of the assignment */
int main() {

    struct BSTree *tree	= newBSTree();

    testAddNode(tree);

    testContainsBSTree(tree);

    printf("printing in-order traversal \n");
    inorderTraversal(tree->root);

    printf("printing pre-order traversal \n");
    preorderTraversal(tree->root);

    printf("printing post-order traversal \n");
    postorderTraversal(tree->root);

    testLeftMost(tree);

    testRemoveNode(tree);

    freeBSTree(tree);

	return 0;
}

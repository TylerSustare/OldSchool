// Created by Tyler Sustare on 6/3/15

#pragma once
class BSTNode
{ 
	friend class BSTree;
	BSTNode(int value, BSTNode* _left, BSTNode* _right)
		: data{ value }, leftChild{ _left }, rightChild{ _right } {};

	BSTNode* leftChild;
	BSTNode* rightChild;
	int data;
	~BSTNode();
};


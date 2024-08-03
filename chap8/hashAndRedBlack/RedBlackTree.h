/*
 * origin source code: https://github.com/sean-lab/ThisIsAlgorithm/blob/main/06/RedBlackTree/RedBlackTree.h
 * This code is a small modification of the original code!!!
 * modify: RBTNode, RBT_CreateNode, RBT_SearchNode, RBT_RemoveNode
 * */
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* ElementType;

typedef struct tagRBTNode 
{
    struct tagRBTNode* Parent;
    struct tagRBTNode* Left;
    struct tagRBTNode* Right;

    enum { RED, BLACK } Color;    

    ElementType Key;
    ElementType Data;

} RBTNode;

void      RBT_DestroyTree( RBTNode* Tree );

RBTNode*  RBT_CreateNode( ElementType NewKey, ElementType NewData );
void      RBT_DestroyNode( RBTNode* Node );

RBTNode*  RBT_SearchNode( RBTNode* Tree, ElementType Key );
RBTNode*  RBT_SearchMinNode( RBTNode* Tree );
void      RBT_InsertNode( RBTNode** Tree, RBTNode *NewNode );
void      RBT_InsertNodeHelper( RBTNode** Tree, RBTNode *NewNode );
RBTNode*  RBT_RemoveNode( RBTNode** Root, ElementType Key );
void      RBT_RebuildAfterInsert( RBTNode** Tree, RBTNode* NewNode );
void      RBT_RebuildAfterRemove( RBTNode** Root, RBTNode* X );

void      RBT_RotateLeft( RBTNode** Root, RBTNode* Parent );
void      RBT_RotateRight( RBTNode** Root, RBTNode* Parent );

#endif

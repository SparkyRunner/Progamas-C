#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "Binary_Tree.h"
#include "avltree.h"
#include "rbt.h"
#define TRUE 1
#define FALSE !1

#ifndef _Chained_H
#define _Chained_H

typedef struct encad Chain;
typedef struct List List;

Chain *encad_create(void *data);
List *list_create();

//------------ Mostrar,  Inserir, Procurar e Remover ----------//
int show_list(List *l);
int Insert(List *l, void *data);
int Insert_FILE(List *l, int dados);
int equals(void *a, void *b);
void *Search(List *l,void *data, int(equals(void*, void*)));
void *Remove(List *l,void *data, int(equals(void*, void*)));

//------------ Encontrar A em B , Inserir e Remover ----------//
int Equals_Chain_Chain(List *l, List *l2);
int Add_Not_Equals_Chain_Chain(List *l, List *l2);
int Remove_Equals_Chain_Chain(List *l, List *l2);

int Equals_Chain_Hash(List *l, bank *checker);
int Add_Not_Equals_Chain_Hash(List *l, bank *checker);
int Remove_Equals_Chain_Hash(List *l, bank *checker);

int Equals_Chain_BTree(List *l, Tnode *t);
int Add_Not_Equals_Chain_BTree(List *l, Tnode *t);
int Remove_Equals_Chain_BTree(List *l, Tnode *t);

int Equals_Chain_AVLTree(List *l, Node *t);
int Add_Not_Equals_Chain_AVLTree(List *l, Node *t);
int Remove_Equals_Chain_AVLTree(List*l, Node *t);

int Equals_Chain_RBTree(List *l, RBNode *t);
int Add_Not_Equals_Chain_RBTree(List *l, RBNode *t);
int Remove_Equals_Chain_RBTree(List *l, RBNode *t);

#endif

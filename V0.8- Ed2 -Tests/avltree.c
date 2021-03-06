#include "avltree.h"

//  AVL tree node
struct node_tree
{
	int key;
	Node *left;
	Node *right;
	int height;
};


Node* createAvlTree(int dados){
    Node *root = NULL;
     FILE *arq;
    if(dados == 1){  
        arq = fopen("dados/file1000.txt","r");
    }else if(dados == 2){
        arq = fopen("dados/file5000.txt","r");
    }else if( dados == 3){
      arq = fopen("dados/file10000.txt","r");

    }else if(dados == 4){
      arq = fopen("dados/file50000.txt","r");
    }else if(dados == 5){
      arq = fopen("dados/file100000.txt","r");
    }
    else if(dados == 6){
      arq = fopen("dados/file500000.txt","r");
    }else if(dados == 7){
      arq = fopen("dados/file1000000.txt","r");
    }
    char aux[50];
   
    while(fgets(aux, 20,arq) != NULL){
      char tmp[20];
      int tmp_aux = 0;
      for(int i = 0 ; aux[i] != '\0' ; i++){
        
        if(aux[i] != ','){
          if(aux[i] != '[' && aux[i] != ']' && aux[i] != " "){
          tmp[tmp_aux] = aux[i];
          
          tmp_aux++;
          
          }
        }else{
          tmp[tmp_aux] = '\0';
		  
          int nmb = atoi(tmp);
          
          root = insert(root, nmb);
		 
          tmp_aux = 0;
        } 
      }
     
    }
    
    fclose(arq);
	
    return root;
}


// pega altura da arvore
int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// 
int max(int a, int b)
{
	return (a > b)? a : b;
}

//cria um novo no//
Node* newNode(int key)
{
    Node* node = (Node*)
						malloc(sizeof(Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; 
	return(node);
}
//rotaçao para direita//
Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	// rotaçao
	x->right = y;
	y->left = T2;

	// atualiza altura
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	
	return x;
}

//rotaçao para direita
Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	//rotaçao
	y->left = x;
	x->right = T2;

	// atualiza altura
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	
	return y;
}


int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{
	
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Dados iguais nao sao permitidos
		return node;

	/* 2.atualiza altura do antecessor */
	node->height = 1 + max(height(node->left),
						height(node->right));

	
	int balance = getBalance(node);

	//Caso estejam desbalanceados :

	// LLR
	if (balance > 1 && key < node->left->key){
        return rightRotate(node);
	}


	// RRR
	if (balance < -1 && key > node->right->key){
        return leftRotate(node);
	}


	// LRR
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// RLR
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}


	return node;
}

//pega o menor valor 
Node *minValueNode(Node *node)
{
	Node* current = node;

	
	while (current->left != NULL)
		current = current->left;

	return current;
}

//Deleta o no com a chave fornenicda

Node* deleteNode(Node* root, int key)
{
	// removaçao padrao

	if (root == NULL)
		return root;

	
	if ( key < root->key )
		root->left = deleteNode(root->left, key);

	
	else if( key > root->key )
		root->right = deleteNode(root->right, key);

	
	else
	{
		// no com um ou nenhum filho
		if( (root->left == NULL) || (root->right == NULL) )
		{
			Node *temp = root->left ? root->left :
											root->right;

			// sem filho
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // um filho
			*root = *temp; 

			free(temp);
		}
		else
		{
			
			Node* temp = minValueNode(root->right);

		
			root->key = temp->key;

			
			root->right = deleteNode(root->right, temp->key);
		}
	}

	//arvore vazia
	if (root == NULL)
	return root;

	// atualizar a altura do no atual
	root->height = 1 + max(height(root->left),
						height(root->right));

	// balanceamento desse no 
	
	int balance = getBalance(root);

	// 4 casos se estiver desbalanceado

	// LLR
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// LRR
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// RRR
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// RLR
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}


int preOrder(Node *root)
{
	if(root != NULL)
	{
		int quant = 0;
		printf("%d ", root->key);
		quant += preOrder(root->left);
		quant += preOrder(root->right);
		quant++;
		return quant;
	}
	return 0 ;
}

int compara(int a, Node *b)
{
    if(b != NULL)
	{
	    if(a == b->key)
        {
            return TRUE;
	    }
	    if(compara(a, b->left) != TRUE && compara(a, b->right) != TRUE)
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
	}
}

void iguais(Node *a, Node *b)
{
	if(a != NULL)
    {
        if(compara(a->key,b) == TRUE)
        {
            printf("%d ",a->key);
        }
        iguais(a->right,b);
        iguais(a->left,b);
	}
}

Node *inserirBA(Node *a, Node *b)
{
    if(a != NULL)
    {
        if(compara(a->key,b) != TRUE)
        {
            printf("%d ",a->key);
            b = insert(b, a->key);
        }
        b = inserirBA(a->right,b);
        b = inserirBA(a->left,b);
    }
    return b;
}

Node *removeBA(Node *a, Node *b)
{
    if(a != NULL)
    {
        if(compara(a->key,b) == TRUE)
        {
            printf("%d ",a->key);
            b = deleteNode(b, a->key);
        }
        b = removeBA(a->right,b);
        b = removeBA(a->left,b);
    }
    return b;
}

void *AVLSearch(Node *t, void *key, int (cmp)(void *, void*)){
  if(t != NULL){
    int stat = cmp(key, t->key);

    if(stat == 0){
      
        return t->key;
    }else if (stat < 0 ){
      
      return AVLSearch(t->right ,key,  cmp);

    }else {

      return AVLSearch(t->left, key, cmp);
    }
  }

   return NULL;
}

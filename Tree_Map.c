#include <stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE !TRUE

typedef struct _tree_{
  struct _tree_ *l, *r;
  void *data;

}Tnode;



int cmp(void *a , void *b){
  if(a > b){
    return -1;
  }else if (a == b){

    return 0;
  }else{

    return 1;
  }

}
Tnode *tree_create(void *data){
    Tnode *t = (Tnode*)malloc(sizeof(Tnode));
    if(t != NULL){
        t->l = NULL;
        t->r = NULL;
        t->data = data;
        return t;
    }
}
int alturaH(Tnode *t){

  int h = 0 , hl = 0 , hr = 0;

  if(t != NULL){

      hl = alturaH(t->l);

      hr = alturaH(t->r);

      if(hl > hr){

        h = hl +1;

      }else{

        h = hr + 1;

      }
      return h;
  }
  return 0;
}

int contaG2(Tnode *t){
  int n = 0;
  if(t != NULL){
    int nl = 0, nr = 0;
    if(t->l != NULL && t->r != NULL){
      n = 1;
      nl = contaG2(t->l);
      nr = contaG2(t->r);
      return nl+n +nr;
    }
  }
  return 0;

}

void *abQuery(Tnode *t, void *key, int (cmp)(void *, void*)){
  if(t != NULL){
    int stat = cmp(key, t->data);

    if(stat == 0){

        return t->data;
    }else if (stat < 0 ){

      return abQuery(t->r ,key,  cmp);

    }else {

      return abQuery(t->l, key, cmp);
    }
  }

   return NULL;
}

Tnode *Insert(Tnode *t, void *data, int(*cmp)(void *, void *)){
  int stat; Tnode *newt;
  if(t != NULL){
    stat = cmp(data , t->data);

    if(stat > 0){

        t->l = Insert(t->l, data, cmp);


    }else if(stat < 0){

      t->r = Insert(t->r, data, cmp);


    }else{
        return t;

    }

  }else{

    newt = (Tnode*)malloc (sizeof(Tnode));
    if(newt != NULL){
      newt->data = data;
      newt->l = NULL;
      newt->r = NULL;
      return newt;
    }
  }

}

void *abMaior(Tnode *t, int (*cmp)(void*, void*)){
    int m = NULL, m2 = NULL;
    if(t != NULL){
        m  = t->data;
        m2 = abMaior(t->r, cmp);

        if(m2 != NULL){
            if(m >= m2){
                return m;
            }
            return m2;

        }
        return m;
    }
    return NULL;
}
void *abMenor(Tnode *t, int (*cmp)(void*, void*)){
    int m = NULL, m2= NULL;
    if(t != NULL){
        m = t->data;
        m2 = abMenor(t->l, cmp);
        if(m2 != NULL){
            if(m <= m2){
                return m;
            }
            return m2;
        }
        return m;
    }
    return NULL;
}

void Simetrica(Tnode *t){

    if(t != NULL){
        Simetrica(t->l);
        printf("data %d ", t->data);
        Simetrica(t->r);
    }
}

void Pre_ordem(Tnode *t){

    if(t != NULL){
        printf("data %d ", t->data);
        Pre_ordem(t->l);
        Pre_ordem(t->r);
    }
}
void Pos_ordem(Tnode *t){

    if(t != NULL){
        Pos_ordem(t->l);
        Pos_ordem(t->r);
        printf("data %d ", t->data);
    }
}

int abDual(Tnode *t, Tnode *t2, int(*cmp)(void *, void *)){
    int stat = NULL, stat2 = NULL ;
    if(t != NULL && t2 != NULL){

        stat = abDual(t->l, t2->l, cmp);
        stat2 = abDual(t->r, t2->r, cmp);

        if(t->data <= t2->data && stat != FALSE && stat2 != FALSE){
            return TRUE;
        }else{
            return FALSE;
        }

    }else if (t != NULL && t2 == NULL){
        return FALSE;
    }else if (t == NULL  && t2 != NULL){
        return FALSE;
    }
    return TRUE;

}


int main(void) {

    Tnode *root = tree_create(7);
    Insert(root, 5, cmp);
    Insert(root, 10, cmp);
    Insert(root, 4, cmp);
    Insert(root, 8, cmp);

    printf("Pre ordem : ");
    Pre_ordem(root);
    printf("\n Simetrica : ");
    Simetrica(root);
    printf("\n Pos ordem : ");
    Pos_ordem(root);

    printf("\n Query  = %d ", abQuery(root, 8, cmp));
    printf("\n Altura H = %d", alturaH(root));

    Tnode *root2 = tree_create(10);
    Insert(root2, 7, cmp);
    Insert(root2, 12, cmp);
    Insert(root2, 5, cmp);
    Insert(root2, 11, cmp);

    int stat = abDual(root,root2, cmp);
    if(stat == TRUE){
        printf(" \n opa");
    }else{
        printf("\n ue");
    }


}

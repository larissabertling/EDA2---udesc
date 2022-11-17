struct Reg *Interseccao(struct Reg *p, struct Reg *q){
  struct Reg *pp,*r,*novo;
 
  r = NULL;
  pp = p;
  while(pp != NULL){
    if( Pertence(q, pp->num) ){
      novo = (struct Reg*)malloc(sizeof(struct Reg));
      if(novo == NULL){
        printf("Memória insuficiente\n");
        exit(1);
      }
      novo->num = pp->num;
      if(r == NULL){
        r = novo;
        novo->prox = NULL;
      }
      else{
        novo->prox = r;
        r = novo;
      }
    }
    pp = pp->prox;
  }
  return r;
}



struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
}

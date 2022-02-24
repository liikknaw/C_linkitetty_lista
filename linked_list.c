#include <stdio.h>
#include <stdlib.h>

typedef struct luku{
    int arvo;
    struct luku* seuraava;
} LUKU;

void tulosta(LUKU *head){
    LUKU *ptr = head;
    printf("Listassa:");
    while(ptr != NULL){
        printf(" %d", ptr->arvo);
        ptr = ptr->seuraava;
    }
    printf("\n");
}

LUKU *varaaLuku(int luku){
    LUKU *varattu;
    if ((varattu = malloc(sizeof(LUKU))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    varattu->arvo = luku;
    varattu->seuraava = NULL;
    return varattu;
}

LUKU *lisaaEteen(LUKU *head, LUKU *lisattava){
    lisattava->seuraava = head;
    return lisattava;
}

LUKU *lisaaEteen2(LUKU *head, LUKU *lisattava){
    lisattava->seuraava = head;
    return lisattava;
}

void lisaaJalkeen(LUKU *lisattava, LUKU *edeltava){
    lisattava->seuraava = edeltava->seuraava;
    edeltava->seuraava = lisattava;
}

void lisaaLoppuun(LUKU *lisattava, LUKU *head){
    LUKU *temp = head;
    while(temp->seuraava != NULL){
        temp = temp->seuraava;
    }
    temp->seuraava = lisattava;
}

LUKU *etsiLuku(LUKU *head, int arvo){
    LUKU *temp = head;
    while(temp != NULL){
        if(temp->arvo == arvo){
            return temp;
        }
        temp = temp->seuraava;
    }
    return NULL;
}
void vapauta(LUKU *head){
    LUKU *temp = head;
    if(temp->seuraava != NULL){
        vapauta(temp->seuraava);
    }
    free(head);
}

int main(){
    LUKU *head = NULL;
    LUKU *tmp;
    
    for(int i = 1; i<26; i++){
        tmp = varaaLuku(i);
        head = lisaaEteen(head, tmp);
    }

    tmp = etsiLuku(head, 13);
    lisaaJalkeen(varaaLuku(69), tmp);
    printf("Löytyi arvo %d\n", tmp->arvo);
    lisaaLoppuun(varaaLuku(99), head);
    tulosta(head);
    vapauta(head);

    return 0;
}
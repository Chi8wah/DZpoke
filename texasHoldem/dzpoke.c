#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

int account[11]={0},money[11]={0},flag[11]={0},n;

int game(){
    char ch="";
    int i,F,max,pos,x,temp,pool;

startGame:
    printf("Start new game?(Y/N)\n");
    fflush(stdin);scanf("%c",&ch);
    if(ch=='N'){
        return 0;
    }
    pos=1;pool=0;
    for(i=1;i<=n;i++){
        flag[i]=1;
        money[i]=-100;
    }
    printf("Tickets -100!\n");

startTurn:
    for(i=1;i<=n;i++){
        account[i]+=money[i];
        pool+=abs(money[i]);
        money[i]=0;
        printf("Player %d has $%d\n",i,account[i]);
    }

    printf("The pool has $%d!\nStart new turn?(Y/N)\n",pool);
    fflush(stdin);scanf("%c",&ch);
    if(ch=='N'){
        printf("Game Over!The winner is:");
        scanf("%d",&i);
        account[i]+=pool;
        for(i=1;i<=n;i++){
            printf("Player %d has $%d\n",i,account[i]);
        }
        goto startGame;
    }
    F=0;max=0;i=pos;
    do{
       if(!flag[i]){
            goto endPlayerTurn;
       }

       betMoney:
       printf("Min= $%d\nPlayer %d wants to bet:($0 means exit) $",max,i);
       scanf("%d",&x);
       if(x==0){
           if(F==1){
                flag[i]=0;
           }
           goto endPlayerTurn;
       }
       if(x<max){
            printf("Player %d bet too little! Try again!\n",i);
            goto betMoney;
       }
       if(x>max){
            max=x;
            pos=i;
       }
       F=1;
       money[i]=-x;

       endPlayerTurn:
           i++;
           if(i>n){
                i=1;
           }
    }
    while(i!=pos);
    goto startTurn;
}

int main(){
    char ch="";
    int m,i;
startMain:
    printf("Start new room?(Y/N)\n");
    fflush(stdin);scanf("%c",&ch);
    if(ch=='N'){
        return 0;
    }
    printf("Players(2~10): ");
    fflush(stdin);scanf("%d",&n);
    if(n<2||n>10){
        printf("Out of range! Start again.\n");
        goto startMain;
    }

    printf("How much money does each player has: ");
    fflush(stdin);scanf("%d",&m);
    for(i=1;i<=n;i++){
        account[i]=m;
    }

    if(!game()){
        goto startMain;
    }
}

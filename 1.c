/*                                    this program is made to show a game

starting for two players p1 and p2. first we will distribute cards equally(means 26 each) and randomly between them. each player will holds their
all the cards in their stack.


each player will play its card one by one from their deck which is arranged in stack format. starting from p1. now we will store these playing
cards in some another stack (lets say stack k) and wait until the played cards of any player (lets say player p2)match with the card
which is already present in stack k and then we will pop all the cards from the stack k and push them into the stack of that player p2 and the
game again start from player p2


and this process continuously goes on until anyone of the player losses all of its cards
the player which will have the cards still in the deck will be declared as winner
if both losses their all cards than match will get draw


we are saying stack means all the operation that we will do on them  will only as per stack data type format
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>///uses for time() fuction
#include<ctype.h>
////#include<cstdlib.h>
typedef struct cards///to make cards
{
    int v;
    char e[15];
    struct cards* next;/// to holds the address of another card in the stack
}cards;
typedef struct game///to initialize the players
{
    cards* top;///this is to hold the memory address for the top card of the players
}game;
cards *initc(char *s, int n)///this function is to make cards for the game
{
    cards *t;
    t=(cards *)malloc(sizeof(cards));/// allocating memory for the new card
    t->next=NULL;
    t->v=n;
    strcpy(t->e,s);
    return t;/// ret
}
game *initg()/// this function is to initiate player
{
    game *s;
    s=(game *)malloc(sizeof(game));/// allocating memory
    s->top=NULL;
    return s;
}
int checksame(cards *s,cards *t)///to compare 2 cards needed during the running of the game
{
    if((s->v==t->v)&&(strcmp(s->e,t->e)==0))
        return 1;
    else
        return 0;
}
void display(game *p/*,int n*/)/// it is to show the cards a player p and n is for player no. that is 1 or 2
{
    cards *t;/// this is declared to traverse the deck of the player p
    t=p->top;
    int i=1;/// for no. of cards displaying at a particular iteration
    while(t!=NULL)
    {
        printf("\nthe %dth card in card deck of player has colour:%s  and no. :%d",i,t->e,t->v);
        t=t->next;
        ++i;
    }
    printf("\n");
    return;
}
void push(game* s,cards* t)/// this to push a card t in the stack of s
{
    if(s->top==NULL)
    {
        s->top=t;
    }
    else
    {
        t->next=s->top;
        s->top=t;
    }
    return ;
}
cards* pop(game *s)/// this game is to pop a card from  the player s and return the address of that card
{
    if(s->top==NULL)
    {
        printf("\nthere is nothing to be pop from the deck");
        return NULL;
    }
    else
    {
        cards *k;
        k=s->top;
        s->top=s->top->next;
        k->next=NULL;
        return k;
    }
}

int nele(game *s)///to check no. of cards in the game stack s
{
    int n=0;
    cards *t=s->top;
    while(t!=NULL)
    {
        ++n;
        t=t->next;
    }
    return n;
}
void makeplayer(game *p1,game *p2)/// to distribute cards to the players p1 and p2
{

    char d2[4][15]={"Hearts","Diamonds(<>)","Spades","Clubs"};///this is to give color to the card
    int i=0;///declared i to check the no. of cards that we will have distribute to a particular player
    int r;/// declared to denote the no. that we will get from random function
    int e[15]={0};///to count no. of  each cards of a particular type and we use only from e[2] to e[14]
    /* as we have given no. to each cards so the above array is declared to check whether we have got all the four types of a particular numbered
    card */
    int q;
    cards *t;/// for adding a card in the players deck
    cards *p;/// this card is declared to check whether the player have got that card already while distribution previously
    srand(time(NULL));/// this function will help us to generate different random no. in each time of this program run
    p=(cards *)malloc(sizeof(cards));
    while(i<26)/// checking whether we have distribute 26 cards to the player 1 or not
    {

        r=(rand()%13)+2;///rand function will generate a no. from 0 to form RAND_MAX  ( RAND_MAX can be any no. )
        /// this format of rand function will help us to give a no. from 2 to 14
        q=(rand()%4);/// this will use for giving the type for the particular card like "hearts","clubs" etc.
        int g=0;///uses as flag for the duplication of cards in the particular player deck
        p->v=r;
        strcpy(p->e,d2[q]);/// here we are using i%4 for distribution
        cards *k;/// this card will be used for traversing the deck of the player and checking the duplicacy of card
        k=p1->top;
        for(int j=0;j<i;j++)///to check whether the player have get the cards previously or not
        {
            if(checksame(k,p)==1)
               {
                   g=1;
                   break;
               }
            k=k->next;
        }
        if((e[r]<4)&&(g==0))/// now checking all the condition to add the card in the deck of player
        {
            t=initc(d2[q],r);
            push(p1,t);
            ++e[r];/// increasing the no. of that card
            ++i;/// now increasing the total no. of cards in the players deck
        }
    }
    i=2;
    int f=1;
    while(i<28)
    {
        r=(rand()%13)+2;
        q=(rand()%4);
        int g=0;
        p->v=r;
        strcpy(p->e,d2[q]);
        cards *k;
        k=p1->top;
        for(int j=0;j<26;j++)///to check the card whether i get now is it already present in the deck of Player 1
        {
            if(checksame(k,p)==1)
               {
                   g=1;
                   break;
               }
            k=k->next;
        }
        if(g==0)
        {
            k=p2->top;
            for(int j=2;j<i;j++)
            {
                if(checksame(k,p)==1)
                {
                    g=1;
                    break;
                }
                k=k->next;
            }
        }
        if((e[r]<4)&&(g==0))
        {
            t=initc(d2[q],r);
            push(p2,t);
            ++e[r];
            ++i;
        }
    }
    return ;
}
void mainMenu(char *play1,char *play2)
{
    int ch, ch1;
    char c;
    FILE *fwptr;
    fwptr=fopen("ScoreBoard.txt","r");
    lb:
    fseek(fwptr,0,SEEK_SET);
    system("cls");
    printf("Welcome to the Main game window, here you have the following options:");
    printf("\n1.New Game(By default it will be single player mode)");
    printf("\n2.Player-Mode");
    printf("\n3.Instructions");
    printf("\n4.Exit");
    printf("\n5.Score board of previous Matches");
    printf("\n6.delete previous matches scores");
    printf("\n||||enter your valid choice|||| :");
    fflush(stdin);
    scanf("%d",&ch);
    switch(ch)
        {
            case 1: {
                       system("cls");
                       ///printf("By default it will be a single player mode:");
                       printf("Plz type the name of the player 1:");
                       fflush(stdin);
                       scanf("%[^\n]%*c",play1);
                       strcpy(play2,"computer");
                       fclose(fwptr);
                       return;
                       break;
                    }
            case 2:{
                        system("cls");
                        printf("Please select your mode:");
                        printf("\n1.Single player mode");
                        printf("\n2.Double player mode");
                        printf("\nSelect your choice:");
                        scanf("%d",&ch1);
                        switch(ch1)
                        {
                            case 1:{
                                      printf("\n\nPlz type the name of the player 1:");
                                      fflush(stdin);
                                      scanf("%[^\n]%*c",play1);
                                      strcpy(play2,"computer");
                                      fclose(fwptr);
                                      return;
                                  }
                           case 2:{
                                      printf("\nPlz type the name of the player 1:");
                                      fflush(stdin);
                                      scanf("%[^\n]%*c",play1);
                                      printf("Plz type the name of the player 2:");
                                      fflush(stdin);
                                      scanf("%[^\n]%*c",play2);
                                      fclose(fwptr);
                                      return;
                                  }
                       }
                    }
            case 3:{
                        system("cls");
                        printf("The rules for the game are as per the followings:");
                        printf("\n1.starting for two players p1 and p2. first we will distribute cards equally(means 26 each) and randomly between them.");
                        printf("\n2.each player will holds their all the cards in their stack.");
                        printf("\n3.each player will play its card one by one from their deck which is arranged in stack format. starting from p1.");
                        printf("\n4.now we will store these playing cards in some another stack (lets say stack k) and wait until the played cards of any player");
                        printf("\n(lets say player p2)match with the card which is already present in stack k and then we will pop");
                        printf("\nall the cards from the stack k and push them into the stack of that player p2 and the");
                        printf("\n5.game again start from player p2 and this process continuously goes on until anyone of the player losses all of its cards");
                        printf("\n6.the player which will have the cards still in the deck will be declared as winner");
                        printf("\n7.if both losses their all cards than match will get draw");
                        printf("\n\nenter any key to proceed for main menu:");
                        fflush(stdin);
                        scanf("%c",&c);
                        goto lb;
                    }
            case 4:{
                        fclose(fwptr);
                        exit(0);
                    }
            case 5:{
                        system("cls");
                        printf("Previous matches records\n");
                        while((c=fgetc(fwptr))!=EOF)
                        {
                            printf("%c",c);
                        }
                        printf("\n\nenter any key to proceed for main menu:");
                        fflush(stdin);
                        scanf("%c",&c);
                        goto lb;
                    }
            case 6:{
                    system("cls");
                    printf("Remember this function will delete all the records your system has stored till now");
                    printf("\nFirst Let i show you the previous records\n");
                    while((c=fgetc(fwptr))!=EOF)
                    {
                        printf("%c",c);
                    }
                    printf("\nDo you really wanna delete these record now,if yes,then Just enter Y or y,otherwise any other key:");
                    fflush(stdin);
                    scanf("%c",&c);
                    if((c=='y')||(c=='Y'))
                    {
                        fclose(fwptr);
                        fwptr=fopen("ScoreBoard.txt","w");
                        fclose(fwptr);
                        fwptr=fopen("ScoreBoard.txt","r");
                        printf("\nthe records has been deleted");
                        printf("\n\nenter any key to proceed for main menu:");
                        fflush(stdin);
                        scanf("%c",&c);
                        goto lb;
                    }
                    else
                    {
                        goto lb;
                    }
                    }
            default :{
                         printf("\nplease enter the valid choice as per the option given");
                         goto lb;
                    }
        }
}

int reshuffle(game *play){

    srand(time(NULL));/// this function will help us to generate different random no. in each time of this program run
    game *inter1=initg();
    game *inter2=initg();/// this function is to initiate player
    printf("\nEnter the no. of times you want to shuffle your card deck(Take the no. less than 10 otherwise your hand will pain):");
    int q;/// This is store the no. of times a user want to reshuffle
    fflush(stdin);
    scanf("%d", &q);
    int k= nele(play);
    cards *t;/// for adding a card in the players deck
    int r; /// this is the no. at which we will reshuffle at a time in the deck
    /// we now have to run a loop so that we can repetadly push and pop from the player's card deck
    int y=0;
    while(y<q){

        int r=(rand()%(k-1));///rand function will generate a no. from 0 to form RAND_MAX  ( RAND_MAX can be any no. )
        /// this format of rand function will help us to give a no. from where we can shuffle the card deck
        /// pop these r elements from the card deck and push these r elements into the inter1 card deck
        /// and then remaining elements is to be push to inter2 card deck
        /// and then we have to push the the cards of intre1 into the players card deck and
        /// and then also push the cards of inter2 into player's card deck

        for (int i= 0; i<r; i++)
        {
            t=pop(play);
            push(inter1, t);
        }
        for (int i= 0; i<r-k; i++)
        {
            t=pop(play);
            push(inter2, t);
        }
        for (int i= 0; i<r; i++)
        {
            t=pop(inter1);
            push(play, t);
        }
        for (int i= 0; i<r-k; i++)
        {
            t=pop(inter2);
            push(play, t);
        }
        ++y;
    }

}
int GamingContinue(char *play1,char *play2, game *p1,game *p2)
{
     int n;
     int ch;
     printf("\nIn the continue window you have the following action:");
     printf("\n1.Reshuffle Your card Deck");
     printf("\n2.Tell Result from the current position");
     printf("\n3.Go to main menu(remember all of your data upto now will get deleted)");
     printf("\n4.exit from the game(remember all of your data upto now will get deleted)");
     printf("\n5.Back to game");
     printf("\nenter your choice:");
     scanf("%d",&ch);
     switch(ch)
     {
         case 1:{
                 if(strcmp(play2,"computer")==0)
                 {
                     reshuffle(p1);
                     printf("\nWe have reshuffle your card well, don't worry proceed ahead, you chances for winning should increase now");
                     return 1;
                 }
                 else
                 {
                     printf("\n1.player-1");
                     printf("\n2.player-2");
                     printf("\n3.both player");
                     printf("\nSelect the player whose cards you want to reshuffle::");
                     fflush(stdin);
                     scanf("%d",&ch);
                     switch(ch)
                     {
                        case 1:{
                                    reshuffle(p1);
                                    printf("\nWe have reshuffle player-1's card deck well, don't worry proceed ahead, you chances for winning should increase now");
                                    return 1;
                                }
                        case 2:{
                                    reshuffle(p2);
                                    printf("\nWe have reshuffle player-2's card deck well, don't worry proceed ahead, you chances for winning should increase now");
                                     return 1;
                               }
                        case 3:{
                                    reshuffle(p1);
                                    printf("\nWe have reshuffle player-1's card deck well, don't worry proceed ahead, you chances for winning should increase now");
                                    printf("\nNow we are going to reshuffle the deck of player-2's card deck");
                                    reshuffle(p2);
                                    printf("\nWe have reshuffle player-2's card deck well, don't worry proceed ahead, you chances for winning should increase now");
                                    return 1;
                               }
                     }
                  }
                  return 1;
               }
        case 2:{
                  return 2;
               }
        case 3:{
                  return 3;
                }
        case 4:{
                  exit(0);
                }
        case 5:{
                  return 1;
               }
    }
}
void main ()
{
    game *s,*p1,*p2;/// s is the stack for the cards played by player 1 and player 2
    p1=initg();///taking the memory address of the location where our players data are going to be save
    p2=initg();
    s=initg();
    FILE *fwptr;
    fwptr=fopen("ScoreBoard.txt","a");
    int d=1;
    char gp,play1[20],play2[20];
    char q=' ';
    gh:
    makeplayer(p1,p2);
    mainMenu(play1,play2);
    system("cls");
    printf("Now we are going to start your game!!!");
    printf("\nThe no. 11 represent  JACK ");
    printf("\nThe no. 12 represent  QUEEN ");
    printf("\nThe no. 13 represent  KING  ");
    printf("\nThe no. 14 represent  ACE \n\n");
    int flag=1;/// this variable is used to check which player have to play the card
    cards *t;///this card will be used for the game processing
    int j=0,k=0;
    do///this is to do the game processing
    {
        switch(flag)/// this to find it is which player's turn to pop his card
        {
            case 0:
                    {
                            t=pop(p2);
                            push(s,t);
                            printf("The cards played by player  %s  has  no.%d  and  colour:%s  ",play2,t->v,t->e);
                            printf("\nEnter any key for further proceeding:");
                            fflush(stdin);
                            scanf("%c",&gp);
                            printf("\n");
                            flag=1;
                            ++j;
                            break;
                    }
            case 1:
                    {
                            t=pop(p1);
                            push(s,t);
                            printf("The cards played by player  %s  has  no.:%d  and  colour:%s  ",play1,t->v,t->e);
                            printf("\nEnter any key for further proceeding:");
                            fflush(stdin);
                            scanf("%c",&gp);
                            printf("\n");
                            flag=0;
                            ++j;
                            break;
                    }
        }
        if(nele(s)>1)///this is to check for the matching of cards just played in stack s and before that
        {
            cards *h;///this card will be used for the checking
            t=pop(s);/// last played card in stack s
            h=pop(s);/// second last card in stack s
            if((t->v==h->v)&&(flag==0))///if the cards t and h are same and last card is played by player 1(using flag)
            {
                printf("\n Ooh wow, it matches for player 1 \n ****Hip-Hip Hoory**** \n ****Hip-Hip Hoory**** \n ****Hip-Hip Hoory****");
                printf("\n Congratulation to him/her!!!!!");
                printf("\n Now all the cards established in the match (till now after any match previous) goes to player 1\n");
                printf("\n\nEnter any key for further proceeding:");
                fflush(stdin);
                scanf("%c",&gp);
                printf("\n");
                push(p1,t);
                push(p1,h);
                while(nele(s)>0)/// this is to pop all the cards from stack s to push in player p1 as per games rules
                {
                    t=pop(s);
                    push(p1,t);
                }
                flag=1;/// this to make p1 to show its card in next chance
                j=0;
                system("cls");
            }
            else if((t->v==h->v)&&(flag==1))///it is the check if the cards t and h are same and last card is played by player 1(using flag)
            {
                printf("Ooh wow, it matches for player 2 \n ****Hip-Hip Hoory**** \n ****Hip-Hip Hoory**** \n ****Hip-Hip Hoory****");
                printf("\n Congrates to him!!!!!");
                printf("\n Now all the cards established in the match (till now after any match previous) goes to player 2");
                printf("\n\nEnter any key for further proceeding:");
                fflush(stdin);
                scanf("%c",&gp);
                push(p2,t);
                push(p2,h);
                while(nele(s)>0)/// this is to pop all the cards from stack s to push in player p2 as per games rules
                {
                    t=pop(s);
                    push(p2,t);
                }
                flag=0;/// this to make P2 to show its card in next chance
                j=0;
                system("cls");
            }
            else
            {
                push(s,h);
                push(s,t);
                if(j%6==0)
                {
                    printf("\nDo you want a pause from game (if yes than press 'y' or 'Y' otherwise just press enter):");
                    fflush(stdin);
                    scanf("%c",&q);
                     if((q=='y')||(q=='Y'))
                     {
                        k=GamingContinue(play1,play2,p1,p2);
                        printf("\nJust press any key(other than enter) to proceed further:");
                        fflush(stdin);
                        scanf("%c",&q);
                        printf("\n");
                     }
                     else{
                        printf("\n");
                     }
                 }
             }
        }
    }while((nele(p1)>0)&&(nele(p2)>0)&&(k!=2)&&(k!=3));/// until card deck of any player gets empty
    if(k==3)
    {
        fclose(fwptr);
        free(p1);
        free(p2);
        free(s);
        goto gh;
    }
    printf("\n\nHere we are about to just declare the result,press any key:");
    fflush(stdin);
    scanf("%c",&gp);
    if(nele(p2)>nele(p1))
    {
        printf("\n\nPlayer 2 named by:%s have win by %d no. of card!!!!\n",play2,nele(p2));
        fprintf(fwptr,"Player 2 named by:%s have win by %d no. of card against player:%s!!!!\n",play2,nele(p2)-nele(p1),play1);
    }
    else if(nele(p1)>nele(p2))
    {
        printf("\n\nPlayer 1 named by:%s have win by %d no. of card!!!\n",play1,nele(p1));
        fprintf(fwptr,"Player 1 named by:%s have win by %d no. of card against player:%s!!!\n",play1,nele(p1)-nele(p2),play2);
    }
    else
    {
        printf("\nThe match become draw!!!");
        fprintf(fwptr,"The match become draw between %s and %s as each having %d no. of cards!!!",play1,play2,nele(p2));
    }
    fclose(fwptr);
    free(p1);
    free(p2);
    free(s);
}


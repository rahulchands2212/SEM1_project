#include<stdio.h>
//define all function;
void header();
void user_input();
void normal_calculation();
void history();
int exit_();

//header;
void header(){
  printf("\n\t\tCALCULATOR\n\n"); //header;
    printf("FEATURES :-\n\n");
    printf("1.Normal_calculation\n");
    printf("2.History\n");
    printf("3.Exit\n\n");

    user_input();   //call user_input function; 
}

//user input;
void user_input(){
    int user;
printf("Select Feature : ");
scanf("%d",&user);
//check and open features;
if(user>0 && user<=3){
    if(user==1){
      normal_calculation();
    }else if(user==2){
      history();
    }else if(user==3){
        exit_();
    }
}else{
printf("invalid selection");
}
}

//normal calculation;
void normal_calculation(){
//store in output in history file;
  FILE *fptr;
  fptr = fopen("history.txt","a");
  
  //check;
  if(fptr==NULL){
    printf("not able to  read");
  }

  //check 
  if(fptr==NULL){
    printf("file not created\n");
  }

  int yes = 1;  //using for input multiple time;
  while(yes==1){

  //define and take input by user;
  int num1,num2;
  char operator;
  printf("enter number 1 ,operator ,number 2 : ");
  scanf("%d %c %d",&num1,&operator,&num2); 

  
  //using switch;
  switch (operator){
    case  '+':
    printf("%d + %d = %d\n",num1,num2,num1+num2);
    //store in history file;
    fprintf(fptr,"%d + %d = %d\n",num1,num2,num1+num2);
    break;

    case '-':
    printf("%d - %d = %d\n",num1,num2,num1-num2);
     //store in history file;
       fprintf(fptr,"%d - %d = %d\n",num1,num2,num1-num2);
    break;

    case '*':
    printf("%d x %d = %d\n",num1,num2,num1*num2);
     //store in history file;
       fprintf(fptr,"%d x %d = %d\n",num1,num2,num1*num2);
    break;

    case '/':
    //add the not define case;
    if(num2==0){
      printf("%d/%d = not define\n",num1,num2);
       //store in history file;
      fprintf(fptr,"%d/%d = not define\n",num1,num2);
    }else{
    printf("%d/%d = %.2f\n",num1,num2,(float)num1/num2);
     //store in history file;
      fprintf(fptr,"%d/%d = %.2f\n",num1,num2,(float)num1/num2);
    }
    break;

    //adding the default case;
    default :
    printf("enter input according to given instruction\n");
    break;
  }
  //ask user for work continue or exit ;
  printf("do you want close yes/no(yes:1 or no:<=0) :  ");  //ask user to stop the loop;
  scanf("%d",&yes);

//while close
}
//closing file;
fclose(fptr);
//header call;
header();

}

//history;
void history(){
  FILE *fptr;
  fptr = fopen("history.txt","r");

  //chek;
  if(fptr ==NULL){
    printf("file not able to read");
  }
  //read character by character;
  int ch; 
  ch = fgetc(fptr); //store first character in ch;
  while(ch!=EOF){
    printf("%c",ch);  //print ch;;
    ch = fgetc(fptr); //update loop;
  }

  //close file;
  fclose(fptr);

  //call main;
  header();
}

//exit;
int exit_(){
  return 0;
}

//main function;
int main(){
  header();
    return 0;
}
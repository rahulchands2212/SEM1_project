#include<stdio.h>
//define all function;
void header();
void user_input();
void normal_calculation(int n);
void digit_to_binary(int b);
void binary_to_digit(int d);
void history();
void exit();

//header;
void header(){
  printf("\n\t\tCALCULATOR\n\n"); //header;
    printf("FEATURES :-\n\n");
    printf("1.Normal_calculation\n");
    printf("2.Digit to binary\n");
    printf("3.Binary to digit\n");
    printf("4.History\n");
    printf("5.Exit\n\n");

    user_input();   //call user_input function; 
}

//user input;
void user_input(){
    int user;
printf("Select Feature : ");
scanf("%d",&user);
//check and open features;
if(user>0 && user<=4){
    if(user==1){
      normal_calculation(user);
    }else if(user==2){
      digit_to_binary(user);
    }else if(user==3){
      binary_to_digit(user);
    }else if(user==4){
      history();
    }else{
      exit();
    }
}else{
printf("invalid selection");
}
}

//main function;
int main(){
  header();
    return 0;
}
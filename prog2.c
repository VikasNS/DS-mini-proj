#include<stdio.h>
#include<string.h>
#define PARK_SPACE 10

typedef struct CAR
{
  char car_no[10];
  int no_movements;
}CAR;




//////////////////////////////////////////////////////
            //TEMP_PARK_SPACE//
typedef struct Temp_Park_Space
{
  int rear;
  int front;
  CAR car_list[PARK_SPACE];
}TEMP_PARK_SPACE;

void push_car_temp_park_space(TEMP_PARK_SPACE *TMPS,CAR car)
{
  TMPS->car_list[++(TMPS->rear)]=car;
}

CAR pop_car_temp_park_space(TEMP_PARK_SPACE *TMPS)
{
  return (TMPS->car_list[(TMPS->front)--]);
}

int is_temp_park_space_full(TEMP_PARK_SPACE *TMPS)
{
  return TMPS->rear==(PARK_SPACE-1);
}

int is_temp_park_space_empty(TEMP_PARK_SPACE *TMPS)
{
  return TMPS->front>TMPS->rear;
}

void display_cars_temp_park_space(TEMP_PARK_SPACE *TMPS)
{
  for(int i=0;i<=TMPS->rear;i++) printf("%s \n",(TMPS->car_list[i]).car_no);
}
          //TEMP_PARK_SPACE//
//////////////////////////////////////////////////////



//////////////////////////////////////////////////////
            //MAIN_PARK_SPACE//
typedef struct MAIN_PARK_SPACE
{
  int front;
  int rear;
  CAR car_list[PARK_SPACE];
}MAIN_PARK_SPACE;

void push_car_main_park_space(MAIN_PARK_SPACE *MPS,CAR car)
{
    MPS->car_list[++(MPS->rear)]=car;
}

CAR pop_car_main_park_space(MAIN_PARK_SPACE *MPS)
{
   return MPS->car_list[(MPS->front)--];
}

int is_main_park_space_full(MAIN_PARK_SPACE *MPS)
{
  return MPS->rear==(PARK_SPACE-1);
}

int is_main_park_space_empty(MAIN_PARK_SPACE *MPS)
{
  return MPS->front>MPS->rear;
}

void display_cars__main_park_space_space(MAIN_PARK_SPACE *MPS)
{
  
  if(is_main_park_space_empty(MPS)) 
  printf("Parking space is empty. \n");
  else
  {
    int i=MPS->front;
    for(i;i<=MPS->rear;i++) printf("%s at slot %d \n",(MPS->car_list[i]).car_no,i+1);
  } 
    
  }

            //MAIN_PARK_SPACE//
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
            //WAITING_LIST_SPACE//
typedef struct Waiting_List_space
{
  int front;
  int rear;
  CAR car_list[PARK_SPACE];
}WAITING_LIST_SPACE;

void push_car_waiting_list_space(WAITING_LIST_SPACE *WPS,CAR car)
{
    WPS->car_list[++(WPS->rear)]=car;
}

CAR pop_car_waiting_list_space(WAITING_LIST_SPACE *WPS)
{
   return WPS->car_list[(WPS->front)--];
}

int is_waiting_list_space_full(WAITING_LIST_SPACE *WPS)
{
  return WPS->rear==(PARK_SPACE-1);
}

int is_waiting_list_space_empty(WAITING_LIST_SPACE *WPS)
{
  return WPS->front>WPS->rear;
}

void display_cars_in_waiting_list_space(WAITING_LIST_SPACE *WPS)
{
  if(is_waiting_list_space_empty(WPS)) printf("Waiting List is empty.\n");
  else
  {
    int i=WPS->front;
    for(i;i<=WPS->rear;i++) printf("%s at slot %d \n",(WPS->car_list[i]).car_no,i+1);
  }
}
            //WAITING_LIST_SPACE//
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
          //PARK MY CAR//

void park_my_car(MAIN_PARK_SPACE *MPS,WAITING_LIST_SPACE *WPS,CAR my_car)
{
  if(is_main_park_space_full(MPS))
  {
    if(is_waiting_list_space_full(WPS)) printf("Sorry,Both Parking space and Waiting list are FULL.! \n");
    else
    {
      printf("You have been added to Waiting List as no Parking space is available \n");
      push_car_waiting_list_space(WPS,my_car);
    }
  }
  else 
  {
    push_car_main_park_space(MPS,my_car);
    printf("%s has been successfully added to Parking space\n",my_car.car_no);
    printf("\n");
  }
  
}

          //PARK MY CAR//
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
          //CREATE MY CAR//
CAR create_my_car(char car_no[10])
{
    CAR my_car;
    strcpy(my_car.car_no,car_no);
    my_car.no_movements=0;
    return my_car;
}
          //CREATE MY CAR//
//////////////////////////////////////////////////////




void main()
{
  
  TEMP_PARK_SPACE TMPS;
  TMPS.front=0;
  TMPS.rear=-1;
  
  char instruction[1];
  char car_reg_no[10];
  
  WAITING_LIST_SPACE WPS;
  WPS.front=0;
  WPS.rear=-1;
  
  MAIN_PARK_SPACE MPS;
  MPS.front=0;
  MPS.rear=-1;
  CAR poped_car;
  
  
  char car_no[10];
  int choice;
  CAR my_car;
  printf("Enter\n");
  printf("1 To Input \n");
  printf("2 To display cars in Parking space \n");
  printf("3 To display cars in Waiting list \n");
  printf("4 To Exit \n");
  scanf("%d",&choice);
  
  while(choice!=4)
  {
    switch(choice)
    {
      case 1:
      printf("Enter \n");
      printf("A to park the car \n");
      printf("D to get your car \n");
      printf("Follow it by registration number and press enter \n");
      scanf(" %s",instruction);
      scanf(" %s",car_reg_no);
      
      
      if(strcmp(instruction,"A")==0)
      {
        my_car=create_my_car(car_reg_no);
        park_my_car(&MPS,&WPS,my_car);
      }
      else if(strcmp(instruction,"D")==0)
      {
        int i=0; 
        while(!is_main_park_space_empty(&MPS))
        { 
          poped_car=pop_car_main_park_space(&MPS);
          printf("%d \n",MPS.rear);
          i++;
          if(strcmp((poped_car).car_no,car_reg_no)==0) 
          {
            printf("Here is your CAR with %s registration no \n1",poped_car.car_no);
            printf("It moved %d times \n",poped_car.no_movements);
          }else
          {
            push_car_temp_park_space(&TMPS,poped_car);  
          }
          
           
        }
        while(!is_temp_park_space_empty(&TMPS)) push_car_main_park_space(&MPS,pop_car_temp_park_space(&TMPS));
        if(!is_waiting_list_space_empty(&WPS)) push_car_main_park_space(&MPS,pop_car_waiting_list_space(&WPS));
        
         
        
        
        
        
        
       
        
      }else printf("Invalid Input");
      break;
      case 2:display_cars__main_park_space_space(&MPS);
      break;
      case 3:display_cars_in_waiting_list_space(&WPS);
      break;
      case 4:
      break;
      default: printf("Invalid input \n");
    }
   
    printf("Enter\n");
  printf("1 To Input \n");
  printf("2 To display cars in Parking space \n");
  printf("3 To display cars in Waiting list \n");
  printf("4 To Exit \n");
  scanf("%d",&choice);
  }
  
  
  
    
    
  
  
  
  

}













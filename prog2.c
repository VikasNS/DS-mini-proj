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
  printf("\n");
  printf("iNSIDE TEMP PUSH AND CAR IFO %s\n",car.car_no);
  TMPS->car_list[++(TMPS->rear)]=car;
  display_cars_temp_park_space(TMPS);
  printf("\n");
}

CAR pop_car_temp_park_space(TEMP_PARK_SPACE *TMPS)
{
  return (TMPS->car_list[(TMPS->front)++]);
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
  if(is_temp_park_space_empty(TMPS)) printf("Temp Park Space is empty \n");
  else for(int i=TMPS->front;i<=TMPS->rear;i++) printf("%s \n",(TMPS->car_list[i]).car_no);
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
   return MPS->car_list[(MPS->front)++];
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
   return WPS->car_list[(WPS->front)++];
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
  CAR other_car;
  strcpy(other_car.car_no,"one");
  
  strcpy(my_car.car_no,"one");
  
  for(int i=0;i<=6;i++)
  {
    push_car_temp_park_space(&TMPS,my_car);
  }
  
  printf("\n");
  for(int i=0;i<=3;i++)
  {
    pop_car_temp_park_space(&TMPS);
  }
  display_cars_temp_park_space(&TMPS);
  
  /*
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
        //printf("232 \n");
        int found=0;
         //printf("234 \n");
        int i=0; 
         //printf("236 \n");
        while(!is_main_park_space_empty(&MPS))
        { 
          //printf("IS is_main_park_space_empty %d",is_main_park_space_empty(&MPS));
          //printf("238\n");
          poped_car=pop_car_main_park_space(&MPS);
          //printf("241\n");
          printf("%d \n",i);
          i++;
          //printf("244\n");
          if(strcmp((poped_car).car_no,car_reg_no)==0) 
          {
            //printf("247\n");
            printf("Here is your CAR with %s registration no. \n",poped_car.car_no);
            //printf("249\n");
            printf("It moved %d times \n",poped_car.no_movements);
            //printf("251\n");
            found=1;
          }else
          {
            printf("255\n");
            
            push_car_temp_park_space(&TMPS,poped_car);  
            display_cars_temp_park_space(&TMPS);
          }
          
           
        }
        //printf("261\n");
        while(!is_temp_park_space_empty(&TMPS)) push_car_main_park_space(&MPS,pop_car_temp_park_space(&TMPS));
        if(found)
        {
           //printf("265\n");
          if(!is_waiting_list_space_empty(&WPS)) push_car_main_park_space(&MPS,pop_car_waiting_list_space(&WPS));
        }
        else printf("Car not found");
        
        
        
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
  
  */
  
    
    
  
  
  
  

}













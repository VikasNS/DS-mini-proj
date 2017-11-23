#include<stdio.h>
#include<string.h>
#define PARK_SPACE 10

typedef struct CAR
{
  char car_no[10];
  int password;
}CAR;




//////////////////////////////////////////////////////
            //TEMP_PARK_SPACE//
typedef struct Temp_Park_Space
{
  int top;
  CAR car_list[PARK_SPACE];
}TEMP_PARK_SPACE;

void push_car_temp_park_space(TEMP_PARK_SPACE *TMPS,CAR car)
{
  TMPS->car_list[++(TMPS->top)]=car;
}

CAR pop_car_temp_park_space(TEMP_PARK_SPACE *TMPS)
{
  return (TMPS->car_list[(TMPS->top)--]);
}

int is_temp_park_space_full(TEMP_PARK_SPACE *TMPS)
{
  return TMPS->top==(PARK_SPACE-1);
}

int is_temp_park_space_empty(TEMP_PARK_SPACE *TMPS)
{
  return TMPS->top==-1;
}

void display_cars_temp_park_space(TEMP_PARK_SPACE *TMPS)
{
  for(int i=0;i<=TMPS->top;i++) printf("%s \n",(TMPS->car_list[i]).car_no);
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
  int i=MPS->front;
  for(i;i<=MPS->rear;i++) printf("%s \n",(MPS->car_list[i]).car_no);
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
  int i=WPS->front;
  for(i;i<=WPS->rear;i++) printf("%s \n",(WPS->car_list[i]).car_no);
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
CAR create_my_car(char car_no[10],int password)
{
    CAR my_car;
    strcpy(my_car.car_no,car_no);
    my_car.password=password;
    return my_car;
}
          //CREATE MY CAR//
//////////////////////////////////////////////////////




void main()
{
  
  TEMP_PARK_SPACE TMPS;
  TMPS.top=-1;
  
  WAITING_LIST_SPACE WPS;
  WPS.front=0;
  WPS.rear=-1;
  
  MAIN_PARK_SPACE MPS;
  MPS.front=0;
  MPS.rear=-1;
  
  int choice;
  
  char car_no[10];
  int password;
  
  printf("Enter 1 to Park Your CAR\n");
  printf("      2 to Get Your CAR\n");
  printf("      3 to exit\n");
  scanf("%d",&choice);
  while(choice!=3)
  {
    switch(choice)
    {
      case 1:
        printf("Please enter Car Registration number \n");
        scanf("%s",car_no);
        printf("Please enter Secret password \n");
        scanf("%d",password);
        park_my_car(&MPS,&WPS,create_my_car(car_no,password));
        break;
      case 2:
        break;
      case 3:
        break;
      default:
        printf("Invalid Input \n");
        
    }
    printf("Enter 1 to Park Your CAR\n");
    printf("      2 to Get Your CAR\n");
    printf("      3 to exit\n");
    scanf("%d",&choice);
    
    
  }
  
  
  

}













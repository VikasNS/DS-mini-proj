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
  for(int i=0;i<=TMPS->top;i++) printf("%d \n",(TMPS->car_list[i]).car_no);
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
  for(i;i<=MPS->rear;i++) printf("%d \n",(MPS->car_list[i]).car_no);
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
  for(i;i<=WPS->rear;i++) printf("%d \n",(WPS->car_list[i]).car_no);
}
            //WAITING_LIST_SPACE//
//////////////////////////////////////////////////////



void main()
{
  WAITING_LIST_SPACE WPS;
  printf("woring");
    CAR car;
    strcpy(car.car_no,"kA01");
    push_car_waiting_list_space(&WPS,car);
  
  
  display_cars_in_waiting_list_space(&WPS);
  
}













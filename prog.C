    #include<stdio.h>
    struct stack
    {
        int info[100];
        int top;
    };
    typedef struct stack stack;
    
    void push(stack *s,int ele)
    {
        s->info[++(s->top)]=ele;
    }
    
    int pop(stack *s)
    {
        return s->info[(s->top)--];
    }
    int isEmpty(stack s)
    {
        return s.top==-1;
    }
    void display(stack s)
    {
        printf("Contens of stack are \n ");
        for(int i=0;i<=s.top;i++) printf("%c \n",s.info[i]);
    }
    
    void printsize(stack s)
    {
      printf("The number of elements are %d \n ",s.top + 1);
    }
    int main() 
    {
        stack mystack;
        int valid=1;
        mystack.top=-1;
        
        char cha;
        scanf(" %c",&cha);
        int i=0;
        //To take the input and check untill user inputs m
        while(cha!='m' && valid)
        {
           printsize(mystack);
           printf(" You have  entered %c  , validity is %d , top is %d \n",cha,valid,mystack.top);
           
           if(cha=='D') 
           {
             if(mystack.top!=-1)
             {
               valid=0;
               break;
             }
           }
           else if(cha=='C')
           {
             while(!isEmpty(mystack))
             {
               printf("Enter the next Charecter");
               scanf("%c",&cha);
               if(cha!=pop(&mystack))
               {
                 valid=0;
                 break;
               }
             }
           }
           else
           {
             push(&mystack,cha);
           }
          if(valid)
          {
            printf("Enter the next element");
            scanf("%c",&cha);
          }
          
          
         }
         
        if(valid ) printf("valid expression \n");
        else
        {
          printf("InValid expression");
        }
    
       
       
       
       
    }

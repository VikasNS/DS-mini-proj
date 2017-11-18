      #include<stdio.h>
      #define size 100
    struct stack

    {
        //making the array int enable's the program to be even compatible number
        //ie: We can recognize even numerical patter
        int info[size];

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
        int foundm=0;
        mystack.top=-1;

        

        char cha;
        printf("Enter the  Charecter,If want to exit enter m \n");
        scanf(" %c",&cha);

        

        
        //We will stop checking when the user enters m 
        //or if we find that the patter is invalid at any point of validation
        while(cha!='m' && valid)

        {
          //If the user entered C,it implies the charecters to follow
          //will be the image of charecters before C
          //If not its invalid
          if(cha=='C')

           {
             char poped;
             while(!isEmpty(mystack))

             {

               printf("Enter the  Charecter,If want to exit enter m \n");
               scanf(" %c",&cha);
               if(cha=='C') break;
               else
               {
                  poped=pop(&mystack);
                  
                     if(cha!=poped)
      
                     {
                        
                       valid=0;
      
                       break;
      
                     }
               }
               

             }
             if(valid) 
             {
               
               printf("Enter the  Charecter,If want to exit enter m \n");
               scanf(" %c",&cha);
               if(cha=='m') foundm=1;
               else if(cha!='D') 
               {
               valid=0;
               }
             }
             

           }

           else if(cha!='D')
          {
            
             push(&mystack,cha);

           }

          if(valid && !foundm)

          {
              
              printf("Enter the  Charecter,If want to exit enter m \n");
              scanf(" %c",&cha);

          }

          

          

         }

         

        if(isEmpty(mystack) && valid ) printf("valid expression \n");

        else

        {

          printf("InValid expression");

        }

    

       

       

       

       

    }

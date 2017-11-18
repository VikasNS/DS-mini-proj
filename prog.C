      #include<stdio.h>
      #include<stdlib.h>
      #include<time.h>
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
    
    void humour(int ran_num)
    {
      
      switch(ran_num)
      {
        
        case 0: 
        printf("\n");
        printf("I need to sleep,Enter the next Charecter Fast >.<,else enter m to exit\n");
        break;
        case 1: 
          printf("\n");
          printf("Come on,I have a date.! Enter the next Charecter ASAP :),else enter m to exit \n");
        break;
        case 2: 
         
          printf("\n");
          printf("Uff..Human's are soo slow.! next please :D,else enter m to exit \n");
        break;
        case 3: 
         
          printf("\n");
          printf("I'm sure you can't break this code.! Go on waste you time by entering the next char :p ,else enter m to exit\n");
        break;
        case 4:
         
          printf("\n");
        printf("I'm out of jokes.! continue please :(,else enter m to exit\n");
        break;
        case 5:
         
          printf("\n");
        printf("beep beep beep beeeeeeep , don't laught.Even i like to sing.! next Please :|,else enter m to exit\n ");
        break;
        case 6:
         
          printf("\n");
        printf("How,many more inputs?But I'm sure not more than the number of Holidays RIT students get in odd sem 0_o,Next Pease.!,else enter m to exit\n");
        break;
        
        default : printf("Enter the next one please,else enter m to exit\n");
        
      }
    }

    int main() 

    {

        stack mystack;
        srand( time(NULL) );
        int valid=1;
        int foundm=0;
        mystack.top=-1;
        char name[20];
        printf("Hello,may I know your name?");
        scanf("%s",name);
        printf("\n");
        printf("%s, I'm Pattern Patrick\n",name);
        printf("I can help you to recognize Pattern of the form xCyD\n");
        printf("But be fast.\n");

        char cha;
        printf("Enter the Charecter please,enter m to exit \n");
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

               humour(rand()%8);
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
               
               humour(rand()%8);
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
              
              humour(rand()%8);
              scanf(" %c",&cha);

          }

          

          

         }

         

        if(isEmpty(mystack) && valid ) 
        {
          printf("%s Vola.! You have entered a valid expression \n",name);
          printf("If i was useful,Give these guys some bonus marks.! \n");
        }

        else

        {

          printf("%s Sorry.! You have entered an Invalid expression.!\n",name);
          printf("If i was useful,Give these guys some bonus marks.! \n");

        }

    

       

       

       

       

    }

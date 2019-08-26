# C syntax 

* auto: You do not use it at all in general. it gives a local variable a local lifetime. so if you say, int x = 5; 
        If it is the same as auto int x = 5
* enum: check the enum.c file
* extern: extern int global_var; define the global variable, which also needs to be init somewhere else
* extern: extern int global_var; define the global variable, which also needs to be init somewhere else
* register: it is a hint to the compiler that the variable will be heavily used and that you recommend it be kept in a processor register if possible. Most modern compilers do that automatically, and are better at picking them than us humans.
* volatile: volatile tells the compiler not to optimize anything that has to do with the volatile variable. One of the many reasons is when you work with hardware. 

   For example:
   ```
   typedef struct {
        int command;
        int data;
        int busy;
   } MyHardware
   
   void SendCommand(volatile MyHardware * hardware, int command, int data){
       while(hardare -> busy){
        // do nothing
       }
       hardware -> data = data;
       hardware -> command = command;
   }
   ```
   Without volatile, the compiler will optimized out the while loop which does nothing. it may or may change the order that the data/command is initialized. The compiler will try to be smart, read the hardare->busy once and fill into infinite loop. In this case, if you have Hardware to be defined as volatile.
   
   Volatile forces the compiler to do whatever you write. It cannot remove the memory assignments, it cannot cache variables in regsiter and it cannot change the order of assignments either. 

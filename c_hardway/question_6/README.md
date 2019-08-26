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

* static: check the static.c example.
  - The static variable will not go beyond its own scope. It will only remain in memory while the program is running. A normal or auto var is destroyed when the func is over.
  - static variables are allocated memory in data segment, not in stack segment. (check memory_layout_of_c.md)
  - static variables are initialized as 0, if not initialized explicitly.
  - static variables can only be initialized using const literals. Having `static int i = init();` will not work.
  - you can also have static global var and func. see static_func.c as example
  - the static var cannot be declared inside struct. The reason is that, the struct members need to reside in the same memory segment because the value for the struct ele is fetched by counting the offset of the element from the begining address of the structure. In other words, the c compiler requires the entire struct elements to have continuous mem allocation. 

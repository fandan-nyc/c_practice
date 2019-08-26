# C syntax 

* auto: You do not use it at all in general. it gives a local variable a local lifetime. so if you say, int x = 5; 
        If it is the same as auto int x = 5
* enum: check the enum.c file
* extern: extern int global_var; define the global variable, which also needs to be init somewhere else
* extern: extern int global_var; define the global variable, which also needs to be init somewhere else
* register: it is a hint to the compiler that the variable will be heavily used and that you recommend it be kept in a processor register if possible. Most modern compilers do that automatically, and are better at picking them than us humans.
* volatile: volatile tells the compiler not to optimize anything that has to do with the volatile variable. One of the many reasons is when you work with hardware. 

   For example:


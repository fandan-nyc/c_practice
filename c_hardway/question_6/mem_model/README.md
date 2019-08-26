# mem layout of c program

1. text segment
2. initialized data segment
3. uninitialized data segment
4. stack
5. heap

the pic shows how that works.

![Alt text](./memoryLayoutC.jpg?raw=true "Memory layout of C")


* text segment
  
  A text segment, also known as a code segment or simply as text, is one of the sections of a program in an object file or in mem, which contains executable instruct.

  As a mem region, a text segment may be placed below heap/stack in order to prevent heaps and stack overflow from overwriting it. 

  Usually, the text segment is sharable so that only a single copy needs to be in mem for text editor, c compiler etc. also, the text semgent is often read-only to prevent accidental change.

* initialized data segment:

  initialized data segment, also called data segment. It is a portion of virtual address space of a program, which contains the global var and static var that are initialized by the programmer. 
 
  You can further classfiy it into read-only and read-write area. For example. global var char s[] = "hello" wll be in the read-write section. A global var like const char* name = "Peter" will be in the read-only area.

* uninitialized data segment

  often called bss segment, named after (block started by symbol). Data in this segment it initialized by the kernel to arithmetic 0 before the program starts. 

  uninitialized data starts at the end of the data segment and contains all global var and static var that are initialized to zero or do not have explicit initialization in source code only. 
  
  For instance, a variable declared as static int i; or global extern int j; will be in bss

* stack
  stack area traditionally adjoined the heap and grow in the opposite diretion.when stack pointer met the heap pointer, free mem is exhausted.

  the stack contains the program stack, a LIFO strcut, typically located in the higher parts of mem. on PC X86, it grows to address zero. 

  A stack pointer tracks the top of the stack, it is adjusted each time a value is pushed onto the stack.

  

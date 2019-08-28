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

  A stack pointer tracks the top of the stack, it is adjusted each time a value is pushed onto the stack. This is how recursive func in C can work. Each time a recursive func calls itself, a new stack frame is used, so one set of variables does not interfere with the variables from another instance of the func.

* Heap
  Heap is the segment where dynamic memory allocation usually takes place. The head areas begins at the end of the BSS segment and grows to larger address from there. The heap area is managed by malloc, realloc, and free, which may use the brk and sbrk system calls to adjust the size.
  

For example
test_1 has no global var and static var. so there is on Text section
```
dfan-mbp143:mem_model dfan$ size -m test_1
Segment __PAGEZERO: 4294967296
Segment __TEXT: 4096
	Section __text: 15
	Section __unwind_info: 72
	total 87
Segment __LINKEDIT: 4096
```

test_2 has only global var and not initialized.
```
total 4294975488
dfan-mbp143:mem_model dfan$ size -m test_2
Segment __PAGEZERO: 4294967296
Segment __TEXT: 4096
	Section __text: 15
	Section __unwind_info: 72
	total 87
Segment __DATA: 4096
	Section __common: 4
	total 4
Segment __LINKEDIT: 4096
total 4294979584
```

test 3 has global var and static var, but neither is initialized
```
dfan-mbp143:mem_model dfan$ size -m test_3
Segment __PAGEZERO: 4294967296
Segment __TEXT: 4096
	Section __text: 15
	Section __unwind_info: 72
	total 87
Segment __DATA: 4096
	Section __bss: 4
	Section __common: 4
	total 8
Segment __LINKEDIT: 4096
total 4294979584
```

test4 has global and static initialized
```
dfan-mbp143:mem_model dfan$ size -m test_4
Segment __PAGEZERO: 4294967296
Segment __TEXT: 4096
	Section __text: 15
	Section __unwind_info: 72
	total 87
Segment __DATA: 4096
	Section __data: 8
	total 8
Segment __LINKEDIT: 4096
total 4294979584
```

test 5 is more comlicated text struct
```dfan-mbp143:mem_model dfan$ size -m test_5
Segment __PAGEZERO: 4294967296
Segment __TEXT: 4096
	Section __text: 74
	Section __stubs: 6
	Section __stub_helper: 26
	Section __cstring: 3
	Section __unwind_info: 72
	total 181
Segment __DATA: 4096
	Section __nl_symbol_ptr: 16
	Section __la_symbol_ptr: 8
	total 24
Segment __LINKEDIT: 4096```

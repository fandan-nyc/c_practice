Compile and run: gcc test.c test_1.c -o main.out

static func is limited within the file itself. If you have static func, you cannot get access through other files

The test_1.h file is an interface. Missing that will not break any thing, but giving you a warning of 

```test.c:6:5: warning: implicit declaration of function 'demo_1' is invalid in C99 [-Wimplicit-function-declaration]```

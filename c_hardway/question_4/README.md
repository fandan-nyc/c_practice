# use debugger
the GDB does not work on mac any more. use LLDB
for example

```
dfan-mbp143:question_4 dfan$ lldb
(lldb) file test
Current executable set to 'test' (x86_64).
(lldb) r
Process 28497 launched: '/Users/dfan/src/c_practice/c_hardway/question_4/test' (x86_64)
this is year 2019
Process 28497 exited with status = 0 (0x00000000)
(lldb) q

```


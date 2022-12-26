
# Syscall
A simple syscall that copies a 2d matrix from user space to kernel space where it is copied to another
matrix onto the user space. The syscall is added to the syscall table at the 451st index.



## Running Tests

To test the syscall, add the patch file to your syscall table and sycall file, and add the
test.c file to a directory you would like to test. Now run the following commands:

run this in the kernel directory 
```bash
> make
> make modules
> make modules_install
```

now move to the directory of the tester file, compile and run the test file
```bash
> make
> ./test
```
if matrix printed after the syscall are same, the syscall has been implemented sucessfully

## Appendix

syscall namd kernel_2d_memcpy is added to syscalls_64.tbl as the 451st entry, and the code for kernel_2d_memcpy is appended is sys.c in the kernel
directory. Tester file runs with 451st syscall, copying a 2d array from source to destination.
The kernel is compiled again after ading the new syscall implementation.



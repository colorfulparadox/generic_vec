## C Generic Vector
I made this for fun. 

Look inside of main.c to how it works. Check out vector.h in includes dir to see the methods.
<br>
<br>
I used gcc to compile. run ./build.bat build to build and do ./build.bat clean to to cleanup (will need GCC installed to compile)

```
gcc -pedantic -Wall --std=c17 src/main.c src/vector.c -o target/main.exe
```
# MenuDrivenProgramGenerator
A code generation program that will take as an input from stdin a file containing the specifications of a menu and output a C code to stdout.
Done by creating a General Purpose Binary Tree, to then generate nested switch cases. 
Same level items are Siblings, 
Tabbed into an item creates a Parent-Child relationship

To run
```
gcc proggen.c -o codegen
./codegen < menu.dat > outputprog.c
gcc outputprog.c -o outprog
./outprog < inputsequence.txt > output.txt
```

# function_grapher
A simple function grapher/plotter with zoom/pan features.

I made this because I have trouble graphing and visualizing functions, a process which often requires repeated calculation of the result of functions and plotting them. Additional features include drawing a grid and axis.

Uses Allegro 5; Programmed in C99 with CodeBlocks.
![alt text](preview.PNG "Graph of abs, sin, cos, -x^2, -3 and 1/x.")

Current issues:
* Zoom feature zooms relative to the location of the zero vector on the plane, rather than the center of the current view of the function.

The program is very incomplete but does the job I've created it to (visualize functions).

Future features I think would be nice:
* Connect plots with lines
* Draw axis labels
* Function parser
* GUI for adding additional functions and their colour
* Function trace and function information hover on mouse over.

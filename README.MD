HOW TO RUN:
just type "make" "make run" works as well
"make clean" to clean.

how inheiritance was used:
    all events classes were forced to override the getDetails() function and all inheirted common attributes such as date, name, loc
    these were listed as protected so a child object could edit its own date, name, loc as you may want to update these things without relying on public funtions in the base class.


why design patterns is beneficial:
    design patterns are beneficial because it can help us come up with an approach to a problem.


why use of vector of pointers:
    because we can store pointers to child classes that derive from same base class in the same vector and pointers are efficent to pass around.


any challenges encounterd during devlopment:
    I was originall going to have a text file that would save events at the end of a a program run and load old ones upon start but i canned it cause i realized we didnt need to do that. reading from text files is never the fun part of programming. 
    
    took me a second to come up with way to distinguish object types in vector of type of base class.
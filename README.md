I implemented a reduction from a CSAT problem to a CNF-SAT one.

For the implementation I used these sources: <br>
-> https://www.usna.edu/Users/cs/wcbrown/courses/S17SI335/lec/l33/lec.html
<br>
-> https://en.wikipedia.org/wiki/Tseytin_transformation

main.c:

- the input and output files are given as arguments;
- first read the first two values from the first row (the number of inputs and the output value);
- then I read the rest of the information in the file;
- first I go through all the data in the file and approach the three possible cases (NOT, OR, AND) and I use a variable called "nr_clauses" to see the total number of clauses;
- write the first line in the file with the required data ("p cnf" + "output" + "nr_clause");
- then I go through the data in the file once more and go through each possible case that applies the CNF transformation formula, for each logic gate and write the data in the output file.

Makefiles:

- contains the build, run and check rules

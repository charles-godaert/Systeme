file.run: file1.o file2.o 
	g++ -o file.run file1.o file2.o

file1.o: file1.cxx
	g++ -c file1.cxx -I../include/notreEntete.h

file2.o: file2.cxx
	g++ -c file2.cxx -I../include/notreEntete.h 

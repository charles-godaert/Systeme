COMPILER = g++ -c -I../include/ 


$(nom).run: $(nom).o file2.o 
	g++ -s -o $(nom).run $(nom).o -L. -lSys

$(nom).o: $(nom).cxx ../include/notreEntete.h
	$(COMPILER) $(nom).cxx ../include/notreEntete.h

file2.o: file2.cxx ../include/notreEntete.h
	$(COMPILER) file2.cxx ../include/notreEntete.h

file2.o: file2.cxx ../include/notreEntete.h
	ar -cqs libSys.a file2.o; rm file2.o


clean:
	rm *.o $(nom).run



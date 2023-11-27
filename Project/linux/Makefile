all:
	make installHeader
	make createObj
	make createLib
	make installLib

createObj:
	gcc -c -fPIC DSL/src/singlyll.cpp -o DSL/lib/o/singlyll.o -w;
	gcc -c -fPIC DSL/src/singlycl.cpp -o DSL/lib/o/singlycl.o -w;
	gcc -c -fPIC DSL/src/doublyll.cpp -o DSL/lib/o/doublyll.o -w;
	gcc -c -fPIC DSL/src/doublycl.cpp -o DSL/lib/o/doublycl.o -w;
	gcc -c -fPIC DSL/src/tree.cpp -o DSL/lib/o/tree.o -w;
	gcc -c -fPIC DSL/src/stack.cpp -o DSL/lib/o/stack.o -w 
	gcc -c -fPIC DSL/src/queue.cpp -o DSL/lib/o/queue.o -w 
	
createLib:
	gcc -shared -o DSL/lib/so/libgenlists.so DSL/lib/o/*;

installHeader:
	sudo cp -r DSL/include/lists /usr/local/include/
	
installLib:
	sudo cp DSL/lib/so/libgenlists.so /usr/local/lib/
	sudo ldconfig

clean:
	rm ../lib/o/*
	rm ../lib/so/*
	rm MyExe

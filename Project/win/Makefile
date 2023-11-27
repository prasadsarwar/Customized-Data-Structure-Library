all:
	make installHeader
	make createObj
	make createLib
	make installLib
	make createDll

createObj:
	gcc -c -DBUILDING_EXAMPLE_DLL DSL\src\singlyll.cpp -o DSL\lib\o\singlyll.o -w
	gcc -c -DBUILDING_EXAMPLE_DLL DSL\src\doublyll.cpp -o DSL\lib\o\doublyll.o -w
	gcc -c -DBUILDING_EXAMPLE_DLL DSL\src\doublycl.cpp -o DSL\lib\o\doublycl.o -w
	gcc -c -DBUILDING_EXAMPLE_DLL DSL\src\tree.cpp -o DSL\lib\o\tree.o -w
	gcc -c -DBUILDING_EXAMPLE_DLL DSL\src\stack.cpp -o DSL\lib\o\stack.o -w
	gcc -c -DBUILDING_EXAMPLE_DLL DSL\src\queue.cpp -o DSL\lib\o\queue.o -w
	
createLib:
	g++ -shared -o DSL\lib\so\libgenlists.so DSL\lib\o\*.o;

createDll:
	g++ -shared -o DSL\lib\dll\libgenlists.dll DSL\lib\o\*.o

installHeader:
	copy -r DSL\include\lists \MinGW\include\

installLib:
	copy DSL\lib\so\libgenlists.so \Windows\System32\
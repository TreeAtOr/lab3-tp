make all:
	rm ./dist/*
	g++ worker.cpp -o dist/worker.o -c 
	g++ fulltimeworker.cpp -o dist/fulltimeworker.o -c 
	g++ hourlyworker.cpp -o dist/hourlyworker.o -c
	g++ shareworker.cpp -o dist/shareworker.o -c
	g++ main.cpp -o dist/main.o -c
	
	g++ -o dist/target dist/worker.o dist/fulltimeworker.o dist/hourlyworker.o dist/shareworker.o dist/main.o 

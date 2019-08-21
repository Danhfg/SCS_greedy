all:
	g++ -std=c++14 -Wall -o exe_greedy src/greedy_scs.cpp

inst_lower:
	g++ -std=c++14 -Wall -o exe_inst_lower src/create_instances_lowe_bound.cpp

greedy:
	g++ -std=c++14 -Wall -o exe_greedy src/greedy_scs.cpp

exact:
	g++ -std=c++11 -Wall -o exe_exact src/exact.cpp

inst:
	g++ -std=c++11 -Wall -o exe_inst src/create_instances.cpp
	
clean:
	rm -f exe_*

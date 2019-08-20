all:
	g++ -std=c++14 -Wall -o exe_greedy greedy_scs.cpp

inst_lower:
	g++ -std=c++14 -Wall -o exe_inst_lower create_instances_lowe_bound.cpp

greedy:
	g++ -std=c++14 -Wall -o exe_greedy greedy_scs.cpp

exact:
	g++ -std=c++11 -Wall -o exe_exact exact.cpp

inst:
	g++ -std=c++11 -Wall -o exe_inst create_instances.cpp
	
clean:
	rm -f exe_*
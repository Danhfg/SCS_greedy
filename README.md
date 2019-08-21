# SCS
Desenvolvimente de um algoritmo guloso e exato para o problema da menor supercadeia comum e criadores de instâncias

## Para executar o algoritmo exato basta executar o seguinte comando
    make exact
    ./exe_exact <filename>

## Para executar o guloso exato basta executar o seguinte comando
    make greedy
    ./exe_greedy <filename>

## Para executar o algoritmo de criação de instâncias basta executar o seguinte comando
    make inst
    ./exe_inst <m> <n> > <filename> (sendo m o tamanho das strings e n a quantidade de strings)

## Para executar o algoritmo de criação de instâncias para o limite inferior basta executar o seguinte comando
    make inst_lower
    ./exe_inst_lower <k> > <filename> 

## Para limpar o executaveis
    make clean
# Algoritmos para o problema SCS

## Introducao

Neste repositorio ha a implementacao de um algoritmo guloso denominado de GREEDY e de um exato para o problema da menor supercadeia comum - ou shortest commom superstring (__SCS__). Alem disso, associado a esse problema, tambem foi implementado um gerador de instâncias.

- [Requisitos](#requisitos) - Requisitos de software necessarios para executar o projeto
- [Compilacao e execucao](#compilacao-e-execucao) - Explicao das etapas de compilacao e execucao do projeto


## Requisitos    

Compilador C++ 14 (g++).
	
	Obs.: Para usuários Linux, o g++ eh nativo, faltando apenas atualiza-lo para a versao 14.  
	Porém, caso deseje usar o g++ no Windows será necessário instalar-lo por meio do MinGW. 

## Compilacao e execucao

	Obs.: Todos os códigos digitados no terminal deverão ser na respectiva pasta raiz do programa.  
	
As etapas de compilacao e execucao diferenciaram um para outra de acordo com o algoritmo a ser executado. Diante disso, para **executar o algoritmo exato** basta executar os seguintes comandos:
    
```
$ make exact
$ ./exe_exact <filename>
```  
Ou, para **executar o algoritmo guloso** basta executar os seguintes comandos:
    
```
$ make greedy
$ ./exe_greedy <filename>
``` 
    
Ou, para **executar o algoritmo de criação de instâncias** basta executar os seguintes comandos: 
    
```
$ make inst
$ ./exe_inst <m> <n> > <filename> (sendo m o tamanho das strings e n a quantidade de strings)
``` 
Ou, para **executar o algoritmo de criação de instâncias para o limite inferior** basta executar os seguintes comandos:

```
$ make inst_lower
$ ./exe_inst_lower <k> > <filename> 
``` 
Alem disso, caso deseje limpar o executaveis, digite
```
$ make clean
``` 

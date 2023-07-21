all: main

# Define o comando padrão do compilador:
CC := g++

# Compila e gera o executável main:
main:
	$(CC) -o main *.cpp

# Executa o programa já compilado:
run: main
	@./main -c cursos.csv -d disciplinas.csv -p avaliacoes.csv -a alunos.csv -n notas.csv

# Limpa arquivos compilados e arquivos de entrada/saída.
clean:
	@rm -f main *.o *.csv
	

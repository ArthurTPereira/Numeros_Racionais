#Nome do projeto
PROJ_NAME=racional

#Arquivos .c
C_SOURCE=$(wildcard *.c)

#Arquivos .h
H_SOURCE=$(wildcard *.h)

#Aquivos object
OBJ=$(C_SOURCE:.c=.o)

#Compilador
CC=gcc

#Parametros de compilacao
CC_FLAGS=-c

#Compilar tudo
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)

main.o: main.c $(H.SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)

#Apagar arquivos
clean:
	rm -rf *.o *~ racional
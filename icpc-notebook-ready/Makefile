TARGET=main

all: pdf

pdf:
	latexmk -xelatex $(TARGET).tex

clean:
	latexmk -c

cleanall:
	latexmk -C

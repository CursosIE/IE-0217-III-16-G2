
FILE= list3K.txt
WORD= wrong
TOLERANCE = 2
all: build run clean


build:
	g++ -std=c++11 -o main *.cpp -Wall

run:
	./main $(WORD) $(FILE) $(TOLERANCE)

clean:
	rm main

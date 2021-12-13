MAIN    = main.cpp
OTHERS  = annexe.cpp
OUTPUT  = main.exe

VERSION = -std=c++20
WARNING = -Wall -Wextra -Wconversion -Wsign-conversion -pedantic

all:
	g++ $(VERSION) $(WARNING) $(OTHERS) $(MAIN) -o $(OUTPUT)
clean:
	rm main

MAIN    = main.cpp
OTHERS  = c1.cpp c2.cpp
OUTPUT  = main.out

VERSION = -std=c++20
WARNING = -Wall -Wextra -Wconversion -Wsign-conversion -pedantic

all:
	g++ $(VERSION) $(WARNING) $(OTHERS) $(MAIN) -o $(OUTPUT)
clean:
	rm main

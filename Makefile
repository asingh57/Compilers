JAVA=/usr/bin/java
OUTPUT=output
GENERATED=generated
TESTRIG=testrig
GRAMMAR=Tiger.g4
BIN = cs8803_bin

# here is where you plug in the runtime for your OS
LOCAL=/usr/local/
CC=g++ -std=c++17 
CCARGS=-c -I $(LOCAL)/include/antlr4-runtime/ -I $(GENERATED)	
LDARGS=-g
LIBS=$(LOCAL)/lib/libantlr4-runtime.a
CCARGS2=-c

BACKENDSRC=part2/src/


all: backend

instruction: dirs
	$(CC) $(CCARGS2) $(BACKENDSRC)/Instruction.cpp -o $(OUTPUT)/Instruction.o
	
allocators: dirs
	$(CC) $(CCARGS2) $(BACKENDSRC)/RegisterAllocator.cpp -o $(OUTPUT)/RegisterAllocator.o

naiveAllocator:
	$(CC) $(CCARGS2) $(BACKENDSRC)/NaiveAllocator.cpp -o $(OUTPUT)/NaiveAllocator.o

blockAllocator:
	$(CC) $(CCARGS2) $(BACKENDSRC)/BlockAllocator.cpp -o $(OUTPUT)/BlockAllocator.o
	
briggsAllocator:
	$(CC) $(CCARGS2) $(BACKENDSRC)/BriggsAllocator.cpp -o $(OUTPUT)/BriggsAllocator.o

function: dirs
	$(CC) $(CCARGS2) $(BACKENDSRC)/Function.cpp -o $(OUTPUT)/Function.o
	
functionReader: dirs
	$(CC) $(CCARGS2) $(BACKENDSRC)/FunctionReader.cpp -o $(OUTPUT)/FunctionReader.o

main: dirs
	$(CC) $(CCARGS2) $(BACKENDSRC)/main.cpp -o $(OUTPUT)/main.o
	

backend: instruction allocators naiveAllocator blockAllocator briggsAllocator function functionReader main
	$(CC) $(OUTPUT)/RegisterAllocator.o $(OUTPUT)/NaiveAllocator.o $(OUTPUT)/BlockAllocator.o $(OUTPUT)/BriggsAllocator.o $(OUTPUT)/Instruction.o $(OUTPUT)/Function.o $(OUTPUT)/FunctionReader.o $(OUTPUT)/main.o -o $(BIN)/tigerc


listener:
	$(CC) $(CCARGS) $(GENERATED)/TigerBaseListener.cpp -o $(OUTPUT)/TigerBaseListener.o 
	$(CC) $(CCARGS) $(GENERATED)/TigerListener.cpp -o $(OUTPUT)/TigerListener.o 

lexparse:
	$(CC) $(CCARGS) $(GENERATED)/TigerParser.cpp -o $(OUTPUT)/TigerParser.o 
	$(CC) $(CCARGS) $(GENERATED)/TigerLexer.cpp -o $(OUTPUT)/TigerLexer.o 

symbolstat:
	$(CC) $(CCARGS) stat.cpp -o $(OUTPUT)/stat.o
	$(CC) $(CCARGS) symbol.cpp -o $(OUTPUT)/symbol.o

tiger: dirs antlr4 main.cpp symbolstat lexparse listener
	$(CC) $(CCARGS) main.cpp  -o $(OUTPUT)/tiger.o 
	$(CC) $(CCARGS) symbolTable.cpp -o $(OUTPUT)/symbolTable.o
	$(CC) $(CCARGS) scope.cpp -o $(OUTPUT)/scope.o
	$(CC) $(LDARGS) $(OUTPUT)/scope.o $(OUTPUT)/symbolTable.o $(OUTPUT)/symbol.o $(OUTPUT)/stat.o $(OUTPUT)/tiger.o $(OUTPUT)/TigerBaseListener.o $(OUTPUT)/TigerLexer.o $(OUTPUT)/TigerListener.o $(OUTPUT)/TigerParser.o $(LIBS) -o $(BIN)/tigercFrontEnd

antlr4: $(GRAMMAR)
	antlr -Dlanguage=Cpp -o $(GENERATED) $(GRAMMAR)

dirs:
	mkdir -p $(OUTPUT)
	mkdir -p $(GENERATED)
	mkdir -p $(TESTRIG)
	mkdir -p $(BIN)

clean:
	rm -rf $(OUTPUT)/*
	rm -rf $(GENERATED)/*
	rm -rf $(TESTRIG)/*
	rm -f tigerc
	rm -rf $(BIN)
	
	
testrig: clean
	antlr -o $(TESTRIG) $(GRAMMAR)
	cp $(GRAMMAR) $(TESTRIG)/
	javac -cp /usr/local/lib/antlr-4.9.1-complete.jar $(TESTRIG)/*.java


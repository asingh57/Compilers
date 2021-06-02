JAVA=/usr/bin/java
OUTPUT=output
GENERATED=generated
GRAMMAR=Hello.g4

# here is where you plug in the runtime for your OS
LOCAL=/usr/local/
CC=g++
CCARGS=-c -I $(LOCAL)/include/antlr4-runtime/ -I $(GENERATED)	
LDARGS=-g
LIBS=$(LOCAL)/lib/libantlr4-runtime.a

all: hello

hello: dirs antlr4 main.cpp
	$(CC) $(CCARGS) main.cpp  -o $(OUTPUT)/hello.o 
	$(CC) $(CCARGS) $(GENERATED)/HelloBaseListener.cpp -o $(OUTPUT)/HelloBaseListener.o 
	$(CC) $(CCARGS) $(GENERATED)/HelloLexer.cpp -o $(OUTPUT)/HelloLexer.o 
	$(CC) $(CCARGS) $(GENERATED)/HelloListener.cpp -o $(OUTPUT)/HelloListener.o 
	$(CC) $(CCARGS) $(GENERATED)/HelloParser.cpp -o $(OUTPUT)/HelloParser.o 
	$(CC) $(LDARGS) $(OUTPUT)/hello.o $(OUTPUT)/HelloBaseListener.o $(OUTPUT)/HelloLexer.o $(OUTPUT)/HelloListener.o $(OUTPUT)/HelloParser.o $(LIBS) -o hello

antlr4: $(GRAMMAR)
	antlr -Dlanguage=Cpp -o $(GENERATED) $(GRAMMAR)

dirs:
	mkdir -p $(OUTPUT) 
	mkdir -p $(GENERATED) 

clean:
	rm -rf $(OUTPUT)
	rm -rf $(GENERATED)

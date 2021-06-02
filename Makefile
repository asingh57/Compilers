JAVA=/usr/bin/java
OUTPUT=output
GENERATED=generated
GRAMMAR=Tiger.g4

# here is where you plug in the runtime for your OS
LOCAL=/usr/local/
CC=g++
CCARGS=-c -I $(LOCAL)/include/antlr4-runtime/ -I $(GENERATED)	
LDARGS=-g
LIBS=$(LOCAL)/lib/libantlr4-runtime.a

all: clean tiger

tiger: dirs antlr4 main.cpp
	$(CC) $(CCARGS) main.cpp  -o $(OUTPUT)/tiger.o 
	$(CC) $(CCARGS) $(GENERATED)/TigerBaseListener.cpp -o $(OUTPUT)/TigerBaseListener.o 
	$(CC) $(CCARGS) $(GENERATED)/TigerLexer.cpp -o $(OUTPUT)/TigerLexer.o 
	$(CC) $(CCARGS) $(GENERATED)/TigerListener.cpp -o $(OUTPUT)/TigerListener.o 
	$(CC) $(CCARGS) $(GENERATED)/TigerParser.cpp -o $(OUTPUT)/TigerParser.o 
	$(CC) $(LDARGS) $(OUTPUT)/tiger.o $(OUTPUT)/TigerBaseListener.o $(OUTPUT)/TigerLexer.o $(OUTPUT)/TigerListener.o $(OUTPUT)/TigerParser.o $(LIBS) -o tigerc

antlr4: $(GRAMMAR)
	antlr -Dlanguage=Cpp -o $(GENERATED) $(GRAMMAR)

dirs:
	mkdir -p $(OUTPUT) 
	mkdir -p $(GENERATED) 

clean:
	rm -rf $(OUTPUT)
	rm -rf $(GENERATED)
	rm tigerc

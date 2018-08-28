SRCFILES := $(shell find src/ | fgrep \.cpp)
HDRFILES := $(shell find src/ | fgrep \.h)
CODEFILES := $(SRCFILES) $(HDRFILES)
OBJFILES := $(patsubst src/%.cpp,obj/%.o,$(SRCFILES))
DEPFILES := $(patsubst %.o,%.d,$(OBJFILES))

CC := g++
WARNINGS := -Wall
INCLUDES := -L/lib/x86_64-linux-gnu
LIBS := 
CFLAGS := $(WARNINGS) $(INCLUDES) -DDEBUG_MODE -L/usr/local/lib/ -MMD -MP -g --std=c++14 -lpcap -lssl -lcrypto
OUTFILE := main

-include $(DEPFILES)

all : main

main: $(OBJFILES)
	@echo "Building $@"
	@$(CC) $(CFLAGS) $(OBJFILES) $(LIBS) -o $(OUTFILE)
	@echo "$@ finished"

obj/%.o : src/%.cpp Makefile
	@echo "Building $<"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$< finished"

print:
	@echo $(DEPFILES)

list:
	@grep -Prin "todo|fixme" src/

.PHONY: clean all main

clean:
	-rm $(OBJFILES) $(DEPFILES) $(OUTFILE)

PNAME := multibrot

PCXXSRC := $(wildcard src/*.cpp)
PCXXSRC += $(wildcard src/imgui/*.cpp)

POBJS = $(PCXXSRC:.cpp=.o)

CXXFLAGS += -std=c++17

LDFLAGS += -lSDL2 -lGLEW -lGL

.PHONY: all
.SILENT: all $(POBJS)

all: $(PNAME)

$(PNAME): $(POBJS)
	@- $(LINK.cc) $(POBJS) -o $(PNAME) $(LDFLAGS)
	@- $(RM) $(POBJS)

clean:
	@- $(RM) $(PNAME)
	@- $(RM) $(POBJS)
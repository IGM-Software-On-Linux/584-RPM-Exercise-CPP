CXX = g++
SDL_LIB = -L/usr/local/lib -lSDL2 -lSDL2_image
SDL_INCLUDE = -I/usr/local/include
CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
APP = sharkapp
ASSETS = assets
EXE = shark
BINDIR = $(DESTDIR)/usr/bin
SHAREDIR= $(DESTDIR)/usr/share

all: $(EXE)

$(EXE): src/main.o
	$(CXX) $< $(LDFLAGS) -o $@

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

install:
	install -D -m 0755 $(EXE) $(BINDIR)/$(EXE)
	mkdir -p $(SHAREDIR)/$(APP)/$(ASSETS)
	install -D -m 0644 $(ASSETS)/leftshark.png $(SHAREDIR)/$(APP)/$(ASSETS)/

uninstall:
	rm -rf $(BINDIR)/$(EXE)
	rm -rf $(SHAREDIR)/$(APP)

clean:
	rm src/*.o && rm $(EXE)

# Der Compiler
CXX = g++

# Compiler Flags
# -Wall aktiviert die meisten Compiler-Warnungen
# -g fügt Debug-Informationen hinzu
CXXFLAGS = -Wall -g

# Das Endziel / Programm
TARGET = game

# Quelldateien
SRC = main.cpp hero.cpp character.cpp item.cpp

# Objektdateien
OBJ = $(SRC:.cpp=.o)

# Standard-Regel zum Kompilieren des Programms
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regel für die Objektdateien
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Regel zum Säubern des Projekts (entfernt Objektdateien und das ausführbare Programm)
clean:
	rm -f $(OBJ) $(TARGET)

# Abhängigkeiten
# Hier könnten Sie explizit angeben, welche Header-Dateien Ihre Quelldateien benötigen,
# um sicherzustellen, dass das Makefile das Programm neu kompiliert, wenn eine dieser Dateien geändert wird.
# Beispiel:
# main.o: main.cpp hero.h character.h item.h
# hero.o: hero.cpp hero.h
# character.o: character.cpp character.h
# item.o: item.cpp item.h

# Diese explizite Angabe von Abhängigkeiten ist optional, da moderne Compiler
# und Make-Versionen in der Lage sind, Abhängigkeiten automatisch aufzulösen.

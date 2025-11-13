# Definición del compilador y las banderas
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Isrc


# Directorios
SRC_DIR = src
BUILD_DIR = build

# Ejecutables 
PART1_EXECS = ej1 ej2 ej3 ej4 ej5

# Archivos fuente
PART1_SRCS = ejercicio1.cpp ejercicio2.cpp ejercicio3.cpp ejercicio4.cpp ejercicio5.cpp

# Target principal: compila todos los ejecutables
all: $(PART1_EXECS)

# Compilar los ejecutables
ej1: $(SRC_DIR)/ejercicio1/main.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

ej2: $(SRC_DIR)/ejercicio2/main.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

ej3: $(SRC_DIR)/ejercicio3/main.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

ej4: $(SRC_DIR)/ejercicio4/main.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

ej5: $(SRC_DIR)/ejercicio5/main.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

# Limpieza de archivos generados
clean:
	rm -f $(BUILD_DIR)/*
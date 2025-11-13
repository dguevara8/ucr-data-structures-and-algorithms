# Definición del compilador y las banderas
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Isrc


# Directorios
SRC_DIR = src
BUILD_DIR = build

# Ejecutables de la Parte 1 y Parte 2
PART1_EXECS = ej1 ej2 ej3 ej4 ej5 ej6

# Archivos fuente de la Parte 1 y Parte 2
PART1_SRCS = ejercicio1.cpp ejercicio2.cpp ejercicio3.cpp ejercicio4.cpp ejercicio5.cpp ejercicio6.cpp

# Target principal: compila todos los ejecutables
all: $(PART1_EXECS)

# Compilar los ejecutables de la Parte 1
ej1: $(SRC_DIR)/ejercicio1/ejercicio1.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

ej2: $(SRC_DIR)/ejercicio2/ejercicio2.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

ej3: $(SRC_DIR)/ejercicio3/ejercicio3.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

ej4: $(SRC_DIR)/ejercicio4/ejercicio4.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

ej5: $(SRC_DIR)/ejercicio5/ejercicio5.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

ej6: $(SRC_DIR)/ejercicio6/ejercicio6.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

# Limpieza de archivos generados
clean:
	rm -f $(BUILD_DIR)/*
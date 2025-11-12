# Definición del compilador y las banderas
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Isrc


# Directorios
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = test

# Ejecutables de la Parte 1 y Parte 2
PART1_EXECS = ej1 ej2 ej3 ej4
PART2_EXEC = part2

# Archivos fuente de la Parte 1 y Parte 2
PART1_SRCS = lab1_ej1_promedios.cpp lab1_ej2_estudiantes.cpp lab1_ej3_temperaturas.cpp lab1_ej4_primos.cpp
PART2_SRCS = lab1_part2_calculadora.cpp lab1_part2_driver.cpp

# Target principal: compila todos los ejecutables
all: $(PART1_EXECS) $(PART2_EXEC)

# Compilar los ejecutables de la Parte 1
ej1: $(SRC_DIR)/lab1_ej1_promedios.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

ej2: $(SRC_DIR)/lab1_ej2_estudiantes.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

ej3: $(SRC_DIR)/lab1_ej3_temperaturas.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

ej4: $(SRC_DIR)/lab1_ej4_primos.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<

# Compilar el ejecutable de la Parte 2
part2: $(SRC_DIR)/lab1_part2_calculadora.cpp $(SRC_DIR)/lab1_part2_driver.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $^

# Limpieza de archivos generados
clean:
	rm -f $(BUILD_DIR)/*
	rm -f $(TEST_DIR)/output.txt

# Pruebas para cada ejercicio de la Parte 1
test_ej1:
	./$(BUILD_DIR)/ej1 < $(TEST_DIR)/part1/ej1/input1.txt > $(TEST_DIR)/output.txt
	diff $(TEST_DIR)/output.txt $(TEST_DIR)/part1/ej1/expected_output1.txt

test_ej2:
	./$(BUILD_DIR)/ej2 < $(TEST_DIR)/part1/ej2/input1.txt > $(TEST_DIR)/output.txt
	diff $(TEST_DIR)/output.txt $(TEST_DIR)/part1/ej2/expected_output1.txt

test_ej3:
	./$(BUILD_DIR)/ej3 < $(TEST_DIR)/part1/ej3/input1.txt > $(TEST_DIR)/output.txt
	diff $(TEST_DIR)/output.txt $(TEST_DIR)/part1/ej3/expected_output1.txt

test_ej4:
	./$(BUILD_DIR)/ej4 < $(TEST_DIR)/part1/ej4/input1.txt > $(TEST_DIR)/output.txt
	diff $(TEST_DIR)/output.txt $(TEST_DIR)/part1/ej4/expected_output1.txt

# Prueba para la Parte 2
test_part2:
	./$(BUILD_DIR)/part2 < $(TEST_DIR)/part2/input1.txt > $(TEST_DIR)/output.txt
	diff $(TEST_DIR)/output.txt $(TEST_DIR)/part2/expected_output1.txt

# Pruebas completas: ejecuta todas las pruebas de la Parte 1 y Parte 2
test_all: test_ej1 test_ej2 test_ej3 test_ej4 test_part2

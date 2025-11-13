# ProyectoEDAI_ReservaDeVuelos
- Fabián Muñoz C15386
- Bryan Mora C15141
- Leonardo Serrano C17484
- Danna Guevara C23562

Este programa busca modelar un sistema de reserva de vuelos.

## Estructura
- `src/`: Archivos fuente del proyecto.
- `build/`: Aquí se almacenarán los archivos de ejecución una vez ejecutado el make.

# Uso del Makefile para compilar y ejecutar
Este programa puede ser compilado y ejecutado a través del uso del Makefile. Es necesario posicionarse en el directorio principal.

Para compilar y ejecutar se debe utilizar el comando `make all`. Para limpiar su contenido se puede ejecutar `make clean`.

## Dependencias
Para ejecutar este programa puede ser necesario instalar algunas dependencias, las cuales se pueden instalar de la siguiente forma:

```
sudo apt update
sudo apt install -y \
    qtbase5-dev \
    qtchooser \
    qt5-qmake \
    qttools5-dev-tools \
    qtdeclarative5-dev \
    qtlocation5-dev \
    qtpositioning5-dev \
    qml-module-qtpositioning \
    qml-module-qtquick-controls \
    qml-module-qtquick-controls2 \
    qml-module-qtquick-dialogs \
    qml-module-qtquick-layouts \
    qml-module-qtquick-window2 \
    qml-module-qtquick2 \
    libqt5quickwidgets5 \
    libqt5quick5 \
    libqt5qml5 \
    libqt5gui5 \
    libqt5network5 \
    libqt5widgets5 \
    libqt5core5a \
    libqt5positioning5 \
    libgl1-mesa-dev \
    libpthread-stubs0-dev \
    build-essential

```

# Lógica y contenido

## Algoritmo de Dijkstra. (Bryan Mora C15141)

El archivo `algorithm.cpp` implementa el algoritmo de Dijkstra para encontrar el camino más corto en un grafo ponderado dirigido.

## Funcionamiento

### 1. Inicialización
- Se crean `dist` (distancias mínimas) y `prev` (nodos anteriores en el camino óptimo).
- Se inicializan distancias a infinito y la de inicio a 0.
- Se usa una cola de prioridad (`pq`) para seleccionar el nodo con menor distancia.

### 2. Exploración de Nodos
- Se extrae el nodo con menor distancia.
- Si es el destino, el algoritmo finaliza.
- Se actualizan distancias y nodos previos si se encuentra un camino más corto.
- Se insertan nodos vecinos en la cola de prioridad.

### 3. Construcción del Camino
- Se reconstruye el camino desde el destino al inicio usando `prev`.
- Se invierte para obtener el orden correcto.
- Si el camino es inválido, se devuelve un vector vacío.

### Consideraciones
- El grafo es ponderado y dirigido.


## Manejo de archivos. (Fabián M C15386)
    Este header pretende trabajar con un archivo de texto "flights.txt" para utilizarlo a modo de base de datos.
Esta funcionalidad permitiria al usuario guardar una sesión, imprimir el grafo dentro del archivo para su
próxima recuperación, y cargar una sesión, procesar este grafo guardado previamente para almacenar los valores
impresos dentro del grafo en el que se esta trabajando actualmente. 

    Los dos metodos existentes son guardarGrafo que requiere dos parámetros, un grafo y el nombre del archivo que
se utilizará como base de datos. A partir de esto imprime los valores deseados de cada ciudad a partir del método
getter del grafo. Este se imprime en el formato:
- CITY Nombre X Y
- CONNECTION Origen Destino Peso

    El siguiente método recibe un grafo y el nombre del archivo nuevamente. Este método se encarga de leer todas 
las líneas del archivo hasta que una de estas este vacia. A partir de esto, utiliza el identificador previo para
distinguir entre conexiones y ciudades. A partir de esta distinción, se procesa cada una de las líneas con los 
métodos existentes para reconstruir las ciudades y conexiones con sus datos pertinentes.

    El recurso principal fue el siguiente:
- [Files_YT](https://www.youtube.com/watch?=Cz4fl-TUjVkt=225sab_channel=CalebCurry)

## Clase Grafo. (Leonardo Serrano C17484)

Ester archivo header pretende definir la estructura y funcionalidades de un grafo dirigido para representar una red de vuelos entre ciudades.

### Características
**Modelado de Ciudades y Vuelos:**
Cada ciudad se modela con un nombre, coordenadas y una lista de vuelos (conexiones). Cada vuelo contiene la ciudad destino y un peso que puede representar, por ejemplo, el costo o la distancia.

**Gestión del Grafo:**
Se proporcionan métodos para agregar y eliminar ciudades, así como para agregar, modificar y eliminar conexiones entre ellas. También se incluye una función para vaciar el grafo por completo.

**Uso de Contenedores STL:**
Se utilizan estructuras como unordered_map para almacenar las ciudades y vector para gestionar las conexiones, aprovechando las ventajas de la biblioteca estándar de C++.

### Métodos Principales
`agregarCiudad:`
Añade una nueva ciudad al grafo, evitando duplicados.

`eliminarCiudad:`
Elimina una ciudad y todas las conexiones asociadas, asegurando la integridad del grafo.

`agregarConexion:`
Crea un vuelo entre dos ciudades, añadiendo la conexión en la ciudad de origen.

`modificarConexion:`
Permite actualizar el peso de un vuelo existente.

`eliminarConexion:`
Borra una conexión específica entre dos ciudades.

`vaciarGrafo:`
Elimina todas las ciudades y conexiones del grafo, reiniciando su estado.

## Interfaz gráfica. (Danna Guevara C23562)
    Esta interfaz gráfica pretende unificar los códigos planteados con el fin de realizar un sistema de reserva de vuelos que permita a los usuarios interactuar con un mapa.

## Funcionalidades Principales
## Características
- Agregar, eliminar y modificar ciudades y vuelos.
- Calcular rutas óptimas entre ciudades mediante el algoritmo de Dijkstra.
- Visualización de la red de vuelos en un mapa interactivo.
- Cargar y guardar la información del grafo desde/hacia archivos.

## Interfaz Gráfica
La interfaz incluye:
- Menús desplegables para seleccionar ciudades de origen y destino.
- Botones para gestionar ciudades y vuelos.
- Botón para calcular la ruta óptima.
- Botones para guardar y cargar grafos.
- Barra de estado para mostrar mensajes e información.
- Área de visualización del mapa con ciudades y conexiones.

### Manejo de Ciudades y Vuelos
- **Agregar Ciudad**: Se agrega una nueva ciudad ingresando un nombre y seleccionando una ubicación en el mapa.
- **Eliminar Ciudad**: Se elimina una ciudad y sus conexiones asociadas.
- **Agregar Vuelo**: Se establece una conexión entre dos ciudades con un peso específico.
- **Modificar Vuelo**: Se cambia el peso de una conexión existente.
- **Eliminar Vuelo**: Se elimina una conexión entre dos ciudades.
- **Cargar Grafo**: Se carga la red de vuelos desde un archivo.
- **Guardar Grafo**: Se guarda la red de vuelos en un archivo.

### Cálculo de Ruta Óptima
El método `button_calcularRutaOptima()` usa el algoritmo de Dijkstra para calcular la ruta más eficiente entre dos ciudades seleccionadas.

### Selección de ubicación de ciudad
El método `eventFilter()` detecta cuando el usuario hace clic en la imagen del mapa mientras está en modo de selección de ubicación de ciudad, si el clic es válido, convierte las coordenadas al sistema original y abre una ventana para agregar una ciudad en esa ubicación. Además, conecta la señal ciudadAgregada para que, si el usuario confirma la acción, la ciudad se agregue a través de la función `agregarCiudadDesdeVentana()`.

### Visualización del Mapa
El método `updateMapDisplay()` actualiza la interfaz cada vez que se necesite según lo que se seleccione con ciudades vistas como círculos rojos con etiquetas, las conexiones o vuelos mostrados como líneas entre ciudades, las rutas óptimas resaltadas en azul y los pesos de las conexiones visibles.

## Estructura del Proyecto
### Archivos Incluidos
- `file_manager.h`: Funciones para guardar y cargar grafos.
- `graphs.h`: Implementación de la estructura del grafo.
- `mainwindow.h`: Definición de la clase `MainWindow`.
- `ui_mainwindow.h`: Generado por Qt Designer.

### Clases de tipo .h
- `AgregarCiudad`: Agrega una nueva ciudad.
- `agregarvuelo`: Agrega una nueva conexión entre ciudades.
- `ModificarVuelo`: Modifica la información de un vuelo.
- `eliminarciudad`: Elimina una ciudad existente.
- `EliminarVuelo`: Elimina una conexión entre ciudades.

    Dentro de los recursos utilizados son los siguientes:
- [Youtube](https://www.youtube.com/watch?v=V4ACsfbKtpU)
- [Youtube](https://www.youtube.com/watch?v=cnFItSiEJTU&t=467s)
- [Youtube](https://www.youtube.com/watch?v=64QRNUg5_YA)
- [Youtube](https://www.youtube.com/watch?v=h56hO1Wqa20)
- [Youtube](https://www.cppbuzz.com/qt/projects/c++-qt-gui-project-on-movie-ticket-booking)

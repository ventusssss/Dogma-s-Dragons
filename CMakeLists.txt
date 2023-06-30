# specifica la versione minima richiesta di cmake
cmake_minimum_required(VERSION 3.0)

# nome del progetto
project(ddgm)

# dichiarazione di una "variabile"
set( 
  # variabile che racchiude la lista delle risorse
  SRC 
  # path relativi al CMakeLists.txt
  src/main.cpp 
  src/entity.cpp
  src/player.cpp
  src/enemies.cpp
  src/utilities.cpp
  src/items.cpp
  src/pawn.cpp
  )

# crea l'eseguibile con nome (p1) e risorsa (p2)
add_executable(${CMAKE_PROJECT_NAME} ${SRC})

# include la cartella "include" del progetto, permettendo un path relativo alla compilazione
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE include)
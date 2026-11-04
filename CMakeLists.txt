cmake_minimum_required(VERSION 3.16)
project(Switch2LiteEngineAI CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Definição global da lista de fontes para evitar escopos vazios
set(SOURCES
    src/cpu_engine.cpp
    src/gpu_translation.cpp
    src/shader_engine.cpp
    src/memory_manager.cpp
    src/system_services.cpp
    src/audio_engine.cpp
    src/game_loader.cpp
    src/dynamic_ai.cpp
    src/compatibility.cpp
)

# Detectar se estamos compilando via libnx (devkitPro) ou nativo para testes (Linux/Host)
if(DEFINED ENV{DEVKITPRO})
    message(STATUS "Configurando para Nintendo Switch (libnx / deko3d)")
    add_executable(switch2_lite_engine src/main.cpp ${SOURCES})
else()
    message(STATUS "Configurando para Host (Testes Automatizados)")
    add_library(engine_core STATIC ${SOURCES})
    
    add_executable(unit_tests 
        tests/test_cpu.cpp 
        tests/test_memory.cpp 
        tests/test_loader.cpp
    )
    target_link_libraries(unit_tests engine_core)
endif()

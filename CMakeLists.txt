cmake_minimum_required(VERSION 3.16)
project(log-visual-monitor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# herramientas automáticas de Qt (Signals/Slots, UI, Recursos)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Qt6
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# archivos
qt_add_executable(log-visual-monitor
    src/main.cpp
    src/core/LogEntry.h
    src/core/LogParser.cpp
    src/core/LogParser.h
)

# carpetas
target_link_libraries(log-visual-monitor PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
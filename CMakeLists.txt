cmake_minimum_required(VERSION 3.16)

project(CpuMonitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpu_monitor
	src/main.cpp
	src/monitor/cpu.cpp
	src/monitor/mem.cpp
	src/monitor/temp.cpp
	src/events/events.cpp
	src/display/display.cpp
)

target_include_directories(cpu_monitor PRIVATE
	src/monitor
	src/events
	src/display

)

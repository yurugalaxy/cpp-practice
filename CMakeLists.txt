cmake_minimum_required(VERSION 4.0)
project(rocky)
set(SOURCES
	src/supp/supp.cpp
	src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
	PRIVATE
		${PROJECT_SOURCE_DIR}/src/supp
)

#..............................................................
# CMakeList.txt : CMake project for Compilers, include source and define
# project specific logic here.
#..............................................................

cmake_minimum_required (VERSION 3.8)

project ("mamba")

# Add source to this project's executable: check name and dependences
add_executable (mamba
	"Compilers.h"	"Compilers.c"
	"Reader.h"		"Reader.c"		"MainReader.c"
	"Scanner.c"		"MainScanner.c"		"Scanner.h"
	"Parser.h"		"Parser.c"		"MainParser.c"
)
)

# TO_DO: Add tests and install targets if needed.

CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

PROJECT(ProvaIntermediaBarbatoCasucciPinton LANGUAGES CXX)

ADD_EXECUTABLE(testCmake
	"./src/Book.cpp"
	"./src/BookShelf.cpp"
	"./src/Date.cpp"
	"./src/main.cpp"
	"./src/MyVector.cpp"
	"./include/Book.h"
	"./include/BookShelf.h"
	"./include/Date.h"
	"./include/MyVector.h"
)
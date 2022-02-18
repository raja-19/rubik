main: main.cpp init.h init.cpp shader.h shader.cpp input.h input.cpp run.h run.cpp 3d.h 3d.cpp rubik.h rubik.cpp animation.h animation.cpp
	g++ glad.c main.cpp init.cpp shader.cpp input.cpp run.cpp 3d.cpp rubik.cpp animation.cpp -o main -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

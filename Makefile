# SRC_SOURE = glad.c main.cpp Window.cpp Program.cpp Shader.cpp Vertex.cpp Texture.cpp  Camera.cpp Model.cpp
all:
	g++ -o gltest $(wildcard ./*cpp ./*.c) -lglfw3 -lGL -lm -lXrandr -lX11 -lXxf86vm -lpthread -ldl
	./gltest
	clear
clean:
	rm -rf gltest *.o
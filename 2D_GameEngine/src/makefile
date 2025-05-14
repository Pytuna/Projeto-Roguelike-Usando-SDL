all: 
	g++ -Wall -pedantic-errors -Werror -g -lm -c Vector2D.cpp `pkg-config --cflags --libs sdl2` -lSDL2_image
	g++ -Wall -pedantic-errors -Werror -g -lm -c TextureManager.cpp `pkg-config --cflags --libs sdl2` -lSDL2_image
	g++ -Wall -pedantic-errors -Werror -g -lm -c Map.cpp `pkg-config --cflags --libs sdl2` -lSDL2_image
	g++ -Wall -pedantic-errors -Werror -g -lm -c GameObject.cpp `pkg-config --cflags --libs sdl2` -lSDL2_image
	g++ -Wall -pedantic-errors -Werror -g -lm -c Game.cpp `pkg-config --cflags --libs sdl2` -lSDL2_image
	g++ -Wall -pedantic-errors -Werror -g -lm Main.cpp Game.o TextureManager.o Vector2D.o Map.o GameObject.o `pkg-config --cflags --libs sdl2` -lSDL2_image
	./a.out

clean:
	rm -rf *.out && rm -rf *.o
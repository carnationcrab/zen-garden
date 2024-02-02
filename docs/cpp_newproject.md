# Setting up a New C++ Project with SDL2 (sublime)

## Steps used to make this repo

1. run command, replacing [name] with name:

`mkdir [name] && cd [name] && mkdir res src bin bin/debug bin/release include && touch [name].sublime-project && cd src && touch main.cpp`

2. in [name].sublime-project paste:

for linux:
`{
	"folders":
	[
		{
			"path": "bin/.."
		}
	],
	"build_systems": 
	[
		{
			"name": "Debug",
			"working_dir": "${project_path}",
			"cmd": ["g++ -c src/*.cpp -std=c++14 -m64 -g -Wall -I include && g++ *.o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image && ./bin/debug/main"],
			"selector": "source.c++",
			"shell": true
		},
		{
			"name": "Release",
			"working_dir": "${project_path}",
			"cmd": ["g++ -c src/*.cpp -std=c++14 -m64 -03 -Wall -I include && g++ *.o -o bin/release/main -s -lSDL2main -lSDL2 -lSDL2_image && ./bin/release/main"],
			"selector": "source.c++",
			"shell": true
		}	
	]
}
`

3. open [name].sublime-project with sublime.

4. open main.cpp

5. paste 
```
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argv, char* args[]) 
{
	std::cout << "yay" << sdt::endl;
}
```

6. Tools > Build System > check Debug

7. Ctrl+6 to run program

### Additional steps

1. Navigate to x86_64-linux-gnu folder

2. grab sdl and sdl image files

3. put them in project src and rename

4. copy and paste those into debug and main bin folders

IMPORTANT ***

Every time you add an asset you MUST COPY AND PASTE res folder into debug and release!!

ugh that is annoying I should fix that.

## Notes

### Command from Step 2

- `g++ -c src/*.cpp -std=c++14 -w64 -g -Wall -I include` compiles the project.

- `g++ *.o -o bin/debug/main -lSDL2_main -lSDL2 -lSDL2_image` sets the logging to the folder for the given environment does some SDL2 stuff

- `./bin/debug/main` runs the project

*src* [.cpp] file is for cpp files.
*include* [.h] file is for header files
*include* [~] file is for resource files (assets, graphics, sound, etc.)

open new package in sublime
ctrl+shift+p
Package Control/ Install Package

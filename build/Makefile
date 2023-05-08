LINUX_CXX=g++
LINUX_CXXFLAGS=-std=c++17 -Wall -Wextra -Wno-unused-result -O3 -Wno-reorder
LINUX_LINKERFLAGS=-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
LINUX_TARGET=Proj-linux
LINUX_OUT=linux_obj
LINUX_PACKAGE=builds/LinuxPackage

WINDOWS_CXX=x86_64-w64-mingw32-g++
WINDOWS_CXXFLAGS=-std=c++17 -Wall -Wextra -Wno-unused-result -O3 -ISFML-win/include -DSFML_STATIC -Wno-reorder
WINDOWS_LINKERFLAGS=-LSFML-win/lib -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopenal32 -lvorbisenc -lvorbisfile -lvorbis -logg -lFLAC -static -static-libgcc -static-libstdc++
WINDOWS_TARGET=Proj-windows.exe
WINDOWS_OUT=windows_obj
WINDOWS_PACKAGE=builds/WindowsPackage

ASSETS_PATH=assets

all: linux windows

##### LINUX SECTION BEGIN #####
linux: linux_main
	$(LINUX_CXX) $(LINUX_OUT)/*.o -o $(LINUX_TARGET) $(LINUX_LINKERFLAGS)

linux_main: linux_common linux_scene linux_scene_manager linux_image
	$(LINUX_CXX) -c ../src/main.cc -o $(LINUX_OUT)/main.o $(LINUX_CXXFLAGS)

linux_common:
	$(LINUX_CXX) -c ../src/common.cc -o $(LINUX_OUT)/common.o $(LINUX_CXXFLAGS)

linux_scene:
	$(LINUX_CXX) -c ../src/scene.cc -o $(LINUX_OUT)/scene.o $(LINUX_CXXFLAGS)

linux_scene_manager:
	$(LINUX_CXX) -c ../src/scene_manager.cc -o $(LINUX_OUT)/scene_manager.o $(LINUX_CXXFLAGS)

linux_image:
	$(LINUX_CXX) -c ../src/image.cc -o $(LINUX_OUT)/image.o $(LINUX_CXXFLAGS)
##### LINUX SECTION END #####

##### WINDOWS SECTION BEGIN #####
windows: windows_main
	$(WINDOWS_CXX) $(WINDOWS_OUT)/*.o -o $(WINDOWS_TARGET) $(WINDOWS_LINKERFLAGS)

windows_main: windows_common windows_scene windows_scene_manager windows_image
	$(WINDOWS_CXX) -c ../src/main.cc -o $(WINDOWS_OUT)/main.o $(WINDOWS_CXXFLAGS)

windows_common:
	$(WINDOWS_CXX) -c ../src/common.cc -o $(WINDOWS_OUT)/common.o $(WINDOWS_CXXFLAGS)

windows_scene:
	$(WINDOWS_CXX) -c ../src/scene.cc -o $(WINDOWS_OUT)/scene.o $(WINDOWS_CXXFLAGS)

windows_scene_manager:
	$(WINDOWS_CXX) -c ../src/scene_manager.cc -o $(WINDOWS_OUT)/scene_manager.o $(WINDOWS_CXXFLAGS)

windows_image:
	$(WINDOWS_CXX) -c ../src/image.cc -o $(WINDOWS_OUT)/image.o $(WINDOWS_CXXFLAGS)
##### WINDOWS SECTION END #####

##### MISCHELANEOUS SECTION BEGIN #####
clean: cleanLinux cleanWindows

cleanLinux:
	rm -rf $(LINUX_OUT)/*.o $(LINUX_TARGET) ../$(LINUX_PACKAGE)

cleanWindows:
	rm -rf $(WINDOWS_OUT)/*.o $(WINDOWS_TARGET) ../$(WINDOWS_PACKAGE)

package: linuxPackage windowsPackage

linuxPackage: linux
# create package folder
	mkdir ../$(LINUX_PACKAGE)
# copy entire assets folder into package
	cp -r $(ASSETS_PATH) ../$(LINUX_PACKAGE)
# copy linux binary into package
	mv $(LINUX_TARGET) ../$(LINUX_PACKAGE)
# create a README.text into package
	echo "Thanks for installing!" > ../$(LINUX_PACKAGE)/README.txt

windowsPackage: windows
# create package folder
	mkdir ../$(WINDOWS_PACKAGE)
# copy entire assets folder into package
	cp -r $(ASSETS_PATH) ../$(WINDOWS_PACKAGE)
# copy windows executable into package
	mv $(WINDOWS_TARGET) ../$(WINDOWS_PACKAGE)
# copy required DLL into package
	cp SFML-win/bin/openal32.dll ../$(WINDOWS_PACKAGE)
# create a README.text into package
	echo "Thanks for installing!" > ../$(WINDOWS_PACKAGE)/README.txt
##### MISCHELANEOUS SECTION END #####

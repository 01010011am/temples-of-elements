all: main

main: backpack.hpp backpack.cpp bloodspace.hpp bloodspace.cpp boss.hpp boss.cpp earthspace.hpp earthspace.cpp entrancehall.hpp entrancehall.cpp firespace.hpp firespace.cpp game.hpp game.cpp interactable.hpp interactable.cpp interestpoint.hpp interestpoint.cpp player.hpp player.cpp portal.hpp portal.cpp space.hpp space.cpp spacelist.hpp spacelist.cpp waterspace.hpp waterspace.cpp windspace.hpp windspace.cpp main.cpp
	g++ backpack.hpp backpack.cpp bloodspace.hpp bloodspace.cpp boss.hpp boss.cpp earthspace.hpp earthspace.cpp entrancehall.hpp entrancehall.cpp firespace.hpp firespace.cpp game.hpp game.cpp interactable.hpp interactable.cpp interestpoint.hpp interestpoint.cpp player.hpp player.cpp portal.hpp portal.cpp space.hpp space.cpp spacelist.hpp spacelist.cpp waterspace.hpp waterspace.cpp windspace.hpp windspace.cpp main.cpp -o main

clean:
	rm main
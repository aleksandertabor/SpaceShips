#Windows
1.Install C++ in Visual Studio 2017.
2.Download SFML 2.5.1 for Visual C++ 15 (2017) - 32-bit.
https://www.sfml-dev.org/download/sfml/2.5.1/
3.Save files in "C:\SFML-2.5.1\"
4.Set x86 compile in VS Projects.
5.Configure SFML on Visual Studio 2017.
https://www.sfml-dev.org/tutorials/2.5/start-vc.php
6.Compile and run project

#Linux (Ubuntu)
sudo apt-get install g++
sudo apt-get install libsfml-dev
cd SpaceShips
g++ -std=c++11 -o SpaceShips main.cpp Bullet.cpp Collision.cpp CsvFiles.cpp Enemy.cpp Game.cpp Gift.cpp Player.cpp -lsfml-graphics -lsfml-window -lsfml-system
./SpaceShips
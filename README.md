# SpaceShips
<br />
## General
SpaceShips game written in C++ language, using SFML library. <br />
The project was created in Microsoft Visual Studio 2017. <br />
The game is in the process of creating.

## Screens
![alt text](https://raw.githubusercontent.com/aleksandertabor/SpaceShips/master/Screens/s1.png) <br />
![alt text](https://raw.githubusercontent.com/aleksandertabor/SpaceShips/master/Screens/s2.png) <br />
![alt text](https://raw.githubusercontent.com/aleksandertabor/SpaceShips/master/Screens/s3.png) <br />
![alt text](https://raw.githubusercontent.com/aleksandertabor/SpaceShips/master/Screens/s4.png) <br />
![alt text](https://raw.githubusercontent.com/aleksandertabor/SpaceShips/master/Screens/s5.png) 

## Compilation

###Windows
```
1.Install C++ in Visual Studio 2017.
2.Download SFML 2.5.1 for Visual C++ 15 (2017) - 32-bit.
https://www.sfml-dev.org/download/sfml/2.5.1/
3.Save files in "C:\SFML-2.5.1\"
4.Set x86 compile in VS Projects.
5.Configure SFML on Visual Studio 2017.
https://www.sfml-dev.org/tutorials/2.5/start-vc.php
6.Compile and run project
```

###Linux (Ubuntu)
```
sudo apt-get install g++
sudo apt-get install libsfml-dev
cd SpaceShips
g++ -std=c++11 -o SpaceShips main.cpp Bullet.cpp Collision.cpp CsvFiles.cpp Enemy.cpp Game.cpp Gift.cpp Player.cpp -lsfml-graphics -lsfml-window -lsfml-system
./SpaceShips
```

## Authors
The game was written by **Aleksander Tabor** and **Tomasz Zurek**<br />
* My website: **https://aleksandertabor.pl/** <br />
* Co-author's website: **http://zurektomasz.pl/**
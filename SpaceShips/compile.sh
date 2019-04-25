sudo apt-get install g++
sudo apt-get install libsfml-dev
g++ -std=c++11 -o SpaceShips main.cpp Bullet.cpp Collision.cpp CsvFiles.cpp Enemy.cpp Game.cpp Gift.cpp Player.cpp -lsfml-graphics -lsfml-window -lsfml-system
./SpaceShips
<h1 align="center"> SpaceShips <img align="center" src="https://github.com/aleksandertabor/SpaceShips/blob/master/android-port/app/src/main/res/mipmap-xxxhdpi/ic_launcher_round.png?raw=true" width="45"/> - multiplatform game</h1> <br>
<p align="center">
<b>🆕 Available on:</b>
<a href='https://play.google.com/store/apps/details?id=org.spaceships.android&pcampaignid=MKT-Other-global-all-co-prtnr-py-PartBadge-Mar2515-1'><img alt='Get it on Google Play' src='https://play.google.com/intl/en_us/badges/images/generic/en_badge_web_generic.png' width="180" align="center"/></a>
</p>
<p align="center">
<img align="center" src="http://aleksandertabor.pl/spaceships/spaceships.gif" width="100%"/>
</p>
<br />
<br />
<p align="center">
  <a href="#general">General</a> �
  <a href="#screens">Screens</a> �
  <a href="#compilation">Compilation</a> �
  <a href="#authors">Authors</a>
</p>

## General

<table>
<tr>
<td>
SpaceShips game written in C++ language, using SFML library. <br />
The project was created in Microsoft Visual Studio 2017. <br />
Multiplatform game for <b>Windows</b>, <b>Linux</b> and <b>Android</b>. <br />
The game is in the process of creating.
</td>
</tr>
</table>


## Screens
![alt text](https://raw.githubusercontent.com/aleksandertabor/SpaceShips/master/Screens/s1.png) <br />
![alt text](https://raw.githubusercontent.com/aleksandertabor/SpaceShips/master/Screens/s2.png) <br />
![alt text](https://raw.githubusercontent.com/aleksandertabor/SpaceShips/master/Screens/s3.png) <br />
![alt text](https://raw.githubusercontent.com/aleksandertabor/SpaceShips/master/Screens/s4.png) <br />
![alt text](https://raw.githubusercontent.com/aleksandertabor/SpaceShips/master/Screens/s5.png) <br />

## Compilation

### Windows
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
<p align="center">
<img align="center" src="http://aleksandertabor.pl/spaceships/visualstudiodebug.png" width="70%"/>
</p>

### Linux (Ubuntu)
```
sudo apt-get install g++
sudo apt-get install libsfml-dev
git clone https://github.com/aleksandertabor/SpaceShips/
cd SpaceShips
g++ -std=c++11 -o SpaceShips main.cpp Bullet.cpp Collision.cpp CsvFiles.cpp Enemy.cpp Game.cpp Gift.cpp Player.cpp -lsfml-graphics -lsfml-window -lsfml-system
./SpaceShips
```

### Android
```
1.Build SFML for Android with tutorial.
https://github.com/SFML/SFML/wiki/Tutorial:-Building-SFML-for-Android
2.Extract all content from repository in non-ASCII characters path (characters like space or dashes -_ don't work). 
Note: If you run project in Android Studio it will throw an error about non-ASCII:
"Your project path contains non-ASCII characters. This will most likely cause the build to fail on Windows. Please move your project to a different directory."
    
	Working: C:\SpaceShips\
	Not working: C:\SpaceShips - 2019\
    
3.You can debug project with Gradle commands or open in Android Studio.
Note: Android Port required all files from repository. DON'T extract only /android-port/ folder. 
Source files (SpaceShips folder) are mutual for all platforms.
4.Open project in Android Studio by choosing only build.gradle file in explorer directly from /android-port/ directory.
5.Before debbuging remember about changing your paths for SDK and NDK in android-port\local.properties.
Android Studio automatically will be scanning for source files from /SpaceShips/ folder - Android.mk and Application.mk are there.
Android assets (images, audio, levels) are in android-port\app\src\main\assets, only code is mutual.
Java code is in android-port\app\src\main\java directory.
```
<p align="center">
<img align="center" src="http://aleksandertabor.pl/spaceships/androidstudiodebug.png" width="70%"/>
</p>

## Authors
[![Aleksander Tabor](https://avatars0.githubusercontent.com/u/22729643?s=144&v=4)](https://github.com/aleksandertabor)  | [![Tomasz Zurek](https://avatars1.githubusercontent.com/u/26256302?s=144&v=4)](https://github.com/zurektomasz)
---|---
[Aleksander Tabor ](https://aleksandertabor.pl) |[Tomasz Zurek](htts://zurektomasz.pl)
<br />
The game was written by **Aleksander Tabor** and **Tomasz Zurek**<br />
* My website: **https://aleksandertabor.pl/** <br />
* Co-author's website: **http://zurektomasz.pl/**
#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <thread>
#include <map>
#include <algorithm>
#include <utility>
#include <set>
#include <fstream>
#include <stdio.h>
#include <errno.h>
#if defined(__ANDROID__)
// These headers are only needed for direct NDK/JDK interaction
#include <exception>
#include <jni.h>
#include <assert.h>
#include <android/native_activity.h>
#include <android/log.h>
#include <android/asset_manager.h>
// Since we want to get the native activity from SFML, we'll have to use an
// extra header here:
#include <SFML/System/NativeActivity.hpp>
#endif


#include "Collision.h"
#include "CsvFiles.h"

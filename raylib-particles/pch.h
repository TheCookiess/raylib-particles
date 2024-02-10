#pragma once // so much for pre-compiled headers being "only essential" includes..

using namespace std;
#include <iomanip>
#include <iostream> 
#include <functional>
#include <memory>
#include <thread>
#include <utility>
#include <chrono>
#include <ranges>
#include <stdexcept>
#include <random>
#include <algorithm>
#include <unordered_map>
#include <stdio.h>

// External Libraries.. oh the linking..
#include <raylib.h>
//#include <raymath.h>
//#include <rlgl.h>

// Data Structures
#include <vector>
#include <string>
#include <array>
//#include <stack>
//#include <deque>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>

// Type Definitions
using u8 = uint8_t;	// unsigned char
using u16 = uint16_t;	// unsigned short
using u32 = uint32_t;	// unsigned long int (equal to int on 64 bit systems)
using u64 = uint64_t;	// unsigned long long

using i8 = int8_t;		// char
using i16 = int16_t;	// short
using i32 = int32_t;	// long int (equal to int on 64 bit systems)
using i64 = int64_t;	// long long

using f32 = float;		// float
using f64 = double;		// double (long float)

using Colour = Color;
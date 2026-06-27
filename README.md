# Camera (Raylib C++ Project)

Hello 👋
This is mysmall project using **Raylib with C++**.

## ⚙️ Requirements

To compile and run this project, you need:

* C++ compiler (g++, clang, or MSVC)
* Raylib installed

---

# 🐧 Linux (Ubuntu / Debian)

### Install Raylib:

```bash id="l1"
sudo apt update
sudo apt install libraylib-dev
```

### Compile:

```bash id="l2"
g++ camera.cpp -o camera -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

### Run:

```bash id="l3"
./camera
```

---

# 🍎 macOS

### Install Raylib:

```bash id="m1"
brew install raylib
```

### Compile:

```bash id="m2"
g++ camera.cpp -o camera -lraylib -framework OpenGL -framework Cocoa -framework IOKit
```

### Run:

```bash id="m3"
./camera
```

---

# 🪟 Windows (MinGW / MSYS2)

### Install Raylib:

```bash id="w1"
pacman -S mingw-w64-x86_64-raylib
```

### Compile:

```bash id="w2"
g++ camera.cpp -o camera.exe -lraylib -lopengl32 -lgdi32 -lwinmm
```

### Run:

```bash id="w3"
camera.exe
```


## ❤️ Author

Made by a beginner learning C++ + Raylib
Building small game systems step by step 

# Minimal CMake Project

Configure (creates build/ folder automatically)
```bash 
cmake --preset default
```

Build Debug
```bash
cmake --build --preset debug
```

Run the app (use .exe on Windows)
```bash
./build/Debug/myapp
```
```bash
./build/Debug/myapp.exe
```

Run tests (defaults to Debug)
```bash
ctest --preset default
```

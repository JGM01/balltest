# Balls

Clone using:
```bash
git clone --recurse-submodules https://github.com/JGM01/balltest.git
```

## Build
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

## Web

Build for web
```bash
emcmake cmake -B build-web \
  -DDAWN_FETCH_DEPENDENCIES=ON \
  -DProtobuf_FOUND=OFF \
  -DDAWN_BUILD_PROTOBUF=OFF \
  -DTINT_BUILD_IR_BINARY=OFF \
  && cmake --build build-web
```

Start a server
```bash
npx http-server
```

Navigate to `build-web/app.html`, should show the result.

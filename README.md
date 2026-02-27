# RayTracer

A small, educational ray tracer implemented while following the "Ray Tracing in One Weekend" tutorials by Peter Shirley.

## Summary
This project reproduces the examples from the "Ray Tracing in One Weekend" series. It implements the simple ray tracing renderer and outputs a PPM image (`image.ppm`). The code follows the book's progression and is intended for learning and experimentation.

## Build
- Using the included `Makefile`: run `make` (if your environment supports it).
- With g++ (MinGW / Linux / macOS):

  ```bash
  g++ -std=c++17 -O2 ray_tracer.cpp -o ray_tracer.exe
  ```

- In VS Code: use the task `C/C++: g++.exe build active file` to build the active file.

## Run
- Run the executable and redirect stdout to produce the image:

  ```bash
  ./ray_tracer.exe > image.ppm
  ```

  On Windows (PowerShell / cmd):

  ```powershell
  .\ray_tracer.exe > image.ppm
  ```

- Open `image.ppm` with an image viewer that supports PPM files (or convert to PNG with an image tool).

## Project layout
- `ray_tracer.cpp` — main program and example scenes.
- `headers/` — supporting headers used by the renderer (materials, geometry, utilities, etc.).
- `image.ppm` — example output image (committed for reference).

## Credits
This work follows and gives full credit to the "Ray Tracing in One Weekend" series by Peter Shirley.
See: https://raytracing.github.io/books/RayTracingInOneWeekend.html

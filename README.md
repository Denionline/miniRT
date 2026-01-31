# miniRT

A small ray tracer written in C, built for the 42 **miniRT** project.

This project parses a `.rt` scene file, builds a world (camera, light, objects), renders the scene into an image, and displays it using **MiniLibX** on Linux.

## Features

- **Ray tracing core**: rays, intersections, hit selection, normals, transformations
- **Phong lighting** with ambient/diffuse/specular components
- **Shadows** (single point light source)
- **Objects**
  - Sphere (`sp`)
  - Plane (`pl`)
  - Cylinder (`cy`)
  - Cone (`co`)
- **Patterns** (in code): stripe, gradient, ring, checkboard
- **Scene parsing** from a text `.rt` file

## Requirements

- Linux OS
- A C compiler (`cc`)
- X11 development libraries (required by MiniLibX on Linux)
- `make`

This repo vendors (or can auto-fetch) its dependencies:

- `include/libft/`
- `include/get_next_line/`
- `include/minilibx-linux/`

## Build

```bash
make
```

Useful targets:

```bash
make clean
make fclean
make re
```

Notes:

- The Makefile will **clone** `libft`, `get_next_line`, and `minilibx-linux` if their folders are missing.

## Run

The program expects exactly **one** argument: the scene file path.

```bash
./miniRT scenes/default.rt
```

If you run without a scene argument, the program exits immediately.

## Controls

- `ESC`: close the window and exit

## Scene file format (`.rt`)

A scene file is read line-by-line. Empty/whitespace-only lines are ignored.

### Required identifiers

Your scene must include **exactly one** of each:

- `A` (ambient light)
- `C` (camera)
- `L` (light)

If any are missing, the parser errors.

### Supported identifiers

- `A <ratio> <R,G,B>`
- `C <x,y,z> <nx,ny,nz> <fov_degrees>`
- `L <x,y,z> <brightness> <R,G,B>`
- `sp <x,y,z> <diameter> <R,G,B>`
- `pl <x,y,z> <nx,ny,nz> <R,G,B>`
- `cy <x,y,z> <nx,ny,nz> <diameter> <height> <R,G,B>`
- `co <x,y,z> <nx,ny,nz> <diameter> <height> <R,G,B>`

Where:

- Colors are in **0–255** and internally normalized to **0–1**.
- `<nx,ny,nz>` vectors are expected to be valid direction vectors; they are normalized by the parser for planes/cylinders.
- `ratio` and `brightness` are expected in **[0.0, 1.0]**.
- The camera `fov` is expected in **(0, 180]** degrees.

### Example

```text
A 0.2 255,255,255
C -50,0,20 0,0,1 70
L -40,0,30 0.7 255,255,255

pl 0,0,0 0,1,0 255,0,225
sp 0,0,20 20 255,0,0
cy 50,0,20.6 0,0,1 14.2 21.42 10,0,255
cy 50,0,30 0,0,1 14.2 10.0 50,230,0
```

## Implementation notes / limitations

These notes reflect the current implementation in this repository:

- **Single light only**: the world stores one `t_light`, and the parser rejects duplicate `L` entries.
- **Fixed render size**: the camera is constructed as **500×300** during parsing.
- Supported objects in parsing are: **sphere**, **plane**, **cylinder**, **cone**.

## Tests / Debug helpers

This repo includes a small interactive test runner script:

```bash
./test
```

- It uses `whiptail` to select a file from `tests/`.
- It rebuilds with `make MAIN_FILE="tests/<selected>.c"`.
- It can run in `normal`, `valgrind`, or `gdb` mode.

## Project structure

- `main.c`: program entrypoint
- `include/`: headers and third-party libs (libft, GNL, MiniLibX)
- `src/`: implementation (parsing, math, rays, objects, lighting, world, canvas)
- `scenes/`: sample `.rt` scenes
- `tests/`: unit/integration-style test mains

## Troubleshooting

- If the build fails at link time with X11-related errors, install the X11 development packages for your distro.
- If launching shows no window, ensure you are running under an X session (or a configured X server).

---

If you want, share the PDF rubric/rules and I’ll adjust this README to match it exactly (section order, required headings, screenshots, badges, etc.).

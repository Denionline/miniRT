# Mini Ray Tracing

This project has been created as part of the 42 curriculum by **dximenes** and **nsaraiva**.

## Description

**MiniRT** is a small ray tracer written in **C**.  
Its goal is to generate a 3D scene rendered into a 2D image by simulating how rays of light intersect with objects.

In this project, a scene is described in a `.rt` file (camera, lights, objects, materials/colors, etc.). The program parses this file, computes intersections (ray/object), applies lighting (at minimum ambient + diffuse; optionally specular), and displays the rendered result in a window (typically via MiniLibX).

Key ideas typically covered by miniRT:
- Ray generation from a camera through each pixel
- Intersection tests (sphere, plane, cylinder, etc.)
- Surface normals and shading
- Basic lighting and shadows
- Simple scene parsing and validation

## Instructions

### Requirements
- A Unix-like environment (Linux or macOS)
- `make`
- A C compiler (`cc`, `clang`, or `gcc`)
- **MiniLibX** available/installed (exact setup depends on your 42 campus / OS)

### Build
From the repository root:
```sh
make
```

Common extra rules (if provided in your project):
```sh
make clean
make fclean
make re
```

### Run
Typical usage:
```sh
./miniRT scenes/example.rt
```

If your project supports options (bonus features, save-to-file, etc.), document them here, for example:
```sh
./miniRT <scene.rt>
```

### Scene files (`.rt`)
- Ensure your scene file follows the miniRT subject format (identifiers, vectors, RGB ranges, required elements, etc.).
- If your parser is strict (recommended), invalid or missing elements should produce an error and exit cleanly.

## Resources

### Ray Tracing References
- Scratchapixel (excellent ray tracing lessons): https://www.scratchapixel.com/
- Ray Tracing in One Weekend (intro series): https://raytracing.github.io/
- Wikipedia — Ray tracing: https://en.wikipedia.org/wiki/Ray_tracing_(graphics)
- Phong reflection model (common for miniRT shading): https://en.wikipedia.org/wiki/Phong_reflection_model
- MiniLibX (general 42 reference, varies by campus):  
  - https://harm-smits.github.io/42docs/libs/minilibx

### How AI Was Used
AI (ChatGPT) was used to assist with:
- Drafting this README structure to match the **42 miniRT** requirements (sections and wording).
- Creating a checklist of what a miniRT README should explain (build/run steps, scene format, and references).

AI was **not** used to generate or copy any external copyrighted code into the project. All implementation decisions and code were written and validated by the project author(s).
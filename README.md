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
- A Unix-like environment.
- `make`
- A C compiler (`cc`, `clang`, or `gcc`)
- **MiniLibX** available/installed.

# Build
From the repository root:
```sh
make
```

Common extra rules:
```sh
make fclean // clear
make re // re-build
```

# Run

To run the program you have to execute in shell the main file **`miniRT`**, with a scene as argument, the scene must have the extension `.rt`.
````
./miniRT <scene.rt>
````
You can start running the example:
````
./miniRT scenes/default.rt
````
# Scene files (.rt) 

### General syntax rules
- **One element per line**.
- Empty or Commented lines are ignored.
- Parameters are separated by spaces and/or tabs.
- **Vectors** are written as: `x,y,z`
- **Colors** are written as: `R,G,B` (integers `[0..255`)
- Object lines may optionally end with **one pattern keyword** (`ck`, `st`, `rg`, `gr`).

### Required arguments (limits)
A valid scene must contain:
- Exactly **one** `A` (ambient light)
- Exactly **one** `C` (camera)
- Exactly **one** `L` (light)
- Objects (**no min or max**): `sp`, `pl`, `cy`, `co`

## Elements detailed

### `A` --- Ambient light

**Format**
```text
A <ratio> <R,G,B>
```

**Params**
1. `ratio` (float): ambient intensity ratio `0.0..1.0`
2. `R,G,B` (color): ambient color (`[0..255`])

### `C` --- Camera
**Format**
```text
C <x,y,z> <x,y,z> <fov>
```

**Params**
1. `x,y,z` (vector): camera position in world space `[0..100]`
2. `x,y,z` (vector): camera orientation (view direction) `[-1,1]`
3. `fov` field of view as integer `0..180`

### `L` --- Light
**Format**
```text
L <x,y,z> <brightness> <R,G,B>
```

**Params**
1. `x,y,z` (vector): light position in world space `[0..100]`
2. `brightness` (float): light intensity ratio `[0.0..1.0]`
3. `R,G,B` (color): light color `[0..255]`

## Objects

### `sp` --- Sphere
**Format**
```text
sp <x,y,z> <diameter> <R,G,B> [pattern]
```

**Params**
1. `x,y,z`: (vector) center position `[0..100]`
2. `diameter` (positive float) `[0..100]`
3. `R,G,B`: base object color `[0..255]`

### `pl` --- Plane
**Format**
```text
pl <x,y,z> <x,y,z> <R,G,B> [pattern]
```

**Params**
1. `x,y,z`: a point on the plane `[0..100]`
2. `x,y,z`: plane normal direction `[-1.0..1.0]`
3. `R,G,B`: base object color `[0..255]`

### `cy` --- Cylinder
**Format**
```text
cy <x,y,z> <x,y,z> <diameter> <height> <R,G,B> [pattern]
```

**Params**
1. `x,y,z`: (vector) cylinder position `[0..100]`
2. `x,y,z`: (vector) cylinder axis direction `[-1,1]`
3. `diameter` (positive float) `[0..100]`
4. `height` (positive float) `[0..100]`
5. `R,G,B`: base object color `[0..255]`

### `co` --- Cone
**Format**
```text
co <x,y,z> <x,y,z> <diameter> <height> <R,G,B> [pattern]
```

**Params**
1. `x,y,z`: (vector) cone position `[0..100]`
2. `x,y,z`: (vector) cone axis direction `[0..100]`
3. `diameter` (float) `[0..100]`
4. `height` (float) `[0..100]`
5. `R,G,B`: base object color `[0..255]`

## Patterns (optional)

### How to write it
Append the keyword as the **last token** of an object line:
```text
<object ...> <pattern_keyword>
```

### Supported pattern keywords
| Keyword | Pattern type |
|--------:|--------------|
| `ck` | checkerboard |
| `st` | stripes |
| `rg` | rings |
| `gr` | gradient |

### Limits / behavior
- Patterns are **optional**.
- Patterns in this repo **do not accept extra parameters** in the `.rt` file.
- Pattern colors are currently **hardcoded in code** (the keyword chooses a fixed pair of colors).
- If an extra token is present and it’s not one of the 4 keywords above, the parser treats the line as invalid.


## Full example scene
```text
A 0.2 255,255,255
C 0,0,0 0,0,1 70
L 10,10,10 0.7 255,255,255

sp 0,0,20 10 255,0,0 ck
pl 0,-5,0 0,1,0 200,200,200 st
cy 5,0,25 0,1,0 4 12 0,0,255 rg
co -5,0,25 0,1,0 6 10 255,255,255 gr
```
# Resources

### Ray Tracing References
- Book **The Ray Tracer Challenge** by Jamis Buck: http://raytracerchallenge.com/

### How AI Was Used
AI (ChatGPT) was used to assist with:
- Drafting this README structure to match the **42 miniRT** requirements (sections and wording).
- Creating a checklist of what a miniRT README should explain (build/run steps, scene format, and references).

AI was **not** used to generate or copy ay external copyrighted code into the project. All implementation decisions and code were written and validated by the project author(s).
# FdF – Wireframe 3D Map Renderer

FdF (Fil de Fer – “wireframe”) is a 42 School graphics project that renders a 3D heightmap as a 2D isometric wireframe using the modern **MLX42** library. It reads a textual grid of altitude values (optionally with per‑point colors), transforms the data into projected screen coordinates, and draws it efficiently using **Bresenham’s line algorithm** with color interpolation.

This README goes beyond usage: it explains the theory of projections, scaling, gradients, memory layout, and algorithmic decisions so you can extend or refactor the project confidently.

---

## 1. High‑Level Pipeline

```
 Map File (.fdf)
     │
     ▼
  Parse & Validate → Build 2D array of t_map {x,y,z,color}
     │
     ▼
  Normalize & Compute Offsets (fit to window)
     │
     ▼
  Isometric Projection (rotate + pseudo depth)
     │
     ▼
  Line Generation (horizontal & vertical neighbors)
     │     (Bresenham + gradient per pixel)
     ▼
  Raster Output (MLX42 image → window)
```

---

## 2. Features

* Isometric projection (classic 30°/45° compound) for intuitive depth perception.
* Automatic scaling & centering to any map resolution.
* Per‑segment color gradients (linear interpolation in RGB space).
* Support for explicit colors (e.g. `3,0xFFAA00`) or altitude‑based defaults.
* Memory‑safe parsing with consistency checks (rectangular maps enforced).
* Efficient integer line rasterization (Bresenham) with minimal branching.
* Clean shutdown via ESC key or window close.

---

## 3. Map File Format

Each line = one row (y). Values separated by spaces. A value can be:

```
Z
Z,0xRRGGBB
```

Example:

```
0 0 0 1 2,0xFF0000
0 1 2 3 4,0x00FFAA
```

Constraints:
* All rows must have identical column counts.
* Z is parsed as `int` (can be negative).
* Colors default to a base purple variant scaled by altitude if unspecified.

---

## 4. Core Data Structures

| Struct | Purpose |
|--------|---------|
| `t_map` | Stores a single point’s projected (x,y), original `z`, and final `color`. |
| `t_box` | Global map width & height (in points). |
| `t_offset` | Scaling interval (zoom) + starting screen offsets. |
| `t_parameters` | Working state for Bresenham (dx, dy, sx, sy, error p). |
| `t_coordinates` | Raw endpoints for a line prior to parameter derivation. |

Internally the map is a dynamically allocated 2D array: `t_map **map` with `height` rows each owning `width` contiguous `t_map` elements.

---

## 5. Parsing & Validation

Files are first counted line‑wise (`ft_count_height`) to allocate the row pointer array. Each line is read and stored verbatim (`ft_get_all`). During `ft_parse_map`:

1. Each line is split on spaces.
2. The first line defines canonical width; all subsequent lines must match.
3. Each token is transformed by `ft_fill_element` → (z, color, original x,y indices).
4. Memory is freed immediately on any consistency failure.

Color parsing supports `0x` prefixed hex; otherwise a fallback gradient rule applies using altitude scaling.

Complexity: O(N) in number of map points (each parsed exactly once).

---

## 6. Projection Mathematics

Classical isometric view approximates a rotation of the 3D grid around the Z and then X (or Y) axes to emulate depth while preserving equal axis foreshortening.

In this implementation:

```
iso_x = cos(45°)*x - sin(45°)*y - z*cos(60°)
iso_y = sin(45°)*x + cos(45°)*y - z*sin(60°)
```

Angles chosen:
* 45° → balances x & y contribution.
* 60° depth factor → vertical compression / perceived height.

The map is also uniformly scaled by an integer interval chosen to fit within `WIDTH × HEIGHT`. Offsets are then added to center the result.

---

## 7. Scaling & Centering Strategy

`ft_define_offset` computes `interval = min(WIDTH/width, HEIGHT/height)` ensuring the map fits. Then:

```
scaled_x = original_x * interval
scaled_y = original_y * interval
```

After projection, a final `(start_x, start_y)` offset recenters geometry. This avoids floating overflow and preserves integer raster milestones while still using `float` for projection.

---

## 8. Line Rasterization (Bresenham)

To draw a segment between two projected points only integer increments and additions are used, avoiding per‑pixel multiplications or divisions.

Two variants handle slope magnitude:
* Shallow: |slope| < 1 → step in x, conditionally adjust y.
* Steep:   |slope| ≥ 1 → step in y, conditionally adjust x.

Decision variable `p` (here `params->p`) evolves:
```
p0 = 2*dy - dx (shallow)
If p <= 0: p += 2*dy
Else:      p += 2*dy - 2*dx and y += sy
```

This results in O(L) time where L is the dominant delta (dx or dy) with constant memory.

---

## 9. Color Gradients

`ft_gradient(start_color, end_color, position, length)` interpolates each RGB channel linearly:

```
channel = start + (end - start) * position / length
```

Alpha is fixed at 0xFF (opaque). This gives smooth transitions across terrain lines when endpoints differ in color.

---

## 10. Event Loop & Input

MLX42 provides an internal loop; a hook checks every frame whether ESC is pressed, then gracefully closes the window. (Further interactions—zoom, rotate, pan—can be layered by extending `ft_hook`).

---

## 11. Directory Structure

```
includes/       Public header (fdf.h)
lib/            Submodules: libft (utility library) + MLX42 (graphics)
maps/           Sample .fdf map files
source/         Project source code
  bresenhams_line.c  – Line raster functions
  draw.c             – Iterates neighbors & triggers line draws
  draw_utils.c       – Parameter derivation & viewport scaling logic
  fdf.c              – Entry point: init, parse, render, loop
  fdf_utils.c        – Hooks, error handling, file height counting
  gradient.c         – Color interpolation
  isometric.c        – Projection & rescaling
  parse_map.c        – Core map parsing
  parse_utils.c      – Memory helpers & width computation
  parse_colours.c    – Z/color token decoding
Makefile         Build script
README.md        This document
```

---

## 12. Build & Run

Prerequisites:
* GCC or Clang
* CMake (for MLX42) & GLFW (runtime)

Build:
```bash
git clone https://github.com/mifavoyke/FdF.git
cd FdF
git submodule update --init --recursive
make
```

Run:
```bash
./fdf maps/42.fdf
```

---

## 13. Extending the Project

Ideas:
* Interactive controls: WASD pan, +/- zoom, Q/E rotate.
* Alternative projections: dimetric, perspective (divide by depth).
* Z exaggeration slider.
* Mesh fill / triangle rasterization for solid surfaces.
* Dynamic color palettes based on altitude ranges.
* FPS counter & frame timing.

Architectural Notes:
* Keep projection pure (no side effects outside of coordinate rewriting) to allow toggling views.
* Consider caching original x,y,z separately from projected screen coordinates if multiple projections will coexist.

---

## 14. Performance Considerations

* Bresenham is already optimal for line drawing; overdraw is minimal (each edge once).
* Using an image buffer then presenting avoids immediate mode flicker.
* Potential optimization: skip drawing lines fully outside viewport (trivial reject on endpoints).
* For very large maps: introduce dynamic downscaling or cull distant lines.

---

## 15. Error Handling & Memory Safety

* All allocations checked; failures propagate by early return.
* On format violations (non‑rectangular map) memory freed for processed rows.
* File descriptor is closed in both success and early failure paths (in counting & reading functions).
* Pixel plotting is bounds‑guarded.

---

## 16. Theoretical References

* Bresenham, J. E. (1965). “Algorithm for computer control of a digital plotter.” IBM Systems Journal.
* Classic isometric game projection formulas derived from axis rotations.
* Linear color interpolation in RGB space.

---

## 17. File‑by‑File Summary

| File | Role |
|------|------|
| `fdf.c` | Program entry: init MLX, parse arguments, orchestrate render & loop. |
| `isometric.c` | Scaling + isometric projection logic. |
| `draw.c` | Iterates map grid, draws horizontal & vertical connections. |
| `bresenhams_line.c` | Shallow & steep line implementations. |
| `draw_utils.c` | Parameter setup & viewport interval + centering. |
| `gradient.c` | RGB interpolation & packing into 32‑bit pixel. |
| `parse_map.c` | Main parsing orchestration and row handling. |
| `parse_utils.c` | Helpers for width counting & freeing structures. |
| `parse_colours.c` | Token → (z,color) decoding with altitude default mapping. |
| `fdf_utils.c` | Event hook, error reporting, file height counting, line collection. |

---

## 18. Controls

* ESC – Exit the program.

Future controls can be added inside `ft_hook` (keyboard state polling via MLX42).

---

## 19. License & Attribution

* Core project authored as part of the 42 curriculum by the repository owner.
* Uses [MLX42](https://github.com/codam-coding-college/MLX42) (see its LICENSE).
* Includes a local copy of `libft` (42 common utility library).

---

## 20. Screenshot Evolution

Early wireframe vs enhanced coloring and centering:

![2](https://github.com/user-attachments/assets/72229fa8-f2cb-45a0-bed5-01b5cda08b34)
<img width="465" alt="4" src="https://github.com/user-attachments/assets/fb553dfb-3040-4590-8d8d-86e26158b538">

Final examples:

<img width="772" alt="5" src="https://github.com/user-attachments/assets/0a5a5424-36e5-4b78-aeb8-3eaceffecfd3">
<img width="683" alt="6" src="https://github.com/user-attachments/assets/cbc31b83-561d-49a0-903d-e2a531ffebaf">
<img width="728" alt="7" src="https://github.com/user-attachments/assets/7b214a91-ff92-4ac8-a2e6-f184748454c3">

---

## 21. Quick FAQ

**Why floats for projection but ints for raster?**  Projection involves trigonometric transforms; final pixel decisions use integer stepping for speed.

**Why modify coordinates in place?**  Simplicity & memory locality. For multiple projections, store originals separately.

**Why not perspective?**  The project specification focuses on pedagogical isometric rendering.

---

## 22. Next Steps (Suggested Roadmap)

1. Add interactive zoom & pan.
2. Implement rotation around Z at runtime.
3. Maintain original coordinate buffer for reversible projections.
4. Add on‑screen legend (help + stats) using MLX42 text API.
5. Optimize by clipping lines outside viewport.

---

Happy hacking – explore, extend, and experiment with projections!


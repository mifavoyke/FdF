# FdF – Wireframe 3D Map Renderer

FdF (Fil de Fer – “wireframe”) is a graphics project that renders a 2D isometric wireframe using MLX42 library. It reads a map (see the format below), parses the values and calculates the coordinates for pixels first primitively from above. Then, takes into account the given altitude and recalculates coordinates into a 3D-like isometric projection.

## Demo

<img width="400" src="https://github.com/user-attachments/assets/0a5a5424-36e5-4b78-aeb8-3eaceffecfd3">
<img align="right" width="400" src="https://github.com/user-attachments/assets/7b214a91-ff92-4ac8-a2e6-f184748454c3">
<p align="center">
<img width="400" src="https://github.com/user-attachments/assets/cbc31b83-561d-49a0-903d-e2a531ffebaf">
</p>

## Map File Format

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

Each number represents a point in space:
• The horizontal position corresponds to its abscissa.
• The vertical position corresponds to its ordinate.
• The value corresponds to its altitude.

## Projection Mathematics

In this implementation I applied the 3 x 3 rotation matrix that I found on Wikipedia:

https://en.wikipedia.org/wiki/Rotation_matrix

<p align="center">
  <img src="https://github.com/user-attachments/assets/97d8fab8-d8d2-4f17-81a2-bd4e5c1b881f" width="300"/>
</p>

I took the third matrix since the we only rotate around z axis. Hence these formulas:
```
	isometric_x = cos(45 * (PI / 180)) * x - sin(45 * (PI / 180)) * y;
	isometric_y = sin(45 * (PI / 180)) * x + cos(45 * (PI / 180)) * y;
```

## Lines

If we wanted perfectly straight or diagonal lines it wouldn't be an issue to just iterate through x and y in loops. Here, the diagonal line can have let's say width 10 and height 4 which would be a shallow line. Because pixels can only be integers (no float), before putting one the programme must decide whether it moves straight to the right (or left) or up (or down). That's where this guy helped me:
https://youtu.be/RGB-wlatStc?si=RZXFxfKUcOPuE_mq

#### Basically
Two variants handle slopes:
* Shallow: |slope| < 1 → step in x, conditionally adjust y.
* Steep:   |slope| ≥ 1 → step in y, conditionally adjust x.

## Color Gradients

`ft_gradient(start_color, end_color, position, length)` interpolates each RGB channel linearly:

```
channel = start + (end - start) * position / length
```

## The end
Thanks for reading. If you reached here, I am already fond of you.

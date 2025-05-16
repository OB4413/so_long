# 🎮 so_long

> A small 2D game project developed at 1337 School using the MiniLibX graphics library.

## 📌 Description

In **so_long**, the player controls a character on a grid-based map, aiming to:
- Collect all items (`C`)
- Reach the exit (`E`)
- Avoid enemies or obstacles (optional)
- All while respecting a basic move counter

This project is a great introduction to graphics programming and game loop logic in C.

## 🛠️ Features

- Grid-based player movement
- Collectibles and exit logic
- Basic enemy or trap support
- Custom map parsing from `.ber` files
- Frame rendering with MiniLibX (X11)

## 🎮 Controls

| Key       | Action         |
|-----------|----------------|
| `W` / `↑` | Move Up        |
| `A` / `←` | Move Left      |
| `S` / `↓` | Move Down      |
| `D` / `→` | Move Right     |
| `ESC`     | Exit Game      |

## 🗂️ Project Structure


## 🧠 What I Learned

- Handling input and event hooks in X11
- Managing 2D graphics with MiniLibX
- Game loop and frame rendering
- Map parsing and error handling
- Clean memory management and freeing resources

## 📦 Requirements

- Linux environment (MiniLibX uses X11)
- GCC compiler
- `make` utility
- `minilibx-linux` installed

## 🚀 How to Run

```bash
make
./so_long maps/map1.ber

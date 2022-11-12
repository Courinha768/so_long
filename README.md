# SO_LONG
![alt text](https://img.shields.io/aur/last-modified/google-chrome?color=14141414134&style=for-the-badge)

The goal of the project is to create a basic 2D game in which a dolphin escapes Earth after eating some fish. Instead of a dolphin, fish, and the Earth, it can be any character, any collectible and any place.

![alt text](https://github.com/Courinha768/so_long/blob/master/so_long.png?raw=true)

## Installing

```
git clone https://github.com/Courinha768/so_long.git
```
or download the zip file on git hub.

## Usage

to compile the project do:
```
make all
```
And to run the game do :
```
./so_long [map_name]
```
replacing "[map_name]" with the path to the file of ur map.

## Map creation

To create a map you have to create a file with the .ber extension.
All maps should be rectangles and the borders should be made of walls
U can look at the given maps to understand better

| character | Description                                     |
| --------- | -----------------------------------------------|
| 0         | free space |
| 1         | wall |
| P         | player starting point |
| E         | exit |
| C         | collectables |
#include "canvas.h"

Canvas::Canvas(int lines, int columns) : lines(lines), columns(columns) {
	grid = new char* [lines];
	for (int i = 0; i < lines; i++) {
		grid[i] = new char[columns];
	}
	clear();
}

Canvas::~Canvas() {
	for (int i = 0; i < lines; i++) {
		delete[] grid[i];
	}
	delete[] grid;
}

void Canvas::set_pixel(int x, int y, char value) {
	if (x >= 0 && x < lines && y >= 0 && y < columns) {
		grid[x][y] = value;
	}
}

void Canvas::set_pixels(int count, ...) {
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++) {
		int x = va_arg(args, int);
		int y = va_arg(args, int);
		char value = (char)va_arg(args, int);
		set_pixel(x, y, value);
	}
	va_end(args);
}

void Canvas::clear() {
	for (int i = 0; i < lines; ++i) {
		for (int j = 0; j < columns; ++j) {
			grid[i][j] = ' ';
		}
	}
}

void Canvas::print() const {
	for (int i = 0; i < lines; ++i) {
		for (int j = 0; j < columns; ++j) {
			std::cout << grid[i][j];
		}
		std::cout << '\n';
	}
}
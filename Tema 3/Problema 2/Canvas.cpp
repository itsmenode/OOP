#include "Canvas.h"
#include <iostream>

Canvas::Canvas(int w, int h) : width(w), height(h) {
	matrix = new char* [height];
	for (int i = 0; i < height; i++) {
		matrix[i] = new char[width];
	}
	Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	int dx = 0, dy = 0;
	int d = 3 - 2 * ray;
	while (dx <= dy) {
		SetPoint(x + dx, y + dy, ch);
		SetPoint(x - dx, y + dy, ch);
		SetPoint(x + dx, y - dy, ch);
		SetPoint(x - dx, y - dy, ch);
		SetPoint(x + dy, y + dx, ch);
		SetPoint(x - dy, y + dx, ch);
		SetPoint(x + dy, y - dx, ch);
		SetPoint(x - dy, y - dx, ch);
		if (d < 0) d = d + 4 * dx + 6;
		else {
			d = d + 4 * (dx - dy) + 10;
			dy--;
		}
		dx++;
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int dx = -ray; dx <= ray; dx++) {
		for (int dy = -ray; dy <= ray; dy++) {
			if (dx * dx + dy * dy <= ray * ray) {
				SetPoint(x + dx, y + dy, ch);
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	for (int i = left; i <= right; i++) {
		SetPoint(i, top, ch);
		SetPoint(i, bottom, ch);
	}
	for (int i = top; i <= bottom; i++) {
		SetPoint(left, i, ch);
		SetPoint(right, i, ch);
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			SetPoint(j, i, ch);
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch) {
	if (x >= 0 && x < width && y >= 0 && y < height) {
		matrix[y][x] = ch;
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int dx = x2 - x1, dy = y2 - y1;
	int abs_dx = (dx < 0) ? -dx : dx;
	int abs_dy = (dy < 0) ? -dy : dy;
	int sx = (dx < 0) ? -1 : 1;
	int sy = (dy < 0) ? -1 : 1;
	int err = abs_dx - abs_dy;

	while (true) {
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2) break;
		int e2 = 2 * err;
		if (e2 > -abs_dy) {
			err -= abs_dy;
			x1 += sx;
		}
		if (e2 < abs_dx) {
			err += abs_dx;
			y1 += sy;
		}
	}
}

void Canvas::Print() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout<<matrix[i][j];
		}
		std::cout << '\n';
	}
}

void Canvas::Clear() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = ' ';
		}
	}
}
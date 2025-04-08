#include "Canvas.h"
#include <cstdio>
#include <cmath>
#include <cstdlib>

Canvas::Canvas(int width, int height) : width(width), height(height)
{
    matrix = new char*[height];
    for (int i = 0; i < height; ++i)
    {
        matrix[i] = new char[width];
        for (int j = 0; j < width; ++j)
            matrix[i][j] = ' ';
    }
}

Canvas::~Canvas()
{
    for (int i = 0; i < height; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
        matrix[y][x] = ch;
}

void Canvas::Clear()
{
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            matrix[i][j] = ' ';
}

void Canvas::Print()
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
            putchar(matrix[i][j]);
        putchar('\n');
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int x = left; x <= right; ++x)
    {
        SetPoint(x, top, ch);
        SetPoint(x, bottom, ch);
    }
    for (int y = top; y <= bottom; ++y)
    {
        SetPoint(left, y, ch);
        SetPoint(right, y, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int y = top; y <= bottom; ++y)
        for (int x = left; x <= right; ++x)
            SetPoint(x, y, ch);
}

void Canvas::DrawCircle(int x0, int y0, int r, char ch)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (y >= x)
    {
        SetPoint(x0 + x, y0 + y, ch);
        SetPoint(x0 - x, y0 + y, ch);
        SetPoint(x0 + x, y0 - y, ch);
        SetPoint(x0 - x, y0 - y, ch);
        SetPoint(x0 + y, y0 + x, ch);
        SetPoint(x0 - y, y0 + x, ch);
        SetPoint(x0 + y, y0 - x, ch);
        SetPoint(x0 - y, y0 - x, ch);
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
    }
}

void Canvas::FillCircle(int x0, int y0, int r, char ch)
{
    for (int y = -r; y <= r; ++y)
        for (int x = -r; x <= r; ++x)
            if (x * x + y * y <= r * r)
                SetPoint(x0 + x, y0 + y, ch);
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;

    while (true)
    {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

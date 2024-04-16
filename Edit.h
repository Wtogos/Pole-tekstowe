#ifndef EDIT_HPP
#define EDIT_HPP

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

class Edit {
public:
    enum Color {
        Black = 0,
        Blue = 1,
        Green = 2,
        Cyan = 3,
        Red = 4,
        Magenta = 5,
        Yellow = 6,
        White = 7,
        Gray = 8,
        LBlue = 9,
        LGreen = 10,
        LCyan = 11,
        LRed = 12,
        LMagenta = 13,
        LYellow = 14,
        LWhite = 15
    };

    Edit();
    void setPosition(int x, int y);
    void setLength(int length);
    void setText(const std::string& text);
    void setTextColor(Color color);
    void setBackgroundColor(Color color);
    std::string getText() const;
    void userText();

private:
    int x, y, length;
    std::string text;
    Color textColor, bgColor;
    void draw();
};

#endif // EDIT_HPP

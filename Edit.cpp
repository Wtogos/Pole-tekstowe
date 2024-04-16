#include "Edit.h"

Edit::Edit() : x(0), y(0), length(0), textColor(White), bgColor(Black) {}

void Edit::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Edit::setLength(int length) {
    this->length = length;
}

void Edit::setText(const std::string& text) {
    this->text = text;
}

void Edit::setTextColor(Color color) {
    this->textColor = color;
}

void Edit::setBackgroundColor(Color color) {
    this->bgColor = color;
}

std::string Edit::getText() const {
    return text;
}

void Edit::userText() {
    char ch;
    while ((ch = _getch()) != 13) { // 13 ASCII code for Enter
        if (ch == 8 && text.size() > 0) { // 8 ASCII code for Backspace
            text.pop_back();
        }
        else if (ch >= 32 && ch <= 126 && text.size() < length) {
            text += ch;
        }
        draw();
    }
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
}

void Edit::draw() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>((bgColor << 4) | textColor));
    std::cout << text;
}

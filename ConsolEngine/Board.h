#pragma once

//отвечает за игровое поле, хранит информацию о расположении блоков, проверяет заполнены ли линии и очищает их
#include "Tetromino.h"
#include <vector>

class Board
{
    private:
    int width;
    int height;
    std::vector <std::vector<int>> grid;

    public:
    Board();
    Board(int w, int h) : width(w), height(h), grid(h, std::vector<int>(w, 0)) {};

    bool IsLineFull(int y);
  
    void ClearLine(int y);


    void PlaceTetromino(const CTetromino& tetromino);


    bool CheckCollision(const CTetromino& tetromino);


    // Другие необходимые методы
};


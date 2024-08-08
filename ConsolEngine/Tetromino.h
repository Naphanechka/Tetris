#pragma once

// Класс фигура в игре. Хранит форму в игре  и текущую позицию, методв для повороти фигуры. хранит ее состояния

//#include <vector>
#include <array>

namespace MyConsts
{
    enum class ETetrominoType;
}

class CTetromino
{
    private:
    std::array<std::array<int, 4>, 4> Shape;
    //std::vector<std::vector<int>> shape;
    int x, y;
    MyConsts::ETetrominoType Type;
    int Spined{0};

public:
    CTetromino();
    CTetromino(const MyConsts::ETetrominoType InType);

    void Rotate();


    void Move(int dx, int dy);


    std::array<std::array<int,4>,4> GetShape() const;
    

    int GetX() const;
   

    int GetY() const;
  

    // Другие необходимые методы

    private:
    void SetType(const MyConsts::ETetrominoType InType);
};

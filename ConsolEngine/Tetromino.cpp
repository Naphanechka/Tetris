#pragma once

#include "Tetromino.h"
#include <array>
#include "MyConsts.h"


//CTetromino::CTetromino(const std::vector<std::vector<int>>& s) 
//    : shape(s)
//    , x(0)
//    , y(0)
//{}

namespace
{
    std::array<std::array<std::array<int, 4>, 4>, 9> ArrAllTetromino = {
         std::array<std::array<int, 4>, 4>{{ //INVALID
             { 0, 0, 0, 0 },
             { 0, 0, 0, 0 },
             { 0, 0, 0, 0 },
             { 0, 0, 0, 0 }
         }},
         std::array<std::array<int, 4>, 4>{{ //LINE
             { 1, 0, 0, 0 },
             { 1, 0, 0, 0 },
             { 1, 0, 0, 0 },
             { 1, 0, 0, 0 }
         }},
         std::array<std::array<int, 4>, 4>{{ //T
             { 1, 1, 1, 0 },
             { 0, 1, 0, 0 },
             { 0, 0, 0, 0 },
             { 0, 0, 0, 0 }
         }},
         std::array<std::array<int, 4>, 4>{{ //SQUARE
             { 1, 1, 0, 0 },
             { 1, 1, 0, 0 },
             { 0, 0, 0, 0 },
             { 0, 0, 0, 0 }
         }},
         std::array<std::array<int, 4>, 4>{{ //L
             { 1, 0, 0, 0 },
             { 1, 0, 0, 0 },
             { 1, 1, 0, 0 },
             { 0, 0, 0, 0 }
         }},
         std::array<std::array<int, 4>, 4>{{ //J
             { 0, 1, 0, 0 },
             { 0, 1, 0, 0 },
             { 1, 1, 0, 0 },
             { 0, 0, 0, 0 }
         }},
         std::array<std::array<int, 4>, 4>{{ //Z
             { 1, 1, 0, 0 },
             { 0, 1, 0, 0 },
             { 0, 1, 1, 0 },
             { 0, 0, 0, 0 }
         }},
         std::array<std::array<int, 4>, 4>{{ //S
             { 0, 1, 1, 0 },
             { 0, 1, 0, 0 },
             { 1, 1, 0, 0 },
             { 0, 0, 0, 0 }
         }},
         std::array<std::array<int, 4>, 4>{{ //COUNT
             { 0, 0, 0, 0 },
             { 0, 0, 0, 0 },
             { 0, 0, 0, 0 },
             { 0, 0, 0, 0 }
         }}
    };
}
CTetromino::CTetromino():CTetromino(MyConsts::ETetrominoType::INVALID)
{


}

CTetromino::CTetromino(const MyConsts::ETetrominoType InType)
    : x(0)
    , y(0)
    , Type (InType)
{
    CTetromino::SetType(Type);
}



void CTetromino::Rotate()
    {
        // Поворот фигуры
    }

    void CTetromino::Move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }

    std::array<std::array<int, 4>, 4> CTetromino::GetShape() const
    {
        return std::array<std::array<int, 4>, 4>();
    }

    int CTetromino::GetX() const
    {
        return x;
    }

    int CTetromino::GetY() const
    {
        return y;
    }

    void CTetromino::SetType(const MyConsts::ETetrominoType InType)
    {

        Shape = ArrAllTetromino[static_cast<int>(InType)];
    }

    // Другие необходимые методы

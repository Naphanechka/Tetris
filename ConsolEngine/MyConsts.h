#pragma once

#include <vector>

namespace MyConsts
{
   constexpr size_t XRenderStats{ 1 }; 
   constexpr size_t YRenderStats{ 1 };

   constexpr char* SLines { " LINES " };
   constexpr char* SLevel { " LEVEL " };
   constexpr char* SScore { " SCORE " };


    constexpr size_t XBordStart{ 30 }; //XBordStart > 1 || XBordStart > 1
    constexpr size_t YBordStart{ 1 };

    constexpr char* StrLeft            { " Turn Left       'Left'  or 'A'" };
    constexpr char* StrRight           { " Turn Right      'Right' or 'D'" };
    constexpr char* StrSpeedUp         { " Speed Up        'Up'    or 'S'" };
    constexpr char* StrRotateTetromino { " RotateTetromino 'Space'" };


    enum class ETetrominoType
    {
        INVALID = 0,
        LINE,
        T,
        SQUARE,
        L,
        J,
        Z,
        S,
        COUNT
    };



}

#pragma once
#include "BaseApp.h"

#include "Board.h"
//#include "Tetromino.h"
class CTetromino;

class TetrisApp : public BaseApp
{
    private:

    Board board;
    CTetromino* currentTetromino = nullptr;//сделать умный указатель
    // Другие необходимые переменные и методы


    public:

    TetrisApp(int xSize, int ySize);
    void KeyPressed(int btnCode) override;
    void UpdateF(float deltaTime) override;


    private:

    void RenderStr(const std::string& InStr, const size_t InX, const size_t InY);
    void RenderStats();
    void RenderNextTetramino();
    void RenderControls(size_t XControlsStart, size_t YControlsStart);
    void RenderBoard(const std::vector<std::vector<int>>& VBord);
    
};





#pragma once
#include "TetrisApp.h"

#include <vector>

#include "Tetromino.h"
#include "MyConsts.h"


TetrisApp::TetrisApp(int xSize, int ySize)
    : BaseApp(xSize, ySize)
{

}

void TetrisApp::KeyPressed(int btnCode)
{
// Обработка нажатий клавиш для управления фигурами
}



void TetrisApp::UpdateF(float deltaTime) //render
{
    std::vector<std::vector<int>> VBord{//исправить на array
                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                                { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
                                                { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                                { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
                                                { 0, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
                                                { 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 } };

   // CTetromino NextTetromino;
    int a = currentTetromino->GetX();
    //size_t count{1};
    //std::string str = {" Hello Woorld!"};
    //for (char a : str)
    //{
    //    SetChar(count, 1, a);
    //    count++;
    //}
     
    
    //SetChar(1, 1, L'H');
    // Логика обновления игры

    
    TetrisApp::RenderStats();

    TetrisApp::RenderBoard(VBord);

    TetrisApp::RenderControls((MyConsts::XBordStart + (VBord[0].size())) + 2, MyConsts::YBordStart);
    
}

void TetrisApp::RenderStr(const std::string& InStr, const size_t InX, const size_t InY) // Just my String output
{
    size_t Count{ 0 };

    
    for (const char& a : InStr)
    {
        SetChar(InX + Count, InY, a);
        Count++;
    }
}

void TetrisApp::RenderStats()
{

    size_t Count{ 0 };

    TetrisApp::RenderStr(MyConsts::SLines, MyConsts::XRenderStats, MyConsts::YRenderStats + Count++);
    TetrisApp::RenderStr(MyConsts::SLevel, MyConsts::XRenderStats, MyConsts::YRenderStats + Count++);
    TetrisApp::RenderStr(MyConsts::SScore, MyConsts::XRenderStats, MyConsts::YRenderStats + Count++);
}

void TetrisApp::RenderNextTetramino()//вівод на єкран фигруры, кот будет Next
{

}

void TetrisApp::RenderControls(const size_t XControlsStart, const size_t YControlsStart)
{

    size_t Count{0};
    
    TetrisApp::RenderStr(MyConsts::StrLeft, XControlsStart, YControlsStart + Count++);
    TetrisApp::RenderStr(MyConsts::StrRight, XControlsStart, YControlsStart + Count++);
    TetrisApp::RenderStr(MyConsts::StrSpeedUp, XControlsStart, YControlsStart + Count++);
    TetrisApp::RenderStr(MyConsts::StrRotateTetromino, XControlsStart, YControlsStart + Count++);
   
}

void TetrisApp::RenderBoard(const std::vector<std::vector<int>>& VBord)
{
    
    size_t boardHeight = VBord.size();
    size_t boardWidth = VBord.empty() ? 0 : VBord[0].size();

    size_t AraundXBordStart{ MyConsts::YBordStart - 1};
    size_t AraundXBordFinish{ MyConsts::YBordStart + boardHeight};
    size_t AraundYBordStart{ MyConsts::XBordStart - 1 };
    size_t AraundYBordFinish{ MyConsts::XBordStart + boardWidth };

    

    if (MyConsts::XBordStart + boardWidth > X_SIZE || MyConsts::YBordStart + boardHeight > Y_SIZE)
        {
            std::cerr << "Board dimensions exceed rendering area." << std::endl;
            return;
        }


    for (size_t Row = 0; Row < VBord.size(); ++Row)
    {
        for (size_t Column = 0; Column < VBord[Row].size(); Column++)
        {
            SetChar((MyConsts::XBordStart + Column), (MyConsts::YBordStart + Row), (VBord[Row][Column] == 0 ? '.' : '#'/*'\u2588'*/));
        }
        
    }

    for (size_t DrawTopBorder = 0; DrawTopBorder < boardWidth; ++DrawTopBorder)
    {
        SetChar(DrawTopBorder + MyConsts::XBordStart,AraundXBordStart,  '@');
        SetChar(DrawTopBorder + MyConsts::XBordStart,AraundXBordFinish,  '@');

    }
    for (size_t ColumnDraw = 0; ColumnDraw < boardHeight + 2; ColumnDraw++)
    {
        SetChar(AraundYBordStart, ColumnDraw + MyConsts::YBordStart - 1 , '@');
        SetChar(AraundYBordFinish, ColumnDraw + MyConsts::YBordStart - 1, '@');
    }




}


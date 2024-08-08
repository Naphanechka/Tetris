// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "BaseApp.h"
#include <algorithm>
#include <time.h>
#include <conio.h>
#include <assert.h>
#include <strsafe.h>
#include <windows.h>
#include <fcntl.h>
#include <io.h>

#define MY_PERFORMENCE_COUNTER

#include "PerformanceCounter.h"

BaseApp::BaseApp(int xSize, int ySize) : X_SIZE(xSize), Y_SIZE(ySize)
{
    COORD windowBufSize = {X_SIZE, Y_SIZE};

    mConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    mConsoleIn = GetStdHandle(STD_INPUT_HANDLE);

    SMALL_RECT windowSize = { 0, 0, 1, 1 };
    if (!SetConsoleWindowInfo(mConsole, TRUE, &windowSize))
    {
        cout << "SetConsoleWindowInfo failed with error " << GetLastError() << endl;
    }
    if(!SetConsoleScreenBufferSize(mConsole,  windowBufSize))
    {
        cout << "SetConsoleScreenBufferSize failed with error " << GetLastError() << endl;
    }
    windowSize = { 0, 0, static_cast<short>(X_SIZE), static_cast<short>(Y_SIZE)};
    if(!SetConsoleWindowInfo(mConsole, TRUE, &windowSize))
    {
        cout << "SetConsoleWindowInfo failed with error " << GetLastError() << endl;
    }

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(mConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(mConsole, &cursorInfo);


    mChiBuffer = (CHAR_INFO*)malloc((X_SIZE)*(Y_SIZE)*sizeof(CHAR_INFO));

    mDwBufferSize.X = X_SIZE;
    mDwBufferSize.Y = Y_SIZE;       // размер буфера данных

    mDwBufferCoord.X = 0;
    mDwBufferCoord.Y = 0;               // координаты ячейки

    mLpWriteRegion.Left = 0;
    mLpWriteRegion.Top = 0;
    mLpWriteRegion.Right = X_SIZE;
    mLpWriteRegion.Bottom = Y_SIZE; // прямоугольник для чтения


    for (int x=0; x<X_SIZE; x++)
    {
        for (int y=0; y<Y_SIZE; y++)
        {
            SetChar(x, y, L' ');
        }
    }

    // Set console output to Unicode
    _setmode(_fileno(stdout), _O_U16TEXT);

    // Set console code page to UTF-8 so it can output Unicode characters
    SetConsoleOutputCP(CP_UTF8);
}

BaseApp::~BaseApp()
{
    free(mChiBuffer);
}

void BaseApp::SetChar(int x, int y, wchar_t c)
{
    auto& Buffer{ mChiBuffer[x + X_SIZE * y] };
    Buffer.Char.UnicodeChar = c;
    Buffer.Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
}

wchar_t BaseApp::GetChar(int x, int y)
{
    return mChiBuffer[x + X_SIZE * y].Char.UnicodeChar;
}

void BaseApp::Render()
{
    if (!WriteConsoleOutput(mConsole, mChiBuffer, mDwBufferSize, mDwBufferCoord, &mLpWriteRegion)) 
    {
        printf("WriteConsoleOutput failed - (%d)\n", GetLastError()); 
    }
}

void BaseApp::Run()
{
    CStopwatch timer;
    int sum = 0;
    int counter = 0;

    int deltaTime = 0;
    while (1)
    {
        timer.Start();
        if (kbhit())
        {
            KeyPressed (getch());
            if (!FlushConsoleInputBuffer(mConsoleIn))
                cout<<"FlushConsoleInputBuffer failed with error "<<GetLastError();
        }

        UpdateF((float)deltaTime / 1000.0f);
        Render();
        Sleep(1);

        while (1)
        {
            deltaTime = timer.Now();
            if (deltaTime > 16)
                break;
        }

        sum += deltaTime;
        counter++;
        if (sum >= 1000)
        {
            TCHAR szbuff[255];
            StringCchPrintf(szbuff, 255, TEXT("FPS: %d"), counter);
            SetConsoleTitle(szbuff);

            counter = 0;
            sum = 0;
        }
    }
}
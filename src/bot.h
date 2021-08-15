/*
 * @Author: lmintlcx 
 * @Date: 2018-06-28 13:30:04 
 * @Description: Simulate mouse and keyboard operation.
 */

#pragma once

#include "src/process.h"

namespace Pt
{

class Bot : public Process
{
  public:
    Bot(HWND hwnd = nullptr);
    ~Bot();

    void LeftDown(int, int);
    void LeftUp(int, int);
    void LeftClick(int, int);
    void Click(int, int);
    void RightDown(int, int);
    void RightUp(int, int);
    void RightClick(int, int);
    void SafeClick();

    void PressESC();
    void PressSpace();
    void PressUp();
    void PressDown();
    void PressLeft();
    void PressRight();
    void PressKey(char);

    void ClickSeed(int);
    void ClickShovel();
    void ClickGrid(double, double);

  private:
    void OpenProcess();
    int GetSlotsCount();
    int GetGameScene();
};

} // namespace Pt

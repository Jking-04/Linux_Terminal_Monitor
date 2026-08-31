#pragma once

#include <iomanip>
#include <iostream>
#include "cpu.h"
#include "mem.h"
#include "temp.h"
#include "network.h"
#include "bar.h"

void tuiDisplay(CpuData&,MemData&,TempData&,NetData&,double);

void openAlternateTerminal();

void closeAlternateTerminal();

void clearTerminal();

void displayCpuData(CpuData&,TempData&);

void displayMemData(MemData&);

void displayNetData(NetData&,double);

void displayGap();

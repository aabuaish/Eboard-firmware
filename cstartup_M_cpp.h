
#ifndef __CSTARTUP__
#define __CSTARTUP__

class NMI
{
public:
    static void Handler();
};

class HardFault
{
public:
    static void Handler();
};

class MemManage
{
public:
    static void Handler();
};

class BusFault
{
public:
    static void Handler();
};

class UsageFault
{
public:
    static void Handler();
};

class SVC
{
public:
    static void Handler();
};

class DebugMon
{
public:
    static void Handler();
};

class PendSV
{
public:
    static void Handler();
};

class SystemTick
{
public:
    static void Handler();
};

#endif //__CSTARTUP__
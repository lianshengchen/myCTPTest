#include <iostream>
#include "ThostFtdcMdApi.h"
#include "CustomMdSpi.h"

//CTPtest project
//VS code Easy C++ projects Plugin

//180.168.146.187:10110
//char* frontMdAddress = "tcp://180.168.146.187:10101";
//char* frontMdAddress = "tcp://180.168.146.187:10110";
//char* frontMdAddress = "tcp://180.168.146.187:10131";
char* frontMdAddress = "tcp://180.168.146.187:10131";
TThostFtdcBrokerIDType gBrokerID = "9999"; 
TThostFtdcInvestorIDType gInvesterID = "158383";                         // 投资者账户名
TThostFtdcPasswordType gInvesterPassword = "123456"; 

CThostFtdcMdApi *g_pMdUserApi = nullptr;

char *g_pInstrumentID[] = {"TF2006", "zn2005", "cs2001", "CF005"}; // 行情合约代码列表，中、上、大、郑交易所各选一种
int instrumentNum = 4; 

int main() {
    std::cout << "Hello CTP" << std::endl;
    g_pMdUserApi = CThostFtdcMdApi::CreateFtdcMdApi();
    CustomMdSpi* pUserMdSpi = new CustomMdSpi();
    g_pMdUserApi->RegisterSpi(pUserMdSpi);
    g_pMdUserApi->RegisterFront(frontMdAddress);
    g_pMdUserApi->Init();
    g_pMdUserApi->Join();
}
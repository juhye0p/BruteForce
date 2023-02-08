//Coded by LJX
#include <iostream>
#include <string.h>
#include <stdbool.h>
#include <cstdlib>

void arrayInit(unsigned char* str, int length){
    for(int i = 0; i < length; i++)
        str[i] = 0x20;
}

int arrayIncrease(unsigned char* str, int length){
    for(int i = 0; i < length; i++){
        if(str[i] >= 0x7e && i != length - 1){
            str[i+1] += 0x01;
            str[i] = 0x20;
        }
        else if(str[i] > 0x7e && i == length - 1)
            return -1;
        if(str[i] <= 0x7e && i == 0)
            str[i] += 1;
    }
    return 0;
}

int main(){
    unsigned char* szExeFile;
    int length = 1;
    int incRes = 0;
    int maxLength = 0;

    std::cout << "MaxLength(0 ~ 256): ";
    std::cin >> maxLength;

    if(maxLength <= 0 || maxLength > 256){
        std::cerr << "[-] Out of range.." << std::endl;
        return -1;
    }

    for(; length <= maxLength; length++){
        szExeFile = (unsigned char*)malloc(length);
        arrayInit(szExeFile, length);
        
        while(true){
            for(int i = 0; i < length; i++)
                std::printf("%c", szExeFile[i]);
            std::endl(std::cout);
            incRes = arrayIncrease(szExeFile, length);
            if(incRes == -1)    break;
        }

        free(szExeFile);
    }
    std::cout << "[+] Done!" << std::endl;
}
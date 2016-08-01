#include "bitOperations.h"
bool getBit(int num, int pos){
	return ((num&(1<<pos)) != 0);
}
int setBit(int num, int pos){
	return num | (1<<pos);
}
int clearBit(int num, int pos){
	return num & (~(1<<pos));
}
int clearBitFromLeft(int num, int pos){
	int mask = (1<<pos)-1;
	return mask & num;
}
int clearBitFromRight(int num, int pos){
	int mask = (-1 << (pos+1));
	return mask & num;
}
std::string intToBinary(int num){
	std::string bin = "";
	while(num){
		if(num%2)
			bin = bin + "1";
		else
			bin = bin + "0";
		num /= 2;
	}
	std::reverse(bin.begin(),bin.end());
	return bin;
}
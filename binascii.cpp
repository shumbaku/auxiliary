#include "binascii.h"

std::string aad::hexlify(const char *data,size_t size)
{
	std::string temp = ""; 
	unsigned j = 0; 
	char tmp = 0;
	for(unsigned i=0;i<size;i++)
	{
		j = data[i] % 256; //
		for(unsigned k=0;k<2;k++)
		{
			tmp = j % 16;
			switch(tmp)
			{
				case 0: temp.append("0"); break;
				case 1: temp.append("1"); break;
				case 2: temp.append("2"); break;
				case 3: temp.append("3"); break;
				case 4: temp.append("4"); break;
				case 5: temp.append("5"); break;
				case 6: temp.append("6"); break;
				case 7: temp.append("7"); break;
				case 8: temp.append("8"); break;
				case 9: temp.append("9"); break;
				case 10: temp.append("a"); break;
				case 11: temp.append("b"); break;
				case 12: temp.append("c"); break;
				case 13: temp.append("d"); break;
				case 14: temp.append("e"); break;
				case 15: temp.append("f"); break;
				default:  break;
			}
			j = j >> 4;
		}
	}
	for(int i = 0;i<temp.size() && temp.size()%2==0 ;i+=2)
	{
		tmp = temp[i];
		temp[i] = temp[i+1];
		temp[i+1] = tmp;
	}
	return temp;
}
std::string aad::hexlify(std::string data)
{
	return hexlify(data.c_str(),data.size());
}

std::string aad::unhexlify(std::string data,char *p,size_t s)
{
	std::string temp ="";
	if(data.size()%2==0)
	{	
		char tmp1=0x00,tmp2=0x00;
		for(unsigned i=0,j=0;i<data.size();i+=2,j++)
		{
			for(int k=0;k<2;k++)
			{
				switch(data[i+k])
				{
					case '0': tmp1 = tmp1 | 0x00; break;
					case '1': tmp1 = tmp1 | 0x01; break;
					case '2': tmp1 = tmp1 | 0x02; break;
					case '3': tmp1 = tmp1 | 0x03; break;
					case '4': tmp1 = tmp1 | 0x04; break;
					case '5': tmp1 = tmp1 | 0x05; break;
					case '6': tmp1 = tmp1 | 0x06; break;
					case '7': tmp1 = tmp1 | 0x07; break;
					case '8': tmp1 = tmp1 | 0x08; break;
					case '9': tmp1 = tmp1 | 0x09; break;
					case 'A':
					case 'a': tmp1 = tmp1 | 0x0a; break;
					case 'B':
					case 'b': tmp1 = tmp1 | 0x0b; break;
					case 'C':
					case 'c': tmp1 = tmp1 | 0x0c; break;
					case 'D':
					case 'd': tmp1 = tmp1 | 0x0d; break;
					case 'E':
					case 'e': tmp1 = tmp1 | 0x0d; break;
					case 'F':
					case 'f': tmp1 = tmp1 | 0x0f; break;
				}
				if(k==0)
					tmp1 = tmp1 << 4;
				else
					p[j] = tmp1;
			}
			tmp1 = 0x00;
		}
		temp.append(p,s);
	}
	return temp;
}
std::string aad::unhexlify(std::string data)
{
	size_t s = data.size() / 2;
	char p[s];
	return unhexlify(data,p,s);
}

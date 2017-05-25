#ifndef _H_BINASCII
#define _H_BINASCII
#include <string>
namespace aad {
	std::string hexlify(const char *data,size_t size);
	std::string hexlify(std::string data);
	std::string unhexlify(std::string data,char *p,size_t s);
	std::string unhexlify(std::string data);
}

#endif 

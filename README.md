# classes
Auxiliary classes and functions for C++

# Files
* binascii.h 

# Example for binascii
```
std::string str = "hello";
std::cout<<"str:"<<str<<" hex:"<<aad::hexlify(str)<<std::endl;
std::cout<<"------------------------------"<<std::endl;
std::string rstr=aad::hexlify(str);
std::cout<<"hex:"<<rstr<<" str:"<<aad::unhexlify(rstr)<<std::endl;
```

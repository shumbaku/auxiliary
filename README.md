# classes
Auxiliary classes and functions for C++

# Files
* binascii.h => It's translate from binary and hex codings 
* array.h => It's using for two dimensional arrays

# Example for binascii
```
std::string str = "hello";
std::cout<<"str:"<<str<<" hex:"<<aad::hexlify(str)<<std::endl;
std::cout<<"------------------------------"<<std::endl;
std::string rstr=aad::hexlify(str);
std::cout<<"hex:"<<rstr<<" str:"<<aad::unhexlify(rstr)<<std::endl;
```

# Example for array
```
aad::array<char> ex(10,10);
std::cout<<ex.get(0,0)<<std::endl;
char tmp='a';
ex.set(0,0,tmp);
```

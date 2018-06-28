#include "F00DUtils.h"

#include <vector>

int f00d::string_to_byte_array(std::string str, std::uint32_t nBytes, unsigned char* dest)
{
   if(str.length() < nBytes * 2)
      return -1;

   for(std::uint32_t i = 0, j = 0 ; j < nBytes; i = i + 2, j++)
   {
      std::string byteString = str.substr(i, 2);
      unsigned char byte = (unsigned char)strtol(byteString.c_str(), NULL, 16);
      dest[j] = byte;
   }
   return 0;
}

std::string f00d::byte_array_to_string(const unsigned char* source, int nBytes)
{
   std::vector<char> result(nBytes * 2 + 1);

   for(int i = 0, j = 0 ; j < nBytes; i = i + 2, j++)
   {
      sprintf(result.data() + i, "%02x", source[j]);
   }

   return std::string(result.data(), nBytes * 2);
}
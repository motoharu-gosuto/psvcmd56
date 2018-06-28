#pragma once

#include <string>
#include <cstdint>

namespace f00d
{

   int string_to_byte_array(std::string str, std::uint32_t nBytes, unsigned char* dest);

   std::string byte_array_to_string(const unsigned char* source, int nBytes);

}
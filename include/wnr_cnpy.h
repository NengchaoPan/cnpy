#pragma once

#include <memory>
#include <string>
#include <vector>

namespace cnpy {
    char* npyarray_to_char(std::string file_path, char& data_type, size_t& word_size, std::vector<size_t>& shape, size_t& num_vals); 

};

#include <string.h>
#include <stdlib.h>

#include "cnpy.h"
#include "wnr_cnpy.h"

namespace cnpy {
    char* npyarray_to_char(
            std::string file_path,
            char& data_type,
            size_t& word_size,
            std::vector<size_t>& shape,
            size_t& num_vals) {
        NpyArray arr = npy_load(file_path);

        data_type = arr.data_type;
        word_size = arr.word_size;
        shape.resize(arr.shape.size());
        for (size_t i = 0; i < shape.size(); i++) {
            shape[i] = arr.shape[i];
        }
        num_vals = arr.num_vals;
        char* p_buffer = static_cast<char*>(malloc(sizeof(char) * word_size * num_vals));

        char* buffer = p_buffer;
        char* buffer_ori = arr.data<char>();

        memcpy(buffer, buffer_ori, word_size * num_vals * sizeof(char));
        return p_buffer;
    }

};

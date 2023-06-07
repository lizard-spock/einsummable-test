#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Struct to store the extracted data
struct TensorData {
    std::string name;
    size_t size;
    std::vector<float> tensor;
};

int main() {
    // Open the binary file in read mode
    std::cout << "Hello world!" << std::endl;
    std::ifstream file("../output.bin", std::ios::binary);
    
    if (!file) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::cout << "after opening file!" << std::endl;
    // Vector to store the extracted data
    std::vector<TensorData> extracted_data;
    
    while (true) {
        std::cout << "staart of while loop!" << std::endl;
        // Read the text data (name of weight tensor)
        char text_data[11];
        file.read(text_data, 10);
        text_data[10] = '\0';
        std::string name(text_data);
        
        // If no more data to read, break the loop
        if (name.empty() || file.eof()) {
            break;
        }
        
        // Read the binary data (size of tensor)
        uint32_t size;
        file.read(reinterpret_cast<char*>(&size), sizeof(uint32_t));
        
        // Read the tensor data
        std::vector<float> tensor(size);
        file.read(reinterpret_cast<char*>(tensor.data()), size * sizeof(float));
        
        // Store the extracted data
        extracted_data.push_back({name, size, tensor});
    }
    
    // Print the extracted data
    for (const auto& data : extracted_data) {
        std::cout << "Name of weight tensor: " << data.name << std::endl;
        std::cout << "Size of tensor: " << data.size << std::endl;
        std::cout << "Tensor: ";
        for (float value : data.tensor) {
            std::cout << value << " ";
        }
        std::cout << std::endl << std::endl;
    }
    
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "json.h"

int main(int argc, char* argv[]) {
    bool useFile = false;
    const char* filename = nullptr;

    if (argc >= 3 && strcmp(argv[1], "-o") == 0) {
        useFile = true;
        filename = argv[2];
    }

    auto array_numbers = new ArrayValue();
    array_numbers->add(new NumberValue(5));
    array_numbers->add(new NumberValue(10));
    array_numbers->add(new NumberValue(15));

    auto array_strings = new ArrayValue();
    array_strings->add(new StringValue("abc"));
    array_strings->add(new StringValue("def"));
    array_strings->add(new StringValue("ghi"));

    auto subobject = new ObjectValue();
    subobject->add("email", new StringValue("t@gmail.com"));
    subobject->add("name", new StringValue("T"));
    subobject->add("online", new BoolValue(true));

    auto object = new ObjectValue();
    object->add("n", new NullValue());
    object->add("array_numbers", array_numbers);
    object->add("array_strings", array_strings);
    object->add("info", subobject);

    std::cout << "Top node has " << (unsigned)*object << " subnodes\n";

    if (useFile) {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            object->print(outFile);
            outFile << std::endl;
            outFile.close();
            std::cout << "JSON written to " << filename << std::endl;
        }
        else {
            std::cerr << "Error: Could not open file " << filename << std::endl;
        }
    }
    else {
        object->print(std::cout);
        std::cout << std::endl;
    }

    delete object;
    
    return 0;
}
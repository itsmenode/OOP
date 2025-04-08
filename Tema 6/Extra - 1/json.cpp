#define _CRT_SECURE_NO_WARNINGS
#include "json.h"
#include <cstring>

void NullValue::print(std::ostream& out) const {
    out << "null";
}

void NumberValue::print(std::ostream& out) const {
    out << value;
}

void BoolValue::print(std::ostream& out) const {
    out << (value ? "true" : "false");
}

StringValue::StringValue(const char* val) {
    strncpy(value, val, 255);
    value[255] = '\0';
}

void StringValue::print(std::ostream& out) const {
    out << "\"" << value << "\"";
}

ArrayValue::~ArrayValue() {
    for (JsonValue* element : elements) {
        delete element;
    }
}

void ArrayValue::add(JsonValue* value) {
    if (elements.size() < MAX_SIZE) {
        elements.push_back(value);
    }
}

void ArrayValue::print(std::ostream& out) const {
    out << "[";

    for (size_t i = 0; i < elements.size(); i++) {
        elements[i]->print(out);

        if (i < elements.size() - 1) {
            out << ", ";
        }
    }

    out << "]";
}

ArrayValue::operator unsigned() const {
    unsigned count = 1;
    for (JsonValue* element : elements) {
        count += static_cast<unsigned>(*element);
    }
    return count;
}

ObjectValue::~ObjectValue() {
    for (const Property& prop : properties) {
        delete prop.value;
    }
}

void ObjectValue::add(const std::string& name, JsonValue* value) {
    if (properties.size() < MAX_SIZE) {
        Property prop;
        prop.name = name;
        prop.value = value;
        properties.push_back(prop);
    }
}

void ObjectValue::print(std::ostream& out) const {
    out << "{";

    for (size_t i = 0; i < properties.size(); i++) {
        out << "\"" << properties[i].name << "\": ";
        properties[i].value->print(out);

        if (i < properties.size() - 1) {
            out << ", ";
        }
    }

    out << "}";
}

ObjectValue::operator unsigned() const {
    unsigned count = 1;
    for (const Property& prop : properties) {
        count += static_cast<unsigned>(*prop.value);
    }
    return count;
}
#pragma once

#include <iostream>
#include <string>
#include <vector>

class JsonValue {
public:
    virtual ~JsonValue() = 0;

    virtual void print(std::ostream& out) const = 0;

    virtual operator unsigned() const = 0;
};

inline JsonValue::~JsonValue() {}

class NullValue : public JsonValue {
public:
    NullValue() {}
    ~NullValue() override {}

    void print(std::ostream& out) const override;

    operator unsigned() const override { return 1; }
};

class NumberValue : public JsonValue {
private:
    double value;

public:
    NumberValue(double val) : value(val) {}
    ~NumberValue() override {}

    void print(std::ostream& out) const override;

    operator unsigned() const override { return 1; }
};

class BoolValue : public JsonValue {
private:
    bool value;

public:
    BoolValue(bool val) : value(val) {}
    ~BoolValue() override {}

    void print(std::ostream& out) const override;

    operator unsigned() const override { return 1; }
};

class StringValue : public JsonValue {
private:
    char value[256];

public:
    StringValue(const char* val);
    ~StringValue() override {}

    void print(std::ostream& out) const override;

    operator unsigned() const override { return 1; }
};

class ArrayValue : public JsonValue {
private:
    std::vector<JsonValue*> elements;
    static const int MAX_SIZE = 16;

public:
    ArrayValue() {}
    ~ArrayValue() override;

    void add(JsonValue* value);
    void print(std::ostream& out) const override;

    operator unsigned() const override;
};

class ObjectValue : public JsonValue {
private:
    struct Property {
        std::string name;
        JsonValue* value;
    };

    std::vector<Property> properties;
    static const int MAX_SIZE = 16;

public:
    ObjectValue() {}
    ~ObjectValue() override;

    void add(const std::string& name, JsonValue* value);
    void print(std::ostream& out) const override;

    operator unsigned() const override;
};
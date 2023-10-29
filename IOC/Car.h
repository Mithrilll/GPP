#pragma once
#include <string>
#include <random>

struct EngineType
{
    enum Type
    {
        Straight = 0,
        V,
        Flat,
        W,
        Radial,
        U,
        Opposite,
        X,
    }type;

    operator std::string() const
    {
        static constexpr char const* names[8]{
            "Straight",
            "V-Shape",
            "Flat",
            "W-SHape",
            "Radial",
            "U-Shape",
            "Opposite",
            "X-Shape"
        };

        return names[(int)type];
    }
};

class IEngine
{
public:
    virtual std::string info() const = 0;
    virtual void work() = 0;
    virtual ~IEngine() = default;
};

class BMWEngine : public IEngine
{
public:
    BMWEngine(EngineType e_type, float capacity) :
        engine_type{ e_type },
        engine_capacity{ capacity }
    {
    }

    virtual std::string info() const override
    {
        return  std::string("Engine:\nManufacturer: BMW\n") +
            "Type: " + (std::string)engine_type + "\n" +
            "Capacity: " + std::to_string(engine_capacity) + "\n" +
            "Strenght: " + std::to_string(strenght);
    }

    virtual void work() override
    {
        strenght *= 1 - (rand() % 100) * 0.000001;
    }

private:
    EngineType engine_type{ EngineType::Straight };
    float engine_capacity = 1.0f;
    float strenght = 100.0f;
};

class MercedesEngine : public IEngine
{
public:
    MercedesEngine(EngineType e_type, float capacity) :
        engine_type{ e_type },
        engine_capacity{ capacity }
    {
    }

    virtual std::string info() const override
    {
        return  std::string("Engine:\nManufacturer: Mercedes\n") +
            "Type: " + (std::string)engine_type + "\n" +
            "Capacity: " + std::to_string(engine_capacity) + "\n" +
            "Strenght: " + std::to_string(strenght);
    }

    virtual void work() override
    {
        strenght *= 1 - (rand() % 200) * 0.000001;
    }

private:
    EngineType engine_type{ EngineType::Straight };
    float engine_capacity = 1.0f;
    float strenght = 100.0f;
};

class NullEngine : public IEngine
{
public:
    virtual std::string info() const override
    {
        return std::string("No Engine");
    }

    virtual void work() override
    {
        return;
    }
};

class Car
{
public:
    Car(std::shared_ptr<IEngine> engine) :
        engine{ engine }
    {

    }

    std::shared_ptr<IEngine> getEngine()
    {
        return engine;
    }

    void setEngine(std::shared_ptr<IEngine> engine)
    {
        this->engine = engine;
    }

    std::string info() const
    {
        return "Car info:\n" + engine->info();
    }

private:
    std::shared_ptr<IEngine> engine;
};
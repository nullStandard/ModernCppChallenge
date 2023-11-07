#ifndef TEMPERATURE_H 
#define TEMPERATURE_H

#include <iostream>
#include <memory>

// namespace TempLib
// {
using temp_t = long double;

class Temperature;

class IScale
{
protected:
    Temperature* m_tmpContext;

public:
    virtual temp_t GetCelsius() = 0;
    virtual temp_t GetFahrenheit() = 0;
    virtual temp_t GetKelvin() = 0;

    // IScale& operator=(const IScale&);
    virtual ~IScale() = default;

    friend class Temperature;
};

class CelsiusScale : public IScale
{
public:

    virtual temp_t GetCelsius() override final;
    virtual temp_t GetFahrenheit() override final;
    virtual temp_t GetKelvin() override final;
};


class FahrenheitScale : public IScale
{
public:

    virtual temp_t GetCelsius() override final;
    virtual temp_t GetFahrenheit() override final;
    virtual temp_t GetKelvin() override final;
};


class KelvinScale : public IScale
{
public:

    virtual temp_t GetCelsius() override final;
    virtual temp_t GetFahrenheit() override final;
    virtual temp_t GetKelvin() override final;
};


class Temperature
{
private:
    temp_t m_temp;
    std::shared_ptr<IScale> m_currentScale;

    explicit Temperature(temp_t temp, std::shared_ptr<IScale> initScale);

    friend Temperature operator"" _deg(temp_t cel);
    friend Temperature operator"" _f(temp_t fahr);
    friend Temperature operator"" _K(temp_t kelv);
    friend std::ostream& operator<<(std::ostream& out, const Temperature& temp);

public:

    Temperature()  = delete;
    Temperature(const Temperature&) = default;
    Temperature(Temperature&&) = default;
    Temperature& operator=(const Temperature&) = default;
    Temperature& operator=(Temperature&&) = default;

    Temperature operator+(Temperature other);
    Temperature operator-(Temperature other);

    temp_t& GetRawTempValue();
    void TransitToNewScale(std::shared_ptr<IScale> newScale);

    temp_t GetCelsius();
    temp_t GetFahrenheit();
    temp_t GetKelvin();
    void   ConvertToCelsius();
    void   ConvertToFahrenheit();
    void   ConvertToKelvin();
    
    ~Temperature() = default;
};
// } // namespace TempLib 


inline Temperature operator"" _deg(temp_t cel)
{
    return Temperature(cel, std::make_shared<CelsiusScale>());
}

inline Temperature operator"" _f(temp_t fahr)
{
    return Temperature(fahr, std::make_shared<FahrenheitScale>());
}

inline Temperature operator"" _K(temp_t kelv)
{
    return Temperature(kelv, std::make_shared<KelvinScale>());
}

inline std::ostream& operator<<(std::ostream& out, const Temperature& temp)
{
    out << temp.m_temp;
    return out;
}
#endif // TEMPERATURE_H
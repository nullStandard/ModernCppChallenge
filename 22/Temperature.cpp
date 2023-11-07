#include "Temperature.h"

// namespace TempLib
// {


// IScale& IScale::operator=(const IScale& other)
// {
    
// }

temp_t CelsiusScale::GetCelsius()
{
    return m_tmpContext->GetRawTempValue();
}

temp_t CelsiusScale::GetFahrenheit()
{
    return 1.8L * GetCelsius() + 32.0L;
}

temp_t CelsiusScale::GetKelvin()
{
    return GetCelsius() + 273.15L;
}


temp_t FahrenheitScale::GetCelsius()
{
    return (GetFahrenheit() - 32.0L) / 1.8L;
}

temp_t FahrenheitScale::GetFahrenheit()
{
    // do nothing since it's already Fahrenheit
    return m_tmpContext->GetRawTempValue();
}

temp_t FahrenheitScale::GetKelvin()
{
    return GetCelsius() + 273.15L;
}


temp_t KelvinScale::GetCelsius()
{
    return GetKelvin() - 273.15L;
}

temp_t KelvinScale::GetFahrenheit()
{
    return 1.8L * GetCelsius() + 32.0L;
}

temp_t KelvinScale::GetKelvin()
{
    // do nothing since it's already Kelvin
    return m_tmpContext->GetRawTempValue();
}


Temperature::Temperature(temp_t temp, std::shared_ptr<IScale> initScale) : m_temp(temp), m_currentScale(initScale) 
{
    std::cout << "New object: " << this << std::endl;
    m_currentScale->m_tmpContext = this;
}


Temperature Temperature::operator+(Temperature other)
{
    other.TransitToNewScale(m_currentScale);
    return Temperature(m_temp + other.m_temp, m_currentScale);
}

Temperature Temperature::operator-(Temperature other)
{
    other.TransitToNewScale(m_currentScale);
    return Temperature(m_temp - other.m_temp, m_currentScale);
}

void Temperature::TransitToNewScale(std::shared_ptr<IScale> newScale)
{
    // decltype(auto) scaleType = typeid(*newScale);
    // if (scaleType == typeid(CelsiusScale))
    //     m_temp = GetCelsius();
    // else if(scaleType == typeid(FahrenheitScale))
    //     m_temp = GetFahrenheit();
    // else if(scaleType == typeid(KelvinScale))
    //     m_temp = GetKelvin();

    if (dynamic_cast<CelsiusScale*>(newScale.get()))
        m_temp = GetCelsius();
    else if (dynamic_cast<FahrenheitScale*>(newScale.get()))
        m_temp = GetFahrenheit();
    else if (dynamic_cast<KelvinScale*>(newScale.get()))
        m_temp = GetKelvin();

    m_currentScale = newScale;
    m_currentScale->m_tmpContext = this;
}
// } // namespace TempLib 


temp_t& Temperature::GetRawTempValue()
{
    return m_temp;
}

temp_t Temperature::GetCelsius()
{
    return m_currentScale->GetCelsius();
}

temp_t Temperature::GetFahrenheit()
{
    return m_currentScale->GetFahrenheit();
}

temp_t Temperature::GetKelvin()
{
    return m_currentScale->GetKelvin();
}

void   Temperature::ConvertToCelsius()
{
    TransitToNewScale(std::make_shared<CelsiusScale>());
}

void   Temperature::ConvertToFahrenheit()
{
    TransitToNewScale(std::make_shared<FahrenheitScale>());
}

void   Temperature::ConvertToKelvin()
{
    TransitToNewScale(std::make_shared<KelvinScale>());
}

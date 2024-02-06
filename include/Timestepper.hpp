#pragma once

class TimeStepper
{
public:
    TimeStepper(float timeStep);
    void update();
    bool shouldUpdate() const;
    void reset();

private:
    float accumulator;
    float currentTime;
    float timeStep;
};
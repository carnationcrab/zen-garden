#include "TimeStepper.hpp"
#include "Utils.hpp"

TimeStepper::TimeStepper(float timeStep)
    :accumulator(0.0f), currentTime(utils::TimeInSeconds()), timeStep(timeStep)
{
}

void TimeStepper::update()
{
    float newTime = utils::TimeInSeconds();
    float frameTime = newTime - currentTime;

    currentTime = newTime;
    accumulator += frameTime;
}

bool TimeStepper::shouldUpdate() const
{
    return accumulator >= timeStep;
}

void TimeStepper::reset()
{
    accumulator -= timeStep;
}
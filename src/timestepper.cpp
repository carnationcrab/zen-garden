#include "TimeStepper.hpp"
#include "Utils.hpp"
#include <cassert>

TimeStepper::TimeStepper(float timeStep)
    : accumulator(0.0f), currentTime(utils::TimeInSeconds()), timeStep(timeStep)
{
    assert(timeStep >= 0.0f && "Negative time step in TimeStepper constructor!");
}

void TimeStepper::update()
{
    float newTime = utils::TimeInSeconds();
    float frameTime = newTime - currentTime;

    assert(frameTime >= 0.0f && "Negative frame time in TimeStepper::update!");

    currentTime = newTime;
    accumulator += frameTime;
}

bool TimeStepper::shouldUpdate() const
{
    assert(accumulator >= 0.0f && timeStep >= 0.0f && "Negative accumulator or time step in TimeStepper::shouldUpdate!");

    return accumulator >= timeStep;
}

void TimeStepper::reset()
{
    assert(accumulator >= 0.0f && timeStep >= 0.0f && "Negative accumulator or time step in TimeStepper::reset!");

    accumulator -= timeStep;
}
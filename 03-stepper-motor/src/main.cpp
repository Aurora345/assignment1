#include <Arduino.h>

const int motorPins[] = {16, 17, 18, 19};
const int pinCount = sizeof(motorPins) / sizeof(motorPins[0]);

const int stepsPerCircle = 4096;
const int stepDelay = 2;
const int stopDelay = 1000;

const int stepSequence[][4] = {
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {1, 0, 0, 1},
};

const int sequenceLength = sizeof(stepSequence) / sizeof(stepSequence[0]);

void writeStep(int stepIndex)
{
  for (int i = 0; i < pinCount; i++)
  {
    digitalWrite(motorPins[i], stepSequence[stepIndex][i]);
  }
}

void stopMotor()
{
  for (int i = 0; i < pinCount; i++)
  {
    digitalWrite(motorPins[i], LOW);
  }
}

void rotateMotor(int direction, int steps)
{
  for (int i = 0; i < steps; i++)
  {
    int stepIndex = direction > 0 ? i % sequenceLength : (sequenceLength - 1 - (i % sequenceLength));
    writeStep(stepIndex);
    delay(stepDelay);
  }

  stopMotor();
}

void setup()
{
  for (int i = 0; i < pinCount; i++)
  {
    pinMode(motorPins[i], OUTPUT);
    digitalWrite(motorPins[i], LOW);
  }
}

void loop()
{
  rotateMotor(1, stepsPerCircle);
  delay(stopDelay);

  rotateMotor(-1, stepsPerCircle);
  delay(stopDelay);
}

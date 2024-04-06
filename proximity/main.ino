const int trig = 12;
const int echo = 13;

const int LED1 = 7;
const int LED2 = 6;
const int LED3 = 5;
const int buzzer = 8;

int duration = 0;
int distance = 0;

void setup()
{
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);

    pinMode(buzzer, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    digitalWrite(trig, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH);
    distance = (duration / 2) / 28.5;
    Serial.println(distance);
    bool toned = false;

    digitalWrite(buzzer, 0);
    if (distance <= 7)
    {
        if (!toned)
        {
            tone(buzzer, 440 * 3);
            toned = true;
        }
        digitalWrite(LED1, HIGH);
    }
    else
    {
        digitalWrite(LED1, LOW);
    }
    if (distance <= 28)
    {
        if (!toned)
        {
            tone(buzzer, 440 * 2);
            toned = true;
        }
        digitalWrite(LED2, HIGH);
    }
    else
    {
        digitalWrite(LED2, LOW);
    }
    if (distance <= 156)
    {
        if (!toned)
        {
            tone(buzzer, 440 * 1);
            toned = true;
        }
        digitalWrite(LED3, HIGH);
    }
    else
    {
        noTone(buzzer);
        digitalWrite(LED3, LOW);
    }
}
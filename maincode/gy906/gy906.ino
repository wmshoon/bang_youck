#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup()
{
    Serial.begin(9600);
    while (!Serial)
        ;

    Serial.println("Adafruit MLX90614 test");

    if (!mlx.begin())
    {
        Serial.println("Error connecting to MLX sensor. Check wiring.");
        while (1)
            ;
    };
}

float temp = 0.0;
int times = 0;
bool serial = false;
void loop()
{

    Serial.print(mlx.readObjectTempC());
    Serial.print("      ");
    Serial.println(mlx.readAmbientTempC());
}

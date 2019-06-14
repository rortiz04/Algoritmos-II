/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

static const int AMOUNT_OF_WEATHER_VARS = 6 ;

Weather weather_from_file(FILE* file)
{
    Weather weather;
 //   int k_atemp = 0;
 //   int k_maxtemp = 0;
 //   int k_mintemp = 0;
 //   unsigned int k_pressure = 0u;
 //   unsigned int k_humidity = 0u;
 //   unsigned int k_rainfall = 0u;

	int test = fscanf(file, "%i %i %i %u %u %u ", &weather._average_temp,
												  &weather._max_temp,
												  &weather._min_temp,
												  &weather._pressure,
												  &weather._moisture,
												  &weather._rainfall);

	 if (test != AMOUNT_OF_WEATHER_VARS) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }

    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp,
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
